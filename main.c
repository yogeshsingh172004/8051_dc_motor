#include<reg51.h>

// DEFINING LED PINS 
sbit in1 = P1^0;
sbit in2 = P1^1;

sbit ena = P1^7;

// DEFINING BUTTON PINS

sbit sw1 = P2^0;
sbit sw2 = P2^1;
sbit sw3 = P2^2;
sbit sw4 = P2^3;
sbit sw5 = P2^4;
sbit sw6 = P2^5;
sbit sw7 = P2^6;
sbit sw8 = P2^7;


// SOFTWARE DELAY LOGIC

void delay(int time)
{
	int i,j;
	
	for( i = 0 ; i < time ; i++ )
	{
		for( j = 0 ; j < 1275 ; j++ );
		
	}
}

void s(); // stop declared

void f() // forward
{ // f start
	s();
	in1 = 1;
	in2 = 0;
} // f end

void b() // backward 
{ // b start
	s();
	in2 = 1;
	in1 = 0;
} // b end

void s() // start
{// s start
	delay (20);
	in1 = 0;
	in2 = 0;
	delay(20);
} // s end


// MAIN LOGIC

void main()
	
{ // main start 
	
	int ms = 0;
	
	P1 = 0x00;
	P2 = 0xff;
	
	ena = 1;
	
	while(1)
	{ // while start
		if( sw1 == 0 )
		{  // if_1_1 _s
			delay(20);
			if ( sw1 ==0 )
			{ // if_1_2_s
						
			if (ms == 1) // if_1_3_s
			{
				continue;
				
			} // if_1_3_e
			
			else { // else_1_s
					delay(20);
			f();
				
				ms = 1;
				
			} // else_1_e
			while(sw1 == 0);
		} // if_1_2_e
		} //if_1_1_e
		
		else if ( sw2 == 0 )
		{  // if_2_1_s
				delay(20);
			if (sw2 == 0)
			{ // if_2_2_s
			
			if(ms == 2)
			{ // if_2_3_s
				continue;
			} // if_2_3_e
			else{ // else_2_s
				delay(20);
			b();
				ms = 2;
			}		// else_2_e
     while(sw2 == 0);			
		} // if_2_2_e
	} // if_2_1_e
		
		
		else if ( sw3 == 0) 
		{ // if_3_1_s
				delay(20);
			if(sw3 == 0)
			{ // if_3_2_s
			if (ms == 0)
			{ // if_3_3_s
				continue;
			} // if_3_3_e
			else{ // else_3_s
			delay(20);
			s();
				ms = 0;
			} // else_3_e
			while(sw3 == 0);
		} // if_3_2_e
	} // if_3_1_e
		
} // while end

} // main end
