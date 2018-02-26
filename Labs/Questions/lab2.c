#include "xparameters.h"
#include "xgpio.h"
#include "xstatus.h"

//====================================================
    XGpio dip, push, leds;
//int led_out(void)
//{
//volatile int j;
//int status;
//int led = 0xf0;
//
//status = XGpio_Initialize(&leds, XPAR_LEDS_DEVICE_ID);
//if(status!=XST_SUCCESS)
//{	return XST_FAILURE;
//}
//XGpio_SetDataDirection(&leds, 1, 0x00);
//
//while(1)
//{
//	XGpio_DiscreteWrite(&leds, 1,led);
//led = ~led;
//for(j=0;j<100000000;j++);
//}
//return XST_SUCCESS;
//}

int main (void) 
{


	int psb_check, dip_check, led_status;
	int led = 0xf0;
    xil_printf("-- Start of the Program --\r\n");
 
    XGpio_Initialize(&dip, XPAR_SWITCH_DEVICE_ID);
	XGpio_SetDataDirection(&dip, 1, 0xff);
	
	XGpio_Initialize(&push, XPAR_BTNS_DEVICE_ID);
	XGpio_SetDataDirection(&push, 1, 0xff);
	
	XGpio_Initialize(&leds, XPAR_LEDS_DEVICE_ID);
	XGpio_SetDataDirection(&leds, 1, 0x00);

	while (1)
		{
		  psb_check = XGpio_DiscreteRead(&push, 1);
		  xil_printf("Push Buttons Status %x\r\n", psb_check);
		  dip_check = XGpio_DiscreteRead(&dip, 1);
		  xil_printf("DIP Switch Status %x\r\n", dip_check);
		 XGpio_DiscreteWrite(&leds, 1,led);
		 led = ~led;
		  sleep(1);
		}

//	led_status = led_out();
 
}
 
