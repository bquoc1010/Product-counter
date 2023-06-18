#include <16f877a.h>
#Fuses   hs
#use delay(clock=20M)
const char Mang[]={"                 DA DU SO LUONG    "};
#define LCD_ENABLE_PIN  PIN_B5
#define LCD_RS_PIN      PIN_B7
#define LCD_RW_PIN      PIN_B6
#define LCD_DATA4       PIN_B4
#define LCD_DATA5       PIN_B3
#define LCD_DATA6       PIN_B2
#define LCD_DATA7       PIN_B1
#define  UP PIN_D0 
#define  DW PIN_D2
#define  XOA PIN_D3
#include   <lcd.c>
SIGNED INT32  SOMAX, SP;


 VOID HIENTHI_SOMAX()
  {   
  lcd_gotoxy(1,1);
  lcd_putc("MAX:"); 
  delay_ms(100);
  lcd_putc(SOMAX/10+0x30);      
  lcd_putc(SOMAX%10+0x30);
  } 
VOID HIENTHI_SP()
{
      lcd_gotoxy(1,2);           
      lcd_putc("SO SAN PHAM:"); 
      delay_ms(100);
      lcd_putc(SP/10+0x30);      
      lcd_putc(SP%10+0x30);
}

 void hamtang()
 {
    if (input(UP)==0)
     {  
   delay_us(20);
   while(input(UP) == 0 )
   {
   SOMAX++;
   
   while(input(UP)==0);   
 }
 }
 }    

  void hamgiam()
 {
    if (input(DW)==0)
     {  
   delay_us(20);
   while(input(DW) == 0 )
   {
   SOMAX--;
  
   
   while(input(DW)==0);   
 }
 }
 } 
 
 void hamxoa()
 {
    if (input(XOA)==0)
     {  
   while(input(XOA)==0)
   {
    SP=0;
    HIENTHI_SP();
    set_timer0(0);
   }
 }
}

 VOID MAIN()
 {

   set_tris_b(0b00000000);
   set_tris_a(0b11111111);
   set_tris_d(0b11111111);
   set_tris_c(0b00000000);
    
     lcd_init();
     SOMAX=10;
  
   
   SETUP_TIMER_0(T0_EXT_H_TO_L|T0_DIV_1);  
   SET_TIMER0(0);
   
while(true)
   {  
  

  hamtang();
  hamgiam(); 
  HIENTHI_SOMAX();
  hamxoa();
  SP=get_timer0();  
  HIENTHI_SP();

 if (SP == SOMAX)
 {
    WHILE(TRUE)
     {
     char i,j;
     lcd_init();
     for (j=0;j<=16;j++)
     {
        for (i=1;i<=16;i++)
         {
           lcd_gotoxy(i,2);
        printf(lcd_putc,"%c",Mang[i+j-1]);     
         }
         delay_ms(200);
     }
     
     delay_ms(900);  
  }   
}

}
 }
 
 