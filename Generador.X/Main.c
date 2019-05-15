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

#define XTAL_FREQ 4000000 //8Mhz


int q,w,e,r;
//int a=1,s,d,f,g;
//unsigned char frecuencia[10],ciclo[10],columna=0,cantidad=0,fila=0,cadena[10],cad[10];

void main() {
//PWM_generar(50,5000);
char key;    
//OSCCON= 0b01100011;        //configuración del Oscilador
ANSELD=0;
Lcd_Init();
int_teclado();
do{
    
 
 
    key = Recuperar();

    
    
 if(key==' '){
      q=1; 
      do{
      int_teclado();
      Lcd_Init();
      Lcd_Cmd(LCD_CLEAR);
      Lcd_Cmd(LCD_CURSOR_OFF);
      Lcd_Out2(1,1,"Universidad de ");
      __delay_ms(100);
      Lcd_Out2(2,3,"Guanajuato");
      __delay_ms(100);
      Lcd_Cmd(LCD_CLEAR);
      Lcd_Out2(1,1,"Proyecto Final");
      Lcd_Out2(2,3,"Generador");
      __delay_ms(100);
      Lcd_Cmd(LCD_CLEAR);
      Lcd_Cmd(LCD_CURSOR_OFF);
      __delay_ms(50);
      __delay_ms(50);
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
            Lcd_Init();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"A.-Cuadrada");
            Lcd_Out2(2,1,"B.-Senoidal");
            __delay_ms(100);
            __delay_ms(100);
            __delay_ms(100);
            key = Recuperar();  
            Lcd_Init();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"C.-Triangular");
            __delay_ms(100);
            __delay_ms(100);
            __delay_ms(100);
            key = Recuperar();  
       
      //menu triangular
        if(key=='C'){
        w=1;
        Lcd_Init();
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        int_teclado();  
        key=Recuperar();
         do{
           Lcd_Init();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"A.-Senal 1");
            Lcd_Out2(2,1,"B.-Señal 2");
            __delay_ms(100);
            __delay_ms(100);
            key = Recuperar();  
            Lcd_Init();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"C.-Senal 3");
            __delay_ms(100);
            __delay_ms(100);
            key = Recuperar();  
         if(key=='A'){
             q=1;
             Lcd_Init();
             Lcd_Cmd(LCD_CLEAR);
             Lcd_Cmd(LCD_CURSOR_OFF);
             int_teclado();  
             key=Recuperar();
             do{
            Lcd_Init();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"Señal 1");
      
            TRISCbits.RC2=0; 
    int valoresSeno [50]= {4,8,12,16,20,24,28,32,
36,40,44,48,52,56,60,64,
68,72,76,80,84,88,92,96,
100,96,92,88,84,80,76,72,
68,64,60,56,52,48,44,40,
36,32,28,24,20,16,12,8,
4,0};
    int i, j,k;
    for (i=0;i<50;i++){    
        valoresSeno [i]=valoresSeno [i];
    }
    while(1){
        for (i=0;i<50;i++){    
            for (j=0;j<valoresSeno[i];j++){
                PORTCbits.RC2=1;
            }
            k=100-valoresSeno[i];
            for (j=0;j<k;j++){
                PORTCbits.RC2=0;
            }
        }
    }      __delay_ms(100);
           __delay_ms(100);
           __delay_ms(100);
           __delay_ms(100);
          __delay_ms(100);
          __delay_ms(100);
           __delay_ms(100);
            key=Recuperar();
            __delay_ms(100);
           __delay_ms(100);
           __delay_ms(100);
           __delay_ms(100);
          __delay_ms(100);
          __delay_ms(100);
           __delay_ms(100);
            key=Recuperar();
            if(key=='*'){q=0;} 
             }while(q==1);
         }    
         if(key=='D'){w=0;}
         }while(w==1);
     }   
            
            
      //Menu seno      
     if(key=='B'){
        w=1;
        Lcd_Init();
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        int_teclado();  
        key=Recuperar();
         do{
           Lcd_Init();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"A.-Senal 1");
            Lcd_Out2(2,1,"B.-Señal 2");
            __delay_ms(100);
            __delay_ms(100);
            key = Recuperar();  
            Lcd_Init();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"C.-Senal 3");
            __delay_ms(100);
            __delay_ms(100);
            key = Recuperar();  
         if(key=='A'){
             q=1;
             Lcd_Init();
             Lcd_Cmd(LCD_CLEAR);
             Lcd_Cmd(LCD_CURSOR_OFF);
             int_teclado();  
             key=Recuperar();
             do{
            Lcd_Init();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"Señal 1");
            __delay_ms(100);
            key=Recuperar();
            if(key=='*'){q=0;} 
             }while(q==1);
         }    
         if(key=='D'){w=0;}
         }while(w==1);
     }       
