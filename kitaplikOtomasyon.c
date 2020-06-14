#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include <time.h>

struct musteri{
	char tcno[11];
	char ad[50];
	char soyad[50];
	char adres[100];
};
struct users{
	char username[30];
	char password[30];
};
struct Bookinfo{
	char book_name[20];
	char author[20];
	char type[15];
	char printing[15];
	int pagecount;
};
struct Gazeteinfo{
	char name[20];
	double fiyat;
	int pagecount;
};
struct Dergiinfo{
	char name[20];
	char author[20];
	char type[15];
	char printing[15];
	int pagecount;
	double fiyat;
};
struct Kirtasiyeinfo{
	char name[20];
	double fiyat;
	char type[15];
};

struct urunler {
   
   int barkod;
   char urunAdi[20];
   char kategori[20];
   int birimFiyat;
   int adet;
   struct urunler* next;
   
};


	 char username[30];
 	char password[30];
 int Login(struct users user_login)
 {
     puts("..::: Giris Sayfasi :::..");
     int returntype=0;
 	printf("kullanici adi:");
 	gets(user_login.username);
 	printf("parola:");
 	gets(user_login.password);

   
 	FILE *users;
 	users=fopen("users.txt","r");
 	while(!feof(users))
    {
        fscanf(users,"%s %s\n",username,password);
        if(strcmp(username,user_login.username)==0 &&strcmp(password,user_login.password)==0)
        {
            returntype=1;
            
            break;
        }
    }
 	fclose(users);
 	return returntype;
 }
 void Kaydol(struct users user)
 {
     puts("..::: Kayit Ekrani :::..");
 	printf("kullanici adi:");
 	gets(user.username);

 	printf("parola:");
 	gets(user.password);

 	FILE *userDB;
 	userDB=fopen("users.txt","a");
 	fprintf(userDB,"%s %s\n",user.username,user.password);
 	fclose(userDB);
 }

   void gazeteAra(struct Gazeteinfo gazeteinfo)
{
    puts("..::: Gazete ARAMA SAYFASI :::..");
    char name[20];
    char temp[20]="";
    printf("Gazete isim:");
 	gets(name);

 	int i=1;
   puts("ID   isim              sayfa sayisi Fiyat");
   FILE *gazeteDB;
   gazeteDB=fopen("gazete.txt","r");
   while(!feof(gazeteDB))
    {
        fscanf(gazeteDB,"%s %d %lf\n",gazeteinfo.name,&gazeteinfo.pagecount,&gazeteinfo.fiyat);
        strncpy(temp, gazeteinfo.name,strlen(name));
        if(strcmp(name,temp)==0)
        {
            printf("%-4d %-20s %-6d %.2lf\n",i,gazeteinfo.name,gazeteinfo.pagecount,gazeteinfo.fiyat);
            i++;
        }
    }
 	fclose(gazeteDB);
}
 void gazeteList(struct Gazeteinfo gazeteinfo)
{
    puts("..::: Gazete LISTELEME SAYFASI :::..");
    int i=1;
   puts("ID   isim              sayfa sayisi Fiyat");
   FILE *gazeteDB;
   gazeteDB=fopen("gazete.txt","r");
   while(!feof(gazeteDB))
    {
        fscanf(gazeteDB,"%s %d %lf\n",gazeteinfo.name,&gazeteinfo.pagecount,&gazeteinfo.fiyat);
            printf("%-4d %-20s %-6d %.2lf\n",i,gazeteinfo.name,gazeteinfo.pagecount,gazeteinfo.fiyat);
        i++;
    }
 	fclose(gazeteDB);
 	puts("");
}
void gazeteAdd(struct Gazeteinfo gazeteinfo)
{
    puts("..::: Gazete EKLEME SAYFASI :::..");
    printf("Gazete ismi:");
 	gets(gazeteinfo.name);
    printf("Sayfa Sayisi:");
 	scanf("%d",&gazeteinfo.pagecount);
 	printf("fiyat:");
 	scanf("%lf",&gazeteinfo.fiyat);

 	FILE *gazeteDB;
 	gazeteDB=fopen("gazete.txt","a");
 	fprintf(gazeteDB,"%s %d %lf\n",gazeteinfo.name,gazeteinfo.pagecount,gazeteinfo.fiyat);
 	fclose(gazeteDB);
}

