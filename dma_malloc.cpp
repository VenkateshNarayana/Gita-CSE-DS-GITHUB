/*1. Allocate memory for 5 integers using malloc() and display them*/
#include<stdlib.h>
#include<stdio.h>
void display_array(int*);
int main(){
	int* ptr_mal	=  (int*)malloc(5*sizeof(int));
	if(ptr_mal==NULL){
		printf("Memory allocation failed.....");
		return 1;
	}
	display_array(ptr_mal); //uninitialised values(garbage values)
	//array notation arr[index]
	ptr_mal[0] = 20;
	ptr_mal[1] = 60;
	ptr_mal[2] = 30;
	ptr_mal[3] = 40;
	ptr_mal[4] = 50;
	display_array(ptr_mal);
	//pointer arithmetic
	*(ptr_mal+0) = 20;
	*(ptr_mal+1) = 20;
	*(ptr_mal+2) = 20;
	*(ptr_mal+3) = 20;
	*(ptr_mal+4) = 20;
	display_array(ptr_mal);
	
	//free the ptr to prevent memory leak
	free(ptr_mal);
}
void display_array(int* my_arr){
	printf("\nMyArray elements using arrayname passed to function: ");
	for(int i=0;i<5;i++){
		printf("%d ,",*(my_arr+i));//pointer arithmetics & dereference operator we can access the values
	}
}
