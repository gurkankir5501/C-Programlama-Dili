#include <stdio.h>

int temp=0;
int foo(int index ,int firstNumber,int secondNumber){
	
	int thirdNumber=firstNumber + secondNumber;
	
	if(index==1){
		
		return firstNumber;
	}
	temp=temp+1;
	return foo(index-1,secondNumber,thirdNumber);
}

int bar(){
	
	int index;
	printf("Kacinci elemanin hesaplanacagini giriniz : ");
	scanf("%d",&index);
	return index;
}

void baz(int index,int result){
	
	printf("Serinin %d.'nci elemaninin degeri: %d\n",index,result);
	printf("Serinin %d.'nci elemaninin hesaplanmasi icin fonksiyon cagrilma sayisi: %d\n",index,temp);
}

int main(){
	
	int firstNumber=0;
	int secondNumber=1;
	int index=bar();
	int result = foo(index,firstNumber,secondNumber);
	baz(index,result);
}
