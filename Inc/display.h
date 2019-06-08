#define DISP_1_ON   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET)
#define DISP_1_OFF  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET)
#define DISP_2_ON   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET)
#define DISP_2_OFF  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET)
#define DISP_3_ON   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET)
#define DISP_3_OFF  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET)
#define DISP_4_ON   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET)
#define DISP_4_OFF  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET)

#define DISP_VAL_NULL HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0 | GPIO_PIN_1 | \
                                               GPIO_PIN_2 | GPIO_PIN_3 | \
                                               GPIO_PIN_4 | GPIO_PIN_5 | \
                                               GPIO_PIN_6 | GPIO_PIN_7 , \
                                               GPIO_PIN_SET)

#define DISP_VAL_0	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0 | GPIO_PIN_1 | \
                                              GPIO_PIN_2 | GPIO_PIN_3 | \
                                              GPIO_PIN_4 | GPIO_PIN_5 , \
                                              GPIO_PIN_RESET)
#define DISP_VAL_1	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1 | GPIO_PIN_2 , \
                                              GPIO_PIN_RESET)
#define DISP_VAL_2	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0 | GPIO_PIN_1 | \
                                              GPIO_PIN_3 | GPIO_PIN_4 | \
                                              GPIO_PIN_6 , \
                                              GPIO_PIN_RESET)
#define DISP_VAL_3	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0 | GPIO_PIN_1 | \
                                              GPIO_PIN_2 | GPIO_PIN_3 | \
                                              GPIO_PIN_6 , \
                                              GPIO_PIN_RESET)
#define DISP_VAL_4	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1 | GPIO_PIN_2 | \
    	                                       GPIO_PIN_5 | GPIO_PIN_6 , \
                                              GPIO_PIN_RESET)
#define DISP_VAL_5	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0 | GPIO_PIN_2 | \
                                              GPIO_PIN_3 | GPIO_PIN_5 | \
                                              GPIO_PIN_6 , \
                                              GPIO_PIN_RESET)
#define DISP_VAL_6	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0 | GPIO_PIN_2 | \
                                              GPIO_PIN_3 | GPIO_PIN_4 | \
                                              GPIO_PIN_5 | GPIO_PIN_6 , \
                                              GPIO_PIN_RESET)
#define DISP_VAL_7	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0 | GPIO_PIN_1 | \
                                              GPIO_PIN_2 , \
                                              GPIO_PIN_RESET)
#define DISP_VAL_8	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0 | GPIO_PIN_1 | \
                                              GPIO_PIN_2 | GPIO_PIN_3 | \
                                              GPIO_PIN_4 | GPIO_PIN_5 | \
                                              GPIO_PIN_6 , \
                                              GPIO_PIN_RESET)
#define DISP_VAL_9	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0 | GPIO_PIN_1 | \
                                              GPIO_PIN_2 | GPIO_PIN_3 | \
                                              GPIO_PIN_5 | GPIO_PIN_6 , \
                                              GPIO_PIN_RESET)

#define DISP_DOT  	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7 , \
                                              GPIO_PIN_RESET)

#define DISP_VAL_O	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0 | GPIO_PIN_1 | \
                                              GPIO_PIN_2 | GPIO_PIN_3 | \
                                              GPIO_PIN_4 | GPIO_PIN_5 , \
                                              GPIO_PIN_RESET)
#define DISP_VAL_N	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | \
												GPIO_PIN_4 | GPIO_PIN_5, GPIO_PIN_RESET)

#define DISP_VAL_F	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0 | GPIO_PIN_4 | \
												GPIO_PIN_5 | GPIO_PIN_6, GPIO_PIN_RESET)


void display(int keyCounter);
