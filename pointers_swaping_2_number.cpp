/*2. Swap two numbers using pointers.
*/
#include <stdio.h>
void swap(int,int);
void swap_by_ref(int*,int*);
int main(){
	int x=20,y=40;
	
	printf("\nvalue Before swap x=%d,y=%d",x,y);
	swap(x,y);
	printf("\nvalue After swap x=%d,y=%d",x,y);
	swap_by_ref(&x,&y);
	printf("\nvalue After swap_by_ref x=%d,y=%d",x,y);
	
	return 0;
}
void swap_by_ref(int* a,int* b){
	int temp;
	temp = *a;
	*a    = *b;
	*b    = temp;
}
void swap(int x,int y){
	int temp;
	temp = x;
	x    = y;
	y    = temp;
}
