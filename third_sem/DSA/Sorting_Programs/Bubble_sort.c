#include<stdio.h>
void Bubble_sort(int[] ,int );
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

	Bubble_sort(arr,n);

	printf("\n*****after sorting*****\n");
	for(int i = 0;i<n;i++){
	printf("%d\t",arr[i]);}

return 0;
}
void Bubble_sort(int A[],int n){
	for(int i =0;i<n-1;i++){
		 for(int j=0;j<n-i-1;j++){
		 	 if(A[j]>A[j+1]){

		 	 int temp = A[j];
		     A[j]=A[j+1];
		     A[j+1]=temp;
		 }
		  
		  
	}
}
}