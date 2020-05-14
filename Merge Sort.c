#include<stdlib.h>
#include<stdio.h>

  //dizimizi olu�turup elemanlar� at�yoruz.
    int arr[] = {1363, 1453, 1071, 1922, 1176, 1301, 1915};
    //dizimizin boyutunu hesapl�yoruz.
    int size = sizeof(arr)/sizeof(arr[0]);
  //sorun yokkk
 
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    //Sol ve sa� dizi i�in de�i�kenker
    int n1 = m - l + 1;
    int n2 =  r - m;
  
    //Ge�ici dizilerimiz, boyutlar� dizimizi ikiye b�lece�imiz esas�na g�re olu�turuyoruz.
    int L[n1], R[n2];
  
   //A�a��daki iki d�ng� ge�ici dizilerimize elemanlar� at�yor.
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
  
    //Yukar�da yapt���m�z i�lemlerden �t�r� de�i�kenlerimizin say�lar� de�i�ti, burada fabrika ayarlar�na d�nd�r�yoruz.
    i = 0; 
    j = 0;
    k = l;
 
    //Esas birle�tirme mevzusu burada d�n�yor. 
    //sol ve sa� dizide eleman olduk�a d�ng�m�z d�necek
    while (i < n1 && j < n2)
    {
        //E�er sol dizinin i. indisindeki eleman, sa� dizinin j. indisindeki elemandan k���k e�itse 
        //yeni olu�turulacak dizinin ilk eleman� sol dizinin ilk eleman� oluyor.
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        //Yok de�ilse sa� dizinin ilk eleman� yeni dizimizin ilk eleman� oluyor.
        else
        {
            arr[k] = R[j];
            j++;
        }
        //dikkat edin, k de�i�kenini her durumda art�r�yoruz.
        k++;
       
    }
  
    //E�er atama i�lemlerinden sonra sol dizide bo�ta eleman kald�ysa bo�ta kalan yerlere yerle�tiriyoruz.
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
  
     //E�er atama i�lemlerinden sonra sa� dizide bo�ta eleman kald�ysa bo�ta kalan yerlere yerle�tiriyoruz.
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
     printArray();
}
  
 
void mergeSort(int arr[], int l, int r)
{
    //sol sa�dan k���kse statement'a gider, bu �art� koymasayd�k en k���k par�alara ayr�lmas�n�n kontrol�n� yapamazd�k..
    if (l < r)
    {
        //dizinin ortas�n� hesapl�yoruz. 
        int m = l+(r-l)/2;
  
         
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
         
        //Esas  fonksiyona dizimizi, sol indisi, orta indisi ve sa� indisi parametre olarak yolluyoruz
        merge(arr, l, m, r);
        
    }
    
}
  
//Diziyi ekrana basan fonksiyon
int k=1;
void printArray()
{
	printf("%d.adim = ",k);
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("\n");
    k=k+1;
}
  
 
int main()
{
  
  
    
    
     
    //Dizimizi mergeSortisimli fonksiyona g�nderiyoruz. Parametre olarak dizimizi, sol minimum indisi ve sa� indisi g�nderiyoruz.
    mergeSort(arr, 0, size - 1);
  
    //S�ralanm�� diziyi ekrana bas�yoruz.
    
    return 0;
}