void gazeteSatinAl()
{
	
	char name[20];
	double fiyat;
	int pagecount;
	int result=0;
	puts("..::: Gazete Al :::..");
	char gazete_name[20];
	printf("Almak istediginiz Gazete Adini giriniz ");
	scanf("%s",gazete_name);
	
	FILE *gazete;
    gazete=fopen("gazete.txt","r");
    FILE *satis;
 	satis=fopen("odunc.txt","a");
    while(!feof(gazete))
    {
         fscanf(gazete,"%s %d %lf\n",name,&pagecount,&fiyat);
        
        if(strcmp(gazete_name,name)==0)
        {
        	fprintf(satis,"%s %s %s\n",username,name,"Gazete");
        	result=1;
        	puts("islem basarili");
        	break;
		}
        
    }
    if(result==0){
    	
    	puts("Sistemde Boyle Bir Gazete Bulunmamaktadir!");
	}
 	fclose(gazete);
 	fclose(satis);
}


void oduncGazeteAl()
{
	
	char name[20];
	double fiyat;
	int pagecount;
	int result=0;
	puts("..:::Gazete Al :::..");
	char gazete_name[20];
	int gun;
	printf("Almak istediginiz Gazete Adini giriniz ");
	scanf("%s",gazete_name);
	printf("Kac gun sonra teslim edeceksiniz ");
	scanf("%d",&gun);
	
	FILE *gazete;
    gazete=fopen("gazete.txt","r");
    FILE *satis;
 	satis=fopen("satislar.txt","a");
    while(!feof(gazete))
    {
         fscanf(gazete,"%s %d %lf\n",name,&pagecount,&fiyat);
        
        if(strcmp(gazete_name,name)==0)
        {
        	fprintf(satis,"%s %s %s %d\n",username,name,"Gazete",gun);
        	result=1;
        	puts("islem basarili");
        	break;
		}
        
    }
    if(result==0){
    	
    	puts("Sistemde Boyle Bir Gazete Bulunmamaktadir!");
	}
 	fclose(gazete);
 	fclose(satis);
}



