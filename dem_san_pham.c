#include <16f877a.h>
#Fuses   hs
#use delay(clock = 20M)
const char Mang[] = { "                 DA DU SO LUONG    " };
const int8 lcd_custom_chars_1[] =
{
    0b00000100,
    0b00001110,
    0b00010101,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000000,

    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00010101,
    0b00001110,
    0b00000100,
    0b00000000,

    0b00000011,
    0b00000101,
    0b00001111,
    0b00011100,
    0b00010100,
    0b00011100,
    0b00010100,
    0b00011100,

    0b00011100,
    0b00010100,
    0b00011100,
    0b00010100,
    0b00011100,
    0b00001111,
    0b00000101,
    0b00000011,

    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00011111,
    0b00001010,
    0b00011111,

    0b00011111,
    0b00001010,
    0b00011111,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,

    0b00011000,
    0b00010100,
    0b00011110,
    0b00000111,
    0b00000101,
    0b00000111,
    0b00000101,
    0b00000111,

    0b00000111,
    0b00000101,
    0b00000111,
    0b00000101,
    0b00000111,
    0b00011110,
    0b00010100,
    0b00011000
};

const int8 lcd_custom_chars_2[] =
{
    0b00000111,
    0b00001111,
    0b00001111,
    0b00001111,
    0b00001111,
    0b00001111,
    0b00001111,
    0b00000111,

    0b00011100,
    0b00011110,
    0b00011110,
    0b00011110,
    0b00011110,
    0b00011110,
    0b00011110,
    0b00011100,

    0b00011111,
    0b00011111,
    0b00011111,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,

    0b00011111,
    0b00011111,
    0b00011111,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00011111,
    0b00011111,

    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00011111,
    0b00011111,
    0b00011111,

    0b00001111,
    0b00000111,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000011,
    0b00000111,

    0b00011110,
    0b00011100,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00011000,
    0b00011100,

    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000111,
    0b00001111
};


#define LCD_ENABLE_PIN  PIN_B5
#define LCD_RS_PIN      PIN_B7
#define LCD_RW_PIN      PIN_B6
#define LCD_DATA4       PIN_B4
#define LCD_DATA5       PIN_B3
#define LCD_DATA6       PIN_B2
#define LCD_DATA7       PIN_B1
#define UP              PIN_D0 
#define DW              PIN_D2
#define XOA             PIN_D3

#include   <lcd.c>
SIGNED INT32  SOMAX, SP, CHON;

void lcd_load_custom_chars_1(void)
{
#define UP_ARROW   0
#define DOWN_ARROW 1
#define CORNER_1   2
#define CORNER_2   3
#define BAR_2      4
#define BAR_1      5
#define CORNER_3   6
#define CORNER_4   7
    int8 i;

    // Set address counter pointing to CGRAM address 0.
    lcd_send_byte(0, 0x40);

    // Load custom lcd character data into CGRAM.
    // It can only hold a maximum of 8 custom characters.
    for (i = 0; i < sizeof(lcd_custom_chars_1); i++)
    {
        lcd_send_byte(1, lcd_custom_chars_1[i]);
    }

    // Set address counter pointing back to the DDRAM.
    lcd_send_byte(0, 0x80);
}

void lcd_load_custom_chars_2(void)
{
#define LEFT_SIDE   0
#define RIGHT_SIDE  1
#define TOP_BAR     2
#define MID_BAR     3
#define BOT_BAR     4
#define LEFT_END    5
#define RIGHT_END   6
#define BOT_END     7
    int8 i;

    // Set address counter pointing to CGRAM address 0.
    lcd_send_byte(0, 0x40);

    // Load custom lcd character data into CGRAM.
    // It can only hold a maximum of 8 custom characters.
    for (i = 0; i < sizeof(lcd_custom_chars_2); i++)
    {
        lcd_send_byte(1, lcd_custom_chars_2[i]);
    }

    // Set address counter pointing back to the DDRAM.
    lcd_send_byte(0, 0x80);
}

void lcd_so_0(int x, int y)
{
    int i, j;
    i = x;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(LEFT_SIDE);
    i = x;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(LEFT_SIDE);
    i = x + 1;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(TOP_BAR);
    i = x + 1;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(BOT_BAR);
    i = x + 2;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_SIDE);
    i = x + 2;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_SIDE);
    delay_ms(100);
}

