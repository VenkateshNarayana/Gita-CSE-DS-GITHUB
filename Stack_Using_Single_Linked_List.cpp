/* Linked List - It is a linear data structure where nodes are connected to each other using pointers. These node are scattered in 
                 memory unlike arrays where they are stored contigously.
                 A node consists 2 parts,
                 1. data    - This stores the information (primitive data types-int,float,double,char, arrays, user defined types-struct & union)
                 2. pointer - This stores the address of anothere node. 
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
	int     		data; //to store information
	struct node* 	next; //to store the address of next node
};

struct node* head=NULL; //track the head of the linked list
struct node* tail=NULL; //track the tail of the linked list

//creation of node using malloc (DMA)
struct node* create_node(int); //param1 = input data to store the information part,pointer will be always NULL

//insert operations - at head, at tail, at position
void push(int); // insert input data before head

//delete opertions - at head, at tail, at position
void pop();     // delete current head
void peek();    // show the top
int is_empty(); // return 1 if list is empty else 0
//list traversal operation
void traverse_list();
void free_list();

int main(){
	//perform push - opearations
	push(10);
	traverse_list();
	push(20);
	traverse_list();
	
	
	//perform pop operations
	pop();
	
	peek();
	
	traverse_list();
	//free all the nodes
	free_list();
	return 0;
}
struct node* create_node(int input_data){
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	if (new_node==NULL){
		printf("\nmemory allocation failed...");
		return NULL;
	}
	//store input data in information part & store NULL in pointer
	new_node->data = input_data;
	new_node->next = NULL;
	return new_node;
}
int is_empty(){
	return (head==NULL); //if list is empty return 1 else 0
}
void peek(){
	if(is_empty()){
		printf("\nList is empty..cannot perform peek!!");	
	}else{
	
		printf("\nTOP=%d",head->data);
	}
}
void push(int input_data){
	struct node* new_node = create_node(input_data);
	if(new_node==NULL) return;
	//if linked is empty
	if(head==NULL){
		head = new_node;
		tail = new_node;
	}else{
		//step1 : point new node's next to current head
		new_node->next = head;
		//step2 : move the head to new node
		head = new_node; 
	}
	printf("\nPushed(%d) into Stack succesfully!!",input_data);
}

void pop(){
	if(head==NULL){
		printf("\nList is empty cannot perform delete operation");
	}else{
		struct node* temp = head; //store the current head
		int deleted_node   = head->data;
		head = head->next;        //move head to next node
		free(temp);               //free the temp 
		printf("\nPopped %d from Stack successfully!!!",deleted_node); 
	}
}

void traverse_list(){//list traversal
	if (head==NULL){
		printf("\nStack[ empty ]");
	}else{
		struct node* temp = head; //store the first node (head) node's address
		//traverse from head to tail
		printf("\nStack [");
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp = temp->next; //move to next node until null
		}
		printf("null]");	
	}
	
}
void free_list(){
	struct node* temp; //store the first node(head)
	//traverse from head to NULL and free all the nodes
	while(head!=NULL){
		temp = head;
		head = head->next; //move to next node until null
		free(temp);
	}
	printf("\nfreed all the nodes successfully!!");
}
