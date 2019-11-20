#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define uzunluk 10
int dizi[uzunluk-1];

int top = -1;

bool doluMu(){
	
	if(top>=uzunluk-1){
		
		return true;
	}
	else{
		
		return false;
	}
	
}

bool bosMu(){
	
	if(top<0){
		
		return true;
	}
	else{
		
		return false;
	}
}

void elemanEkle(int eleman){
	
	bool kontrol =doluMu();
	if(kontrol==true){
		
		printf("dizimiz dolu oldugu icin eklenemiyor !!!");
	}
	else{
		
		top = top+1;
		dizi[top]=eleman;
	}
}

void elemanSil(){
	
	bool kontrol=bosMu();
	if(kontrol == true){
		
		printf("dizimiz bos oldugu icin silme islemi gerceklestirilemiyor !!!");
	}
	else{
		
		top = top-1;
		printf("silme islemi basariliyla tamamlandi !!! \n");
	}
}

void yazdir(){
	
	int i;
	for(i=0;i<top+1;){
		
		printf("%d. indisimiz => %d \n " ,i,dizi[i]);
		i = i+1;
	}
}

int main(){
	
	int islem;
	int eklenecekEleman;
	while(1==1){
		
		printf("1 : eleman eklemek icin\n");
		printf("2 : eleman silmek icin\n");
		printf("3 : cikmak icin\n");
		printf("lutfen yapmak istediginiz islemi secin :");
		scanf("%d",&islem);
		int eklenecekEleman;
		switch(islem){
		
			case 1:
				
				printf("eklenemek istediginiz sayiyi giriniz : ");
				scanf("%d",&eklenecekEleman);
				elemanEkle(eklenecekEleman);
				yazdir();
				printf("\n");
				break;
			
			case 2:
			 
				elemanSil();
				yazdir();
				printf("\n");
				break;
				
			case 3:
			
			printf("cikiliyor!!!");
			exit(0);	
		}
	}
	
	
}
