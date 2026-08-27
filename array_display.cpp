/*1. Write a program to input and display 5 array elements.
 2.Find the sum of all elements of an array.
*/
#include<stdio.h>
void display_array(int[],int);
int sum_array_elements(int[],int);
void get_inputs_from_user(int[],int);
int find_largest_element(int[],int);
int main(){
	int arr[5]={0}; //create array which can hold 5 elements (size=5)
	int arr1[]={1,2,3,4,5,6,7,8,9,10};
	int size = sizeof(arr)/sizeof(int);
	
	get_inputs_from_user(arr,size);
	display_array(arr,size);
	printf("\nSum of arr elements is %d",sum_array_elements(arr,size));//function call
	printf("\nLargest array element is %d",find_largest_element(arr,size));//function call
	
	size = sizeof(arr1)/sizeof(int);
	display_array(arr1,size);
	printf("\nOut of bound is not performed for arr[5] :");
	printf("%d ",arr[5]);//garbage value - out of bound 
	
	printf("\nSum of arr1 elements is %d",sum_array_elements(arr1,size));//function call
	printf("\nLargest array element is %d",find_largest_element(arr1,size));//function call
	
	return 0;
}
int find_largest_element(int arr[],int size){
	int max = arr[0];
	for(int i=1;i<size;i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}
	return max;
}
void get_inputs_from_user(int arr[],int size){
	printf("\nEnter %d elements :\n");
	for(int i=0;i<size;i++){
		printf("Enter the %d element:",i+1);
		scanf("%d",&arr[i]);
	}
}
int sum_array_elements(int arr[],int size){
	int sum = 0;
	for(int i=0;i<size;i++){
		sum += arr[i]; //sum = sum + arr[i]
	}
	return sum;
}
void display_array(int arr[],int size){
	
	printf("\nThe array elements: ");
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}
