#include<stdlib.h>
#include<stdio.h>

  //dizimizi oluþturup elemanlarý atýyoruz.
    int arr[] = {1363, 1453, 1071, 1922, 1176, 1301, 1915};
    //dizimizin boyutunu hesaplýyoruz.
    int size = sizeof(arr)/sizeof(arr[0]);
  //sorun yokkk
 
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    //Sol ve sað dizi için deðiþkenker
    int n1 = m - l + 1;
    int n2 =  r - m;
  
    //Geçici dizilerimiz, boyutlarý dizimizi ikiye böleceðimiz esasýna göre oluþturuyoruz.
    int L[n1], R[n2];
  
   //Aþaðýdaki iki döngü geçici dizilerimize elemanlarý atýyor.
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
  
    //Yukarýda yaptýðýmýz iþlemlerden ötürü deðiþkenlerimizin sayýlarý deðiþti, burada fabrika ayarlarýna döndürüyoruz.
    i = 0; 
    j = 0;
    k = l;
 
    //Esas birleþtirme mevzusu burada dönüyor. 
    //sol ve sað dizide eleman oldukça döngümüz dönecek
    while (i < n1 && j < n2)
    {
        //Eðer sol dizinin i. indisindeki eleman, sað dizinin j. indisindeki elemandan küçük eþitse 
        //yeni oluþturulacak dizinin ilk elemaný sol dizinin ilk elemaný oluyor.
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        //Yok deðilse sað dizinin ilk elemaný yeni dizimizin ilk elemaný oluyor.
        else
        {
            arr[k] = R[j];
            j++;
        }
        //dikkat edin, k deðiþkenini her durumda artýrýyoruz.
        k++;
       
    }
  
    //Eðer atama iþlemlerinden sonra sol dizide boþta eleman kaldýysa boþta kalan yerlere yerleþtiriyoruz.
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
  
     //Eðer atama iþlemlerinden sonra sað dizide boþta eleman kaldýysa boþta kalan yerlere yerleþtiriyoruz.
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
    //sol saðdan küçükse statement'a gider, bu þartý koymasaydýk en küçük parçalara ayrýlmasýnýn kontrolünü yapamazdýk..
    if (l < r)
    {
        //dizinin ortasýný hesaplýyoruz. 
        int m = l+(r-l)/2;
  
         
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
         
        //Esas  fonksiyona dizimizi, sol indisi, orta indisi ve sað indisi parametre olarak yolluyoruz
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
  
  
    
    
     
    //Dizimizi mergeSortisimli fonksiyona gönderiyoruz. Parametre olarak dizimizi, sol minimum indisi ve sað indisi gönderiyoruz.
    mergeSort(arr, 0, size - 1);
  
    //Sýralanmýþ diziyi ekrana basýyoruz.
    
    return 0;
}