void gazeteRemove()
{
    
    char name[20];
	double fiyat;
	int pagecount;
	int result=0;
	char gazetename[20];
    printf("Silmek istediginiz gazeteyi giriniz:");
 	scanf("%s",gazetename);

 	
   
   FILE *gazeteDB,*tempp;
   gazeteDB=fopen("gazete.txt","r");
   tempp=fopen("tempp.txt","w");
   int i=0;
   while(!feof(gazeteDB))
    {
    	
        fscanf(gazeteDB,"%s %d %lf\n",name,&pagecount,&fiyat);
        if(strcmp(name,gazetename)==0){
        	
        	puts("Silme islemi Yapildi.");
        	result=1;
		}
		else{
			
			fprintf(tempp,"%s %d %lf\n",name,pagecount,fiyat);
		}
		i++;
    }
    if(result==0){
    	
    	puts ("Kayitli Boyle Bir Gazete Yoktur .");
	}
    fclose(tempp);
 	fclose(gazeteDB);
	remove("gazete.txt");
	FILE *icdoldur;
	if(icdoldur=fopen("gazete.txt","w"))
	{
		if(i==1){
			
			
		}
		else{
			
			FILE *icoku=fopen("tempp.txt","r");
			while(!feof(icoku))
			{
				
				fscanf(icoku,"%s %d %lf\n",name,&pagecount,&fiyat);
				fprintf(icdoldur,"%s %d %lf\n",name,pagecount,fiyat);
				
			}
			fclose(icoku);
		}
		fclose(icdoldur);
		
	}
	remove("tempp.txt");
}

   void dergiAra(struct Dergiinfo dergiinfo)
{
    puts("..::: DERGI ARAMA SAYFASi :::..");
    char name[20];
    char temp[20]="";
    printf("name:");
 	gets(name);

 	int i=1;
   puts("ID   isim              yazar               tur            baský        sayfa Sayisi Fiyat");
   FILE *dergiDB;
   dergiDB=fopen("dergi.txt","r");
   while(!feof(dergiDB))
    {
        fscanf(dergiDB,"%s %s %s %s %d %lf\n",dergiinfo.name,dergiinfo.author,dergiinfo.type,dergiinfo.printing,&dergiinfo.pagecount,&dergiinfo.fiyat);
        strncpy(temp, dergiinfo.name,strlen(name));
        if(strcmp(name,temp)==0)
        {
            printf("%-4d %-20s %-20s %-15s %-15s %d %.2lf\n",i,dergiinfo.name,dergiinfo.author,dergiinfo.type,dergiinfo.printing,dergiinfo.pagecount,dergiinfo.fiyat);
            i++;
        }
    }
 	fclose(dergiDB);
}
 void dergiList(struct Dergiinfo dergiinfo)
{
    puts("..::: DERGI LISTELEME SAYFASI :::..");
    int i=1;
   puts("ID   isim              yazar               tur            baský        sayfa Sayisi Fiyat");
   FILE *dergiDB;
   dergiDB=fopen("dergi.txt","r");
   while(!feof(dergiDB))
    {
        fscanf(dergiDB,"%s %s %s %s %d %lf\n",dergiinfo.name,dergiinfo.author,dergiinfo.type,dergiinfo.printing,&dergiinfo.pagecount,&dergiinfo.fiyat);
        printf("%-4d %-20s %-20s %-15s %-15s %-4d %.2lf\n",i,dergiinfo.name,dergiinfo.author,dergiinfo.type,dergiinfo.printing,dergiinfo.pagecount,dergiinfo.fiyat);
        i++;
    }
 	fclose(dergiDB);
 	puts("");
}

void dergiSatinAl()
{
	
	char name[20];
	char author[20];
	char type[15];
	char printing[15];
	int pagecount;
	double fiyat;
	int result=0;
	puts("..::: Dergi Al :::..");
	char derginame[20];
	printf("Almak istediginiz dergi Adini giriniz");
	scanf("%s",derginame);
	
	FILE *dergi;
    dergi=fopen("dergi.txt","r");
    FILE *satis;
 	satis=fopen("odunc.txt","a");
    while(!feof(dergi))
    {
        fscanf(dergi,"%s %s %s %s %d %lf\n",name,author,type,printing,&pagecount,&fiyat);
        
        if(strcmp(derginame,name)==0)
        {
        	fprintf(satis,"%s %s %s\n",username,name,"Dergi");
        	result=1;
        	puts("islem basarili");
        	break;
		}
        
    }
    if(result==0){
    	
    	puts("Sistemde Boyle Bir dergi Bulunmamaktadir!");
	}
 	fclose(dergi);
 	fclose(satis);
}

void oduncDergiAl()
{
	
	char name[20];
	char author[20];
	char type[15];
	char printing[15];
	int pagecount;
	double fiyat;
	int result=0;
	puts("..::: Dergi Al :::..");
	char derginame[20];
	printf("Almak istediginiz dergi Adini giriniz");
	scanf("%s",derginame);
	int gun;
	printf("Kac gun sonra teslim edeceksiniz ");
	scanf("%d",&gun);
	
	
	FILE *dergi;
    dergi=fopen("dergi.txt","r");
    FILE *satis;
 	satis=fopen("satislar.txt","a");
    while(!feof(dergi))
    {
        fscanf(dergi,"%s %s %s %s %d %lf\n",name,author,type,printing,&pagecount,&fiyat);
        
        if(strcmp(derginame,name)==0)
        {
        	fprintf(satis,"%s %s %s %d\n",username,name,"Dergi",gun);
        	result=1;
        	puts("islem basarili");
        	break;
		}
        
    }
    if(result==0){
    	
    	puts("Sistemde Boyle Bir dergi Bulunmamaktadir!");
	}
 	fclose(dergi);
 	fclose(satis);
}

