/* Double Linked List - It is a linear data structure where nodes are connected to each other using pointers. These node are scattered in 
                 memory unlike arrays where they are stored contigously.
                 A node consists 2 parts,
                 1. data    - This stores the information (primitive data types-int,float,double,char, arrays, user defined types-struct & union)
                 2-a. pointer - This stores the address of next node.
				 2-b. pointer - This stores the address of previous node. 
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

//insert operations - at head, at tail, at position
void insert_at_head(int); // insert input data before head
void insert_at_tail(int); // insert input data after tail
void insert_at_position(int,int); //insert input data at position 
//delete opertions - at head, at tail, at position
void delete_at_head(); // delete current head
void delete_at_tail(); // delete current tail


//list traversal operation
void traverse_list();
void traverse_tail();
void free_list();

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
	
//	//delete operations
//	delete_at_head();
//	traverse_list();
//	delete_at_tail();
//	traverse_list();
//	
//	//insert at position
//	insert_at_position(30,15);
//	traverse_list();
		
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
		//step 2:point current head to new node
		head->prev = new_node;
		//step2 : move the head to new node
		head = new_node; 
	}
	printf("\nInserted node(%d) at head succesfully!!",input_data);
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
		
		//step2 : point the new node's prev to current tail
		new_node->prev = tail; //current tail
		
		//step3 : move the tail to new node
		tail = new_node; 
	}
	printf("\nInserted node(%d) at tail succesfully!!",input_data);
}
void insert_at_position(int node_value,int input_data){
	if(head==NULL){
		printf("\nlist is empty..cannot find(%d) node",node_value);
	}else{
		struct node* new_node = create_node(input_data);
		if(new_node==NULL) return; //because memory allocation failed 
		//step 1: traverse to the node before position node
		struct node* temp= head; //start from head
		while(temp->next!=NULL){
			if(temp->next->data==node_value) break;
			temp = temp->next;
		}
		//you are at 1 node before the position node
		//step 2: new nodes next to temp's next
		new_node->next = temp->next;
		//step 3: temp's next to new node
		temp->next = new_node;
		printf("\nInserted node(%d) at position(%d) succesfully!!",input_data,node_value);
	}
}
void delete_at_head(){
	if(head==NULL){
		printf("\nList is empty cannot perform delete operation");
	}else{
		struct node* temp = head; //store the current head
		int deleted_node   = head->data;
		head = head->next;        //move head to next node
		free(temp);               //free the temp 
		printf("\nDeleted %d node from head successfully!!!",deleted_node); 
	}
}
void delete_at_tail(){
	if(tail==NULL){
		printf("\nList is empty cannot perform delete operation");
	}else{
		//struct node* temp_tail = tail; //store the current tail
		struct node* temp = head;
		//traverse to (n-1)th node
		while(temp->next!=tail){
			temp = temp->next; //move to next ndoe
		}
		//you are at the (n-1)th node
		int deleted_node = tail->data;
		temp->next = NULL; //because this is going to be my new tail
		free(tail);       //free the old tail
		tail = temp;      //make the temp as the new tail
		
		printf("\nDeleted %d node from tail successfully!!!",deleted_node); 
	}
}
void traverse_list(){//list traversal
	struct node* temp = head; //store the first node (head) node's address
	printf("\nList (head->tail)[");
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp = temp->next; //move to next node until null
	}
	printf("null]");
	traverse_tail();
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
	struct node* temp; //store the first node(head)
	//traverse from head to NULL and free all the nodes
	while(head!=NULL){
		temp = head;
		head = head->next; //move to next node until null
		free(temp);
	}
	printf("\nfreed all the nodes successfully!!");
}
