#include <stdio.h>
int myArray[]={1363, 1453, 1071, 1922, 1176, 1301, 1915};
int SIZE=7;
 
//fonksiyonuma dizi parametresi gönderiyoruz.
void selectionSort(int x[])
{
    //iç döngü ve dýþ döngü için deðiþkenker.
    int i, j;
    //Anahtar deðer.
    int key;
 
    //Dýþ döngümüz baþlýyor.
    for( i = 0; i < SIZE; i++)
    {
        //Her adýmda anahtar deðer belirliyoruz
        key = i;
 
        //Anahtar deðerin saðýndaki sayýlarla karþýlaþtýrma yapacaðýmýz için i+1'den baþlýyoruz.
        //Soldaki sayýlar zaten sýralý hale geliyor.
        for(j = i + 1; j < SIZE; j++) { if(myArray[key] > myArray[j])
            {
                //dizide key deðerinden daha küçük bir sayý bulduðumuzda key deðerine atýyoruz.
                key = j;
            }
 
        }
        //Yer deðiþtirme fonksiyonumuzu çaðýrýyoruz. Dikkat edin parametre olarak sayýlarý deðil, indisleri gönderiyoruz.
        printSorted();
        swapf(i, key);
        
    }
}
 
//x ve y parametleri indistir, dizinin ilgili indislerindeki deðerleri swap eden fonksiyon.
void swapf(int x, int y)
{
    int temp;
    temp = myArray[x];
    myArray[x] = myArray[y];
    myArray[y] = temp;
 
}
 
 int k=1;
//Sýralanmýþ diziyi ekrana bastýran fonksiyon.
void printSorted()
{
	printf("%d.adim = ",k);
    int i;
    for( i = 0; i < SIZE; i++)
    {
        printf("%d,", myArray[i]);
    }
    printf("\n");
    k=k+1;
}
 
 

//Bu da bizim main fonksiyonu, yalnýzca oluþturduðumuz fonksiyonlarý çaðýrýyoruz.
int main()
{
    
    selectionSort(myArray);
    
    return 0;
}
