#include <iostream>
using namespace std;

class Date {
	private:
	    int month, day, year;
		int lengthTime;
		int monthdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31};
	public:	
		Date(int _month, int _day, int _year): month(_month), day(_day), year(_year){}
		int setTime(){
			int leapYears = 0;
			if (month <= 2 && year % 4 == 0) {
				leapYears = year/4;
				leapYears--;
			}
			else {
				leapYears = year/4 - year/100 + year/400;
			}
		
			long int time = year * 365 + day;

			for (int i=0; i<month - 1; i++) {
				time += monthdays[i];		
			}
			time += leapYears;
			return time;
		}
		void PrintTime(){
			cout << month << "/" << day << "/" << year;
		}
};

class Employee{
	private:
	    string name;
		Date birthDate;
		float salary;
	public:
	    Employee(string _name, Date _birthDate, float _salary): name(_name), birthDate(_birthDate), salary(_salary){}
		float getSalary(){
			return salary;
		}
		string getName(){
            return name;
        }
};

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

	Date date1(9, 20, 2022);
	date1.setTime();

	Date birthDate1(6, 10, 1998);
	birthDate1.setTime();
	Employee e1("George", birthDate1, 70000.5);
    
	int x, y;

	x = birthDate1.setTime();
    y = date1.setTime();


	cout << e1.getName() << " is a Professor at CCNY making " << e1.getSalary() << " per year." << endl;
	cout << "Their birthdate is ";
	birthDate1.PrintTime(); cout << endl;
    cout << "The difference in days between birthdate ";
	birthDate1.PrintTime();
	cout << " and ";
    date1.PrintTime();
    cout << " is " << y - x << endl;

    /***********************/


	return 0;
}

/*********** Results ********
./a.out
Input User's Name
Christian Rasmussen
Name: Christian Rasmussen
File: HW3P2.cpp   Date: Mar 14 2023
George is a Professor at CCNY making 70000.5 per year.
Their birthdate is 6/10/1998
The difference in days between birthdate 6/10/1998 and 9/20/2022 is 8868

*******************************/