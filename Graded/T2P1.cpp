/********
T2P1.cpp://Points Off:	(-20)
T2P2.cpp://Points Off:  (-6)
Grade:  74/100
*********/

//Points Off:	(-20)

#include <iostream>
using namespace std;

class poly{
    private:
        int order;	  //ok                          //order of the polynomial
	int *coeff;	                            // pointer to array of coeff on the heap
	                                            // size of coeff array predicated on (order + 1)
    public:
        
        poly() {                             
					//default constructor – order=0 & coeff[0] =1
            cout << "Default Constructor - YS" << endl;			//show constructors/destructoes (-1)		
            order = 0;
            coeff = new int[1];
            coeff[0] = 1;
        //};	//ok - superflous ;		  
        }
	   
        poly(int Order , int Default = 1) ;	 // creates  Nth order poly
                                                 // and inits all coeffs
        poly(int Order, int *Coeff){             //creates an Nth polynomial & inits to the values of an external 
            //failed to allocate mmeory on the heap						(-3)

            for (int i=0; i<Order+1; i++){
			//?????? what
            }
        }                                                   // vector of coefficients 
                                            
	    
        //~poly( ){ delete[] coeff;}				        	//  destructor
        ~poly( ){ 
		cout << "destructor - YS" << endl;
		delete[] coeff;}				        	//  destructor
	    
        
        poly(const poly &rhs){                              // copy constructor
	    cout << "copy constructor - YS" << endl;
            //failed to allocate memory on the heap						(-2)
            this->coeff = rhs.coeff;
            this->order  = rhs.order;
        }             
        
        poly& operator=(const poly & rhs){                  //Assignment operator
            //failed to delete all data from heap
	    //prior to creating new destination object					(-2)
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
            return this->order;									//ok
        } 		

        int * get( )const{                                  //returns pointer to coeff array
            return this->coeff;
        }; 	      										//ok - superflous ;

        void print(){
            cout << this->coeff[0] << " + ";
            for (int i=1; i<this->order; i++){
                cout << "(" << this->coeff[i] << ")" << "X^" << i << " + ";
            }
            cout << "(" << this->coeff[order] << ")" << "X^" << order << endl;
        }										//ok - 
											//if you have operator<<()
											//why do you need this
	


        poly operator-( const poly &rhs){                   // subt two polynomials
            int tempPower = max(this->order, rhs.order);				//ok
            int *tempArray = new int[tempPower +1]();					//ok
            poly temp;					   //zero length poly 
            temp.set(tempArray, tempPower);
            for (int i=0; i<this->order+1; i++){
                temp.coeff[i] = this->coeff[i];
            } 
            for (int i=0; i<rhs.order+1; i++){
                temp.coeff[i] = temp.coeff[i] - rhs.coeff[i];
            }
									//failed to deallocate tempArray from
									//heap - memory leak		(-3)
            return temp;
        }		


        poly operator*(const poly &rhs){                    // mult two polynomials
            poly temp;					    //zero length poly .... ????           
							    //failed to allocate memory for temp	(-2)
            temp.order = this->order + rhs.order;
            temp.coeff[0] = 0;
            for (int i=0; i < this->order +1; i++){
                for (int j=0; j < rhs.order +1; j++){
                    temp.coeff[i+j] += this->coeff[i] * rhs.coeff[j];	//zero length poly cannot accomodate
									//these terms			(-2)
                }
            }
            return temp;
        }		


