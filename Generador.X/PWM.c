/*
 * File:   PWM.c
 * Author: francisco
 *
 * Created on 27 de marzo de 2019, 01:38 PM
 */


#include "PWM.h"

void init_pwm()
{
      TRISCbits.TRISC1=0;
      T2CON= 0x07;
      PR2=0x7C;
}

void pwm_25()
{
       CCPR2L=0x1F;
       CCP2CON=0x1C;
    
}


void pwm_50()
{
      CCPR2L=0x3E;
      CCP2CON=0x2C;
    
}

void pwm_75()
{
        CCPR2L=0x5D;
        CCP2CON=0x3C;
    
}

void pwm_100()
{
      CCPR2L=0x7D;
      CCP2CON=0x0C; 
    
}