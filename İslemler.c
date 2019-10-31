#include <stdio.h>

    float bol(a,b)
    int a,b ;
    {
        float g ;
        g = a / b ;
        return g ;
    }

    int topla(a,b)
    int a,b ;
    {
        int g ;
        g = a + b ;
        return g ;
    }

    int main ()
    {
        int x,y,z ;
        float f ;
        printf("birinci sayıyı giriniz :") ;
        scanf("%d",&x) ;
        printf("ikinci sayıyı giriniz :") ;
        scanf("%d",&y) ;
        z = topla(x,y) ;
        f = bol(x,y) ; 
        printf("sayıların toplamı %d , sayıların bölümü ise %f",z,f) ; 
    }