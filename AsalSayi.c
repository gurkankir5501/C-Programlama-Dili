#include <stdio.h>
#include <stdlib.h>


//Struct yapýsý olusturuldu.
struct asalSayilar {				
   									
   int asalSayi;
   struct asalSayilar* next;
};

//start deðiþkeni dinamik dizinin adresini tutuyor.
struct asalSayilar* start=NULL;
//temp deðiþkeni gecici iþlemler için kullandýðýmýz deðiþken
struct asalSayilar* temp=NULL;


//Kullanýcýnýn girdiði sayýya kadar olan asal sayýlarý bulan fonksiyon
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
			
			//kullanýcýnýn girdiði sayýya kadar,olan sayýlardan asal olanlarý dinamik diziye ekliyoruz
			dinamikDizi(i);
		}    
	}
	
}

//Asal sayýlarý dinamik diziye ekleme fonksiyonu
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

//Belleðe baðlantýlý liste þeklinde eklediðimiz dinamik dizideki verileri bellekten temizleme fonksiyonu
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

//Dinamik dizi içindeki asal sayýlarý asalsayilar.txt dosyasýna yazan fonksiyon
void textYazdir(int sayi){
	
	FILE *txtFILE=fopen("asalsayilar.txt","a");
	
	fprintf(txtFILE,"%s %d %s\n","Girdiginiz",sayi,"sayýsýna kadar olan bütün asal sayýlar listelenmektedir...");
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


//Programýn baþlangýç fonksiyonu
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
			//dinamik dizi de ki veriler ile iþimiz bittikten sonra bellek'den temizliyoruz
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
