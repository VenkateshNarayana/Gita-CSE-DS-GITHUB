/*Application of Stack Infix to Postfix (Reverse Polish Notation)
Algorithm
step1: read each token of infix expression from left to right
step2: if token is '(' open parenthesis then push into stack
step3: if token is operand then append to output string
step4: if token is operator then,
	a) if the stack is empty then push into stack
	b) if the top of stack is open parenthesis then push into stack
	c) if the top is operator ,check and pop all the operators from 
	   stack whose precedence is greater than or equal to current operator(infix) 
	   append to the output string else push current operator(infix) into stack
	e) after popping all the elements push the current operator(infix) into stack
	
step5: if token is ')' closing parentheisis,pop to output until ‘(’ is found; discard both parenthesis
step6: if the end of input string is reached then pop all remaining operators to output string.
step7: output string is the postfix expression(RPN)

Example 1: "(2+3*4)"     --> RPN= "234*+"
Example 2: "(6*7+8/2%4)" --> RPN= "67*824%/+"

*/
#include <stdio.h>
#define MAX_SIZE 20
int top = -1; //current index tracker for stack

void traverse(int[]); //param1= array name
void push(int[],int); //param1=array name ; param2=value
int pop(int[]);       //param1=array name ; 
int peek(int[]);      //param1=array name ;
int is_full();        //will return 1 if the stack is full to its MAX SIZE else 0
int is_empty();       //will return 1 if the stack is empty(top index will contain -1)  else 0

int operator_precedence(char);

int main(){
	int stack[MAX_SIZE]={0}; //declare and initialize the stack to zero with MAX_SIZE
	char infix_exp[20]   = "(6*7+8/2%4)";//"(2+3*4)"; //initialize the infix string
	char postfix_exp[20] = ""; //initialize the output to empty string
	int i=0,k=0; //i is for infix and k is for postfix
	int pop_item;
	//step1: read each token of infix expression from left to right
	while(infix_exp[i]!='\0'){
		//step2: if token is '(' open parenthesis then push into stack
		if(infix_exp[i]=='('){
			push(stack,infix_exp[i]); //push open parenthesis into stack
			traverse(stack);
		}
		//step4: if token is operator then,
		else if(infix_exp[i]=='+' || infix_exp[i]=='-' ||
		        infix_exp[i]=='*' || infix_exp[i]=='/' || infix_exp[i]=='%'){
			//   if the top is operator ,check and pop all the operators from 
	   		//   stack whose precedence is greater than or equal to current operator(infix) 
	   		//   append to the output string else push current operator(infix) into stack
			int peek_item = peek(stack);
			while(!is_empty()    && 
				  peek_item!='('  && 	
				  operator_precedence(peek_item)>operator_precedence(infix_exp[i])){
			  	//pop item if the a)stack is not empty and b)peek is not open parenthesis and c) peek item's precedence is higher
				pop_item = pop(stack); 
				postfix_exp[k++] = pop_item; //append operators to the output string
				peek_item = peek(stack);	
			}
			//push the infix operator into stack
			push(stack,infix_exp[i]);
			traverse(stack);
		}
		//step5: if token is ')' closing parentheisis,pop all the operators to output string  
		//until ‘(’ is found & discard both parenthesis
		else if(infix_exp[i]==')'){
			pop_item = pop(stack);
			while(pop_item!='('){
				postfix_exp[k++]=pop_item; //append operators to the output string
				pop_item = pop(stack); //get the next item in stack
			}	
		}
		//step3: if token is operand then append to output string
		else { 
			postfix_exp[k++] = infix_exp[i];//building the output string by appending operands first then operator
		}
		
		i++; //move to next token of the infix expression
	}
	//step6: if the end of input string is reached then pop all remaining operators to output string.
	while(!is_empty()){
		pop_item = pop(stack);
		postfix_exp[k++] = pop_item;	
	}
	postfix_exp[k] = '\0'; //finally append the postfix string with string terminator
	
	printf("\nGiven Infix Expression :%s\n",infix_exp);
	
	printf("\nPostfix    Expression  :%s",postfix_exp);
	return 0;
}

int operator_precedence(char oper){
	switch(oper){
		case '*':
		case '/':
		case '%': return 2;
		case '+':
		case '-': return 1;
		default : printf("\ninvalid operator(%c)",oper);return -1;
	}
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

void push(int stack[],int value){
	if (is_full()) {
		printf("Stack is full..cannot push %d!!!\n",value);
		return;
	}
	stack[++top] = value; //it will incremnet the value of top to zero and then push 10 into it
}
void traverse(int stack[]){
	printf("\nStack elements[");
	for(int i=0;i<=top;i++){
		printf("%c ",stack[i]);
	}
	printf("]");
	
}


