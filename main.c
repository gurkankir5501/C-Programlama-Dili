#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct urunler {
   
   int barkod;
   int adet;
   char urunAdi[20];
   char kategori[20];
   int birimFiyat;
   struct urunler* next;
   
};

struct urunler* temp=NULL;
struct urunler* temp2=NULL;
int toplamTutar=0;

int barkodOlustur(){
	
	int barkod;
	srand(time(NULL)); 
	barkod=100+rand()%900;
	
	return barkod;
}

void urunKayit(struct urunler* urun){
	
	
	
	FILE *txtBarkodFILE=fopen("barkod.txt","a");
	fprintf(txtBarkodFILE,"%d\t",urun->barkod);
	fprintf(txtBarkodFILE,"%s\t",urun->urunAdi);
	fprintf(txtBarkodFILE,"%s\t",urun->kategori);
	fprintf(txtBarkodFILE,"%d\t",urun->birimFiyat);
	fprintf(txtBarkodFILE,"\n");
	
	fclose(txtBarkodFILE);
}

void tarayici(){
	
	FILE *txtBarkodFILE=fopen("barkod.txt","r");
	if(txtBarkodFILE=fopen("barkod.txt","r")){
		
		int barkod;
		char ad[20];
		char kategori[20];
		int fiyat;
		
		printf("\n");
		printf("-------------------- Urunlerin Listesi ------------------------\n");
		printf("\n");
		while(!feof(txtBarkodFILE)){
			
			fscanf(txtBarkodFILE,"%d",&barkod);
			fscanf(txtBarkodFILE,"%s",&ad);
			fscanf(txtBarkodFILE,"%s",&kategori);
			fscanf(txtBarkodFILE,"%d\n",&fiyat);
			
			printf("Barkod No : %d  ",barkod);
			printf("Urun : %s  ",ad);
			printf("Kategori : %s  ",kategori);
			printf("Fiyati : %d\n",fiyat);
		}
		printf("\n");
	}
	else{
	
		printf("\n");
	printf("Sistemde Kayitli Urun Bulunmamaktadir!..\n");
	}
	fclose(txtBarkodFILE);
}


void yazici(struct urunler* urun,int barkod,int adet){
	
	FILE *txtBarkodFILE=fopen("barkod.txt","r");
	if(txtBarkodFILE=fopen("barkod.txt","r")){
		
		int result=0;
		while(!feof(txtBarkodFILE)){
			
			fscanf(txtBarkodFILE,"%d %s %s %d",&(urun->barkod),&(urun->urunAdi),&(urun->kategori),&(urun->birimFiyat));
			urun->adet=adet;
			urun->next=NULL;
			
			if((urun->barkod)==barkod){
				
				
				if(temp==NULL){
					
					temp=urun;
				}
				else{
					
					temp2=temp;
					while(temp2->next!=NULL){
						
						temp2=temp2->next;
					}
					temp2->next=urun;
				}
				
				toplamTutar=toplamTutar+(urun->birimFiyat)*adet;
				
				while(1==1){
			
					int secim;
					printf("Siparisi tamamlamak icin 1 \n");
					printf("Alisverise devam etmek icin 0\n");
					printf("Seciminiz : ");
					scanf("%d",&secim);
						
					if(secim==1){
							
						time_t timer = time(NULL);
	
						FILE *txtFaturaFILE=fopen("fatura.txt","a");
						fprintf(txtFaturaFILE,"%s","Urun Bilgileri :\n");
						
						temp2=temp;
						while(temp2!=NULL){
							
							fprintf(txtFaturaFILE,"%d\t",temp2->barkod);
							fprintf(txtFaturaFILE,"%s\t",temp2->urunAdi);
							fprintf(txtFaturaFILE,"%s\t",temp2->kategori);
							fprintf(txtFaturaFILE,"%d\t",temp2->birimFiyat);
							fprintf(txtFaturaFILE," X %d\n",temp2->adet);
							
							temp2=temp2->next;
						}
						fprintf(txtFaturaFILE,"Fatura Tarihi : %s\n",ctime(&timer));
						fprintf(txtFaturaFILE,"Toplam Tutar: %d\n",toplamTutar);
						fprintf(txtFaturaFILE,"%s\n","--------------------------------------------------------------------");
						fclose(txtFaturaFILE);
						printf("Faturaniz Olusturuldu.\n");
						
						while(temp!=NULL){
			
			
							if(temp->next==NULL){
								
								free(temp);
								temp=NULL;
							}
							else{
								temp2=temp;
								while(temp2->next->next!=NULL){
									
									temp2=temp2->next;
								}
								free(temp2->next);
								temp2->next=NULL;
							}
						}
						
						toplamTutar=0;
						break;
					}
					else if(secim==0){
						
						break;
					}
					else{
							
						printf("Hatali secim yaptiniz , Tekrar deneyiniz !!!\n");
					}
				}
				
				result=1;
				break;
			}	
		}
		
		if(result==0){
			
			printf("\n");
			printf("sistem de kayitli boyle bir urun bulunmamaktadir\n");	
		}
		
			
	}
	else{
	
	printf("\n");
	printf("Sistem de Kayitli Urun Bulunmamaktadir!..\n");
	}
	fclose(txtBarkodFILE);
}



int main(){
	
	printf("Market Otomatik Odeme Sistemine Hosgeldiniz\n");
	while(1==1){
		
		printf("------------------------------------ \n");
		printf("1 . Urun Ekleme \n");
		printf("2 . Urun Listeleme \n");
		printf("3 . Urun Satin Alma \n");
		printf("0 . Cikis Yap \n");
		printf("------------------------------------ \n");
		int islem;
		printf("Yapmak istediginiz islemi seciniz : ");
		scanf("%d",&islem);
		
		if(islem==1){
			
			struct urunler *urun =(struct urunler *)malloc(sizeof(struct urunler));
			
			urun->barkod=barkodOlustur();
			
			printf("Urun Adi Giriniz : ");
			scanf("%s",&(urun->urunAdi));
			
			printf("Urun Kategori Giriniz : ");
			scanf("%s",&(urun->kategori));
			
			printf("Urun Birim Fiyat Giriniz : ");
			scanf("%d",&(urun->birimFiyat));

			urunKayit(urun);
			free(urun);
			printf("\n");
			printf("Urun Sisteme Basarili Bir sekilde Kayit Edilmistir.\n");	
		}
		else if(islem==2){
			
			
			tarayici();
			
		}
		else if(islem==3){
			
			struct urunler *urun2 =(struct urunler *)malloc(sizeof(struct urunler));
			
			int barkod;
			printf("Urunun barkod numarasini giriniz : ");
			scanf("%d",&barkod);
			
			int adet;
			printf("Adet Giriniz : ");
			scanf("%d",&adet);
			
			yazici(urun2,barkod,adet);
			
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
