#include <stdio.h>
int myArray[]={1363, 1453, 1071, 1922, 1176, 1301, 1915};
int SIZE=7;
 
//fonksiyonuma dizi parametresi g�nderiyoruz.
void selectionSort(int x[])
{
    //i� d�ng� ve d�� d�ng� i�in de�i�kenker.
    int i, j;
    //Anahtar de�er.
    int key;
 
    //D�� d�ng�m�z ba�l�yor.
    for( i = 0; i < SIZE; i++)
    {
        //Her ad�mda anahtar de�er belirliyoruz
        key = i;
 
        //Anahtar de�erin sa��ndaki say�larla kar��la�t�rma yapaca��m�z i�in i+1'den ba�l�yoruz.
        //Soldaki say�lar zaten s�ral� hale geliyor.
        for(j = i + 1; j < SIZE; j++) { if(myArray[key] > myArray[j])
            {
                //dizide key de�erinden daha k���k bir say� buldu�umuzda key de�erine at�yoruz.
                key = j;
            }
 
        }
        //Yer de�i�tirme fonksiyonumuzu �a��r�yoruz. Dikkat edin parametre olarak say�lar� de�il, indisleri g�nderiyoruz.
        printSorted();
        swapf(i, key);
        
    }
}
 
//x ve y parametleri indistir, dizinin ilgili indislerindeki de�erleri swap eden fonksiyon.
void swapf(int x, int y)
{
    int temp;
    temp = myArray[x];
    myArray[x] = myArray[y];
    myArray[y] = temp;
 
}
 
 int k=1;
//S�ralanm�� diziyi ekrana bast�ran fonksiyon.
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
 
 

//Bu da bizim main fonksiyonu, yaln�zca olu�turdu�umuz fonksiyonlar� �a��r�yoruz.
int main()
{
    
    selectionSort(myArray);
    
    return 0;
}
