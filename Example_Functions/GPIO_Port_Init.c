#include <stdint.h>
#include "stm32f401_gpio.h"
#include "stm32f401_rcc.h"
#include "stm32f4xx.h"

/*This example displays how to write and read from all the pins associated with a port. In this program,
 * I initialized Port C as input (to read from pushbuttons) and Port A as output. Using an external breadboard,
 * I attached multiple pushbuttons and LEDS to ports C and A respectively on the nucleo-board.
 *
 * To read the values of port C, I created a variable "portc" that would hold the return value of the GPIO_ReadPort() function.
 * Using the debugging feature, the value of this variable can be monitored as various pushbuttons are pressed and released.
 * The value of this specific function will also depend on whether the pushbuttons are using pull-up or pull-down resistors.
 *
 * Additionally, I also wrote all the pins on GPIOA to high using the GPIO_WritePort() function, which turned on all of the LEDs
 * connected to a pin associated with Port A. Due to PA5 being an on-board pushbutton, the LED on the board also turned on.
 *
 * As demonstrated in this example, this driver gives the user the ability to easily read and write to multiple or all of the pins
 * of a port. The functions work very similarly to the GPIo_ReadPin() and GPIO_WritePin function.
 */

uint16_t portc;

int main()
{
	//Initializing all pins in port C as input
	GPIO_Config_t PortC;
	GPIO_Config(&PortC, GPIOC, AllPins, GPIO_Input, GPIO_PushPull, GPIO_LowSpeed, GPIO_PullDown);
	GPIO_Init(&PortC);

	//Initializing all pins in port A as output
	GPIO_Config_t PortA;
	GPIO_Config(&PortA, GPIOA, AllPins, GPIO_Output, GPIO_PushPull, GPIO_LowSpeed, GPIO_PUPD_None);
	GPIO_Init(&PortA);


	while (1)
	{
		//Reading from port C
		portc = GPIO_ReadPort(&PortC);

		//Writing a value to Port A
		GPIO_WritePort(&PortA, 0xffff);

	}
}


