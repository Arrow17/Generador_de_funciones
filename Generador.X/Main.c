/*
 * File:   Main.c
 * Author: francisco
 *
 * Created on 25 de marzo de 2019, 04:21 PM
 */


#include <xc.h>
#include <stdlib.h>
#include "configuracion_bite.h"
#include "conversion.h"
#include "PWM.h"
#include "delays.h"
#include "senoidal.h"
#include "teclado.h"
#include "pantalla.h"
#include "Funciones.h"

#define XTAL_FREQ 8000000 //8Mhz



int q,w,e,r,t;
//int a=1,s,d,f,g;
//unsigned char frecuencia[10],ciclo[10],columna=0,cantidad=0,fila=0,cadena[10],cad[10];

void main() {
//PWM_generar(50,5000);
char key;    
OSCCON= 0b01100011;        //configuración del Oscilador
lcd_init();
int_teclado();
do{
    
 
 
    key = Recuperar();

    
    
 if(key==' '){
      q=1; 
      do{
       Presentacion();
       key=Recuperar();
      if(key=='D' | key=='0'){
          q=0;
      }
      }while(q==1);    
    }

 // Menu de funciones   
if(key=='D'){
        key = Recuperar(); 
        q=1;
        do{
            Menu();
            key = Recuperar();  
// Menu del pwm
 if(key=='A'){
        w=1;
        lcd_init();
        lcd_clear_display();
        int_teclado();  
        key=Recuperar();
        do{
        Menu_Pwm();
        key=Recuperar();          
  if(key=='1') { 
        r=1;
            do{
        Prueba1();
        key=Recuperar();
  if(key=='*'){
            r=0;
        }    
          }while(r==1);
        }
        
        //-----------------------------------------
  if(key=='2') { 
                   Prueba2();
                   key=Recuperar();
        r=1;
            do{
            
        key=Recuperar();
     

        if(key=='*'){
           
            r=0;
        }    
            
            }while(r==1);
        }
        
        
        if(key=='D')
        {
            lcd_clear_display();
            w=0;
        }
        }while(w==1);
        
    };
        
        if(key=='#'){
            lcd_clear_display();
            q=0;
        }        
            }while(q==1);        
        }
  // apagar LCD      
    if(key=='0'){
        q=1;
        lcd_init();
        lcd_clear_display();
        lcd_print("Adios");
        tm_1s();
        key = Recuperar();
        do{
        lcd_clear_display();
        key = Recuperar();
        
      if(key=='*'){
        q=0;
    }       
        }while(q==1);
   
    }

}while(1);
}
