/*Application of Stack post fix(Reverse Polish Notation) evaluation
Algorithm
step1: read each token of postfix expression from left to right
step2: if token is operand then push into stack
step3: if token is operator then pop 2 operands from stack and perform the operation as per the operator,
	   result = [pop2(op1) operator(+-/*%) pop1(op2)] and push the result back into stack
step4: end of postfix string , pop out whatever is left in the stack as the final answer

Example 1: RPN= "234*+"     --> 14
Example 2: RPN= "67*824%/+" --> 46

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


int main(){
	int stack[MAX_SIZE]={0}; //declare and initialize the stack to zero with MAX_SIZE
	char postfix_exp[20] = "234*+"; //answer = 14
	int i=0; //i is for infix and k is for postfix
	int op1=0,op2=0,result=0;
	//step1: read each token of postfix expression from left to right
	while(postfix_exp[i]!='\0'){
		//step2: if token is operand then push into stack
		if(postfix_exp[i]!='+' && postfix_exp[i]!='-' && 
		   postfix_exp[i]!='*' && postfix_exp[i]!='/' && postfix_exp[i]!='%'){
		   	push(stack,postfix_exp[i]-'0');//subtract the current operands ascii with ascii of 0 to get the actual value
		   	traverse(stack);
		   }
		//step3: if token is operator then pop 2 operands from stack and perform the operation as per the operator,
	   	//        result = [pop2(op1) operator(+-/*%) pop1(op2)] and push the result back into stack
		else{
			op2 = pop(stack); //1st pop item
			op1 = pop(stack); //2nd pop item
			
			//perform the operation using the above 2 operands
			switch(postfix_exp[i]){
				case '*': result = op1 * op2; break;
				case '/': result = op1 / op2; break;
				case '%': result = op1 % op2; break;
				case '+': result = op1 + op2; break;
				case '-': result = op1 - op2; break;
			}	
			//push the result back into stack
			push(stack,result);
			traverse(stack);
		}
		i++; //move to next token of the infix expression
	}
	//step4: end of postfix string , pop out whatever is left in the stack as the final answer
	result = pop(stack);
	printf("\nPostfix    Expression  :%s\n",postfix_exp);
	
	printf("\nPostfix    Evaluation  :%d",result);
	
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
		printf("%d ",stack[i]); //print char since these are operators and contain ascii values
	}
	printf("]");
}