void dergiAdd(struct Dergiinfo dergiinfo)
{
    puts("..::: DERGI EKLEME SAYFASI :::..");
    printf("dergi ismi:");
 	gets(dergiinfo.name);
 	printf("yazar:");
 	gets(dergiinfo.author);
    printf("tur:");
 	gets(dergiinfo.type);
    printf("baski:");
 	gets(dergiinfo.printing);
    printf("sayfa Sayisi:");
 	scanf("%d",&dergiinfo.pagecount);
 	printf("fiyat:");
 	scanf("%lf",&dergiinfo.fiyat);

 	FILE *dergiDB;
 	dergiDB=fopen("dergi.txt","a");
 	fprintf(dergiDB,"%s %s %s %s %d %lf\n",dergiinfo.name,dergiinfo.author,dergiinfo.type,dergiinfo.printing,dergiinfo.pagecount,dergiinfo.fiyat);
 	fclose(dergiDB);
}

void dergiRemove()
{
    
    char name[20];
	char author[20];
	char type[15];
	char printing[15];
	int pagecount;
	double fiyat;
	int result=0;
	
	char derginame[20];
    printf("Silmek istediginiz dergiyi giriniz:");
 	scanf("%s",derginame);

 	
   
   FILE *dergiDB,*tempp;
   dergiDB=fopen("dergi.txt","r");
   tempp=fopen("tempp.txt","w");
   int i=0;
   while(!feof(dergiDB))
    {
    	
        fscanf(dergiDB,"%s %s %s %s %d %lf\n",name,author,type,printing,&pagecount,&fiyat);
        if(strcmp(name,derginame)==0){
        	
        	puts("Silme islemi Yapildi.");
        	result=1;
		}
		else{
			
			fprintf(dergiDB,"%s %s %s %s %d %lf\n",name,author,type,printing,pagecount,fiyat);
		}
		i++;
    }
    if(result==0){
    	
    	puts ("Kayitli Boyle Bir Dergi Yoktur .");
	}
    fclose(tempp);
 	fclose(dergiDB);
	remove("dergi.txt");
	FILE *icdoldur;
	if(icdoldur=fopen("dergi.txt","w"))
	{
		if(i==1){
			
			
		}
		else{
			
			FILE *icoku=fopen("tempp.txt","r");
			while(!feof(icoku))
			{
				
				 fscanf(icoku,"%s %s %s %s %d %lf\n",name,author,type,printing,&pagecount,&fiyat);
				 fprintf(icdoldur,"%s %s %s %s %d %lf\n",name,author,type,printing,pagecount,fiyat);
			}
			fclose(icoku);
		}
		fclose(icdoldur);
		
	}
	remove("tempp.txt");
}


  void bookAra(struct Bookinfo bookinfo)
{
        puts("..::: KITAP ARAMA SAYFASI :::..");

    char bookname[20];
    char temp[20]="";
    printf("Kitap Adi:");
 	gets(bookname);

 	int i=1;
   puts("ID   Kitap ismi            yazar               Tur            baski        sayfa sayisi");
   FILE *bookDB;
   bookDB=fopen("books.txt","r");
   while(!feof(bookDB))
    {
        fscanf(bookDB,"%s %s %s %s %d\n",bookinfo.book_name,bookinfo.author,bookinfo.type,bookinfo.printing,&bookinfo.pagecount);
        strncpy(temp, bookinfo.book_name,strlen(bookname));
        printf("%s_______\n",temp);
        if(strcmp(bookname,temp)==0)
        {
        printf("%-4d %-20s %-20s %-15s %-15s %d\n",i,bookinfo.book_name,bookinfo.author,bookinfo.type,bookinfo.printing,bookinfo.pagecount);
            i++;
        }
    }
 	fclose(bookDB);
}
 void bookList(struct Bookinfo bookinfo)
{
            puts("..::: KITAP LISTELEME EKRANI :::..");

    int i=1;
   puts("ID   Kitap ismi            yazar               Tur            baski        sayfa sayisi");
   FILE *bookDB;
   bookDB=fopen("books.txt","r");
   while(!feof(bookDB))
    {
        fscanf(bookDB,"%s %s %s %s %d\n",bookinfo.book_name,bookinfo.author,bookinfo.type,bookinfo.printing,&bookinfo.pagecount);
        printf("%-4d %-20s %-20s %-15s %-15s %d\n",i,bookinfo.book_name,bookinfo.author,bookinfo.type,bookinfo.printing,bookinfo.pagecount);
        i++;
    }
 	fclose(bookDB);
 	puts("");
}

