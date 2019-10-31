#include <stdio.h>

/*vize-final ortalama hesaplama ve dersi gecme durumunu hesaplama */

int main() {

    int vize ,final ;
    float ortalama ;

    printf("vize notunuzu giriniz :");
    scanf("%d",&vize);
    printf("final notunuzu giriniz :");
    scanf("%d",&final);
    ortalama = (vize*0.4) + (final*0.6);
    if (ortalama >= 60 && final >= 50 ) {

        printf("tebrikler dersi %f ile gectiniz .",ortalama);
    }
    else {

        printf("maalesef dersi %f ile gecemediniz .",ortalama);
    }
}