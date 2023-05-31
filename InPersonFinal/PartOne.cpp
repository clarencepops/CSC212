#include <iostream>
#include <list>
#include <algorithm>
using namespace std;


void printList(list<int> P){
    list <int>::iterator P_itr;
    cout << "The list:\n";
    for (P_itr = P.begin(); P_itr != P.end(); ++P_itr){
        cout << *P_itr << " ";
    }
    cout << endl;

}

list<int> listInsert(list<int> P, int Index, int Insert){
    list <int>::iterator P_itr = P.begin();
    
    for (int i=0; i < Index-1; ++i){
        ++P_itr;
    }

    P.insert(P_itr, Insert);

    return P;
}

bool IsOdd(int i){          //Part F
    return((i%2)==1);
}

list<int>::iterator Chercher(list<int>::iterator itr, int size, int value){
    for (int i = 0; i < size; ++i){
        if (*itr == value){
            return itr;
        }
        else{
            ++itr;
        }
    }
}

void findOdd(list<int> P){
    cout << "The first 5 integers which are odd are:\n";
    int count = 0;
    for (const int& num : P) {
        if (IsOdd(num)) {
            cout << num << " ";
            ++count;
            if (count == 5) {
                break;
            }
        }
    }
    cout << endl;
}

int main() {
    /***********************/
	cout << "Name: Christian Rasmussen" << endl;
	cout << "File: " << __FILE__ << "   " << "Date: " << __DATE__  << endl;
	/***********************/

    int Array[10] = {1,3,7,11,13,17,23,29,31,37};   //Part A

    list<int> P (Array, Array+10);      //Part B

    printList(P);           //Part C Print List

    int index = 5;
    int insert = 100;
    P = listInsert(P, index, insert);       //Part D Insert Value into index 5
    printList(P);                           //Part E Print New list 

    int numberOdd = count_if(P.begin(), P.end(), IsOdd);            // Part G
    cout << "The total number of odd numbers in the list is: " << numberOdd << endl;


    list<int>::iterator P_itr;
    int findNumber = 17;
    int replaceNumber = 47;

    P_itr = Chercher(P.begin(), P.size(), findNumber);      //Part H
    *P_itr = replaceNumber;
    printList(P);       //Part I

    findOdd(P);     //Part J


}



/*********** Results ********
Name: Christian Rasmussen
File: PartOne.cpp   Date: May 18 2023
The list:
1 3 7 11 13 17 23 29 31 37 
The list:
1 3 7 11 100 13 17 23 29 31 37 
The total number of odd numbers in the list is: 10
The list:
1 3 7 11 100 13 47 23 29 31 37 
The first 5 integers which are odd are:
1 3 7 11 13 s
*******************************/