void bookSatinAl()
{
	
	char book_name[20];
	char author[20];
	char type[15];
	char printing[15];
	int pagecount;
	int result=0;
	puts("..:::Kitap Al :::..");
	char name[20];
	printf("Almak istediginiz kitabin Adini giriniz ");
	scanf("%s",name);
	
	FILE *bookDB;
    bookDB=fopen("books.txt","r");
    FILE *satis;
 	satis=fopen("odunc.txt","a");
    while(!feof(bookDB))
    {
        fscanf(bookDB,"%s %s %s %s %d\n",book_name,author,type,printing,&pagecount);
        
        if(strcmp(book_name,name)==0)
        {
        	fprintf(satis,"%s %s %s\n",username,book_name,"Kitap");
        	result=1;
        	puts("islem basarili");
        	break;
		}
        
    }
    if(result==0){
    	
    	puts("Sistemde Boyle Bir Kitap Bulunmamaktadir!");
	}
 	fclose(bookDB);
 	fclose(satis);
}

void oduncbookAl()
{
	
	char book_name[20];
	char author[20];
	char type[15];
	char printing[15];
	int pagecount;
	int result=0;
	puts("..:::  Kitap Al :::..");
	char name[20];
	int gun;
	printf("Almak istediginiz kitabin Adini giriniz ");
	scanf("%s",name);
	printf("Kac gun sonra teslim edeceksiniz ");
	scanf("%d",&gun);
	
	FILE *bookDB;
    bookDB=fopen("books.txt","r");
    FILE *satis;
 	satis=fopen("satislar.txt","a");
    while(!feof(bookDB))
    {
        fscanf(bookDB,"%s %s %s %s %d\n",book_name,author,type,printing,&pagecount);
        
        if(strcmp(book_name,name)==0)
        {
        	fprintf(satis,"%s %s %s %d\n",username,book_name,"Kitap",gun);
        	result=1;
        	puts("islem basarili");
        	break;
		}
        
    }
    if(result==0){
    	
    	puts("Sistemde Boyle Bir Kitap Bulunmamaktadir!");
	}
 	fclose(bookDB);
 	fclose(satis);
}

void bookAdd(struct Bookinfo bookinfo)
{
    puts("..::: Kitap Ekle :::..");
    printf("kitap isim:");
 	gets(bookinfo.book_name);
 	printf("yazar:");
 	gets(bookinfo.author);
    printf("tur:");
 	gets(bookinfo.type);
    printf("baski sayisi:");
 	gets(bookinfo.printing);
    printf("sayfa sayisi:");
 	scanf("%d",&bookinfo.pagecount);

 	FILE *bookDB;
 	bookDB=fopen("books.txt","a");
 	fprintf(bookDB,"%s %s %s %s %d\n",bookinfo.book_name,bookinfo.author,bookinfo.type,bookinfo.printing,bookinfo.pagecount);
 	fclose(bookDB);
}

