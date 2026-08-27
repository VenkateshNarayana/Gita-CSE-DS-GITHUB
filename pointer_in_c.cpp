/*1. Write a program to print the value and address of a variable using a pointer
  2. Swap two numbers using pointers.
*/
#include <stdio.h>
int main(){
	int x=10;
	int* ptrx; //syntax pointer datatype followed by pointer name
	//store address of x into pointer 
	ptrx = &x; //using address of operator
	printf("\n%p is the address stored in pointer.",ptrx);
	
	printf("\n%p is the address of x.",&x);
	
	//access the value of x using pointer
	printf("\n%d is the value of x accessed using dereference operator in pointer",*ptrx);
	//manipulate the value using pointer
	*ptrx = 20;
	printf("\n%d is value of x after manipulation using pointer",x);
	
	
	
}

