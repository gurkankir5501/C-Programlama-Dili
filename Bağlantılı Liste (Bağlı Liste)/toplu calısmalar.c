#include <stdio.h>
#include <stdlib.h>

struct node{
	
	int data;
	struct node *next;
};

struct node* start=NULL;

struct node* dugumOlustur(int veri){
	
	struct node* yeniDugum = (struct node*)malloc(sizeof(struct node));
	
	yeniDugum->data=veri;
	yeniDugum->next=NULL;
	return yeniDugum;
} 

void bastanEkle(int veri){
	struct node* temp = start;
	struct node* bastanEklenecek= dugumOlustur(veri);
	
	if (start == NULL){
		
		start = bastanEklenecek;
		return;
	}
	else{
		
		start = bastanEklenecek;
		start->next=temp;
	}
}
void aradanEkle(int veri,int konum){
	struct node* temp=start;
	struct node* arayaEklenecek = dugumOlustur(veri);
	
	if (start == NULL){
		
		start = arayaEklenecek;
	}
	else{
		if(start->next==NULL){
			
			start->next = arayaEklenecek;
			arayaEklenecek->next=NULL;
		}
		else{
			struct node* bar;
			while(temp->next->data!=konum){
				
				temp=temp->next;
			}
			bar = temp->next;
			temp->next=arayaEklenecek;
			arayaEklenecek->next=bar;
		}
	}
}
void sondanEkle(int veri){
	
	struct node* temp=start;
	struct node* sondanEklenecek=dugumOlustur(veri);
	
	if(start == NULL){
		start=sondanEklenecek;
		
	}
	else{
		while(temp->next!=NULL){
			
			temp=temp->next;
		}
		temp->next=sondanEklenecek;
		sondanEklenecek->next=NULL;
		
	}

}

void yazdir(){
	
	struct node* temp =start;
	
	while(temp->next!=NULL){
		
		printf("%d=>",temp->data);
		temp=temp->next;
	}
	printf("NULL");
}

int main(){
	
	
	while(1==1){
		int islem ;
		
		printf("ekleme islemi yapmak icin 1 basin :");
		printf("silme islemi yapmak icin 2 basin : ");
		scanf("%d",&islem);
		
		if(islem==1){
			int ekleme;
			printf("bastan ekleme yapmak icin 1 basin \n aradan ekleme yapmak icin 2 basýn\n sondan ekleme yapmak icin 3 basin");
					
			scanf("%d",&ekleme);
			
			if(ekleme==1){
				printf("eklemek istediðiniz sayiyi giriniz :");
				int sayi ;
				scanf("%d",&sayi);
				bastanEkle(sayi);
				
				
			}
			else if(ekleme == 2){
				printf("eklemek istediðiniz sayiyi giriniz :" );
				int sayi2 ;
				scanf("%d",&sayi2);
				printf("eklemek istediginiz yeri giriniz:");
				int yeri;
				scanf("%d",&yeri);
				aradanEkle(sayi2,yeri);
				
				
		    }
			else if(ekleme==3){
				printf("eklemek istediðiniz sayiyi giriniz : ");
				int sayi3 ;
				scanf("%d",&sayi3);
				sondanEkle(sayi3);
				
				
			}
			else{
				
				printf("gecerli sayi giriniz :");
				
			}
			yazdir();
		}
	}
}
