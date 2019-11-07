#include <stdio.h>
#include <stdlib.h>

struct node {
	
	int data ;
	struct node *next;
};

struct node *start = NULL;
struct node *temp = NULL;
struct node *q ;
void sonaEkle(int veri){
	
	struct node* eklenecek = (struct node*)malloc(sizeof(struct node));
	eklenecek->data = veri;
	eklenecek ->next = NULL;
	
	if (start == NULL){
		
		start = eklenecek;		
	}
	else{
	
		temp = start;
		while(temp->next != NULL){
			
			temp = temp->next;
		}
		
		temp->next = eklenecek;	
	}
}

void yazdir(){
	
	q = start;
	while(q->next != NULL){
		
		printf("%d=>",q->data);
		q = q->next;
	}
	printf(" NULL ");
}

int main(){
	int secim;
	while(1==1){
		
		printf("bir tane sayi girin : ");
		scanf("%d",&secim);
		sonaEkle(secim);
		yazdir();
		
	}
}