void bookRemove()
{
    
    char book_name[20];
	char author[20];
	char type[15];
	char printing[15];
	int pagecount;
	int result=0;
	
	char bookname[20];
    printf("Silmek istediginiz kitabi giriniz:");
 	scanf("%s",bookname);

 	
   
   FILE *bookDB,*tempp;
   bookDB=fopen("books.txt","r");
   tempp=fopen("tempp.txt","w");
   int i=0;
   while(!feof(bookDB))
    {
    	
       fscanf(bookDB,"%s %s %s %s %d\n",book_name,author,type,printing,&pagecount);
        if(strcmp(bookname,book_name)==0){
        	
        	puts("Silme islemi Yapildi.");
        	result=1;
		}
		else{
			
			fprintf(tempp,"%s %s %s %s %d\n",book_name,author,type,printing,&pagecount);
		}
		i++;
    }
    if(result==0){
    	
    	puts ("Kayitli Boyle Bir Kitap Yoktur .");
	}
    fclose(tempp);
 	fclose(bookDB);
	remove("books.txt");
	FILE *icdoldur;
	if(icdoldur=fopen("books.txt","w"))
	{
		if(i==1){
			
			
		}
		else{
			
			FILE *icoku=fopen("tempp.txt","r");
			while(!feof(icoku))
			{
				
				fscanf(icoku,"%s %s %s %s %d\n",book_name,author,type,printing,&pagecount);
				fprintf(icdoldur,"%s %s %s %s %d\n",book_name,author,type,printing,pagecount);
				
			}
			fclose(icoku);
		}
		fclose(icdoldur);
		
	}
	remove("tempp.txt");
}

void satisList()
{
            puts("..::: Sepetim :::..");
	
	char kullaniciAdi[30];
	char urunAdi[20];
	char tur[20];
    int i=1;
   puts("ID   kullanici Adi      urun Adi        Tur   ");
   FILE *satis;
   satis=fopen("satislar.txt","r");
   while(!feof(satis))
    {
        fscanf(satis,"%s %s %s\n",kullaniciAdi,urunAdi,tur);
       
        if(strcmp(username,kullaniciAdi)==0){
        	
        	printf("%d %-20s %-20s %-15s\n",i,kullaniciAdi,urunAdi,tur);
		}
        i++;
    }
 	fclose(satis);
 	puts("");
}

void oduncList()
{
            puts("..::: Odunc Listesi :::..");
	
	char kullaniciAdi[30];
	char urunAdi[20];
	char tur[20];
	int gun;
    int i=1;
   puts("ID kullanici Adi   urun Adi               Tur             Kac Gun Sonra Teslim Edilecek ");
   FILE *odunc; 
   odunc=fopen("odunc.txt","r");
   while(!feof(odunc))
    {
        fscanf(odunc,"%s %s %s %d\n",kullaniciAdi,urunAdi,tur,&gun);
       
        if(strcmp(username,kullaniciAdi)==0){
        	
        	printf("%d %-20s %-20s %-15s %d\n",i,kullaniciAdi,urunAdi,tur,gun);
		}
        i++;
    }
 	fclose(odunc);
 	puts("");
}

int barkodOlustur(){
	
	int barkod;
	srand(time(NULL)); 
	barkod=100+rand()%900;
	
	return barkod;
}

