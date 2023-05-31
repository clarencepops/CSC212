//prgram that creates binary tree for input of ints
//and find/no-find target value in number of search attempts

#include<stdlib.h>
#include<stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

//#define PRINT				//MACRO for rpinting - initially OFF

int Cnt = 0;				//global Count# search variable

class Array				//class Array declaration
{
	int * ptr;
	int size;
public:
      Array(int Size):size(Size){				//parametrized constructor
	ptr = new int[size];
      }
      ~Array(){							//destructor
	delete []ptr;
	cout << "Array destructor" << endl;
     }
     void operator=(const Array rhs){				//assignment operator
	delete []ptr;						//destroy exisiting Array prior to creating new Array
	ptr = new int[rhs.size];
	for(int i = 0; i < rhs.size;++i)
	    ptr[i] = rhs[i];
     }
     int& operator[](int offset){return ptr[offset];}				//index operators
     const int& operator[](int offset)const{return ptr[offset];}
};

struct node{						//binary tree node declaration
	int data;
	struct node * right, * left;
};

void  insert(node ** tree, int val)			//global functions definitions that work with binary trees
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = new node;
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

void print_preorder(node * tree)				//display tree data in pre-order method
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

void print_inorder(node * tree)
{
#ifdef PRINT
    cout << "print_inorder" << endl;
#endif
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(node * tree)
{
#ifdef PRINT
    cout << "print_postorder" << endl;
#endif
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}

void deltree(node * tree)
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

void search(node ** tree, int val)				//binary tree search function for value(target)
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
int main()
{
    node *root;						//binary tree root node pointer
    node *tmp;						//binary tree temp pointer

    ifstream infile; //open the txt file
    infile.open("IArray.txt");
    int X[16];					//declare array of 16 elements
    int target = 0;

    					//input target value from input stream cin

    int temp = 0;
    infile >> target;
    int i = 0;
    
    if (infile.is_open()){
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
    for(int i = 0; i < 16; ++i)
	cout << X[i] << '\t';				//output input data
    cout << endl;

    root = NULL;					//declare root pointer to NULL

    /* Inserting nodes into tree */
    for(int i = 0; i < 16 ; ++i)
	insert(&root, X[i]);				//first time NULL root is replaced with pointer to 
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

    return 0;
}

/*********** Results *********


******************************/
