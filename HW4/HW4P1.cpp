#include <iostream>
#include <vector>
using namespace std;


void countLine(vector<string> lineArray, vector<int> linelengthArray) {
    for (int i=0;i<lineArray.size();i++){
       int lineLength = lineArray[i].size();
       linelengthArray.push_back(lineLength);
    }
    for (int i=0;i<linelengthArray.size();i++){
        cout << "The length of line " << i+1 << ": " << linelengthArray[i] << endl;
    }
}


int main() {
	string Name;				//programmer's name
	/***********************/
	cout << "Input User's Name" << endl;
	cin >> Name;
	cout << "Name: " << Name << endl;
	cout << "File: " << __FILE__ << "   " << "Date: " << __DATE__  << endl;
	/***********************/

    int nL;
    vector<string> lineArray;
    vector<int> linelengthArray;

    cout << "How many lines is your input?" << endl;
    cin >> nL;
    cin.ignore();
    
    
    for (int i=0;i<nL;i++){
        string temp;
        cout << "Enter your line " << i+1 << endl;
        getline(cin, temp);
        lineArray.push_back(temp);
        
    }
    


    for (int i=0;i<nL;i++){
        cout << "Line " << i+1 << ":\n" << lineArray[i] << endl;
    }    

    countLine(lineArray, linelengthArray);

}



/*********** Results ********

Input User's Name
Christian Rasmussen
Name: Christian Rasmussen
File: HW4P1.cpp   Date: Apr 26 2023
How many lines is your input?
4
Enter your line 1
Four score and seven years ago our fathers brought forth upon this continent, a new nation, conceived in Liberty, and dedicated to the proposition that all men are created equal.
Enter your line 2
Now we are engaged in a great civil war, testing whether that nation, or any nation so conceived and so dedicated, can long endure.
Enter your line 3
We are met on a great battle-field of that war. We have come to dedicate a portion of that field, as a final resting place for those who here gave their lives that that nation might live.
Enter your line 4
It is altogether fitting and proper that we should do this...
Line 1:
Four score and seven years ago our fathers brought forth upon this continent, a new nation, conceived in Liberty, and dedicated to the proposition that all men are created equal.
Line 2:
Now we are engaged in a great civil war, testing whether that nation, or any nation so conceived and so dedicated, can long endure.
Line 3:
We are met on a great battle-field of that war. We have come to dedicate a portion of that field, as a final resting place for those who here gave their lives that that nation might live.
Line 4:
It is altogether fitting and proper that we should do this...
The length of line 1: 178
The length of line 2: 131
The length of line 3: 187
The length of line 4: 61

*******************************/