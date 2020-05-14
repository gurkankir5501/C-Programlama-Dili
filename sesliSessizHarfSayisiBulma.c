#include <stdio.h>

void foo(char array[],int size){
	
	int fark = 'a' - 'A';
	for(int i=0;i<size;i++){
		
        if (array[i] >= 'A' && array[i] <= 'Z') {
            array[i] =array[i] + fark;
        }
    }
	
	int vowels=0;
	int consonants=0;
	for(int i=0;array[i]!='\0';i++){
		
		if(array[i]=='a' || array[i]=='e'|| array[i]=='i' || array[i]=='u' || array[i]=='o'){
			
			vowels=vowels+1;		
		}
		else {
			
			consonants =consonants+1;
		}
	}
	printf("Toplam Sesli Harf Sayisi : %d\n",vowels);
	printf("Toplam Sessiz Harf Sayisi : %d",consonants);
}

int main(){
	
	int size=100;
	char array[size];
	
	printf("(Turkce karakter kullanmayiniz !!!)\nKarakter Dizisi Giriniz : ");
	scanf("%s",array);
	foo(array,size);
	
}
