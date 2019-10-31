#include <stdio.h>
#define PI 3.14
    /*kürenin hacmini hesaplama */
    int main(){

        int yaricap ;
        float hacim ;
        printf("kurenin yaricapini giriniz :") ;
        scanf("%d",&yaricap) ;
        hacim = (4/3.0) * PI * (yaricap*yaricap*yaricap) ;
        printf("kurenin yari capi : %f",hacim) ;
        return 0 ;
    }