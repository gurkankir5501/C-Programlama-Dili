#include <stdio.h>
#include <stdlib.h>

struct node {
	
	int data ;
	struct node* next ;
};

struct node* start = NULL;
struct node* temp ;
struct node* temp2;
struct node* foo = NULL;

void sonaEkle(int veri){
	
	struct node* eklenecek = (struct node*)malloc(sizeof(struct node));
	eklenecek->data=veri;
	eklenecek->next = NULL;
	
    if (start == NULL){
		
		start = eklenecek;
		printf("%d=>",start->data);
    }
	else{
		
	    temp = start;
		start = eklenecek;
		start->next=temp;
	}
}


void araEkle(int veri,int yer){
	
	foo = start;
	struct node* eklenecek1 = (struct node*)malloc(sizeof(struct node));
	eklenecek1->data = veri;
	eklenecek1->next = NULL;
	
	while(foo->next->data != yer){
		
		foo = foo->next;
	}
	struct node* bar ;
	bar = foo->next;
	foo->next =eklenecek1;
	eklenecek1->next=bar;
	
	
}

void yazdir(){
	
	
	temp2 = start;
	while(temp2->next != NULL){
		
		printf("%d =>",temp2->data);
		temp2 = temp2->next;		
	}
	printf("NULL");
}

	int b[5]={10,20,30,40,50};

	int yer;
	int deger;
int main(){
		int i = 0;
	    while(i <5){
 	      
 	      sonaEkle(b[i]);
 	      yazdir();
 	      printf("\n");
 	 	  i = i+1;
		}
	
	printf("eklemek istediginiz degeri giriniz :");
	scanf("%d",&deger);	
	printf("eklemek istediğiniz yeri secin");
	scanf("%d",&yer);
	
	araEkle(deger,yer);
	yazdir();	

}

 
 
