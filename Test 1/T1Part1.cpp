#include <iostream>
using namespace std;


class Time{

    private:
    int H, M;
    

    public:
    Time():H(0), M(0) {cout << "Default time constructor\n";};
    
    Time(int h, int m) {
        if (h <= 23 && h >= 0 && m <= 59 && m >= 0){                //ensures no unexpected hour or minute
            H = h;                                                  // for example H > 23 or M > 59
            M = m;
            cout << "Parametrized constructor" << endl;
        }
        else{
            cout << "Your time, " << h << "h " << m << "m, is an invalid time." << endl;
        }
    }; 

    Time(const Time&Copy){                                          // Copy constructor
        H = Copy.H;
        H = Copy.M;
        cout << "Copy Constructor" << endl;
    }

    ~Time(){ cout << "Time destructor\n";};                         // destructor

    void operator=(const Time& T){                                  // Overloaded assignment operator               
        H = T.H;
        M = T.M;
        cout << "Overloaded time constructor" << endl;
    }

    Time operator-(const Time& T){                                  //difference operator
        Time time;

        if (this->H >= T.H && this->M >= T.M){
            time.H = this->H - T.H;
            time.M = this->M - T.M;
            return time;
        }
        else if (this->M <= T.M && this->H > T.H) {
            int i;
            time.H = this->H - T.H;
            i = this->M - T.M;
            time.M = 60 + i;
            time.H -= 1;
            return time;
        }
        else {
            cout << "Invalid subtraction" << endl;
        }
    }

    Time operator+(const Time& T){                                  // Adition overloaded operator to add two time objects
        Time time;
        
        time.H = this->H + T.H;
        time.M = this->M + T.M;

        if (time.M >= 59){
            time.H += 1;
            time.M -= 60;
            cout << "Overloaded addition operator" << endl;
        }
        else if (time.H >= 24){
            cout << "The new time is invalid.\n";
        }

        return time;
    }

    Time operator+(int op){                                         //Addition operator to add constant time, aka minutes
        Time time;
        
        int i = this->M + op;
        if (i > 59) {
            this->H += i / 60;
            this->M = i - (i / 60) * 60;
            cout << "Overloaded addition operator" << endl;
            return *this;
        }
        else if (i >= 0){
            this->H += i / 60;
            cout << "Overloaded addition operator" << endl;
            return *this;
        }
        else {
            cout << "invalid addition" << endl;
        }
    }

    friend ostream& operator<<(ostream& os, const Time& rhs);

    void setValue(int H1, int M2){          //set H1 and M2 to argument values
        int carry = M2 / 60;
        this->H = H1 + carry;
        this->M = M2 % 60;
    }

};

ostream& operator<<(ostream& os, const Time& rhs) {
    return os << "the time is " << rhs.H << " hours and " << rhs.M << " minutes." << endl;
}

int main(){

    cout << "------------------------------------------------------------------------------\n"; 
    cout << "Name: Christian Rasmussen" << endl;
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";

    
    Time A(13,45), B(4,15), C, D;       //initialize time objects

    cout << D;
    
    D = A - B;                          //Subtractor overloader between objects A and B

    cout << D;                          //print the difference between A and B

    D = A + 55;                         //Parametrizes D's value to be A + 55 minutes

    cout << D;  //                      //Output D's time -> (14, 40)
    
    Time E(3,30), F(12,30), G(18,30);   //Create time objects

    int size = 3;
    Time* t = new Time[size];           //create array of time on Heap
    t[0] = E; t[1] = F; t[2] = G;       //sets values of array to correct time values
    
    for (int i = 0; i < size; i++){
        cout << t[i];
    }

    delete [] t;                        //delete array on heap

}


/*********** Results ********
./a.out
------------------------------------------------------------------------------
Name: Christian Rasmussen
FILE: T1Part1.cpp DATE: Mar 30 2023
------------------------------------------------------------------------------
Parametrized constructor
Parametrized constructor
Default time constructor
Default time constructor
the time is 0 hours and 0 minutes.
Default time constructor
Overloaded time constructor
Time destructor
the time is 9 hours and 30 minutes.
Default time constructor
Overloaded addition operator
Copy Constructor
Time destructor
Overloaded time constructor
Time destructor
the time is 40 hours and 0 minutes.
Parametrized constructor
Parametrized constructor
Parametrized constructor
Default time constructor
Default time constructor
Default time constructor
Overloaded time constructor
Overloaded time constructor
Overloaded time constructor
the time is 3 hours and 30 minutes.
the time is 12 hours and 30 minutes.
the time is 18 hours and 30 minutes.
Time destructor
Time destructor
Time destructor
Time destructor
Time destructor
Time destructor
Time destructor
Time destructor
Time destructor
Time destructor
****************************/