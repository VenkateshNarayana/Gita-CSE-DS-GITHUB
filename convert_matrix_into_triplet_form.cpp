/* 
Convert a 2d matrix into triplet form(r,c,v)
Algorithm
Step1: find the non zero count
Step2: row=non zero count + 1(header) ,col= 3 (r,c,v)
       Declare triplet [row][3];
Step3: add the header row
       dimensions of the original matrix(r = rows, c = cols) 
	   v = add the no of non zero elements 
	   
Step4: add the non zero element from the original matrix
       r = row (index) of non zero element  
	   c = col (index) of non zero element 
	   v = actual value non zero elements 
	   
Step5: display the values stored inside the triplet matrix	   
*/
#include <stdio.h>
void display_sparse(int[][5],int,int);//param1= sparse matrix name ;param2:no of rows;param3=no of cols
void display_triplet(int[][3]);
int main(){
	int sparse_mat[4][5]={
							{0,0,3,0,4},
							{0,0,5,7,0},
							{0,0,0,0,0},
							{6,0,0,0,0}
							}; //declare a 2d matrix
	//display
	display_sparse(sparse_mat,4,5);
	
	//convert it into triplet
	//Step1: find the non zero count
	int non_zero_counter =0 ;
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			if(sparse_mat[i][j]!=0){
				non_zero_counter++;
			}
		}
	}
	printf("\nnon zero count=%d\n",non_zero_counter);
	int trip_rows = non_zero_counter + 1; //1 for the header row
	//step2 : declare the triplet
	int triplet_mat[trip_rows][3];
	//step3 : add header row
	triplet_mat[0][0]=4;//add  r = rows
	triplet_mat[0][1]=5;//add  c = cols
	triplet_mat[0][2]=non_zero_counter;//add  v = non zero count
	
	//step 4: add the non zero element from the original matrix
	int k=1; //row tracker for triplet matrix
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			if(sparse_mat[i][j]!=0){
				triplet_mat[k][0]=i;//add  r = row index of non zero element
				triplet_mat[k][1]=j;//add  c = col index of non zero element
				triplet_mat[k][2]=sparse_mat[i][j];//add  v = actual value
				k++;
			}
		}
	}
	//Step5: call the display_triplet
	display_triplet(triplet_mat);
	
	return 0;//for the main
}
void display_triplet(int trip_mat[][3]){//param1= triplet matrix name 
	int rows = trip_mat[0][2] + 1; //3 col stores the non zero count ,add 1 for header row
	printf("triplet rows=%d\n",rows);
	printf("Triplet Matrix:\n");
	printf("Row \tCol \tValue\n");
	for(int i=0;i<rows;i++){
		printf("\n%d \t%d \t%d",trip_mat[i][0],trip_mat[i][1],trip_mat[i][2]); //printing r,c,v
	}
}
void display_sparse(int mat[][5],int rows,int cols){//param1= sparse matrix name ;param2:no of rows;param3=no of cols
	printf("Sparse Matrix:\n");
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n"); //to print every row in new line
	}
}
