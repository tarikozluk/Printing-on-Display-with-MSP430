//Hazırlanmış Şablon hızlıca kullanmak için






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

//const char x1[] ="line 40,120,160,,BLUE";

const char x0[] ="fill 40,199,160,3,RED";

const char y0[]="fill 119,40,3,320,RED";

//const char y2[]="line 120,40,0,320,BLUE";

//Coordinates can be more and changed according to projects
// line command for nextion editor: line x1,y1,x2,y2
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
       
    transmit(dim);
    transmit(term_string); 
    transmit(yellow_screen);                   // clear screen
    transmit(term_string);
       
    transmit(y0);
    transmit(term_string);
    transmit(x0);
    transmit(term_string);

// Part for another installs according to projects with Nextion Display models
// Install the necesseries in addition to this code
}
