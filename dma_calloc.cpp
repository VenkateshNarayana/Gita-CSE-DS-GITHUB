/*2.Use calloc() to create an array of 5 integers and display initial values*/
#include<stdlib.h>
#include<stdio.h>
void display_array(int*);
int main(){
	int* ptr_cal = (int*)calloc(5,sizeof(int));
	if(ptr_cal==NULL){
		printf("Memory allocation failed.....");
		return 1;
	}
	display_array(ptr_cal);//initialized (to zero)
	for(int i=0;i<5;i++){
		ptr_cal[i]=i+1;
	}
	
	display_array(ptr_cal);
	for(int i=0;i<5;i++){
		*(ptr_cal +i) =i*3;
	}
	display_array(ptr_cal);
	//free the pointer 
	free(ptr_cal);
	return 0;
}
void display_array(int* my_arr){
	printf("\nMyArray elements using arrayname passed to function: ");
	for(int i=0;i<5;i++){
		printf("%d ",*(my_arr+i));//pointer arithmetics & dereference operator we can access the values
	}
}
