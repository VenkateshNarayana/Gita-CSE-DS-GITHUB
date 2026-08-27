/*3. Access array elements using a pointer.*/
#include<stdio.h>
void display_array(int*);
int main(){
	int my_arr[5]={1,2,3,4,5}; //array initialized with values
	int* ptr_arr;
	ptr_arr = &my_arr[0]; //storing the base address 
	//base + index * sizeof(datatype)
	
	//access array elements
	printf("\nMyArray elements: ");
	for(int i=0;i<5;i++){
		printf("%d ",my_arr[i]);
	}	
	
	//access my array addresses of all elements
	printf("\nMyArray elements using pointer variable: ");
	for(int i=0;i<5;i++){
		printf("%d-",(ptr_arr+i));
		printf("%d ,",*(ptr_arr+i));//pointer arithmetics & dereference operator we can access the values
	}
	
	//access my array elements using the array name (which is a pointer)
	printf("\nMyArray elements using arrayname: ");
	for(int i=0;i<5;i++){
		printf("%d-",(my_arr+i));
		printf("%d ,",*(my_arr+i));//pointer arithmetics & dereference operator we can access the values
	}
	display_array(my_arr);//arrayname is a pointer which is pointing to the base address
	printf("\nMy array values after modification in display_array function :");
	for(int i=0;i<5;i++){
		printf("%d ,",my_arr[i]);
	}
}
void display_array(int* my_arr){
	printf("\nMyArray elements using arrayname passed to function: ");
	for(int i=0;i<5;i++){
		printf("%d-",(my_arr+i)); 
		*(my_arr+i) = *(my_arr+i) *2;//modify the values of array
		printf("%d ,",*(my_arr+i));//pointer arithmetics & dereference operator we can access the values
	}
}
