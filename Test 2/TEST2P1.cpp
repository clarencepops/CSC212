#include <iostream>
using namespace std;

class poly{
    private:
        int order;	                            //order of the polynomial
	    int *coeff;	                            // pointer to array of coeff on the heap
	                                            // size of coeff array predicated on (order + 1)
    public:
        
        poly() {                                            //default constructor – order=0 & coeff[0] =1                           
            order = 0;
            coeff = new int[1];
            coeff[0] = 1;
        };		  
	   
        poly(int Order , int Default = 1) ;	                // creates  Nth order poly
                                                            // and inits all coeffs
        poly(int Order, int *Coeff){                        //creates an Nth polynomial & inits to the values of an external 
            for (int i=0; i<Order+1; i++){

            }
        }                                                   // vector of coefficients 
                                            
	    
        ~poly( ){ delete[] coeff;}				        	//  destructor
	    
        
        poly(const poly &rhs){                              // copy constructor
            this->coeff = rhs.coeff;
            this->order  = rhs.order;
        }             
        
        poly& operator=(const poly & rhs){                  //Assignment operator
            if(this != &rhs){
                this->order = rhs.order;
                this->coeff = rhs.coeff;
                return *this;
            }
            return *this;
        };	
        

        void set(){                                          // Query user for coefficient values
            cout << "What is the greatest exponent in your polynomial? \n";
            cin >> this->order;
            this->coeff = new int[order];
            cout << "Enter the coefficients of the polynomia (return after each coefficient): \n";
            for (int i = 0; i <= order; i++) {
                cin >> this->coeff[i];
                
            }
        }				 

        void set(int coeff[ ], int size){                   // input coeffs via external coeff vector
            this->coeff = coeff;
            this->order = size;
        } 	 

        int getOrder( )const{                               // get order of polynomial
            return this->order;
        } 		

        int * get( )const{                                  //returns pointer to coeff array
            return this->coeff;
        }; 	      		

        void print(){
            cout << this->coeff[0] << " + ";
            for (int i=1; i<this->order; i++){
                cout << "(" << this->coeff[i] << ")" << "X^" << i << " + ";
            }
            cout << "(" << this->coeff[order] << ")" << "X^" << order << endl;
        }



        poly operator-( const poly &rhs){                   // subt two polynomials
            int tempPower = max(this->order, rhs.order);
            int *tempArray = new int[tempPower +1]();
            poly temp;
            temp.set(tempArray, tempPower);
            for (int i=0; i<this->order+1; i++){
                temp.coeff[i] = this->coeff[i];
            } 
            for (int i=0; i<rhs.order+1; i++){
                temp.coeff[i] = temp.coeff[i] - rhs.coeff[i];
            }
            return temp;
        }		


        poly operator*(const poly &rhs){                    // mult two polynomials
            poly temp;
            temp.order = this->order + rhs.order;
            temp.coeff[0] = 0;
            for (int i=0; i < this->order +1; i++){
                for (int j=0; j < rhs.order +1; j++){
                    temp.coeff[i+j] += this->coeff[i] * rhs.coeff[j];
                }
            }
            return temp;
        }		


        poly operator+( const poly &rhs){                   // add two polynomials
            int tempPower = max(this->order, rhs.order);
            int *tempArray = new int[tempPower +1]();
            poly temp;
            temp.set(tempArray, tempPower);
            for (int i=0; i<this->order+1; i++){
                    temp.coeff[i] +=this->coeff[i];
                }
            for (int i=0; i<rhs.order+1; i++){
                    temp.coeff[i] += rhs.coeff[i];
                }
                return temp;
            
            /*
            // The following is initial design, caused data leeks though so went a different way

            if (rhs.order > this->order){
                for (int i=0; i<this->order+1; i++){
                    temp.coeff[i] = rhs.coeff[i] + this->coeff[i];
                }
                return temp;
            }
            else if(rhs.order < this->order){
                for (int i=0; i<rhs.order+1; i++){
                    temp.coeff[i] = rhs.coeff[i] + this->coeff[i];
                }
                return temp;
            }
            else {
                for (int i=0; i<rhs.order+1; i++){
                    temp.coeff[i] = rhs.coeff[i] + this->coeff[i];
                }
                return temp;
            }
            */
        }		
 
 
        poly operator*( const int scale){                   // scale a  polynomial
            poly temp;
            temp.order = this->order;
            for (int i=0; i<temp.order+1; i++){
                temp.coeff[i] = this->coeff[i] * scale;
            }
            return temp;
        }	
        friend poly operator*(const int scale, poly &rhs){  // scale a polynomial in other direction
            poly temp;
            temp.order = rhs.order;
            for (int i=0; i<temp.order+1; i++){
                temp.coeff[i] = rhs.coeff[i] * scale;
            }
            return temp;
        }

