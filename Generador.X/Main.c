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


#define XTAL_FREQ 8000000 //8Mhz

void Tec(char *cadena);
void Imprimir_pantalla(char *N);
void Frecuencia(char *frecuencia);
void Ciclo(char *ciclo);

int q,w,e,r,t;
int a=1,s,d,f,g;
unsigned char frecuencia[10],ciclo[10],columna=0,cantidad=0,fila=0,cadena[10],cad[10];

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
       key = Recuperar(); 
      lcd_clear_display();
      lcd_goto(1,1);
      lcd_print("Universidad de ");
      lcd_goto(3,2);
      lcd_print("Guanajuato");
      tm_1s();
      tm_1s();
      lcd_clear_display();
      lcd_goto(1,1);
      lcd_print("Proyecto Final");
      lcd_goto(3,2);
      lcd_print("Generador");
      tm_1s();
      tm_1s();
      key = Recuperar(); 
      tm_100();
      if(key=='D'){
          q=0;
      }
      }while(q==1);

      
    }

    
    if(key=='D'){
     
        key = Recuperar(); 
        q=1;
        do{
        
        key = Recuperar(); 
        lcd_clear_display();
        lcd_goto(1,1);
        lcd_print("A.-Cuadrada");
        lcd_goto(1,2);
        lcd_print("B.-Senoidal");
        tm_1s();
        tm_1s();
        key = Recuperar(); 
        lcd_clear_display();
        lcd_goto(1,1);
        lcd_print("C.-Triangular");
        tm_1s();
        tm_1s();
        key = Recuperar(); 
        
        
    if(key=='A'){
        w=1;
        lcd_init();
        lcd_clear_display();
        int_teclado();  
        key=Recuperar();
        do{
        lcd_init();
        lcd_clear_display();
        int_teclado();  
        key=Recuperar();
        lcd_goto(1,1);
        lcd_print("1.-Datos");
        lcd_goto(1,2);
        lcd_print("2.-Comenzar");
        
        tm_500();
        key=Recuperar();
        
                
        if(key=='1') { 
        r=1;
            do{
        Frecuencia(frecuencia);
        Imprimir_pantalla(frecuencia);
        Ciclo(ciclo);
        Imprimir_pantalla(ciclo);
        s=atoi(frecuencia);
        t=atoi(ciclo);
        
        key=Recuperar();
        if(key=='*'){
           
            r=0;
        }    
            
            }while(r==1);
        }
        
        //-----------------------------------------
               if(key=='2') { 
       lcd_init();
       lcd_clear_display();
       e=s*100;
       f=t*100;
       
        cantidad= Conv_Entero(e,cadena);
        lcd_Cadena(cadena,&columna,&fila);
        tm_1s();
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
        


}while(1);
}

void Frecuencia(char *frecuencia){
    lcd_init();
    lcd_clear_display();
    lcd_print("Ingrese Frecuencia");
    Tec(frecuencia);
}
void Ciclo(char *ciclo){
    lcd_init();
    lcd_clear_display();
    lcd_print("Ingrese ciclo");
    Tec(ciclo);
}
void Tec(char *cadena){
    
    unsigned char Key = '+' , aux;
    unsigned int i=0 , j=0, contador = 1;
   
    lcd_goto(contador,2);
    do{
          

       Key = Recuperar();
       if( Key == ' ')continue;
       if( Key == '*')break;
       if(Key == 'B') {
           lcd_goto(--contador,2);
           if(j!= 0) j--;
             aux = '\0';
           continue;
       
      }
    if(Key == aux){
    
        if(Key!='#')
        contador --,j--;
        lcd_goto(contador++,2);
        cadena[j++]=Key;
        continue;
    }
    i = 0;
 
    if(Key == '#' && Key!=aux ){
        aux = Key;
        continue;
    }
    lcd_goto(contador,2);
    cadena[j++]=Key;
    lcd_dato(Key);
    contador++;
    aux=Key;
    }while(1);
    cadena[j] = '\0';

    
}

void Imprimir_pantalla(char *N){
    
    unsigned char fila = 0, columna=0;
    lcd_clear_display();
    fila=0; columna=0;
    lcd_Cadena(N,&columna,&fila);
    tm_1s();
    lcd_clear_display();

}
