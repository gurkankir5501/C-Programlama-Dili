#include <stdio.h>

/* if else calısması, dersten gecme durumu hesaplama */

int main() {

    int notum ;
    printf("lutfen notunuzu girer misiniz %d ",notum );
    scanf("%d",&notum);

    if (notum > 60 ) {

        printf("dersten gectiniz , tebrikler") ;
    }
    else {

        printf("dersten kaldiniz ");
    }
    return 0 ;
}