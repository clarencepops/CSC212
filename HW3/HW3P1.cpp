#include <iostream>
using namespace std;


class Animal {
	protected:
		string name;
		int age, weight;
	public:
		Animal():name(""),age(0),weight(0){}
		Animal(string _name, int _weight, int _age):weight(_weight), name(_name), age(_age) {}
		void showData(){cout << "My name is " << name << ", I weigh " << weight << " pounds, and am " << age << " months old.\nI can eat and sleep. I am not a dog.\n" << endl;};
		~Animal(){
			cout << "This is a deconstructor." << endl;
		}
};
	
	
class Dog : public Animal {
	protected:
	    string Breed;
	public:
	    Dog():Animal("N/A", 0, 0){}
	    Dog(string _name, string _breed, int _weight, int _age):Animal(_name, _weight, _age), Breed(_breed){
			cout << "I am a dog. My name is " << name << " and I am a " << Breed << " dog. I am " << age << " months old and I weigh " << weight << " pounds." << endl; cout << "I can sleep and I can eat. I can also bark!\n" << endl;
		};
		~Dog(){cout << "This is a deconstructor." << endl;};
		
};




int main() {
	string Name;				//programmer's name
	/***********************/
	cout << "Input User's Name" << endl;
	cin >> Name;
	cout << "Name: " << Name << endl;
	cout << "File: " << __FILE__ << "   " << "Date: " << __DATE__  << endl;
	/***********************/

    /***********************/

	Animal bird("Polly", 2, 39);
	bird.showData();

	Dog dog1("John", "pug", 5, 19);
	Dog dog2("Sparky", "doodle", 11, 74);
	return 0;
}

/*********** Results ********
./a.out
Input User's Name
Christian Rasmussen
Name: Christian Rasmussen
File: HW3P1.cpp   Date: Mar 14 2023
My name is Polly, I weigh 2 pounds, and am 39 months old.
I can eat and sleep. I am not a dog.

I am a dog. My name is John and I am a pug dog. I am 19 months old and I weigh 5 pounds.
I can sleep and I can eat. I can also bark!

I am a dog. My name is Sparky and I am a doodle dog. I am 74 months old and I weigh 11 pounds.
I can sleep and I can eat. I can also bark!

This is a deconstructor.
This is a deconstructor.
This is a deconstructor.
This is a deconstructor.
This is a deconstructor.

*******************************/