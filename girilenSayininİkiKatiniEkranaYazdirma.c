#include <stdio.h>
/* soru : girilen sayının iki katını ekrana yazdırma */

    int ikikat(m)
    int m ;
    {
        int g ;
        g = 2 * m ;
        return g ;
    }

    int main()
    {
        int a,b ;
        printf("sayi giriniz :") ;
        scanf("%d",&a) ;
        b = ikikat(a) ;
        printf("sayinizin iki kati %d dir.",b) ;
    }