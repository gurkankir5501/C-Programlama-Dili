#include <stdio.h>
#include <math.h>

/* verilen denklemin köklerini bulma
ax*2 + bx + c
*/

int main() {

    int a,b,c ;
    float x1,x2,delta ;
    printf("a sayisini giriniz :",a );
    scanf("%d",&a);
    printf("b sayisini giriniz :",b );
    scanf("%d",&b);
    printf("c sayisini giriniz :",c );
    scanf("%d",&c);
    delta = b*b -4*a*c ;
    x1 = (-b +(sqrt(delta))) / 2*a ;
    x2 = (-b -(sqrt(delta))) / 2*a ;

    printf("denklemin birinci koku %.2f dir.\n",x1) ;
    printf ("denklemin ikinci koku %.2f dir.",x2) ;

      
}