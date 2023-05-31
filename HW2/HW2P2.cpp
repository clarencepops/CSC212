#include <iostream>
using namespace std;

int findMean(int ray[], int length){
    int sum = 0;
    for (int i=0; i < length; i++){
        sum = sum + ray[i];
    }
    
    int mean = sum/length;

    cout << "The mean of your integer array is: " << mean << endl;
    return mean;
}

int main()
{
	string Name;				//programmer's name
	/***********************/
	cout << "Input User's Name" << endl;
	cin >> Name;
	cout << "Name: " << Name << endl;
	cout << "File: " << __FILE__ << "   " << "Date: " << __DATE__  << endl;
	/***********************/

    /***********************/


	//declare variables
	int length;
    int mean;
    cout << "What is the length of your input array?" << endl;
    cin >> length;
    int ray[length];
    cout << "Enter the inputs for your array:" << endl;
    for (int i=0; i < length; i++){
        cin >> ray[i];
    }

    findMean(ray, length);

	return 0;
}

/*********** Results ********
./a.out
Input User's Name
Christian Rasmussen
Name: Christian Rasmussen
File: HW2P2.cpp   Date: Feb 23 2023
What is the length of your input array?
5
Enter the inputs for your array:
10 20 30 40 50
The mean of your integer array is: 30
*******************************/