/*
 * File:   Main.c
 * Author: francisco
 *
 * Created on 25 de marzo de 2019, 04:21 PM
 */


#include <xc.h>
#define XTAL_FREQ 8000000 //8Mhz
void main(void)
{
    //configuracion de Frecuencia
    OSCCON= 0b01110010;
    TRISCbits.RC2=0; 
    int valoresSeno [20]= {50,35,21,10, 2, 0, 2,10, 21, 35, 50, 65, 79, 90, 98, 
    100, 98, 90, 79, 65};
    int i, j,k;
    for (i=0;i<20;i++){    
        valoresSeno [i]=valoresSeno [i]/10;
    }
    while(1){
        for (i=0;i<20;i++){    
            for (j=0;j<valoresSeno[i];j++){
                PORTCbits.RC2=1;
            }
            k=100/10-valoresSeno[i];
            for (j=0;j<k;j++){
                PORTCbits.RC2=0;
            }
        }
    }
    return;
}
