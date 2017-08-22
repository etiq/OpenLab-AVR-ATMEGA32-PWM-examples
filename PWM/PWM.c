/*
 *File Name:         PWM.c
 *
 * Created:        3/23/2016 10:00:52 AM
 * Author :        Etiq technologies
 Description:       The code implements a gradually varying PWM to control the speed of a DC motor
 */ 

#ifdef F_CPU              //defines the CPU clock to be 8 MHz
#define F_CPU 8000000UL
#endif // F_CPU


#include <avr/io.h>
#include <util/delay.h>

void configure_timer()    //configures the timer module in pwm mode,frequency
{
TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS01);
	
}

void  Set_duty(unsigned char duty)    //duty cycle value assigned to OCR0 register
{
	OCR0=duty;
}

int main(void)
{   
	unsigned char i;                       //PB3 bit set as output
	DDRB|=(1<<PB3);
    configure_timer();
	
    while (1)                                //gradually varying the pwm dutycycle
    {
		for(i=0;i<255;i++)
		{
		Set_duty(i);
		_delay_ms(50);	
    }
	for(i=255;i>0;i--)
	{
		Set_duty(i);
		_delay_ms(50);	
	}
}
}