void satinAl()
{
	
	char kullaniciAdi[30];
	char urunAdi[20];
	char tur[20];
	int gun;
    int tl=2;
    int toplamGun=0;
   FILE *odunc; 
   odunc=fopen("satislar.txt","r");
   time_t timer = time(NULL);
	
	FILE *txtFaturaFILE=fopen("fatura.txt","a");
	fprintf(txtFaturaFILE,"%s","Urun Bilgileri :\n");
   while(!feof(odunc))
    {
        fscanf(odunc,"%s %s %s %d\n",kullaniciAdi,urunAdi,tur,&gun);
       
        if(strcmp(username,kullaniciAdi)==0){
        	
        	fprintf(txtFaturaFILE,"%s\t",kullaniciAdi);
			fprintf(txtFaturaFILE,"%s\t",urunAdi);
			fprintf(txtFaturaFILE,"%s\t",tur);
			fprintf(txtFaturaFILE," %dX%d\n",tl,gun);
        	toplamGun=toplamGun+gun;
		}
        
    }
    fprintf(txtFaturaFILE,"Fatura Tarihi : %s\n",ctime(&timer));
	fprintf(txtFaturaFILE,"Toplam Tutar: %d\n",(toplamGun*2));
	fprintf(txtFaturaFILE,"%s\n","--------------------------------------------------------------------");
	fclose(txtFaturaFILE);
	printf("Faturaniz Olusturuldu.\n");
 	fclose(odunc);
	
}

struct urunler* temp=NULL;
struct urunler* temp2=NULL;
int toplamTutar=0;


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
		
	printf("Aradiginiz Dosya Yok!..\n");
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
					printf("Siparisi Tamamlamak icin 1 \n");
					printf("Alisverise Devam Etmek Ýcin 0\n");
					printf("Seciminiz : ");
					scanf("%d",&secim);
						
					if(secim==1){
							
						time_t timer = time(NULL);
	
						FILE *txtFaturaFILE=fopen("kirtasiyeFatura.txt","a");
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
			
			printf("sistem de kayitli boyle bir urun bulunmamaktadir\n");	
		}
		
			
	}
	else{
		
	printf("Aradiginiz Dosya Yok!..\n");
	}
	fclose(txtBarkodFILE);
}




