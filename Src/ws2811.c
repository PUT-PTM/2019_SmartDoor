#include "stm32f4xx_hal.h"
#include "ws2811.h"



void decimalToBinary(BRG LEDstruct[], uint8_t binaryLED[]){
	int x = 0;
	uint8_t b = 0;
	uint8_t r = 0;
	uint8_t g = 0;
	int temp;
	for (int y = 0; y < 50; y++) {
		b = LEDstruct[y].B * LEDstruct[y].alpha;
		r = LEDstruct[y].R * LEDstruct[y].alpha;
		g = LEDstruct[y].G * LEDstruct[y].alpha;
		temp = 0;
		while (temp < 8) {
			binaryLED[x] = b % 2;
			b = b / 2;
			x++;
			temp++;
		}
		temp = 0;
		while (temp < 8) {
			binaryLED[x] = r % 2;
			r = r / 2;
			x++;
			temp++;
		}
		temp = 0;
		while (temp < 8) {
			binaryLED[x] = g % 2;
			g = g / 2;
			x++;
			temp++;
		}
	}
}

void setDiode(BRG LEDstruct[], int n, uint8_t b, uint8_t r, uint8_t g, double a){
	LEDstruct[n].B = b;
	LEDstruct[n].R = r;
	LEDstruct[n].G = g;
	LEDstruct[n].alpha = a;
}

void allRed(BRG LEDstruct[]){
	for(int x = 0; x < numberOfLEDS; x++){
		LEDstruct[x].B = 0;
		LEDstruct[x].R = 255;
		LEDstruct[x].G = 0;
		LEDstruct[x].alpha = 1;
	}
}

void allGreen(BRG LEDstruct[]){
	for(int x = 0; x < numberOfLEDS; x++){
		LEDstruct[x].B = 0;
		LEDstruct[x].R = 0;
		LEDstruct[x].G = 255;
		LEDstruct[x].alpha = 1;
	}
}

void allBlue(BRG LEDstruct[]){
	for(int x = 0; x < numberOfLEDS; x++){
		LEDstruct[x].B = 255;
		LEDstruct[x].R = 0;
		LEDstruct[x].G = 0;
		LEDstruct[x].alpha = 1;
	}
}

void turnOFF(BRG LEDstruct[]){
	for(int x = 0; x < numberOfLEDS; x++){
		LEDstruct[x].B = 0;
		LEDstruct[x].R = 0;
		LEDstruct[x].G = 0;
		LEDstruct[x].alpha = 0;
	}
}

void even(BRG LEDstruct[]){
	for(int x = 0; x < numberOfLEDS; x++){
		if(x%2==0){
			LEDstruct[x].B = 0;
			LEDstruct[x].R = 0;
			LEDstruct[x].G = 255;
			LEDstruct[x].alpha = 1;
		}
		else{
			LEDstruct[x].B = 0;
			LEDstruct[x].R = 0;
			LEDstruct[x].G = 0;
			LEDstruct[x].alpha = 0;
		}
	}
}

void odd(BRG LEDstruct[]){
	for(int x = 0; x < numberOfLEDS; x++){
		if(x%2!=0){
			LEDstruct[x].B = 0;
			LEDstruct[x].R = 0;
			LEDstruct[x].G = 255;
			LEDstruct[x].alpha = 1;
		}
		else{
			LEDstruct[x].B = 0;
			LEDstruct[x].R = 0;
			LEDstruct[x].G = 0;
			LEDstruct[x].alpha = 0;
		}
	}
}