        bool  operator==(const poly &rhs){                  // return true if the quadtratics are equal
            if (this->order > rhs.order){
                return false;
            }
            else if (rhs.order > this->order){
                return false;
            }
            else {
                for (int i=0; i<rhs.order+1;i++){
                    if (rhs.coeff[i] != this->coeff[i]){
                        return false;
                    }
                }
                return true;
            }
        }

        int operator( )(int X){                             // Solve the quadratic when X = some integer
            int solution = 0;
            for (int i=this->order; i>=0; i--){
                solution = solution * X +this->coeff[i];
            }
            return solution;
        }

        friend ostream & operator<<(ostream & Out, const poly &rhs){    //cout quadratics without having to use .print()
            Out << rhs.coeff[0] << " + ";
            for (int i=1; i<rhs.order; i++){
                Out << "(" << rhs.coeff[i] << ")" << "X^" << i << " + ";
            }
            Out << "(" << rhs.coeff[rhs.order] << ")" << "X^" << rhs.order << endl;
            return Out;
        }


        const int & operator[ ](int I)const{
            return this->coeff[I];
        }
        
        int & operator[ ](int n){
            return this->coeff[n];
        }

};

int main() {
    
    cout << "------------------------------------------------------------------------------\n"; 
    cout << "Name: Christian Rasmussen" << endl;
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";


    int x[5] = {-19, 1, -12, 3, 2};
    int coeff1 = 4;
    int y[8] = {-19, 1, -6, 0, 0, 7, 0, 2};
    int coeff2 = 7;
    
    /*
    int x[4] = {1, 1, 1, 1};     // Testing values
    int coeff1 = 3;
    int y[4] = {1, 1, 2, 1};
    int coeff2 = 3;
    */

    poly P1;
    P1.set(x, coeff1);
    poly P2;
    P2.set(y, coeff2);


    poly P3;

    P3 = P1 + P2;
    cout << "P3 = P1 + P2:\n" << P3 << endl;
    P3 = P2 - P1;
    cout << "P3 = P2 - P1: \n" << P3 << endl;
    P3 = P1*P2;
    cout << "P3 = P1 * P2: \n" << P3 << endl;
	P3 = P1*10;
    cout << "P3 = P1 * 10: \n" << P3 << endl;
	P3 = 10*P1;
    cout << "P3 = 10 * P1: \n" << P3 << endl;
    bool flag = (P1 == P2);

    if (flag == true){
        cout << "The quadratics P1 and P2 are equal!\n";
    }
    if (flag == false){
        cout << "The quadratics P1 and P2 are not equal!\n" << endl;
    }

    int Value = P2[5];              //Assigns the coefficient in front of X^5 in P2 to Value
    P1[3] = Value;                  //Assigns Value (coefficient in front of X^5) to the coefficient in front of X^3 in P1
    cout << "P1: \n" << P1 << endl;

    int Z = P1(5);
    cout << "The quadratic P1 solved when X = 5 is: \n" << Z << endl;
    

    
    /*                      //TESTING
    poly test1;
    test1.set();
    cout << test1;
    
    cout << test1(3) << endl;

    
    poly test2;
    test2.set();
    test2.print();
    
    poly test3;
    test3 = test1 * test2;
    test3.print();
    

    
    cout << "test1\n";
    test1.print();
    poly test2(test1);
    cout << "test2\n";
    test2.print();
    cout << test2.get();
    */
}


/*********** Results ********
./a.out
------------------------------------------------------------------------------
Name: Christian Rasmussen
FILE: T2Part1.cpp DATE: May 9 2023
------------------------------------------------------------------------------

P3 = P1 + P2:
-38 + (2)X^1 + (-18)X^2 + (3)X^3 + (2)X^4 + (7)X^5 + (0)X^6 + (2)X^7

P3 = P2 - P1: 
0 + (0)X^1 + (6)X^2 + (-3)X^3 + (-2)X^4 + (7)X^5 + (0)X^6 + (2)X^7

P3 = P1 * P2: 
361 + (-38)X^1 + (343)X^2 + (-75)X^3 + (37)X^4 + (-149)X^5 + (-5)X^6 + (-122)X^7 + (23)X^8 + (-10)X^9 + (6)X^10 + (4)X^11

P3 = P1 * 10: 
-190 + (10)X^1 + (-120)X^2 + (30)X^3 + (20)X^4

P3 = 10 * P1: 
-190 + (10)X^1 + (-120)X^2 + (30)X^3 + (20)X^4

The quadratics P1 and P2 are not equal!

P1: 
-19 + (1)X^1 + (-12)X^2 + (7)X^3 + (2)X^4

The quadratic P1 solved when X = 5 is: 
1811

****************************/