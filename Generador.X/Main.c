/*
 * File:   Main.c
 * Author: francisco
 *
 * Created on 25 de marzo de 2019, 04:21 PM
 */


#include <xc.h>
#include "configuracion_bite.h"
#include "PWM.h"
#define XTAL_FREQ 8000000 //8Mhz
void main(void)
{
    init_pwm();
    while(1){
        pwm_25();
    }
    return;
}
