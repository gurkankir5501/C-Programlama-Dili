#include <stdio.h>
#include <math.h>

double calcAverage( double doubleArray[],int size){
	
	double temp=0;

	for (int i=0;i<size;i++){
		
		temp=doubleArray[i] + temp;
	}
	
	return temp/size;
}

double calcStdDeviation( double doubleArray[],int size,double ortalama){
	
	double temp=0;
	
	for (int i=0;i<size;i++){
		
		temp=pow((doubleArray[i]-ortalama),2)  + temp;
	}
	
	return sqrt(temp/size-1);
}

double calcVariance( double doubleArray[],int size,double ortalama){
	
	double temp=0;
	
	for (int i=0;i<size;i++){
		
		temp=pow((doubleArray[i]-ortalama),2)  + temp;
	}
	
	return temp/size;
}

void calcMedian(double doubleArray[],int size){
		
	for(int i=0;i<size;i++){
		
		int temp=doubleArray[i];
		for(int j=i;j<size;j++){
			
			if(doubleArray[j]<temp){
				
				doubleArray[i]=doubleArray[j];
				doubleArray[j]=temp;
			}
		}
	}
	
	if(size%2==0){

		printf("Median = %0.1lf and %0.1lf",doubleArray[size/2],doubleArray[(size/2)+1]);	
	}
	else{
		
		printf("Median = %0.1lf",doubleArray[size/2]);
	}
}

int main(){
	
	double doubleArray [] = {1.1,2.2,3.3,4.4,5.5,6.6,
							7.7,8.8,9.9,11.1,22.2,33.3,
							44.4,55.5,66.6,77.7,88.8, 99.9};
	
	int size=sizeof(doubleArray)/sizeof(doubleArray[0]);
	
	double average = calcAverage(doubleArray,size);
	printf("Average = %0.1lf\n",average);	
	
	double stdDeviation = calcStdDeviation(doubleArray,size,average);
	printf("StdDeviation = %0.1lf\n",stdDeviation);
	
	double variance =calcVariance(doubleArray,size,average);
	printf("variance = %0.1lf\n",variance);
	
	calcMedian(doubleArray,size);
	
}