// Menu del pwm
 if(key=='A'){
        w=1;
        Lcd_Init();
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        int_teclado();  
        key=Recuperar();
        do{
        Lcd_Init();
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        Lcd_Out2(1,1,"1.-Datos");
        Lcd_Out2(2,1,"2.-Comenzar");
       __delay_ms(100);
       __delay_ms(100);
        key=Recuperar();          
  if(key=='1') { 
        r=1;
            do{
         Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        Lcd_Out2(1,1,"1.-Frecuencia");
        Lcd_Out2(2,1,"2.-Ciclo");
        __delay_ms(100);
        __delay_ms(100);
        key=Recuperar();         
        if(key=='1'){
            int zx=1;
            do{
                Frecuencia(frecuencia);
                Imprimir_pantalla(frecuencia);
                s=atoi(frecuencia);
                key=Recuperar();  
              if(key=='#'){
                  zx=0;
              }  
            }while(zx==1);
        }
     if(key=='2'){
            int zx=1;
            do{
                Ciclo(ciclo);
                Imprimir_pantalla(ciclo);
                t=atoi(ciclo);
                key=Recuperar();  
              if(key=='#'){
                  zx=0;
              }  
            }while(zx==1);
        }   
  if(key=='*'){
            r=0;
        }    
          }while(r==1);
        }
        
        //-----------------------------------------
  if(key=='2') { 
                            Lcd_Init();
                            Lcd_Cmd(LCD_CLEAR);
                            Lcd_Cmd(LCD_CURSOR_OFF);
                            Lcd_Out2(1,1,"Fre: ");
                            Lcd_Out2(1,13,"Hz");
                             //fila=0; columna=6;
                            cantidad= Conv_Entero(s,cadena);
                            //lcd_Cadena(cadena,&columna,&fila);
                             Lcd_Out(1,8,cadena);
                            Lcd_Out2(2,1,"Ciclo: ");
                            Lcd_Out2(2,12,"%");
                            //fila=1; columna=8;
                            cantidad= Conv_Entero(t,cadena);
                            //lcd_Cadena(cadena,&columna,&fila);
                            Lcd_Out(2,8,cadena);
                             PWM_generar(t,s);

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
                   
            Lcd_Cmd(LCD_CLEAR);
            w=0;
        }
        }while(w==1);
        
    };
        
        if(key=='#'){
            Lcd_Cmd(LCD_CLEAR);
            q=0;
        }        
            }while(q==1);        
        }
  // apagar LCD      
    if(key=='0'){
        q=1;
        Lcd_Init();
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        Lcd_Out2(1,1,"Adios");
        
        __delay_ms(100);
        __delay_ms(100);
        __delay_ms(100);
        key = Recuperar();
        do{
        Lcd_Init();
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        Lcd_Cmd(LCD_TURN_OFF);
        key = Recuperar();
        
      if(key=='*'){
        q=0;
    }       
        }while(q==1);
   
    }

}while(1);
}
