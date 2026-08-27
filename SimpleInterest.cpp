/*
Calculate SI when principal amt,rate and time period are given 
*/
#include<stdio.h>
int main(){
	int principal,rate,time;
	printf("Enter the principal amt:");
	scanf("%d",&principal);
	printf("Enter the rate of interest per annum:");
	scanf("%d",&rate);
	printf("Enter the time period (years):");
	scanf("%d",&time);
	int simpleint;
	simpleint = principal*rate*time/100;
	printf("Simple Interest=%d",simpleint);
	
	return 0;//for the main
}
