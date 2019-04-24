#define _XTAL_FREQ 8000000
void tm_100();
void tm_200();
void tm_500();
void tm_1s();
void tm_100(){
  __delay_ms(50);
  __delay_ms(50);
}

void tm_200(){
  __delay_ms(50);
  __delay_ms(50);
  __delay_ms(50);
  __delay_ms(50);
    
}

void tm_500(){
  __delay_ms(50);
  __delay_ms(50);
  __delay_ms(50);
  __delay_ms(50);
 //--------------
  __delay_ms(50);
  __delay_ms(50);
  __delay_ms(50);
  __delay_ms(50);
  //----------------
  __delay_ms(50);
  __delay_ms(50);

}

void tm_1s(){
   __delay_ms(50);
  __delay_ms(50);
  __delay_ms(50);
  __delay_ms(50);
 //--------------
  __delay_ms(50);
  __delay_ms(50);
  __delay_ms(50);
  __delay_ms(50);
  //----------------
  __delay_ms(50);
  __delay_ms(50);
  //---------------------
   __delay_ms(50);
  __delay_ms(50);
  __delay_ms(50);
  __delay_ms(50);
 //--------------
  __delay_ms(50);
  __delay_ms(50);
  __delay_ms(50);
  __delay_ms(50);
  //----------------
  __delay_ms(50);
  __delay_ms(50);


}