#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *sonraki;
};

int main(){
	
	struct node *ilkdugum=NULL;
	ilkdugum = (struct node*)malloc(sizeof(struct node));
	struct node *ikincidugum = (struct node*)malloc(sizeof(struct node));
	
	ilkdugum->data = 150;
	ilkdugum->sonraki =ikincidugum;
	
	ikincidugum -> data =200;
	ikincidugum -> sonraki = NULL;
	
	printf("%d --> %d", ilkdugum->data,ikincidugum->data);
}
