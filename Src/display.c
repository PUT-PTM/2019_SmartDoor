#include "stm32f4xx.h"
#include "display.h"

int num1;
int num2;
int num3;
int num4;
int keyTab[4];
int key = 0;

void display(int keyCounter){
	  if(keyCounter > 0){
		  if(keyCounter >= 1){
			  DISP_VAL_NULL;
			  DISP_1_OFF;
			  DISP_2_OFF;
			  DISP_3_OFF;
			  DISP_4_OFF;
			  DISP_1_ON;
			  num1 = keyTab[0];
			  switch(num1){
				  case 0:
					  DISP_VAL_0;
					  HAL_Delay(1);
					  break;

				  case 1:
					  DISP_VAL_1;
					  HAL_Delay(1);
					  break;

				  case 2:
					  DISP_VAL_2;
					  HAL_Delay(1);
					  break;

				  case 3:
					  DISP_VAL_3;
					  HAL_Delay(1);
					  break;

				  case 4:
					  DISP_VAL_4;
					  HAL_Delay(1);
					  break;

				  case 5:
					  DISP_VAL_5;
					  HAL_Delay(1);
					  break;

				  case 6:
					  DISP_VAL_6;
					  HAL_Delay(1);
					  break;

				  case 7:
					  DISP_VAL_7;
					  HAL_Delay(1);
					  break;

				  default:
					  HAL_Delay(1);
					  DISP_1_OFF;
					  DISP_2_OFF;
					  DISP_3_OFF;
					  DISP_4_OFF;
			  }
		  }
		  if(keyCounter >= 2){
			  DISP_VAL_NULL;
			  DISP_1_OFF;
			  DISP_2_ON;
			  num2 = keyTab[1];
			  switch(num2){
				  case 0:
					  DISP_VAL_0;
					  HAL_Delay(1);
					  break;

				  case 1:
					  DISP_VAL_1;
					  HAL_Delay(1);
					  break;

				  case 2:
					  DISP_VAL_2;
					  HAL_Delay(1);
					  break;

				  case 3:
					  DISP_VAL_3;
					  HAL_Delay(1);
					  break;

				  case 4:
					  DISP_VAL_4;
					  HAL_Delay(1);
					  break;

				  case 5:
					  DISP_VAL_5;
					  HAL_Delay(1);
					  break;

				  case 6:
					  DISP_VAL_6;
					  HAL_Delay(1);
					  break;

				  case 7:
					  DISP_VAL_7;
					  HAL_Delay(1);
					  break;

				  default:
					  HAL_Delay(1);
					  DISP_1_OFF;
					  DISP_2_OFF;
					  DISP_3_OFF;
					  DISP_4_OFF;
			  }
		  }
		  if(keyCounter >= 3){
			  DISP_VAL_NULL;
			  DISP_3_ON;
			  DISP_2_OFF;
			  num3 = keyTab[2];
			  switch(num3){
				  case 0:
					  DISP_VAL_0;
					  HAL_Delay(1);
					  break;

				  case 1:
					  DISP_VAL_1;
					  HAL_Delay(1);
					  break;

				  case 2:
					  DISP_VAL_2;
					  HAL_Delay(1);
					  break;

				  case 3:
					  DISP_VAL_3;
					  HAL_Delay(1);
					  break;

				  case 4:
					  DISP_VAL_4;
					  HAL_Delay(1);
					  break;

				  case 5:
					  DISP_VAL_5;
					  HAL_Delay(1);
					  break;

				  case 6:
					  DISP_VAL_6;
					  HAL_Delay(1);
					  break;

				  case 7:
					  DISP_VAL_7;
					  HAL_Delay(1);
					  break;

				  default:
					  HAL_Delay(1);
					  DISP_1_OFF;
					  DISP_2_OFF;
					  DISP_3_OFF;
					  DISP_4_OFF;
			  }
		  }
		  if(keyCounter >= 4){
			  DISP_VAL_NULL;
			  DISP_3_OFF;
			  DISP_4_ON;
			  num4 = keyTab[3];
			  switch(num4){
				  case 0:
					  DISP_VAL_0;
					  HAL_Delay(1);
					  break;

				  case 1:
					  DISP_VAL_1;
					  HAL_Delay(1);
					  break;

				  case 2:
					  DISP_VAL_2;
					  HAL_Delay(1);
					  break;

				  case 3:
					  DISP_VAL_3;
					  HAL_Delay(1);
					  break;

				  case 4:
					  DISP_VAL_4;
					  HAL_Delay(1);
					  break;

				  case 5:
					  DISP_VAL_5;
					  HAL_Delay(1);
					  break;

				  case 6:
					  DISP_VAL_6;
					  HAL_Delay(1);
					  break;

				  case 7:
					  DISP_VAL_7;
					  HAL_Delay(1);
					  break;

				  default:
					  HAL_Delay(1);
					  DISP_1_OFF;
					  DISP_2_OFF;
					  DISP_3_OFF;
					  DISP_4_OFF;
			  }
		  }
	  }
	  if(keyCounter == 0 && key == 0){
		  DISP_VAL_NULL;
		  DISP_3_OFF;
		  DISP_1_ON;
		  DISP_VAL_O;

		  HAL_Delay(1);
		  DISP_VAL_NULL;
		  DISP_1_OFF;
		  DISP_2_ON;
		  DISP_VAL_F;

		  HAL_Delay(1);

		  DISP_VAL_NULL;
		  DISP_2_OFF;
		  DISP_3_ON;
		  DISP_VAL_F;

		  HAL_Delay(1);

		  DISP_1_OFF;
		  DISP_2_OFF;
		  DISP_3_OFF;
		  DISP_4_OFF;
	  }
	  else if (keyCounter == 0 && key == 1){
		  DISP_VAL_NULL;
		  DISP_2_OFF;
		  DISP_1_ON;
		  DISP_VAL_O;

		  HAL_Delay(1);
		  DISP_VAL_NULL;
		  DISP_1_OFF;
		  DISP_2_ON;
		  DISP_VAL_N;

		  HAL_Delay(1);

		  DISP_1_OFF;
		  DISP_2_OFF;
		  DISP_3_OFF;
		  DISP_4_OFF;
	  }
}
