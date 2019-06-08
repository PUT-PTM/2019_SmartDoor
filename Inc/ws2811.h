#ifndef WS2811_H_
#define WS2811_H_

#define numberOfLEDS 50
#define high 101
#define low 27
#define ret 0


typedef struct BRG {
	uint8_t B;
	uint8_t R;
	uint8_t G;
	double alpha;
} BRG;

void decimalToBinary(BRG LEDstruct[], uint8_t binaryLED[]);
void setDiode(BRG LEDstruct[], int n, uint8_t r, uint8_t g, uint8_t b, double a);
void allRed(BRG LEDstruct[]);
void allGreen(BRG LEDstruct[]);
void allBlue(BRG LEDstruct[]);
void turnOFF(BRG LEDstruct[]);
void even(BRG LEDstruct[]);
void odd(BRG LEDstruct[]);

#endif
