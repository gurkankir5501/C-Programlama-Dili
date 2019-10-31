#include <stdio.h>

/* soru : klavyeden üc tamsayı okutup ilk ikisinin toplamını ücüncüsüne bolen ve sonucu uygun bir sekilde ekranda gösteren
programı yazınız. */

int main() {

    int x,y,z,toplam ;
    float g ;
    printf("birinci sayiyi giriniz :") ;
    scanf("%d",&x) ;
    printf("ikinci sayiyi giriniz :") ;
    scanf("%d",&y) ;
    printf("ücüncü sayiyi giriniz :") ;
    scanf("%d",&z) ;
    toplam = x + y ;
    g = toplam / z ;
    printf("sonuc %f dir.",g);
    
}