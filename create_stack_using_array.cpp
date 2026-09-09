/*Stack - Stack is a LDS which operates on LIFO principle
  Operations 	1. push
				2. pop
				3. peek
				4. is_empty
				5. is_full
				6. traverse
*/
#include <stdio.h>
#define MAX_SIZE 5
int top = -1; //current index tracker for stack
void show_menu();
void traverse(int[]); //param1= array name
void push(int[],int); //param1=array name ; param2=value
int pop(int[]);       //param1=array name ; 
int peek(int[]);      //param1=array name ;
int is_full();        //will return 1 if the stack is full to its MAX SIZE else 0
int is_empty();       //will return 1 if the stack is empty(top index will contain -1)  else 0

int get_push_value_from_user(); //get a user input from user

int main(){
	int stack[MAX_SIZE]={0}; //declare and initialize the stack to zero with MAX_SIZE
	int choice=0;
	int pop_item;
	int value;
	do{
		show_menu();
		scanf("%d",&choice);
		switch(choice){
			case 1: value = get_push_value_from_user();
					push(stack,value);break;
			case 2: pop_item = pop(stack);printf("popped=%d\n",pop_item);break;
			case 3: printf("Peek = %d\n",peek(stack));break;
			case 4: printf(is_empty()?"Yes\n": "No\n");break;
			case 5: printf(is_full()?"Yes\n": "No\n");;break;
			case 6: traverse(stack);break;
			case 7: printf("Exiting application");
		}
				
	}while(choice!=7);
	
	printf("\n\nExited application successfully!!!");
	
	return 0;
}
int is_empty(){
	return (top==-1); //underflow condiotion check
}
int is_full(){
	return (top== MAX_SIZE -1 ); //overflow condiotion check
}
int pop(int stack[]){       //param1=array name 
	if (is_empty()) {
		printf("Stack underflow..cannot perform pop operation!!!\n");
		return -1;
	}
	int pop_item = stack[top--]; //first fill the value in pop item and them move index to 1 below
	return pop_item;
}
int peek(int stack[]){       //param1=array name 
	if (is_empty()) {
		printf("Stack is empty..cannot perform peek operation!!!\n");
		return -1;
	}
	return stack[top]; //return what is there in the top  of stack
}

int get_push_value_from_user(){
	int push_val;
	printf("\nEnter the value to push :");
	scanf("%d",&push_val);
	return push_val;
}
void show_menu(){
	printf("**************STACK OPERATIONS*****************\n\n");
	printf("1.Push                        2.Pop\n");
	printf("3.Peek                        4.isEmpty\n");
	printf("5.isFull                      6.Traverse\n");
	printf("7.Exit                         \n");
	
	printf("\nEnter your choice[1-7]: ");
	
}
void push(int stack[],int value){
	if (is_full()) {
		printf("Stack is full..cannot push %d!!!\n",value);
		return;
	}
	stack[++top] = value; //it will incremnet the value of top to zero and then push 10 into it
}
void traverse(int stack[]){
	printf("Stack elements[");
	for(int i=0;i<=top;i++){
		printf("%d ",stack[i]);
	}
	printf("]\n");
	
}
