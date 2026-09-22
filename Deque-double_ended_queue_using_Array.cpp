/* Deque (double ended Q) : THe data management and its operation are flexible wherein you can insert and delete from both ends
   Operations   : 1.enqueue_front --> if Q is not full
   			      2.enqueue_rear --> if Q is not full
    			  3.dequeue_front --> if Q is not empty 
    			  4.dequeue_rear --> if Q is not empty 
    			  5.traverse --> for i = front  traverse using circular index formula i = (i+1) % MAX_SIZE 
    			  6.is_empty --> return 1 if size==0  else 0
    			  7.is_full  --> return 1 if (size == MAX_SIZE)  else 0
    			  8.peek_front --> return q[front]
    			  9.peek_rear  --> return q[rear]
    			  
*/
#include<stdio.h>
#define MAX_SIZE 5
int front = 0 ; //to track front
int size  = 0 ; //to track the no of elements in the queue

void enqueue_front(int[],int);//param1= array name ;param2=value
void enqueue_rear(int[],int);//param1= array name ;param2=value

int  dequeue_front(int[]);    //param1= array name
int  dequeue_rear(int[]);    //param1= array name

void traverse(int[]);   //param1= array name
int  is_empty();        //return 1 if front>rear else 0
int  is_full();         //return 1 if rear=MAX_SIZE-1 else 0
int  peek_front(int[]); //param1= array name
int  peek_rear(int[]);  //param1= array name


int main(){
	int queue[MAX_SIZE]={0}; //create an array with size = MAX_SIZE and initialize it to 0
	
	//enqueue operations
	enqueue_front(queue,10);
	traverse(queue);
	enqueue_front(queue,20);
	traverse(queue);
	enqueue_rear(queue,30);
	traverse(queue);
	enqueue_front(queue,40);
	traverse(queue);
	enqueue_rear(queue,50);
	traverse(queue);
	
	printf("\nWho is in the front?%d",peek_front(queue));
	printf("\nWho is in the rear?%d",peek_rear(queue));
	
	enqueue_front(queue,60); //will this work? NO - bcos Q is full
	traverse(queue);

	//dequeue
	int dq_item=dequeue_rear(queue);
	if (dq_item!=-1) printf("\nDequeued %d from rear successfully",dq_item);
	traverse(queue);
	
	printf("\nWho is in the front?%d",peek_front(queue));
	printf("\nWho is in the rear?%d",peek_rear(queue));
	
	enqueue_front(queue,60); //will this work? YES - bcos we have removed 1 item above so Q is not full
	traverse(queue);
	
//	dq_item=dequeue(queue);
//	if (dq_item!=-1) printf("\nDequeued %d successfully",dq_item);
//	traverse(queue);
//	
//	dq_item=dequeue(queue);
//	if (dq_item!=-1) printf("\nDequeued %d successfully",dq_item);
//	traverse(queue);
//	
//	dq_item=dequeue(queue);
//	if (dq_item!=-1) printf("\nDequeued %d successfully",dq_item);
//	traverse(queue);
//	
//	dq_item=dequeue(queue);
//	if (dq_item!=-1) printf("\nDequeued %d successfully",dq_item);
//	traverse(queue);
//	
//	dq_item=dequeue(queue); //will this work? NO because Q is empty
//	if (dq_item!=-1) printf("\nDequeued %d successfully",dq_item);
//	traverse(queue);
	
	return 0; //for main()
}
int  is_empty(){        //return 1 if size==0 else 0
	return(size==0);
}
int  is_full(){         //return 1 if (size == MAX_SIZE) else 0
	return (size == MAX_SIZE);
}

void enqueue_front(int q[],int value){//param1= array name ;param2=value
	if(is_full()){
		printf("\nQ overflow....cannot enqueue %d",value);
	}else{
		front = (front - 1 + MAX_SIZE) % MAX_SIZE;
		q[front]=value;
		size++; //increment size by 1
	}

}
void enqueue_rear(int q[],int value){//param1= array name ;param2=value
	if(is_full()){
		printf("\nQ overflow....cannot enqueue %d",value);
	}else{
		int rear = (front + size) % MAX_SIZE;
		q[rear]=value;
		size++; //increment size by 1
	}
}
int  dequeue_front(int q[]){    //param1= array name
	int dq_item=-1;
	if(is_empty()){
		printf("\nQ underflow....cannot perform dequeu");
	}else{
		dq_item = q[front];
		front = (front + 1) % MAX_SIZE;
		size--; //decrement size by 1
	}
	return dq_item;
}
int  dequeue_rear(int q[]){    //param1= array name
	int dq_item=-1;
	if(is_empty()){
		printf("\nQ underflow....cannot perform dequeu");
	}else{
		int rear = (front + size -1 ) % MAX_SIZE;
		dq_item = q[rear];
		size--; //decrement size by 1
	}
	return dq_item;
}
void traverse(int q[]){   //param1= array name
	int index;
	if(is_empty()){
		printf("\nQ (curr size=0) [ empty ]");
	}else{
		printf("\nQ (curr size=%d) [",size);
		for (int i = 0; i < size; i++){
        	index = (front + i) % MAX_SIZE;
        	printf("%d ", q[index]);
    	}
    	printf("]");
	}
}

int  peek_front(int q[]){ //param1= array name
	if (is_empty()) 
		return -1;
	else 
		return q[front];
}
int  peek_rear(int q[]){  //param1= array name
	if (is_empty()) 
		return -1;
	else {
		int rear = (front + size - 1) % MAX_SIZE;
		return q[rear];
	}
}

