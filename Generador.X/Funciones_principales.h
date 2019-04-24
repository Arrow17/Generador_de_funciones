#define _XTAL_FREQ 8000000
 
void Presentacion();


void Presentacion(){
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
}