        poly operator+( const poly &rhs){                   // add two polynomials
            int tempPower = max(this->order, rhs.order);
            int *tempArray = new int[tempPower +1]();		//ok
            poly temp;						//zero lenght poly		(-2)
            temp.set(tempArray, tempPower);
            for (int i=0; i<this->order+1; i++){
                    temp.coeff[i] +=this->coeff[i];		//same comments as above
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
            poly temp;					    //zero length poly			(-1)
            temp.order = this->order;
            for (int i=0; i<temp.order+1; i++){
                temp.coeff[i] = this->coeff[i] * scale;
            }
            return temp;
        }	
        friend poly operator*(const int scale, poly &rhs){  // scale a polynomial in other direction
            poly temp;						//zero length poly
            temp.order = rhs.order;
            for (int i=0; i<temp.order+1; i++){
                temp.coeff[i] = rhs.coeff[i] * scale;
            }
            return temp;
        }

        bool  operator==(const poly &rhs){                  // return true if the quadtratics are euqal
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
                solution = solution * X +this->coeff[i];				//ok
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
        }										//ok


        const int & operator[ ](int I)const{
            return this->coeff[I];		//ok
        }
        
        int & operator[ ](int n){
            return this->coeff[n];
        }					//ok

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

    cout << "P1: - YS: " << P1 << endl;
    cout << "P2: - YS: " << P2 << endl;			//show input data		(-1)

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


/******* YS Output ********
------------------------------------------------------------------------------
Name: Christian Rasmussen
FILE: T2P1.cpp DATE: May 12 2023
------------------------------------------------------------------------------
P3 = P1 + P2:
933826848 + (34337)X^1 + (-63493)X^2 + (3)X^3 + (2)X^4 + (7)X^5 + (0)X^6 + (2)X^7

P3 = P2 - P1: 
933826848 + (34337)X^1 + (2043)X^2 + (-3)X^3 + (-2)X^4 + (7)X^5 + (0)X^6 + (2)X^7

P3 = P1 * P2: 
931741808 + (34337)X^1 + (2043)X^2 + (-75)X^3 + (37)X^4 + (-149)X^5 + (-5)X^6 + (-122)X^7 + (23)X^8 + (-10)X^9 + (6)X^10 + (4)X^11

P3 = P1 * 10: 
931741808 + (34337)X^1 + (-63493)X^2 + (30)X^3 + (20)X^4

P3 = 10 * P1: 
931741808 + (34337)X^1 + (-63493)X^2 + (30)X^3 + (20)X^4

The quadratics P1 and P2 are not equal!

P1: 
-19 + (1)X^1 + (-12)X^2 + (7)X^3 + (2)X^4

The quadratic P1 solved when X = 5 is: 
1811
a.out(35011,0x104770580) malloc: *** error for object 0x600001e24070: pointer being freed was not allocated
a.out(35011,0x104770580) malloc: *** set a breakpoint in malloc_error_break to debug



//--------------- post YS Edits ********
./a.out
------------------------------------------------------------------------------
Name: Christian Rasmussen
FILE: T2P1.cpp DATE: May 12 2023
------------------------------------------------------------------------------
Default Constructor - YS
Default Constructor - YS
P1: - YS: -19 + (1)X^1 + (-12)X^2 + (3)X^3 + (2)X^4					//ok

P2: - YS: -19 + (1)X^1 + (-6)X^2 + (0)X^3 + (0)X^4 + (7)X^5 + (0)X^6 + (2)X^7		//ok

Default Constructor - YS
Default Constructor - YS
destructor - YS
P3 = P1 + P2:
-1486663392 + (22500)X^1 + (-63493)X^2 + (3)X^3 + (2)X^4 + (7)X^5 + (0)X^6 + (2)X^7	//ERROR 

Default Constructor - YS
destructor - YS
P3 = P2 - P1: 
-1486663392 + (22500)X^1 + (2043)X^2 + (-3)X^3 + (-2)X^4 + (7)X^5 + (0)X^6 + (2)X^7	//ERROR

Default Constructor - YS
destructor - YS
P3 = P1 * P2: 
-1488781200 + (22500)X^1 + (2043)X^2 + (-75)X^3 + (37)X^4 + (-149)X^5 + (-5)X^6 + (-122)X^7 + (23)X^8 + (-10)X^9 + (6)X^10 + (4)X^11

Default Constructor - YS
destructor - YS
P3 = P1 * 10: 
-1488781200 + (22500)X^1 + (-63493)X^2 + (30)X^3 + (20)X^4				//ERROR

Default Constructor - YS
destructor - YS
P3 = 10 * P1: 
-1488781200 + (22500)X^1 + (-63493)X^2 + (30)X^3 + (20)X^4				//ERROR

The quadratics P1 and P2 are not equal!

P1: 
-19 + (1)X^1 + (-12)X^2 + (7)X^3 + (2)X^4

The quadratic P1 solved when X = 5 is: 
1811											//ok
destructor - YS
a.out(35165,0x101164580) malloc: *** error for object 0x600003cd0070: pointer being freed was not allocated
a.out(35165,0x101164580) malloc: *** set a breakpoint in malloc_error_break to debug
									//RUNTIME ERRORS - MMEMORY HEAP
									//PROBLEMS
******************/
