#include<stdio.h>
#include<stdlib.h>
void displayArray(int[],int);
int main(){
	int n;
	printf("Enter the number of blocks:");
	scanf("%d",&n);
	int* ptrarr =(int*)malloc(n*sizeof(int));
	
	if(ptrarr==NULL){
		printf("Memory allocation failed...");
		return 1;
	}
	
	printf("Memory block created successfully");
	//allocation of data
	for (int i=0;i<n;i++){
//		*(ptrarr+i) = i+1;
		ptrarr[i] = i+1;
	}
	
	//print the data
	printf("\nData allocated:");
	displayArray(ptrarr,5);
//	for (int i=0;i<n;i++){
//		printf("%d ",*(ptrarr +i));
//	}
	
	//reallocate the data
	ptrarr = (int*) realloc(ptrarr, (n + 5) * sizeof(int));
	if (temp == NULL) {
	    printf("\nReallocation failed...");
	    return 1;
	}

//	ptrarr = temp;
	//print the data
	printf("\nData allocated:");
	for (int i=0;i<n+5;i++){
		if (i>4) ptrarr[i]=0;
		printf("%d ",*(ptrarr +i));
	}
	
	free(ptrarr);
	return 0;
}
void displayArray(int ptrarr[],int size){
	for(int i=0;i<size;i++){
		printf("%d ",*(ptrarr +i));
	}
}
