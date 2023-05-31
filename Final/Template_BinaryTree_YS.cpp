//prgram that creates binary tree for input of ints
//and find/no-find target value in number of search attempts

#include<stdlib.h>
#include<stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

//#define PRINT				//MACRO for rpinting - initially OFF

int Cnt = 0;				//global Count# search variable


template <typename T>
class Array				//class Array declaration
{
	T * ptr;
	int size;
public:
      Array(int Size):size(Size){				//parametrized constructor
	    ptr = new T[size];
      }
      ~Array(){							//destructor
	delete []ptr;
	cout << "Array destructor" << endl;
     }
     void operator=(const Array rhs){				//assignment operator
	delete []ptr;						//destroy exisiting Array prior to creating new Array
	ptr = new T[rhs.size];
	for(int i = 0; i < rhs.size;++i)
	    ptr[i] = rhs[i];
     }
     T& operator[](int offset){return ptr[offset];}				//index operators
     const T& operator[](int offset)const{return ptr[offset];}
};

template <typename U>
struct node{						//binary tree node declaration
	U data;
	struct node * right, * left;
};

template <typename U>
void  insert(node<U> ** tree, U val)			//global functions definitions that work with binary trees
{
    node<U> *temp = NULL;
    if(!(*tree))
    {
        temp = new node<U>;
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}


template <typename U>
void print_preorder(node<U> * tree)				//display tree data in pre-order method
{
#ifdef PRINT
    cout << "print_preorder" << endl;
#endif
    if (tree){
          cout << tree->data << endl;
          print_preorder(tree->left);
          print_preorder(tree->right);
    }

}

template <typename U>
void print_inorder(node<U> * tree)
{
#ifdef PRINT
    cout << "print_inorder" << endl;
#endif
    if (tree)
    {
        print_inorder(tree->left);
        cout << tree->data << endl;
        print_inorder(tree->right);
    }
}

template <typename U>
void print_postorder(node<U> * tree)
{
#ifdef PRINT
    cout << "print_postorder" << endl;
#endif
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        cout << tree->data <<endl;
    }
}

template <typename U>
void deltree(node<U> * tree)
{
#ifdef PRINT
    cout << "delete tree" <<endl;
#endif
    if (tree)
    {
        deltree(tree->left);					//delete left-hand nodes
        deltree(tree->right);
        free(tree);
    }
}

template <typename U>
void search(node<U> ** tree, U val)				//binary tree search function for value(target)
{
    cout << "search - level: " << ++Cnt << endl;
    if(!(*tree))
    {
        //return NULL;
        cout << "target not found: " << val << endl;
	exit(1);
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        cout << "found value " << (*tree)->data << endl;
    }
}

//-----------------------------------------------------------------//

template <typename V>
void populateTree (V target){
    node<V> *root;						//binary tree root node pointer
    node<V> *tmp;						//binary tree temp pointer

    ifstream infile; //open the txt file
    infile.open("IArray.txt");
    Array<V> X(16);					//declare array of 16 elements

    					//input target value from input stream cin
    
    V temp;
    int i = 0;
    
    if (infile.is_open()){
        infile >> temp;
        while (! infile.eof()){
            infile >> temp;
            X[i] = temp;
            i++;
        }  
    }   
    
							// ./a.out < IArray.txt
    cout << "target = " << target << endl;

    /*
    cout << "Enter Array values" << endl;
    for(int i = 0; i < 16; ++i){
	cin >> X[i];					//input values from IArray.txt
//	cout << X[i] << '\t';
    }							//  ./a.out < IArray.txt
    cout << endl;
    */
    for(int i = 0; i < 16; ++i){
	cout << X[i] << '\t';				//output input data
    }
    cout << endl;

    root = NULL;					//declare root pointer to NULL
    
    /* Inserting nodes into tree */
    for(int i = 0; i < 16 ; ++i){
	insert(&root, X[i]);				//first time NULL root is replaced with pointer to 
    }
							//first created node

    /* Printing nodes of tree */
#ifdef PRINT						//turn-on code when PRINT is defined
    printf("Pre Order Display\n");
    print_preorder(root);
#endif

    printf("In Order Display\n");
    print_inorder(root);				//display all node values in-order process

#ifdef PRINT
    printf("Post Order Display\n");
    print_postorder(root);
#endif

    /* Search node into tree */
    cout << "target = " << target << endl;
    search(&root, target);			//search for target value & count number of search levels
						//for a a well-balanced tree the max #searches ==> log2(N)
						//where N ==>> total number of input values
    /* Deleting all nodes of tree */
    deltree(root);				//remove tree from heap prior to termination

}



int main()
{

    cout << "-----------------------------------------\n";
    cout << "Name: Christian Rasmussen\n";
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "-----------------------------------------\n";

    string target;
    ifstream infile;
    infile.open("IArray.txt");
    getline(infile, target, ' ');

    int i;
    double d;
    char c;

    try {
        if (target.find(".") != string::npos){
            d = std::stod(target);
            std::cout << target << " can be converted to a float: " << d << std::endl;          //attempt converting to float if there is a '.' present
            populateTree<float>(d);                                                 
        }
        else {
            throw std::invalid_argument("a or b");
        }
    } catch (std::invalid_argument&) {
        try {
            i = std::stoi(target);
            std::cout << target << " can be converted to an integer: " << i << std::endl;       //If float fails or there is no '.' then attmpt converting to int
            populateTree<int>(i);
        } catch (std::invalid_argument&) {
            if (target.length() == 1 && std::isalpha(target[0])) {
                c = target[0];
                std::cout << target << " can be converted to a character: " << c << std::endl;
                populateTree<char>(c);                                                          //If float and integer fail, attempt converting to a character
            } else {
                std::cout << target << " is not a valid integer, double or character." << std::endl;    //If all attempts fail, throw an error message regaurding the string as not a float, int or char
            }
        }
    }
    return 0;
}

/*********** Results *********
-----------------------------------------
Name: Christian Rasmussen
FILE: Template_BinaryTree_YS.cpp DATE: May 14 2023
-----------------------------------------
14 can be converted to an integer: 14
target = 14
8       12      14      15      16      10      9       11      13      4       2       6       1       3       5       7
In Order Display
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
target = 14
search - level: 1
search - level: 2
search - level: 3
found value 14
Array destructor
******************************/
