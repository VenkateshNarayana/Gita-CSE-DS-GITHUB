/*WAP to extract the digits from a given number*/
#include<stdio.h>
int main(){
	int num;
	do{
		printf("Enter the number:");
		scanf("%d",&num);
	}while(num<0);	//check if its non negative
	
	//extraction
	while(num!=0){
		int digit = num % 10;
		printf("%d ",digit);
		num/=10;
	}
	
	return 0;
	
}
