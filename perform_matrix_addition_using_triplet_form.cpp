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
void display_triplet(int[][3]);
void display_triplet_to_sparse(int[][3]);      //param1= triplet matrix name
int get_element_from_triplet(int[][3],int,int);//param1= triplet matrix name;param2=row index ;param3=col index
int main(){
	int trip_matA[4][3]={{3,3,3},
						{0,0,5},
						{1,2,3},
						{2,1,4}	
						};
	int matA_rows = trip_matA[0][2]; //get the non zero count
	int trip_matB[5][3]={{3,3,4},
						{0,0,2},
						{1,2,6},
						{2,0,1},
						{2,1,6}
						};
	int matB_rows = trip_matB[0][2]; //get the non zero count
	//step1: calculate rows and col dimensions and then create the result matrix
	int res_trip_rows = trip_matA[0][2]+ trip_matB[0][2];
	int result_trip_mat[res_trip_rows+1][3]={0}; //declare and initialize (add 1 row extra for the header)
	//step2: populate the header row
	result_trip_mat[0][0] = trip_matB[0][0]; //ROWS dimension of orig matrix
	result_trip_mat[0][1] = trip_matB[0][1]; //COLS dimension of orig matrix
	result_trip_mat[0][2] = res_trip_rows;
	//step3: populate the all the other non zero element from matA & matB
	//iterate the rows of matA and matB
	int i=1,j=1,k=1;
	while(i<(matA_rows+1) && j<(matB_rows+1)){
		//case 1: when rows and cols are same then add a single entry into result matrix
		if(trip_matA[i][0]==trip_matB[j][0] && trip_matA[i][1]==trip_matB[j][1] ){
			//single entry where r = col1 of matA , c= col2 of matA , v= col3 of matA + col3 of matB
			result_trip_mat[k][0] = trip_matA[i][0]; //ROWS dimension of orig matrix
			result_trip_mat[k][1] = trip_matA[i][1]; //COLS dimension of orig matrix
			result_trip_mat[k][2] = trip_matA[i][2]+trip_matB[j][2];
			i++; //increment the row counter of matA
			j++; //increment the row counter of matB
			k++; //increment the row counter of result matrix
		} 
		//case 2:  when rows are same but cols are different then add a the lowest col into result matrix
		else if(trip_matA[i][0]==trip_matB[j][0] && trip_matA[i][1]<trip_matB[j][1] ){
			//add entry for the lowest col where r = col1 of matA , c= col2 of matA , v= col3 of matA
			result_trip_mat[k][0] = trip_matA[i][0]; //ROW index of non zero element from matA
			result_trip_mat[k][1] = trip_matA[i][1]; //COLS index oof non zero element from matA
			result_trip_mat[k][2] = trip_matA[i][2]; //ACTUAL VALUE f non zero element from matA
			i++; //increment the row counter of matA
			k++; //increment the row counter of result matrix
		}else if(trip_matA[i][0]==trip_matB[j][0] && trip_matA[i][1]>trip_matB[j][1] ){
			//add entry for the lowest col(matB) where r = col1 of matB , c= col2 of matB , v= col3 of matB
			result_trip_mat[k][0] = trip_matB[j][0]; //ROW index of non zero element from matB
			result_trip_mat[k][1] = trip_matB[j][1]; //COLS index of non zero element from matB
			result_trip_mat[k][2] = trip_matB[j][2]; //ACTUAL VALUE of non zero element from matB
			j++; //increment the row counter of matB
			k++; //increment the row counter of result matrix
		}
		//case 3:  when rows & cols are different then add the lowest row first into result matrix
		else if(trip_matA[i][0]<trip_matB[j][0]){
			//add entry for the lowest col where r = col1 of matA , c= col2 of matA , v= col3 of matA
			result_trip_mat[k][0] = trip_matA[i][0]; //ROW index of non zero element from matA
			result_trip_mat[k][1] = trip_matA[i][1]; //COLS index of non zero element from matA
			result_trip_mat[k][2] = trip_matA[i][2]; //ACTUAL VALUE of non zero element from matA
			i++; //increment the row counter of matA
			k++; //increment the row counter of result matrix
		}else if(trip_matA[i][0]>trip_matB[j][0]){
			//add entry for the lowest col(matB) where r = col1 of matB , c= col2 of matB , v= col3 of matB
			result_trip_mat[k][0] = trip_matB[j][0]; //ROW index of non zero element from matB
			result_trip_mat[k][1] = trip_matB[j][1]; //COLS index of non zero element from matB
			result_trip_mat[k][2] = trip_matB[j][2]; //ACTUAL VALUE of non zero element from matB
			j++; //increment the row counter of matB
			k++; //increment the row counter of result matrix
		}
	}
	//any leftovers from matA need to be added into result matrix
	while(i<(matA_rows+1)){
		
		result_trip_mat[k][0] = trip_matA[i][0]; //ROW index of non zero element from matA
		result_trip_mat[k][1] = trip_matA[i][1]; //COLS index of non zero element from matA
		result_trip_mat[k][2] = trip_matA[i][2]; //ACTUAL VALUE of non zero element from matA
		i++; //increment the row counter of matA
		k++; //increment the row counter of result matrix
	}
	
	//any leftovers from matB need to be added into result matrix
	while(j<(matB_rows+1)){
		result_trip_mat[k][0] = trip_matB[j][0]; //ROW index of non zero element from matB
		result_trip_mat[k][1] = trip_matB[j][1]; //COLS index of non zero element from matB
		result_trip_mat[k][2] = trip_matB[j][2]; //ACTUAL VALUE of non zero element from matB
		j++; //increment the row counter of matB
		k++; //increment the row counter of result matrix
	}
	
	//now print the result matrix
	display_triplet(trip_matA);
	display_triplet(trip_matB);
	display_triplet(result_trip_mat);
	
	return 0;
}
void display_triplet_to_sparse(int triplet_mat[][3]){     //param1= triplet matrix name
	int mat_rows = triplet_mat[0][0]; //header row ->1st col - rows dimension of original matrix
	int mat_cols = triplet_mat[0][1]; //header row ->2nd col - cols dimension of original matrix
	printf("\nMatrix Form:\n");
	for(int i=0;i<mat_rows;i++){
		for(int j=0;j<mat_cols;j++){
			printf("%d ",get_element_from_triplet(triplet_mat,i,j));
		}
		printf("\n");//line breaker for each row
	}
}
int get_element_from_triplet(int triplet_mat[][3],int i,int j){//param1= triplet matrix name;param2=row index ;param3=col index
	int trip_rows = triplet_mat[0][2] +1 ; //non zero count + 1 for the header
	for(int row=0;row<trip_rows;row++){
		if(triplet_mat[row][0]==i && triplet_mat[row][1]==j){//if the row matches with i and col matches with j
			return triplet_mat[row][2]; //return the non zero element stored in 3rd col
		} 
	}
	return 0; //if no match found return 0
}
void display_triplet(int trip_mat[][3]){//param1= triplet matrix name 
	int rows = trip_mat[0][2] + 1; //3 col stores the non zero count ,add 1 for header row
	printf("\ntriplet rows=%d\n",rows);
	printf("Triplet Matrix:\n");
	printf("Row \tCol \tValue\n");
	for(int i=0;i<rows;i++){
		printf("\n%d \t%d \t%d",trip_mat[i][0],trip_mat[i][1],trip_mat[i][2]); //printing r,c,v
	}
}
