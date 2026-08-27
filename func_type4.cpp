/* 1. WAP to find square a given number
   2. find if a given no is even or odd
   3. find largest of 2 numbers
   4. find factorial
   5. generate random number
   6. strong
   7. perfect
   8. special
   
*/
#include<stdio.h>
#include<stdlib.h>
int square(int); //function declaration
void isEven(int);
int generateRandom();
int factorial(int);
int isStrong(int);
int isSpecial(int);
void showMenu();
int getUserInput();
int main(){
	char ch='0';
	do{
		int num;
		showMenu();
		scanf("%c",&ch);
		switch(ch){
			case '1': 	num = getUserInput();
						printf("square=%d",square(num));//function call
						break;
			case '2': 	num = getUserInput();
						isEven(num);
						break;
			case '6': 	num = getUserInput();
						printf("\n%d is %s",num,(isStrong(num)==1)?"STRONG":"NOT STRONG");
						break;
			case '9':
						break;
			default:
				printf("Invalid choice:");
		}
	}while(ch!='9');
	

//	
//	//call isStrong
//	
//	//call isEven
//	isEven(n);
//	//call generateRandom
//	printf("\nGive me a random number:%d",generateRandom());
//	//call isSpecial
//	printf("\n%d is %s",n,(isSpecial(n))?"SPECIAL":"NOT SPECIAL");
	
	return 0;
}
//function definition
void showMenu(){ 
	printf("\n************MENU****************");
	printf("\n1. find square a given number\n");
	printf("2. find if a given no is even or odd\n");
//		   3. find largest of 2 numbers\n
//		   4. find factorial\n
//		   5. generate random number\n
	printf("6. check if a no. is Strong\n");
//		   7. check if a no. is perfect\n
//		   8. check if a no. is special\n
    printf("9. Exit\n");
	printf("Enter your choice:");
//	   ");
}
int getUserInput(){
	int n;
	printf("Enter the number:");
	scanf("%d",&n);
	return n;
}
int isSpecial(int num){
	//extract
	int sumDigit = 0;
	int prdDigit = 1;
	int origNum = num;
	while(num!=0){
		int digit = num%10;
		sumDigit +=digit; //sumDigit = sumDigit + digit
		prdDigit *=digit; //prdDigit = prdDigit * digit
		num/=10; //num = num/10
	}
	return ((sumDigit+prdDigit)==origNum);
}
int isStrong(int num){
	//extraction of the digits
	int origNum =num;
	int sumFact = 0;
	while(num!=0){
		int digit = num%10;
		sumFact += factorial(digit); //sumFact = sumFact + factorial(digit)
		num/=10; //num=num/10
	}
	return (sumFact==origNum);
//	if(sumFact==origNum){
//		return 1;
//	}
//	return 0;
	
}
int factorial(int num){
	int fact=1;
	for(int i=1;i<=num;i++){
		fact = fact*i;
	}
	return fact;
}
int generateRandom(){
	return ((rand() % 100) + 1);
}
void isEven(int num){
	printf("\n%d is %s.",num,(num%2==0)?"Even":"Odd");
}
int square(int num){
	return (num*num);
}
