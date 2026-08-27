/* max of 3 numbers */
#include<stdio.h>
int main(){
	int num1,num2,num3;
	printf("Enter the num1,num2 & num3 :");
	scanf("%d %d %d",&num1,&num2,&num3);
	
	if(num1>num2){
		if(num1>num3){
			printf("%d is greater",num1);
		}else{
			printf("%d is greater",num3);	
		}
	}else{
		if(num2>num3){
			printf("%d is greater",num2);
		}else{
			printf("%d is greater",num3);
		}
	}
	
	if(num1>num2 && num1>num3){
		printf("\n%d is greater",num1);
	}else if(num2>num3){
			printf("\n%d is greater",num2);
	}else{
			printf("\n%d is greater",num3);
	}
	return 0;	
}
