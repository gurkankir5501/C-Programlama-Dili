#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node* start = NULL ;
struct node* temp = NULL ;

void basaEkleme(int x){
	
	temp = start;
	struct node *eklenen =(struct node *)malloc(sizeof(struct node));
	

	eklenen -> data = x;
	eklenen -> next =temp;
	start = eklenen;
	yazdir();
}

void yazdir(){
	temp = start;
	while(temp->next != NULL ){
		
		printf("=>%d=>", temp->data);
		temp = temp->next;
	}
	printf("%d\n",temp->data)	;
}

int main(){
	
	while(1==1){ 
		
		int sayi;
		printf("bir sayi giriniz : ");
		scanf(" %d ",&sayi);
		basaEkleme(sayi);
		
    }
}
