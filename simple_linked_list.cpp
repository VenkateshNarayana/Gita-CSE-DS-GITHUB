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
	struct node* 	next; //to store the address of another node
};
int main(){
	//lets create 4 nodes and connect them together using pointers to make it a linked list
	struct node node1,node2,node3,node4;
	
	//my node1 is going to be the head
	node1.data = 1; //storing data here
	node1.next = &node2; //use the address of operator to store the address of node2
	
	//store information in node2
	node2.data = 2;
	node2.next = &node3; //store node3 address
	
	//store information in node3
	node3.data = 3;
	node3.next = &node4; //store node4 address
	
	//store information in node4
	node4.data = 4;
	node4.next = NULL; //we store NULL because this is my tail node
	
	//display the linked list
	printf("List[");
	printf("%d->",node1.data); // this is node1 data which is 1
	printf("%d->",node1.next->data); //this is going to fetch me 2(which is node2 data)
	printf("%d->",node1.next->next->data); //this is going to fetch me 3(which is node3 data)
	printf("%d->",node1.next->next->next->data); //this is going to fetch me 4(which is node4 data)
	printf("null]\n");
	
	//list traversal
	struct node* temp = &node1; //store the first node (head) node's address
	printf("\nList optimised[");
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp = temp->next; //move to next node until null
	}
	printf("null]");
	
	return 0;
}
