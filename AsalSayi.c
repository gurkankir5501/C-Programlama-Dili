#include <stdio.h>
#include <stdlib.h>


//Struct yap�s� olusturuldu.
struct asalSayilar {				
   									
   int asalSayi;
   struct asalSayilar* next;
};

//start de�i�keni dinamik dizinin adresini tutuyor.
struct asalSayilar* start=NULL;
//temp de�i�keni gecici i�lemler i�in kulland���m�z de�i�ken
struct asalSayilar* temp=NULL;


//Kullan�c�n�n girdi�i say�ya kadar olan asal say�lar� bulan fonksiyon
void asalSayiMi(int sayi){
	
	for(int i=2;i<=sayi;i++){
		
		int result=0;
		for(int j=2;j<i;j++){
			
			if((i%j==0)){
			
				result=1;
				break;	
			}
    	}
		if(result==0){
			
			//kullan�c�n�n girdi�i say�ya kadar,olan say�lardan asal olanlar� dinamik diziye ekliyoruz
			dinamikDizi(i);
		}    
	}
	
}

//Asal say�lar� dinamik diziye ekleme fonksiyonu
void dinamikDizi(int sayi){
	
	struct asalSayilar *newSayi =(struct asalSayilar *)malloc(sizeof(struct asalSayilar));
	
	newSayi->asalSayi=sayi;
	newSayi->next=NULL;
	
	if(start==NULL){
		
		start=newSayi;
	}
	else{
		
		temp=start;
		while(temp->next!=NULL){
			
			temp=temp->next;
		}
		temp->next=newSayi;
	}
}

//Belle�e ba�lant�l� liste �eklinde ekledi�imiz dinamik dizideki verileri bellekten temizleme fonksiyonu
void diziyiTemizle(){
	
	temp=start;
	while(temp!=NULL){
			
			
		if(temp->next==NULL){
								
			free(temp);
			free(start);
			temp=NULL;
			start=NULL;
		}
		else{
					
			while(temp->next->next!=NULL){
									
				temp=temp->next;
			}
			free(temp->next);
			temp->next=NULL;
		}
	}
}

//Dinamik dizi i�indeki asal say�lar� asalsayilar.txt dosyas�na yazan fonksiyon
void textYazdir(int sayi){
	
	FILE *txtFILE=fopen("asalsayilar.txt","a");
	
	fprintf(txtFILE,"%s %d %s\n","Girdiginiz",sayi,"say�s�na kadar olan b�t�n asal say�lar listelenmektedir...");
	temp=start;
	while(temp!=NULL){
		
		printf("%d-",temp->asalSayi);
		fprintf(txtFILE,"%d-",temp->asalSayi);
		temp=temp->next;
	}	
	
	fprintf(txtFILE,"\n");
	fclose(txtFILE);
	printf("\n");
}


//Program�n ba�lang�� fonksiyonu
int main(){
	
	
	while(1==1){
		
		printf("------------------------------------ \n");
		printf("Asal Sayi Hesaplama programina Hosgeldiniz \n");
		printf("1 . Asal sayilari hesaplama \n");
		printf("0 . Cikis Yap \n");
		printf("------------------------------------ \n");
		int islem;
		printf("Yapmak istediginiz islemi giriniz: ");
		scanf("%d",&islem);
		if(islem==1){
			
			int sayi;
			printf("Sayi Giriniz : ");
			scanf("%d",&sayi);
			printf("Asal Sayilar Basarili Sekilde Bulunmustur.\n");
			asalSayiMi(sayi);
			textYazdir(sayi);
			//dinamik dizi de ki veriler ile i�imiz bittikten sonra bellek'den temizliyoruz
			diziyiTemizle();
		}
		else if(islem==0){
			
			printf("Sistemden basarili bir sekilde cikis yaptiniz .");
			break;
		}
		else{
			
			printf("Hatali giris yaptiniz , Tekrar secim yapiniz . \n");
		}
	}
}
