#include <iostream>
using namespace std;

class String {
	public:
		string Normal;
		string Reversed;

		void getReversed();
		void setWord(string wor);
};

void String::setWord(string wor){
	Normal = wor;
	Reversed = wor;
}

void String::getReversed() {
	int last = Reversed.length();
//  characters are swaping from two both side
	for (int i = 0; i < last / 2; i++)
// to swap characters using swap( ) built in function
	swap(Reversed[i], Reversed[last - i - 1]);
}

int main(){

	string Name;				//programmer's name
	/***********************/
	cout << "Input User's Name" << endl;
	cin >> Name;
	cout << "Name: " << Name << endl;
	cout << "File: " << __FILE__ << "   " << "Date: " << __DATE__  << endl;
	/***********************/

    /***********************/

    

	//declare variables
	String base;
	string wor;

    cout << "Enter Word: " << endl;
	cin >> wor;
	base.setWord(wor);
	base.getReversed();

	cout << "Inputed Word: " << base.Normal << endl;
	cout << "Reversed Word: " << base.Reversed << endl;
	
	cout << "This word is a pallindrome: " << endl;

	if (base.Normal == base.Reversed){
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	return 0;
}

/*********** Results ********
./a.out
Input User's Name
ChristianRasmussen
Name: ChristianRasmussen
File: HW2P1.cpp   Date: Feb 23 2023
Enter Word: 
car
Inputed Word: car
Reversed Word: rac
This word is a pallindrome: 
FALSE

./a.out
Input User's Name
Christian Rasmussen
Name: Christian Rasmussen
File: HW2P1.cpp   Date: Feb 23 2023
Enter Word: 
racecar
Inputed Word: racecar
Reversed Word: racecar
This word is a pallindrome: 
TRUE
*******************************/