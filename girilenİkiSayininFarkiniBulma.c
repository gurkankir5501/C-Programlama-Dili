#include <stdio.h>

    /* soru : ii gercel sayı arasındaki farkın tam kısmını cagırana gönderen tamfark() adlı fonksiyonu yazınız . */

    float tamfark(a,b)
    float a,b ;
    {
        int g ;
        g = a - b ;
        return g ;
    }

    int main() {
        int g ;
        float x,y ;
        
        printf("birinci sayiyi giriniz :") ;
        scanf("%f",&x) ;
        printf("ikinci sayiyi giriniz :") ;
        scanf("%f",&y) ;
        g = tamfark(x,y) ;
        printf("sonuc %d dir .",g) ;

    }
