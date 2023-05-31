#include <iostream>
using namespace std;
#include <cstdlib>

void RainGen(int *matrix, int N, int M) {                                   // using the srand(1023) in main()
    //srand(1023);                                                          //to populate the matrix apart from the parity locations
    int rowsFill = N-1;
    for  (int i=0; i<M*N; i++) {
        if (i % 13 == 12 or i > M * rowsFill - 1 ){
            *(matrix+i) = 0;                                                //Parity values are ignored/set to zero
        }
        else {
            int RV = rand() % 100;
            *(matrix+i) = RV;
        }
    }
}

void Parity(int **matrix_ptr_ptr, int N, int M) {                           // add columns and rows
    
    for (int i = 0; i < N-1; i++){
        int tempaddRow = 0;
        for (int j = 0; j < M-1; j++){
            tempaddRow = tempaddRow + matrix_ptr_ptr[i][j];
        }
        matrix_ptr_ptr[i][M-1] = tempaddRow;
    }

    for (int j = 0; j < M-1; j++){
        int tempaddColumn = 0;
        for (int i = 0; i < N-1; i++){
            tempaddColumn = tempaddColumn + matrix_ptr_ptr[i][j];
        }
        matrix_ptr_ptr[N-1][j] = tempaddColumn;
    }
}


void Average(int **matrix_ptr_ptr, int *RainAvg, int N, int M){             // add columns and divide by total number of years
    int totalYears = N - 1;
    for (int j = 0; j < M-1; j++){
        int tempaddColumn = 0;
        for (int i = 0; i < N-1; i++){
            tempaddColumn = tempaddColumn + matrix_ptr_ptr[i][j];
        }
        RainAvg[j] = tempaddColumn / totalYears;
    }
}

void introduceError(int **matrix_ptr_ptr, int N, int M){                    //Produce random error among the matrix
    //srand(1023);
    for (int i = 0; i < N-1; i++){
        int column = rand() % 12;
        matrix_ptr_ptr[i][column] = rand() % 100;
    }
}


void mitigateError(int **matrix_ptr_ptr, int N, int M){
    int tempaddColumn = 0;

    for (int j = 0; j < M-1; j++){                                         //for each column check to see if column adds to expected value
        int tempaddColumn = 0;
//      cout << "j: " << j << endl;
        for (int i = 0; i < N-1; i++){
            tempaddColumn = tempaddColumn + matrix_ptr_ptr[i][j];          
        }
//        cout << "tempaddColumn: " << tempaddColumn << endl;
//        cout << "Correctadd: " << matrix_ptr_ptr[N-1][j] << endl;
        if (tempaddColumn != matrix_ptr_ptr[N-1][j]){                      //If it does not equal expected value, find the row which contains the expected error
            int columnDiff = tempaddColumn - matrix_ptr_ptr[N-1][j];
//            cout << "columnDiff: " << columnDiff << endl;
            for (int k = 0; k < N-1; k++) {
                int tempaddRow = 0;
                int rowDiff = 0;
 //               cout << "k: " << k << endl;
                for (int i = 0; i < M - 1; i++) {                           // Mitigate the error -> subtract the difference
                    tempaddRow = tempaddRow + matrix_ptr_ptr[k][i];         // between original value and error
                }
                rowDiff = tempaddRow - matrix_ptr_ptr[k][M-1];
                if (columnDiff == rowDiff) {
                    matrix_ptr_ptr[k][j] = matrix_ptr_ptr[k][j] - rowDiff; 
//                    cout << "matrix_ptr_ptr[k][j]: " << matrix_ptr_ptr[k][j] << endl;
                }
            }
        }
    }
}




int main(){
    string Name = "Christian Rasmussen";
    cout << "------------------------------------------------------------------------------\n"; 
    cout << "Name: " << Name << endl;
    cout << "FILE: " << __FILE__ << "DATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";


    srand(1023);
    const int N = 6, M = 13;
    
    int matrix[N][M];
    int *matrix_ptr[N];
    int **matrix_ptr_ptr = &matrix_ptr[0];


    for (int cnt=0; cnt < N; cnt++){
        matrix_ptr[cnt] = &matrix[cnt][0];
    }


    RainGen(&matrix[0][0], N, M);
    cout << "Matrix without added rows and columns:" << endl;
    for (int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            cout << matrix[a][b] << "\t";
        }
    cout << endl;
    }



    Parity(matrix_ptr_ptr, N, M);
    cout << "Matrix with added rows and columns:" << endl;
    for (int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            cout << matrix[a][b] << "\t";
        }
    cout << endl;
    }

    int RainAvg[12];
    cout << "The rain average for each month is " << endl;
    Average(matrix_ptr_ptr, RainAvg, N, M);
    for (int i = 0; i < M - 1; i++) {
        cout << RainAvg[i] << "\t";
    }
    cout << endl;

    introduceError(matrix_ptr_ptr, N, M);
    cout << "Matrix with added errors:" << endl;
    for (int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            cout << matrix[a][b] << "\t";
        }
    cout << endl;
    }

    mitigateError(matrix_ptr_ptr, N, M);
    cout << "Matrix with fixed errors:" << endl;
    for (int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            cout << matrix[a][b] << "\t";
        }
    cout << endl;
    }

}

/*

------------------------------------------------------------------------------
Name: Christian Rasmussen
FILE: T1Part2.cppDATE: Mar 30 2023
------------------------------------------------------------------------------
Matrix without added rows and columns:
61      29      95      91      75      75      56      76      11      75      96      38      0
66      21      63      42      79      38      96      80      0       93      13      14      0
25      26      59      98      93      6       74      85      80      85      39      14      0
8       96      6       52      97      21      6       38      53      57      82      58      0
96      49      75      83      63      5       15      80      93      62      80      2       0
0       0       0       0       0       0       0       0       0       0       0       0       0
Matrix with added rows and columns:
61      29      95      91      75      75      56      76      11      75      96      38      778
66      21      63      42      79      38      96      80      0       93      13      14      605
25      26      59      98      93      6       74      85      80      85      39      14      684
8       96      6       52      97      21      6       38      53      57      82      58      574
96      49      75      83      63      5       15      80      93      62      80      2       703
256     221     298     366     407     145     247     359     237     372     310     126     0
The rain average for each month is 
51      44      59      73      81      29      49      71      47      74      62      25
Matrix with added errors:
61      29      95      91      75      75      56      76      11      75      96      66      778
66      21      63      30      79      38      96      80      0       93      13      14      605
25      26      59      98      93      6       74      85      84      85      39      14      684
8       96      6       52      97      21      6       60      53      57      82      58      574
96      49      75      83      63      5       15      80      93      34      80      2       703
256     221     298     366     407     145     247     359     237     372     310     126     0
Matrix with fixed errors:
61      29      95      91      75      75      56      76      11      75      96      38      778
66      21      63      42      79      38      96      80      0       93      13      14      605
25      26      59      98      93      6       74      85      80      85      39      14      684
8       96      6       52      97      21      6       38      53      57      82      58      574
96      49      75      83      63      5       15      80      93      62      80      2       703
256     221     298     366     407     145     247     359     237     372     310     126     0


*/

