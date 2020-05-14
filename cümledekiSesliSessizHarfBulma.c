#include <stdio.h>

char charArray [] = "A computer is a machine that can be instructed to carry out sequences of arithmetic or logical "
					"operations automatically via computer programming.Modern computers have the ability to follow generalized sets "
					"of operations, called programs.These programs enable computers to perform an extremely wide range of tasks.A "
					"complete computer including the hardware, the operating system (main software), and peripheral equipment "
					"required and used for full operation can be referred to as a computer system.This term may as well be used for a "
					"group of computers that are connected and work together, in particular a computer network or computer cluster."
					"Computers are used as control systems for a wide variety of industrial and consumer devices.This includes simple "
					"special purpose devices like microwave ovens and remote controls, factory devices such as industrial robots and "
					"computer-aided design, and also general purpose devices like personal computers and mobile devices such as "
					"smartphones.The Internet is run on computers and it connects hundreds of millions of other computers and their "
					"users.Early computers were only conceived as calculating devices.Since ancient times, simple manual devices like "
					"the abacus aided people in doing calculations.Early in the Industrial Revolution, some mechanical devices were built "
					"to automate long tedious tasks, such as guiding patterns for looms.More sophisticated electrical machines did "
					"specialized analog calculations in the early 20th century.";
					
void foo(int size){
	
	int tempSize[size];
	
	
	int fark = 'a' - 'A';
	for(int i=0;i<size;i++){
		
        if (charArray[i] >= 'A' && charArray[i] <= 'Z') {
            charArray[i] += fark;
        }
        tempSize[i]=0;
    }
    
    for(int i=0;i<size;i++){
    	
    	for(int j=i;j<size;j++){
    		
    		if(charArray[i]==' ' || charArray[i]=='.' || charArray[i]==',' || charArray[i]==')' || charArray[i]=='('){
    			
    			break;
			}
			
			if(charArray[i]==charArray[j]){
				
				tempSize[i]=tempSize[i]+1;
			}
		}
	}
	
	int vowels=0;
	int consonants=0;
	for(int i=0;i<size;i++){
		
		if(tempSize[i]>vowels && (charArray[i]=='a' || charArray[i]=='e'||charArray[i]=='i'||charArray[i]=='u' || charArray[i]=='o')){
				
			vowels=tempSize[i];
		}
		else if(tempSize[i]>consonants && !(charArray[i]=='a' || charArray[i]=='e'||charArray[i]=='i'||charArray[i]=='u' || charArray[i]=='o' || charArray[i]=='\0')){
			
			consonants=tempSize[i];
		}
	}
	
	printf("En Cok Olan Sesli Harfler : ");
	
	for(int i=0;i<size;i++){
		
		if(tempSize[i]==vowels && (charArray[i]=='a' || charArray[i]=='e'||charArray[i]=='i'||charArray[i]=='u' || charArray[i]=='o')){
				
			printf("%c ",charArray[i]);
		}
	}
	
	printf("\nEn Cok Olan Sessiz Harfler : ");
	
	for(int i=0;i<size;i++){
		
		if(tempSize[i]==consonants && !(charArray[i]=='a' || charArray[i]=='e'||charArray[i]=='i'||charArray[i]=='u' || charArray[i]=='o')){
				
			printf("%c ",charArray[i]);
		}
	}
}

void bar(int size){
	
	char harf;
	printf("Lutfen Harf Giriniz : ");
	scanf("%c",&harf);
	
	int temp=0;
	for(int i=0;i<size;i++){
	
		if(charArray[i]==harf){
			
			temp=temp+1;
		}
	}
	
	printf("Girdiginiz %c Harfinden Dizide %d Tane Vardir.",harf,temp);
}
					
int main(){
	
	int size =sizeof(charArray)/sizeof(charArray[0]);
	printf("Dizide Toplam %d Tane Karakter Vardir .\n",size-1);
	foo(size-1);
	printf("\n----------------------------------------\n");
	bar(size-1);
}
