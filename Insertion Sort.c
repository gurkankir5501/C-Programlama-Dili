#include <stdio.h>

int arr[]={1363,1453,1071,1922,1176,1301,1915};
int size=7;
//sorun yok
void insertionSort(int arr[], int n)
{
   int i, deger, j;
   for (i = 1; i < n; i++)
   {
       deger = arr[i];
       j = i-1;
 
       
       while (j >= 0 && arr[j] > deger)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
      
       arr[j+1] = deger;
        printSorted();
   }
}

int k=1;
void printSorted()
{
	printf("%d.adim = ",k);
    int i;
    for( i = 0; i < size; i++)
    {
        printf("%d,", arr[i]);
    }
    k=k+1;
    printf("\n");
    printf("\n");
}


int main(){
	
	insertionSort(arr,size);
	
	return 0;
}

