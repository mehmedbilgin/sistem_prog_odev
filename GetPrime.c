#include <stdio.h>
#include <stdint.h>

uint64_t GetPrime(uint16_t sayi){
    uint16_t i,c,d;
    uint64_t donus;
    int sayac = 0;
    
    uint16_t istenen = sayi;
    for(i=2;i<=100000;i++){
        d=1;
        for (c=2;c<i;c++){
            if (i%c==0){
                d=0;
            }
        }

        if (d==1) {
            sayac++;
        }
        if(sayac == istenen){
            donus = i;
            return donus;
            break;
        }
    }
}


int main(){
    uint16_t girdi;
    int kontrol = 1;
    while(kontrol){
        printf("Deger giriniz\n");
        scanf("%hd", &girdi);
        if(girdi>0){
            kontrol = 0;
        }
    }
    
    uint64_t deger = GetPrime(girdi);
    printf("%hd. asal sayı : %ld",girdi,deger);
    return 0;
}