void lcd_so_1(int x, int y)
{
    int i, j;
    i = x;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(" ");
    i = x;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(" ");
    i = x + 1;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(" ");
    i = x + 1;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(" ");
    i = x + 2;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_SIDE);
    i = x + 2;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_SIDE);
    delay_ms(100);
}

void lcd_so_2(int x, int y)
{
    int i, j;
    i = x;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(LEFT_END);
    i = x;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(LEFT_SIDE);
    i = x + 1;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(MID_BAR);
    i = x + 1;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(BOT_BAR);
    i = x + 2;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_SIDE);
    i = x + 2;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(BOT_BAR);
    delay_ms(100);
}

void lcd_so_3(int x, int y)
{
    int i, j;
    i = x;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(LEFT_END);
    i = x;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(BOT_END);
    i = x + 1;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(MID_BAR);
    i = x + 1;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(BOT_BAR);
    i = x + 2;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_SIDE);
    i = x + 2;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_SIDE);
    delay_ms(100);
}

void lcd_so_4(int x, int y)
{
    int i, j;
    i = x;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(LEFT_SIDE);
    i = x;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(" ");
    i = x + 1;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(BOT_BAR);
    i = x + 1;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(" ");
    i = x + 2;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_SIDE);
    i = x + 2;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_SIDE);
    delay_ms(100);
}

void lcd_so_5(int x, int y)
{
    int i, j;
    i = x;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(LEFT_SIDE);
    i = x;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(BOT_END);
    i = x + 1;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(MID_BAR);
    i = x + 1;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(BOT_BAR);
    i = x + 2;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_END);
    i = x + 2;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_SIDE);
    delay_ms(100);
}

void lcd_so_6(int x, int y)
{
    int i, j;
    i = x;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(LEFT_SIDE);
    i = x;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(LEFT_SIDE);
    i = x + 1;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(MID_BAR);
    i = x + 1;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(BOT_BAR);
    i = x + 2;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_END);
    i = x + 2;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_SIDE);
    delay_ms(100);
}

void lcd_so_7(int x, int y)
{
    int i, j;
    i = x;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(TOP_BAR);
    i = x;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(" ");
    i = x + 1;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(TOP_BAR);
    i = x + 1;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(" ");
    i = x + 2;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_SIDE);
    i = x + 2;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_SIDE);
    delay_ms(100);
}

void lcd_so_8(int x, int y)
{
    int i, j;
    i = x;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(LEFT_SIDE);
    i = x;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(LEFT_SIDE);
    i = x + 1;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(MID_BAR);
    i = x + 1;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(BOT_BAR);
    i = x + 2;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_SIDE);
    i = x + 2;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_SIDE);
    delay_ms(100);
}

void lcd_so_9(int x, int y)
{
    int i, j;
    i = x;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(LEFT_SIDE);
    i = x;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(BOT_END);
    i = x + 1;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(MID_BAR);
    i = x + 1;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(BOT_BAR);
    i = x + 2;
    j = y;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_SIDE);
    i = x + 2;
    j = y + 1;
    lcd_gotoxy(i, j);
    lcd_putc(RIGHT_SIDE);
    delay_ms(100);
}

void Bar1()
{
    int i, j;
    for (i = 2; i <= 6; i++)
    {
        lcd_gotoxy(i, 1);
        lcd_putc(BAR_1);
    }
    for (j = 11; j <= 15; j++)
    {
        lcd_gotoxy(j, 1);
        lcd_putc(BAR_1);
    }
}

void Bar2()
{
    int i, j;
    for (i = 2; i <= 5; i++)
    {
        lcd_gotoxy(i, 2);
        lcd_putc(BAR_2);
    }
    for (j = 12; j <= 15; j++)
    {
        lcd_gotoxy(j, 2);
        lcd_putc(BAR_2);
    }
}

void Coner1()
{
    lcd_gotoxy(1, 1);
    lcd_putc(CORNER_1);
    lcd_gotoxy(16, 1);
    lcd_putc(CORNER_3);
}

void Coner2()
{
    lcd_gotoxy(1, 2);
    lcd_putc(CORNER_2);
    lcd_gotoxy(16, 2);
    lcd_putc(CORNER_4);
}

