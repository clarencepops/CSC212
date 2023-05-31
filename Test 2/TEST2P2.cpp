#include <iostream>
using namespace std;
#include <iomanip>

template <class T> 
class Array{
    public:

        // constructors
        Array(int itsSize){
            this->itsSize = itsSize;
            this->pType = new T[itsSize];
        }

        Array(const Array &rhs){
            this->itsSize = rhs.itsSize;
            this->pType = rhs.pType;
        }           //copy constructor

        ~Array( ) {delete [] pType; cout << "deleted array\n";}       //destructor

        // operators
        Array& operator=(const Array& rhs){
                delete[] pType;
                this->itsSize = rhs.GetitsSize();
                this->pType = new T[itsSize];
                for (int i = 0; i < this->itsSize; i++) {
                    this->pType[i] = rhs.pType[i];
                }
            return *this;
        }   

        Array& operator*(const int scale){
            for (int i = 0 ; i < this->itsSize; ++i) {
		        this->pType[i] = scale * this->pType[i];
	        }   
            return *this;   
        }

        T & operator[](int offSet){
            if (offSet < 0 || offSet >= itsSize){
                throw out_of_range("The Index is Out of Range");
            }
            return pType[offSet];
        }

        const T& operator[](int offSet) const{
            if (offSet < 0 || offSet >= itsSize){
                throw out_of_range("The Index is Out of Range");
            }
            return pType[offSet];
        } //works with const objects

        // accessors
        int GetitsSize() const { return itsSize; }

        // friend function
        friend ostream& operator<< (ostream& out, const Array<T>& rhs){
            out << "[";
            for (int i = 0; i < rhs.itsSize-1; i++) {
                out << rhs.pType[i] << ", ";
            }
            out << rhs.pType[rhs.itsSize-1] << "]" << endl;
            return out;
        }

		                
        void Array<T>::operator++() {               //increments each element of array by one 
        for (int i = 0; i < itsSize; i++) {
            pType[i]++;
        }
}

    private:
        T * pType;
        int  itsSize;

};//T represent the data type(int, float, double, char, string)




int main() {
    cout << "------------------------------------------------------------------------------\n"; 
    cout << "Name: Christian Rasmussen" << endl;
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";

    cout << setprecision(1) << fixed;

	// cout << "Enter number of elements \n";
	int size = 16;
	// cin >> N;

	Array<int> X(size);                        //Fills X -> 0, 3, 6, 9, 12...
	for (int i = 0; i < size; ++i) {
		X[i] = i*3;
	}
	cout << "X = " << X << "\n";


	Array<float> Y(size);                      //Fills Y -> 0.0, 3.0, 6.0, 9.0...
	for (int i = 0; i < size; ++i) {
		Y[i] = i * 3.0;
	}
	cout << "Y = " << Y << "\n";

	Array<char> C(size);                       //Fills C -> a, b, c, d...
	for (int i = 0; i < size; ++i) {
		C[i] = 'a' + i;
	}
	cout << "C = " << C << "\n";

	int value = X[4];
	cout << "The value at X[4]:\n" << value << "\n";

	X[5] = X[6] + X[7];
	cout << "The value at X[5] After addition:\n" << setprecision(0) << X[5] << "\n";
	cout << "The vector X after addition:\n" << X << "\n";

	Y = Y * 3;
	cout << "The vector Y after scaling it by a factor of 3:\n" << setprecision(1) << Y << "\n";
}





/*********** Results ********
------------------------------------------------------------------------------
Name: Christian Rasmussen
FILE: TEST2P2.cpp DATE: May  9 2023
------------------------------------------------------------------------------
X = [0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45]

Y = [0.0, 3.0, 6.0, 9.0, 12.0, 15.0, 18.0, 21.0, 24.0, 27.0, 30.0, 33.0, 36.0, 39.0, 42.0, 45.0]

C = [a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p]

The value at X[4]:
12
The value at X[5] After addition:
39
The vector X after addition:
[0, 3, 6, 9, 12, 39, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45]

The vector Y after scaling it by a factor of 3:
[0.0, 9.0, 18.0, 27.0, 36.0, 45.0, 54.0, 63.0, 72.0, 81.0, 90.0, 99.0, 108.0, 117.0, 126.0, 135.0]

deleted array
deleted array
deleted array
****************************/