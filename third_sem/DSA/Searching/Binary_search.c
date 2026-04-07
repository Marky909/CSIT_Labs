#include<stdio.h>

	int binary_search(int a[100],int l, int r, int key){
		int flag=0;
		int m;
		if(l<=r){
			m=(l+r)/2;
			
			if(key==a[m])
			 return flag=m;
			else if(key<a[m])
				 return binary_search(a,l,m-1,key);
			else 
			 return binary_search(a,m+1,r,key);
			}
		
	    else 
		 return flag;
	}

int main(){
	 int a[100],flag,key,i,n;
	 printf("Enter the size of array: ");
	 scanf("%d",&n);
	
	printf("Enter the data to the array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enetr the key element: ");
	scanf("%d",&key);
	flag=binary_search(a,0,n-1,key);
	if(flag==0){
		printf("search unsuccesfull!!!");
	}
	else
	 printf("Search successfull and element found on position %d\n",flag+1);
	return 0;
}