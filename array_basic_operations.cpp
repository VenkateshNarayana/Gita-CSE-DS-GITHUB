/*Arrays basic operations
1. insert   - insert_at_begin, insert_at_index, insert_at_end 
2. delete   - delete_at_begin, delete_at_index, delete_at_end
3. traverse 
*/
#include<stdio.h>
#define MAX_SIZE 5
int curr_index = 0; //global index for array
//for insert operation
void insert_at_begin(int[],int);
void insert_at_index(int[],int,int);//param1-array name,param2-index (0 based) positon is 1 based,param3-value
void insert_at_end(int[],int);//param1-array name,param2=value
//for delete operation
void delete_at_begin(int[]);//param1-array name
void delete_at_end(int[]);//param1-array name
void delete_at_index(int[],int);////param1-array name,param2=index(0 based) positon is 1 based
//for traversal
void display_array(int[]);//param1-array name
int main(){
	int my_arr[MAX_SIZE]={0};//declare & initialize the size to 5 and values to 0.
	insert_at_end(my_arr,10);
	display_array(my_arr);
	insert_at_end(my_arr,20);
	display_array(my_arr);
	insert_at_end(my_arr,30);
	display_array(my_arr);
	insert_at_end(my_arr,40);
	display_array(my_arr);
	insert_at_end(my_arr,50);
	display_array(my_arr);
	insert_at_end(my_arr,60);
	
	display_array(my_arr);
	
	//delete operation
	delete_at_end(my_arr);
	display_array(my_arr);
	
	delete_at_end(my_arr);
	display_array(my_arr);
	
	delete_at_end(my_arr);
	display_array(my_arr);
	
	delete_at_end(my_arr);
	display_array(my_arr);
	
	//insert at index
	insert_at_index(my_arr,0,100);
	
	display_array(my_arr);
	
	insert_at_index(my_arr,1,200);
	
	display_array(my_arr);
	
	insert_at_index(my_arr,1,300);
	display_array(my_arr);
	
	delete_at_begin(my_arr);
	display_array(my_arr);
	
	delete_at_index(my_arr,1);
	display_array(my_arr);
	
	return 0; //for main
}
void display_array(int arr[]){
	printf("\nMyArray Elements[CURR SIZE=%d]:",curr_index);
	for(int i=0;i<curr_index;i++){
		printf("%d ",arr[i]);
	}
}
void delete_at_begin(int arr[]){
	delete_at_index(arr,0); //pass index as 0 to delete from begin
}
void delete_at_index(int arr[],int index){
	//param1-array name,param2=value
	if(curr_index<=0){
		printf("\nArray is empty..cannot perform delete !!!");
		return;
	}
	for(int i=index;i<=curr_index;i++){
		arr[i] = arr[i+1];//left shifting
	}
	curr_index--;//decrementing the size by 1
	arr[curr_index]=0;
	printf("\nDeleted element at index successfully!!!");
}
void delete_at_end(int arr[]){
	//param1-array name,param2=value
	if(curr_index<=0){
		printf("\nArray is empty..cannot perform delete !!!");
		return;
	}
	curr_index--;//decrementing the size by 1
	arr[curr_index]=0;
	printf("\nDeleted element at end successfully!!!");
}
void insert_at_begin(int arr[],int value){
	insert_at_index(arr,0,value);
}
void insert_at_index(int arr[],int index,int value){
	//param1-array name,param2=index, param3=value
	if(curr_index>=MAX_SIZE){
		printf("\nArray is full..cannot insert %d value!!!",value);
		return;
	}
	for(int i=curr_index-1;i>=index;i--){
		arr[i+1]=arr[i]; //right shifting
	}
	arr[index]=value;
	curr_index++;//incrementing the size by 1
	printf("\nInserted %d value at end successfully!!!",value);
}
void insert_at_end(int arr[],int value){
	//param1-array name,param2=value
	if(curr_index>=MAX_SIZE){
		printf("\nArray is full..cannot insert %d value!!!",value);
		return;
	}
	arr[curr_index]=value;
	curr_index++;//incrementing the size by 1
	printf("\nInserted %d value at end successfully!!!",value);
}
