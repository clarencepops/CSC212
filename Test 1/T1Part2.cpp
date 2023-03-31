#include <iostream>
using namespace std;
#include <cstdlib>


//void RainGen(int *matrix_ptr, int N, int M);
//void Parity(int **matrix_ptr_ptr, int N, int M);
//void Average(int **matrix_ptr_ptr, int *RainAvrg_ptr, int N, int P);
//void AddErr(int *matrix, int N, int P);
//void ErrCorr(int *matrix, int N, int P);



void RainGen(int *matrix, int N, int M) {
    srand(1023);
    int rowsFill = N-1;
    for  (int i=0; i<M*N; i++) {
        if (i % 13 == 12 or i > M * rowsFill - 1 ){
            *(matrix+i) = 0;
        }
        else {
            int RV = rand() % 100;
            *(matrix+i) = RV;
        }
    }
}

void Parity(int **matrix_ptr_ptr, int N, int M) {
    
    for (int i = 0; i < N-1; i++){
        int tempaddRow = 0;
        for (int j = 0; j < M-1; j++){
            tempaddRow = tempaddRow + matrix_ptr_ptr[i][j];
        }
        matrix_ptr_ptr[i][M-1] = tempaddRow;
    }

    for (int j = 0; j < M-1; j++){
        int tempaddRow = 0;
        for (int i = 0; i < N-1; i++){
            tempaddRow = tempaddRow + matrix_ptr_ptr[i][j];
        }
        matrix_ptr_ptr[N-1][j] = tempaddRow;
    }
}





int main(){


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
}