void kirtasiye(){
	
		printf("Kirtasiye Departmanina Hosgeldiniz\n");
	while(1==1){
		
		printf("------------------------------------ \n");
		printf("Urun Ekleme=1 \n");
		printf("Urun Listeleme=2 \n");
		printf("Urun Satin Alma=3 \n");
		printf("Ana bolume Gecmek=0 \n");
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


int main()
{
    int cevap;
    int page=0;
    int kitap_page=0;
    int menu_page=0;
    int dergi_page=0;
    int gazete_page=0;
    int durumlogin=0;
    char temp;

    struct users user;
    struct Bookinfo bookinfo;
    struct Dergiinfo dergiinfo;
    struct Gazeteinfo gazeteinfo;

    ///////////////////////////////////
    FILE *b,*u,*d,*g,*c;
 	b=fopen("books.txt","at");
 	fclose(b);
 	u=fopen("users.txt","at");
    fclose(u);
 	d=fopen("dergi.txt","at");
    fclose(d);
    g=fopen("gazete.txt","at");
    fclose(g);
    c=fopen("satislar.txt","at");
    fclose(c);
    //.txt dosyalarýný .exe nin çalýþtýðý klasörde oluþturur.
    //////
	puts("              	..::: KITAP MAGZASI YONETIM SISTEMINE HOSGELDINIZ  :::..");
  //////////////////////////////////////////////////////////////////////
    do
    {
        puts("Giris yapmak icin 1'e basiniz ");
        puts("Kayit olmak icin 2'ye basiniz ");
        printf("Secim = ");
        scanf("%d",&cevap);
        scanf("%c",&temp);
        switch(cevap)
        {
            case 1 :
                 durumlogin=Login(user);
                if(durumlogin==1)
                    page=1;
                else
                {
                    printf("Parola hatalý\n");
                }
                break;
            case 2 :
                Kaydol(user);
                page=0;
                break;
        }

    }while(page==0);
    page=0;
/////////////////////////////////////////////////////////////////

       do{
            puts("	..::: KITAP MAGZASI YONETIM SISTEMI  :::..");
        
        puts("Kitap Sayfasi=1");
        puts("Dergi Sayfasi=2");
        puts("Gazete Sayfasi=3");
        puts("Aldiginiz Urunleri Listeleyin=4");
        puts("Odunc Aldiklarinizi Listeleyin=5");
        puts("Kirtasiye Departmanina Gecmek icin=6");
        
        //puts("Kirtasiye Page=4");
        printf("Secim=");
        scanf("%d",&cevap);
        scanf("%c",&temp);
        switch(cevap)
        {
            case 1 :
                kitap_page=0;
                 do{
                      puts("Ana menu=0");
        puts("Kitap Ekle=1");
        puts("Kitap Sil=2");
        puts("Kitap Listele=3");
        puts("Kitap Ara=4");
        puts("Kitap Satin Al=5");
         puts("Odunc Kitap Al=6");
         puts("Fatura olustur=7");
        printf("Secim=");
        scanf("%d",&cevap);
        scanf("%c",&temp);
        switch(cevap)
        {
        case 0 :
            kitap_page=1;
            break;
            case 1 :
                bookAdd(bookinfo);
                break;
            case 2 :
                bookRemove();
                break;
            case 3 :
                bookList(bookinfo);
                break;
            case 4 :
                bookAra(bookinfo);
                break;
            case 6 :
                bookSatinAl();
                break;
            case 5 :
                oduncbookAl();
                break;
            case 7 :
                satinAl();
                break;
        }

    }while(kitap_page==0);
                break;
            case 2 :
                dergi_page=0;
                 do{
                      puts("Ana menu=0");
        puts("Dergi Ekle=1");
        puts("Dergi Sil=2");
        puts("Dergi Listele=3");
        puts("Dergi Ara=4");
        puts("Dergi Satin Al=5");
        puts("Odunc Dergi Satin Al=6");
        puts("fatura Olustur=7");
        printf("Secim=");
        scanf("%d",&cevap);
        scanf("%c",&temp);
        switch(cevap)
        {
        case 0 :
            dergi_page=1;
            break;
            case 1 :
                dergiAdd(dergiinfo);
                break;
            case 2 :
                dergiRemove();
                break;
            case 3 :
                dergiList(dergiinfo);
                break;
            case 4 :
                dergiAra(dergiinfo);
                break;
            case 6 :
                dergiSatinAl();
                break;
            case 5 :
                oduncDergiAl();
                break;
            case 7 :
                satinAl();
                break;
        }

    }while(dergi_page==0);
                break;
            case 3 :

                gazete_page=0;
                 do{
                      puts("Ana menu=0");
        puts("Gazete Ekle=1");
        puts("Gazete Sil=2");
        puts("Gazete Listele=3");
        puts("Gazete Ara=4");
        puts("Gazete Satin Al=5");
        puts("Gazete Satin Al=6");
        puts("Fatura Olustur=7");
        printf("Secim=");
        scanf("%d",&cevap);
        scanf("%c",&temp);
        switch(cevap)
        {
        case 0 :
            gazete_page=1;
            break;
            case 1 :
                gazeteAdd(gazeteinfo);
                break;
            case 2 :
                gazeteRemove();
                break;
            case 3 :
                gazeteList(gazeteinfo);
                break;
            case 4 :
                gazeteAra(gazeteinfo);
                break;
            case 6 :
                gazeteSatinAl();
                break;
            case 5 :
                oduncGazeteAl();
                break;
            case 7 :
                satinAl();
                break;
        }

    }while(gazete_page==0);
    
    		case 4:
        		satisList();
                break;
            case 5:
        		oduncList();
                break;
            case 6:
        		kirtasiye();
                break;
        }
        	
			
    }while(menu_page==0);

	puts("	end");
	system("PAUSE");
	return(0);
}