void GioiThieu()
{
    Coner1();
    Coner2();
    Bar1();
    Bar2();
    lcd_gotoxy(7, 1);
    lcd_putc("DTVT");
    lcd_gotoxy(6, 2);
    lcd_putc("GROUP9");
    delay_ms(1200);
    lcd_putc("\f");
}

void HIENTHI_SOMAX()
{

    lcd_load_custom_chars_2();
    lcd_gotoxy(1, 1);
    lcd_putc("NHAP MAX|");
    lcd_gotoxy(1, 2);
    lcd_putc("CAN  DEM|");
    int DonViSOMAX = SOMAX % 10;
    int HangChucSOMAX = SOMAX / 10;
    switch (DonViSOMAX)
    {
    case 0:
        lcd_so_0(14, 1);
        break;
    case 1:
        lcd_so_1(14, 1);
        break;
    case 2:
        lcd_so_2(14, 1);
        break;
    case 3:
        lcd_so_3(14, 1);
        break;
    case 4:
        lcd_so_4(14, 1);
        break;
    case 5:
        lcd_so_5(14, 1);
        break;
    case 6:
        lcd_so_6(14, 1);
        break;
    case 7:
        lcd_so_7(14, 1);
        break;
    case 8:
        lcd_so_8(14, 1);
        break;
    case 9:
        lcd_so_9(14, 1);
        break;
    }

    switch (HangChucSOMAX)
    {
    case 0:
        lcd_so_0(11, 1);
        break;
    case 1:
        lcd_so_1(11, 1);
        break;
    case 2:
        lcd_so_2(11, 1);
        break;
    case 3:
        lcd_so_3(11, 1);
        break;
    case 4:
        lcd_so_4(11, 1);
        break;
    case 5:
        lcd_so_5(11, 1);
        break;
    case 6:
        lcd_so_6(11, 1);
        break;
    case 7:
        lcd_so_7(11, 1);
        break;
    case 8:
        lcd_so_8(11, 1);
        break;
    case 9:
        lcd_so_9(11, 1);
        break;
    }

}
void HIENTHI_SP()
{
    lcd_gotoxy(1, 2);
    lcd_putc("SO SAN PHAM:");
    lcd_gotoxy(15, 2);
    lcd_putc(SP / 10 + 0x30);
    lcd_putc(SP % 10 + 0x30);
}

void HIENTHI_SOMAX_PHU()
{
    lcd_gotoxy(9, 1);
    lcd_putc("MAX:");
    lcd_gotoxy(15, 1);
    lcd_putc(SOMAX / 10 + 0x30);
    lcd_putc(SOMAX % 10 + 0x30);
}

void hamtang()
{
    if (input(UP) == 0)
    {
        delay_us(20);
        while (input(UP) == 0)
        {
            SOMAX = SOMAX + 1;

            while (input(UP) == 0);
        }
    }
}

void hamgiam()
{
    if (input(DW) == 0)
    {
        delay_us(20);
        while (input(DW) == 0)
        {
            SOMAX = SOMAX - 1;


            while (input(DW) == 0);
        }
    }
}

void hamxoa()
{
    if (input(XOA) == 0)
    {
        while (input(XOA) == 0)
        {
            SP = 0;
            CHON = CHON + 1;
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

    lcd_init();
    lcd_load_custom_chars_1();
    GioiThieu();
    lcd_load_custom_chars_2();
    SOMAX = 10;
    CHON = 0;
    SETUP_TIMER_0(T0_EXT_H_TO_L | T0_DIV_1);     ///// chan cam bien vao RA4 nha 
    SET_TIMER0(0);
    do
    {
        hamtang();
        hamgiam();
        HIENTHI_SOMAX();
        hamxoa();
    } while (CHON == 0);
    lcd_putc("\f");
    delay_ms(100);
    while (true)
    {
        SP = get_timer0();
        HIENTHI_SOMAX_PHU();
        HIENTHI_SP();
        hamxoa();

        if (SP == SOMAX)
        {
            WHILE(TRUE)
            {
                char i, j;
                lcd_init();
                for (j = 0; j <= 16; j++)
                {
                    for (i = 1; i <= 16; i++)
                    {
                        lcd_gotoxy(i, 2);
                        printf(lcd_putc, "%c", Mang[i + j - 1]);
                    }
                    delay_ms(200);
                }

                delay_ms(900);
            }
        }

    }
}


