#include <msp430.h>
#include <stdio.h>
void transmit(const char *str);
void adc(const char *ADCresult);
void transmit(const char *str){
       while(*str != 0){
           while(!(UCTXIFG & UCA0IFG));
           UCA0TXBUF = *str++;
       }
   }

const char yellow_screen[] = "cls YELLOW";
const char dim[] = "dim=80";
const char x1[] ="line 40,40,200,40,BLUE";
const char x0[] ="line 40,40,40,360,BLUE";
const char x20[] ="line 200,40,200,360,BLUE";
const char x10[]="line 40,20,200,20,BLUE";
const char x11[]="line 40,60,200,60,BLUE";
const char x12[]="line 40,100,200,100,BLUE";
const char x13[]="line 40,140,200,140,BLUE";
const char x14[]="line 40,180,200,180,BLUE";
const char x15[]="line 40,220,200,220,BLUE";
const char x16[]="line 40,260,200,260,BLUE";
const char x17[]="line 40,300,200,300,BLUE";
const char x18[]="line 40,340,200,340,BLUE";
const char x19[]="line 40,380,200,380,BLUE";
const char x2[] ="line 40,80,200,80,BLUE";
const char x3[] ="line 40,120,200,120,BLUE";
const char x4[] ="line 40,160,200,160,BLUE";
const char x5[] ="fill 40,199,160,3,RED";
const char x6[]="line 40,240,200,240,BLUE";
const char x7[]="line 40,280,200,280,BLUE";
const char x8[]="line 40,320,200,320,BLUE";
const char x9[]="line 40,360,200,360,BLUE";
const char y1[]="line 40,0,40,400,BLUE";
const char y2[]="line 80,40,80,360,BLUE";
const char y3[]="fill 119,40,3,320,RED";
const char y4[]="line 160,40,160,360,BLUE";
const char y6[]="line 20,0,20,400,BLUE";
const char y5[]="line 200,0,200,400,BLUE";
const char y7[]="line 60,40,60,360,BLUE";
const char y8[]="line 100,40,100,360,BLUE";
const char y9[]="line 140,40,140,360,BLUE";
const char y10[]="line 180,40,180,360,BLUE";
const char y11[]="line 220,0,220,400,BLUE";
const char term_string[4] = {255,255,255,0};
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;                // stop watchdog timer
    P3SEL=BIT3 + BIT4;
    TA1CTL = TASSEL_2 + MC_1 + ID_3;
    TA1CCR0=3277;
    UCA0CTL1 |= UCSWRST;
    UCA0CTL1 |= UCSSEL_2;
    UCA0BR0 = 6;
    UCA0BR1 = 0;
    UCA0MCTL = UCBRS_0 + UCBRF_13 + UCOS16;
    UCA0CTL1 &= ~UCSWRST;
    transmit(yellow_screen);                   // clear screen
    transmit(term_string);
