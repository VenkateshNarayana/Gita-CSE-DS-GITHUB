/*3. Demonstrate realloc() by increasing an array size*/

#include<stdlib.h>
#include<stdio.h>
void display_array(int*,int);
int main(){
	int* ptr_mal = (int*) malloc(5*sizeof(int));
	if(ptr_mal==NULL){
		printf("Memory allocation failed.....");
		return 1;
	}
	display_array(ptr_mal,5);
	//initlailise the values
	for(int i=0;i<5;i++){
		ptr_mal[i]=i+1;
	}
	//re-size it to 10 (from 5)
	ptr_mal = (int*)realloc(ptr_mal,10); //increase the size from 5 to 10
	if(ptr_mal==NULL){
		printf("Memory allocation failed.....");
		return 1;
	}
	display_array(ptr_mal,10);
	//free the pointer 
	free(ptr_mal);
	return 0;
}
void display_array(int* my_arr,int size){
	printf("\nMyArray elements using arrayname passed to function: ");
	for(int i=0;i<size;i++){
		printf("%d ",*(my_arr+i));//pointer arithmetics & dereference operator we can access the values
	}
}
