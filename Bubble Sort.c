#include <stdio.h>

int myArray[]={1363, 1453, 1071, 1922, 1176, 1301, 1915};

int SIZE =7;
 // sorun yokkkk
//Kabarcýk sýralama fonksiyonumuz, parametre olarak dizimizi gönderiyoruz.
void bubbleSort(int x[])
{
    int i, j;
 
    //iterasyonlarýn olduðu dýþ döngü
    for(i = 1; i < SIZE; i++)
    {
        //Her iterasyonda elemanlarý karþýlaþtýracak olan iç döngü
        for( j = 0; j < SIZE - 1; j++)
        {
            //iki eleman arasýnda karþýlaþtýrma yapýyor eðer soldaki (i) saðdaki sayýdan (i+1)'den büyükse swap yapýlacak'
            if(myArray[j] > myArray[j+1]){
		
                //swap fonksiyonunu çaðýrýyoruz.
                swapf(j, j+1);
                printSorted();
            }
        }
    }
}
 int k=1;
//dizimizin elemanlarýný ekrana basan fonksiyon
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
 
//swap yani yer deðiþtirme fonksiyonumuz.
//Bu fonksiyon direkt global deðiþken olan dizimiz üzerinde iþlem yapýyor, ondan void
void swapf(int x, int y)
{
    int temp;
    temp = myArray[x];
    myArray[x] = myArray[y];
    myArray[y] = temp;
 
}

 
//ilgili fonksiyonlarý çaðýrdýðýmýz main fonksiyonu
int main()
{
   
    bubbleSort(myArray);
    
    return 0;
}
