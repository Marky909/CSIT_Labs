#include<stdio.h>
void selection_sort(int[],int);
int main(){
	int n;
	printf("enter the size of array: ");
	scanf("%d",&n);

	int arr[n];

	printf("Enter the element you wanna sort\n");
	for(int i = 0;i<n;i++){
	 scanf("%d",&arr[i]);}
	
	printf("\n*****Before sorting*****\n");
	for(int i = 0;i<n;i++){
	 printf("%d\t",arr[i]);}

	selection_sort(arr,n);

	printf("\n*****after sorting*****\n");
	for(int i = 0;i<n;i++){
	printf("%d\t",arr[i]);}

return 0;
}
void selection_sort(int A[],int n){
	for(int i =0;i<n-1;i++){
		int min = i;
		 for(int j = i+1;j<n;j++){
		 	 if(A[j]<A[min])
		 	  min = j;
		 }
		  int temp = A[i];
		  A[i]=A[min];
		  A[min]=temp;
		  
	}
}