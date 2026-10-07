/* Queue using Double Linked List - It is a linear data structure where nodes are connected to each other using pointers. These node are scattered in 
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
	int     		data; //to store information
	struct node* 	next; //to store the address of next node
	struct node* 	prev; //to store the address of previous node
};

struct node* head=NULL; //track the head of the linked list
struct node* tail=NULL; //track the tail of the linked list

//creation of node using malloc (DMA)
struct node* create_node(int); //param1 = input data to store the information part,pointer will be always NULL

//insert operations - at tail,
void enqueue(int); // insert input data after tail

//delete opertions - at head
void dequeue(); // delete current head

//peek operations
void peek_front();
void peek_rear();

//overflow ? underflow?
int is_empty(); //return 1 if link is empty else 0

//list traversal operation
void traverse_q();
void traverse_tail();
void free_list();

int main(){
	//insert - opearations
	enqueue(10);
	enqueue(20);
	enqueue(30);
	peek_front();
	peek_rear();
	
	traverse_q();
	
	//delete - operations
	dequeue();
	peek_front();
	peek_rear();
	
	dequeue();
	dequeue();
	traverse_q();

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
	new_node->next = NULL; //new node next is NULL as its new node
	new_node->prev = NULL; //new node prev is also NULL as its new node
	return new_node;
}
int is_empty(){
	return (head==NULL); //return 1 else 0
}
void peek_front(){
	if (is_empty()){
		printf("\nFRONT=NULL");
	}else{
		printf("\nFRONT=%d",head->data);
	}
}
void peek_rear(){
	if (is_empty()){
		printf("\nREAR=NULL");
	}else{
		printf("\nREAR=%d",tail->data);
	}
}
void enqueue(int input_data){
	struct node* new_node = create_node(input_data);
	if(new_node==NULL) return;
	//if linked is empty
	if(tail==NULL){
		head = new_node;
		tail = new_node;
	}else{
		//step1 : point current tail's next to new node
		tail->next = new_node;
		
		//step2 : point the new node's prev to current tail
		new_node->prev = tail; //current tail
		
		//step3 : move the tail to new node
		tail = new_node; 
	}
	printf("\nInserted node(%d) at tail succesfully!!",input_data);
}
void dequeue(){
	if(head==NULL){
		printf("\nList is empty cannot perform delete operation");
	}else if(head->next==NULL){
		int delete_node_data   = head->data;
		//single node 
		free(head);
		head = NULL;
		tail = NULL;	
		printf("\nDeleted %d node from head successfully!!!",delete_node_data); 
	}else{
		struct node* temp = head; //store the current head
		int delete_node_data   = head->data;
		head         = head->next;        //move head to next node
		head->prev   = NULL;      //head's prev is always NULL in double linked list
		free(temp);               //free the temp 
		printf("\nDeleted %d node from head successfully!!!",delete_node_data); 
	}
}
void traverse_q(){//list traversal
	struct node* temp = head; //store the first node (head) node's address
	if (is_empty()){
		printf("\nQueue [ empty ]");	
	}else{
		printf("\nQueue [");
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp = temp->next; //move to next node until null
		}
		printf("null]");
	}
}
void traverse_tail(){
	struct node* temp = tail; //store the last node (tail)
	printf("\nList(tail->head) [");
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp = temp->prev; //move to previous node until null
	}
	printf("null]\n");
}
void free_list(){
	//check if the list is empty or not
	if(!is_empty()) {
		struct node* temp; //store the first node(head)
		//traverse from head to NULL and free all the nodes
		while(head!=NULL){
			temp = head;
			head = head->next; //move to next node until null
			free(temp);
		}
		printf("\nfreed all the nodes successfully!!");
	}
}
