#include <iostream>
using namespace std;


class Time{

    private:
    int H, M;
    

    public:
    Time():H(0), M(0) {cout << "Default time constructor\n";};
    
    Time(int h, int m) {
        if (h <= 23 && h >= 0 && m <= 59 && m >= 0){
            H = h;
            M = m;
        }
        else{
            cout << "Your time, " << h << "h " << m << "m, is an invalid time." << endl;
        }
    }; 

    Time(const Time&Copy){
        H = Copy.H;
        H = Copy.M;
    }

    void operator=(const Time& T){
        H = T.H;
        M = T.M;
    }

    Time operator+(const Time& T){
        Time time;
        
        time.H = this->H + T.H;
        time.M = this->M + T.M;

        if (time.M >= 59){
            time.H += 1;
            time.M -= 60;
        }
        else if (time.H >= 24){
            cout << "The new time is invalid.\n";
        }

        return time;
    }

    Time operator+(int op){
        Time time;
        
        int i = this->M + op;
        if (i > 59) {
            this->H += i / 60;
            this->M = i - (i / 60) * 60;
            return *this;
        }
        else if (i >= 0){
            this->H += i / 60;
            return *this;
        }
        else {
            cout << "invalid addition" << endl;
        }
    }

    Time operator-(const Time& T){
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

    friend ostream& operator<<(ostream& os, const Time& rhs);

    ~Time(){ cout << "Time destructor\n";};

};

ostream& operator<<(ostream& os, const Time& rhs) {
    return os << "the time is " << rhs.H << " hours and " << rhs.M << " minutes." << endl;
}

int main(){

    cout << "------------------------------------------------------------------------------\n"; 
    cout << "Name: Christian Rasmussen" << endl;
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";

    
    Time A(13,45), B(4,15), C, D;

    D = A - B;

    cout << D;

    D = A + 55;

    

    cout << D;
    
    Time E(3,30), F(12,30), G(18,30);

    int size = 3;
    Time t[size];
    t[0] = E; t[1] = F; t[2] = G;
    
    for (int i = 0; i < size; i++){
        cout << t[i];
    }

}


/*********** Results ********
./a.out
------------------------------------------------------------------------------
Name: Christian Rasmussen
FILE: Partone.cpp DATE: Mar 30 2023
------------------------------------------------------------------------------
Default time constructor //Defining default constructor input A, B, C and D
Default time constructor
Default time constructor
Time destructor
the time is 9 hours and 30 minutes. //D = A - B
Default time constructor
Time destructor
Time destructor
the time is 14 hours and 40 minutes. // D = A + 55
Default time constructor //Defining array of times onto heap
Default time constructor
Default time constructor
the time is 3 hours and 30 minutes.
the time is 12 hours and 30 minutes.
the time is 18 hours and 30 minutes.
Time destructor //Destructor of heap and previous objects destruct
Time destructor
Time destructor
Time destructor
Time destructor
Time destructor
Time destructor
Time destructor
Time destructor
Time destructor

*******************************/