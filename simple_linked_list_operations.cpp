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

//list traversal operation
void traverse_list();

//creation of node using malloc (DMA)
struct node* create_node(int); //param1 = input data to store the information part,pointer will be always NULL

//insert operations - at head, at tail, at position
void insert_at_head(int); // insert input data before head
void insert_at_tail(int); // insert input data after tail

int main(){
	//insert - opearations
	insert_at_head(10);
	traverse_list();
	insert_at_head(20);
	traverse_list();
	
	insert_at_tail(30);
	traverse_list();
	insert_at_tail(50);
	traverse_list();
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
void insert_at_head(int input_data){
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
}
void insert_at_tail(int input_data){
	struct node* new_node = create_node(input_data);
	if(new_node==NULL) return;
	//if linked is empty
	if(tail==NULL){
		head = new_node;
		tail = new_node;
	}else{
		//step1 : point current tail's next to new node
		tail->next = new_node;
		//step2 : move the tail to new node
		tail = new_node; 
		//tail = tail->next;// This is LINKAN's code
	}
}
void traverse_list(){//list traversal
	struct node* temp = head; //store the first node (head) node's address
	printf("\nList [");
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp = temp->next; //move to next node until null
	}
	printf("null]");
}
