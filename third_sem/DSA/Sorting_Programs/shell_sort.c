#include <stdio.h>    
/* function for implementing shellSort */  
int shell(int a[], int b)  
{  
    /* Rearranging the elements of array at n/2, n/4, ..., 1 intervals */  
    for (int interval = b/2; interval > 0; interval /= 2)  
    {  
        for (int i = interval; i < b; i += 1)  
        {  
            /* store a[i] to the tempvar variable and make the ith position empty */  
            int tempvar = a[i];  
            int j;        
            for (j = i; j >= interval && a[j - interval] > tempvar; j -= interval)  
                a[j] = a[j - interval];  
              
            // put tempvar which is a[i] in its correct position  
            a[j] = tempvar;  
        }  
    }  
    return 0;  
}  
void printArr(int a[], int b) /* function to print the array elements */  
{  
    int i;  
    for (i = 0; i < b; i++)  
        printf("%d ", a[i]);  
}    
int main()  
{  
    int a[] = { 303, 11, 55, 80, 13, 18, 22, 22 };  
    int b = sizeof(a) / sizeof(a[0]);  
    printf("Before sorting array elements are - \n");  
    printArr(a, b);  
    shell(a, b);  
    printf("\nAfter applying shell sort, the array elements are - \n");    
    printArr(a, b);  
    return 0;  
} 
