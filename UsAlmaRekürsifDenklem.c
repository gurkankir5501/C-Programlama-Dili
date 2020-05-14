#include <stdio.h>

int f(int x,int y){
	
	if (y==0){
		
		return 1;
	}

	return x*f(x,y-1);
}

int main(){
	
	int x;
	int y;
	printf("x Degerini Giriniz : ");
	scanf("%d",&x);
	printf("y Degerini Giriniz : ");
	scanf("%d",&y);
	int result=f(x,y);
	printf("Sonuc : %d",result);
	
	return 0;
}
