#include <msp430.h> 

/*
 * main.c
 * author : kshitij
 * data : 12th june 2014
 */

#include "recbb.h"

unsigned char buf[3];
int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    bitbang_initialise();


	/*write to all the needed registers and configure their values*/
	regwrite2();

	regwrite9();

	regwrite13();

	regwrite1();
			__delay_cycles(10000);
	regwrite3();

	regwrite6();

	regwrite5();
			__delay_cycles(10000);
	regwrite11();

	regwrite12();

	regwrite0();
			__delay_cycles(10000);
	regwrite4();

	regwrite10();
	/* now in Tx Mode */


	init_reception();
	/* initialise the gpio pins required for initiating the reception mode*/
	
	 P2IE |= SWD_BIT;                                 //interupt set on SWD
	 P2IES &= ~SWD_BIT;		                         //LOW TO HIGH EDGE SELECTED
	 _BIS_SR(GIE);        	                        // Enter w/interrupt
        
        /* else,
        while(!(swd pin & swd bit); - waits for swd pin to go high
        run the loop
        */
        


	 return 0;
	 }



	#pragma vector = PORT2_VECTOR
	__interrupt void swdvector(void)

	{
	unsigned char t,i,stop,lion;
	t=0;
	stop=0;
	lion = 0;
	while(!stop)
	{
		for(i=0; i<8; i++)
		{
			while(!(TXRXCLK_PxIN & TXRXCLK_BIT));
		t=t<<1;
		if((TXRXDATA_PxIN & TXRXDATA_BIT) != 0 )
			t = t + 1;
		else
			t = t + 0;

		while (TXRXCLK_PxIN & TXRXCLK_BIT);
		}

	buf[lion] = t;
	lion++;

	if ( t == 0xFF)
	{ stop = 1; }
	}
	}


/*
 * 1) initiailse gpio for both register writing and actual data
 * 2) initialise registers, write to specific registers.
 * 3) write an ISR for SWD
 * 4) data is stored in an array buffer.
 */
