/* 
 * File:   uart.c
 * Author: bocal
 *
 * Created on April 25, 2016, 6:12 PM
 */

#include "types.h"
#include <p32xxxx.h>

/*
** Coucou
*/

void    init_uart()
{
    U1BRG = 1000000 / (9600 * 16) - 1;
    U1MODEbits.PDSEL = 0x00;
    U1MODEbits.STSEL = 0x00;
    U1STA = 0;
   // U1MODE = 0x8000;
    U1STASET = 0x400; // Set UTXEN bit for Transmission
    U1MODEbits.BRGH = 0;
    U1MODEbits.ON = 1;
}

void    load_data(char *data)
{
    while (*data)
    {
        U1TXREG = *data;
        data++;
    }
}

int main(int argc, char** argv)
{
 //   char    data[5];

//    data[0] = 'A';
  //  data[1] = 'B';
  //  data[2] = 'C';
  //  data[3] = 'D';
  //  data[4] = 0;
    init_uart();
   // load_data(data);
    U1TXREG = 'Z';
}