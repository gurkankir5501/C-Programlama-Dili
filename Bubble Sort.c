#include <stdio.h>

int myArray[]={1363, 1453, 1071, 1922, 1176, 1301, 1915};

int SIZE =7;
 // sorun yokkkk
//Kabarc�k s�ralama fonksiyonumuz, parametre olarak dizimizi g�nderiyoruz.
void bubbleSort(int x[])
{
    int i, j;
 
    //iterasyonlar�n oldu�u d�� d�ng�
    for(i = 1; i < SIZE; i++)
    {
        //Her iterasyonda elemanlar� kar��la�t�racak olan i� d�ng�
        for( j = 0; j < SIZE - 1; j++)
        {
            //iki eleman aras�nda kar��la�t�rma yap�yor e�er soldaki (i) sa�daki say�dan (i+1)'den b�y�kse swap yap�lacak'
            if(myArray[j] > myArray[j+1]){
		
                //swap fonksiyonunu �a��r�yoruz.
                swapf(j, j+1);
                printSorted();
            }
        }
    }
}
 int k=1;
//dizimizin elemanlar�n� ekrana basan fonksiyon
void printSorted()
{
	printf("%d.adim = ",k);
    int i;
    for( i = 0; i < SIZE ; i++)
    {
        printf("%d,", myArray[i]);
    }
    k=k+1;
    printf("\n");
    printf("\n");
    
}
 
//swap yani yer de�i�tirme fonksiyonumuz.
//Bu fonksiyon direkt global de�i�ken olan dizimiz �zerinde i�lem yap�yor, ondan void
void swapf(int x, int y)
{
    int temp;
    temp = myArray[x];
    myArray[x] = myArray[y];
    myArray[y] = temp;
 
}

 
//ilgili fonksiyonlar� �a��rd���m�z main fonksiyonu
int main()
{
   
    bubbleSort(myArray);
    
    return 0;
}
