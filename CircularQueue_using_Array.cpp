/* Circular Queue : THe data management and its operation is governed by FIFO principle(First in first out)
   Operations   : 1.enqueue --> if Q is not full
    			  2.dequeue --> if Q is not empty front = front + 1
    			  3.traverse --> for i = front  traverse using circular index formula i = (i+1) % MAX_SIZE 
    			  4.is_empty --> return 1 if front==-1  else 0
    			  5.is_full  --> return 1 if ((rear+1)%MAX_SIZE == front)  else 0
    			  6.peek_front --> return q[front]
    			  7.peek_rear  --> return q[rear]
    			  
*/
#include<stdio.h>
#define MAX_SIZE 5
int front = -1 ; //this is kept 0 so that we can perform enque and dequeue using rear and front indexes only
int rear  = -1 ;

void enqueue(int[],int);//param1= array name ;param2=value
int  dequeue(int[]);    //param1= array name
void traverse(int[]);   //param1= array name
int  is_empty();        //return 1 if front>rear else 0
int  is_full();         //return 1 if rear=MAX_SIZE-1 else 0
int  peek_front(int[]); //param1= array name
int  peek_rear(int[]);  //param1= array name


int main(){
	int queue[MAX_SIZE]={0}; //create an array with size = MAX_SIZE and initialize it to 0
	dequeue(queue);
	traverse(queue);
	//enqueue
	enqueue(queue,10);
	traverse(queue);
	enqueue(queue,20);
	traverse(queue);
	enqueue(queue,30);
	traverse(queue);
	enqueue(queue,40);
	traverse(queue);
	enqueue(queue,50);
	traverse(queue);
	
	printf("\nWho is in the front?%d",peek_front(queue));
	printf("\nWho is in the rear?%d",peek_rear(queue));
	
	enqueue(queue,60); //will this work? NO - bcos Q is full
	traverse(queue);

//	//dequeue
//	int dq_item=dequeue(queue);
//	if (dq_item!=-1) printf("\nDequeued %d successfully",dq_item);
//	traverse(queue);
//	
//	printf("\nWho is in the front?%d",peek_front(queue));
//	printf("\nWho is in the rear?%d",peek_rear(queue));
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
//	dq_item=dequeue(queue);
//	if (dq_item!=-1) printf("\nDequeued %d successfully",dq_item);
//	traverse(queue);
//	
//	dq_item=dequeue(queue); //will this work? NO because Q is empty
//	if (dq_item!=-1) printf("\nDequeued %d successfully",dq_item);
//	traverse(queue);
	
	return 0; //for main()
}
int  is_empty(){        //return 1 if front==-1 else 0
	return(front==-1);
}
int  is_full(){         //return 1 if ((rear+1) % MAX_SIZE)==front else 0
	return (((rear+1) % MAX_SIZE)==front);
}

void enqueue(int q[],int value){//param1= array name ;param2=value
	if(is_full()){
		printf("\nQ overflow....cannot enqueue %d",value);
	}else{
		if(front==-1){
			front = 0;
		}
		rear = (rear+1) % MAX_SIZE;
		q[rear]=value; //increment rear by 1
	}

}
int  dequeue(int q[]){    //param1= array name
	int dq_item=-1;
	if(is_empty()){
		printf("\nQ underflow....cannot perform dequeu");
	}else{
		dq_item = q[front];
		if(front == rear){
			//reset the Queue
			front = -1;
			rear  = -1;
		}else{
			front = (front+1) % MAX_SIZE; //increment front by 1
		}
	}
	return dq_item;
}
void traverse(int q[]){   //param1= array name
	int size;
	if(is_empty()){
		printf("\nQ (curr size=0) []");
	}else{
		size = (front<rear)?(rear+1 -front):((rear+1)%MAX_SIZE)-front;
		printf("\nQ (curr size=%d) [",size);
		int i = front;
		while(1){
			printf("%d ",q[i]);
			if(i==rear) break;
			i = (i+1) % MAX_SIZE;
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
	else 
		return q[rear];
		
}

