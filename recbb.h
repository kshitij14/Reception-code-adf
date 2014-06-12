/*
 * recbb.h
 *
 *  Created on: Jun 12, 2014
 *      Author: kshitij
 */

#ifndef RECBB_H_
#define RECBB_H_

#include <msp430.h>

//pin definiations

#define BITBANG_CE_PxDIR       P1DIR
#define BITBANG_CE_PxOUT       P1OUT
#define BITBANG_CE_BIT         BIT1

#define BITBANG_SREAD_PxDIR   P1DIR
#define BITBANG_SREAD_PxOUT   P1OUT
#define BITBANG_SREAD_BIT     BIT4
#define BITBANG_SREAD_PxIN   P1IN
#define BITBANG_SREAD_PxREN  P1REN

#define BITBANG_SLE_PxDIR   P1DIR
#define BITBANG_SLE_PxOUT   P1OUT
#define BITBANG_SLE_BIT     BIT2

#define BITBANG_SDATA_PxDIR  P1DIR
#define BITBANG_SDATA_PxOUT  P1OUT
#define BITBANG_SDATA_BIT    BIT0
#define BITBANG_SDATA_PxREN  P1REN

#define BITBANG_SCLK_PxDIR   P1DIR
#define BITBANG_SCLK_PxOUT   P1OUT
#define BITBANG_SCLK_BIT     BIT3

#define TXRXDATA_PxDIR       P2DIR
#define TXRXDATA_PxOUT       P2OUT
#define TXRXDATA_BIT         BIT0
#define TXRXDATA_PxIN		 P2IN				//TXRXDATA is output for Tx mode and input for Rx mode

#define TXRXCLK_PxDIR       P2DIR
#define TXRXCLK_PxOUT       P2OUT
#define TXRXCLK_PxIN		P2IN
#define TXRXCLK_BIT         BIT1				//TXRXCLK in input for both Tx Rx modes. ADF is the master.

#define SWD_PxDIR 			P2DIR
#define SWD_PxOUT			P2OUT
#define SWD_PxIN			P2IN
#define SWD_BIT				BIT3
#define SWD_PxREN			P2REN


/* PROPTYPING FUNCTIONS */
void bitbang_initialise();
void bitbang_deinialise();
void bitbang_write(unsigned char data);
long bitbang_read(unsigned char bitsize);

void init_reception();


/** beginning of new register writing for a 10mhz crystal**/
void regwrite0();
void regwrite1();
void regwrite2();
void regwrite3();
void regwrite4();
void regwrite5();
void regwrite6();
void regwrite7();
void regwrite9();
void regwrite10();
void regwrite11();
void regwrite12();
void regwrite13();


#endif /* RECBB_H_ */
