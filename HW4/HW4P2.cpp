#include <iostream>
using namespace std;


string lower(string word, int N){

	for (int i=0;i<word.length();i++) {
		word[i] = tolower(word[i]);
	}
	
	return word;
}

string sortstring(string word){
	sort(word.begin(), word.end());
	return word;
}

int main() {
	string Name;				//programmer's name
	/***********************/
	cout << "Input User's Name" << endl;
	cin >> Name;
	cout << "Name: " << Name << endl;
	cout << "File: " << __FILE__ << "   " << "Date: " << __DATE__  << endl;
	/***********************/


	string word1, word2;
	int N1, N2;
	cout << "What would you line word 1 to be?\n";
	cin >> word1;
	cout << "What would you line word 1 to be?\n";
	cin >> word2;

	N1 = word1.length();
	N2 = word2.length();

	string lower1 = lower(word1, N1);
	string lower2 = lower(word2, N2);

	string sort1 = sortstring(lower1);
	string sort2 = sortstring(lower2);

	if (sort1 == sort2){
		cout << "The words, " << word1 << " and " << word2 << " are annograms." << endl;
	}
	else {
		cout << "The words, " << word1 << " and " << word2 << " are not annograms." << endl;
	}


}



/*********** Results ********

Input User's Name
Christian Rasmussen
Name: Christian Rasmussen
File: HW4P2.cpp   Date: Apr 27 2023
What would you line word 1 to be?
Rescue
What would you line word 1 to be?
Secure
The words, Rescue and Secure are annograms.

*******************************/