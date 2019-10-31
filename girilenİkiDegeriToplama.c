#include <stdio.h>

/* soru : klavyeden okunan iki gercel sayıyı toplayıp sonucu bit tamsayı degiskenine atayan 
ve o tamsayı degiskeninin icerigini ekranda gösteren programı yazınız. */

int main() {

    int c ;
    float a,b,toplam ;
    printf("birinci sayiyi giriniz :") ;
    scanf("%f",&a) ;
    printf("ikinci sayiyi giriniz :") ;
    scanf("%f",&b) ;

    toplam = a + b ;
    c = toplam ;
    printf("sonuc %d dir",c) ;

}