#ifndef __7 SEGMENT DISPLAYINTER_H__
#define __7 SEGMENT DISPLAYINTER_H__

/* Includes */
#include "stm32f4xx.h"

/* private typedef */
GPIO_IntTypeDef GPIO_InitStructure ;
EXTI_InitTypeDef EXTI;
NVIC_InitTypeDef NVIC;

/* private variables */
unit8_t number ;

/* private function prototype */
extern void Delay(_IO unit32_t nCount);
extern void write_led_7_segment(_IO unit8_t number);

int main(void)
{
    /* GPIOA periph clock enable */
    RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOA ,ENABLE);
    /* enable SYSCFG Clock */
     RCC_AHB2PeriphClockCmd(RCC_AHB1Periph_SYSCFG , ENABLE);

    /* configue 7 segment display : PA1, PA2,PA3, PA4,PA5, PA6,PA7, PA8 */
    GPIO_InitStructure.GPIO_Pin= GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode= GPIO_Mode_OUT ;
    GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz ;
    GPIO_InitStructure.GPIO_OType= GPIO_OType_PP ;
    GPIO_InitStructure.GPIO_PuPd=  GPIO_PuPd_DOWN;

    /* Initialisation de la structure au GPIOA */
    GPIO_Init( GPIOA, & GPIO_InitStructure);


    /* Pin A0 of Push Button input as floating  */
    GPIO_InitStructure.GPIO_Pin= GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode= GPIO_Mode_IN ;
    GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz ;
    GPIO_InitStructure.GPIO_OType= GPIO_OType_PP ;
    GPIO_InitStructure.GPIO_PuPd=  GPIO_PuPd_DOWN;
    GPIO_Init( GPIOA, & GPIO_InitStructure);

    /*  EXTI configuration et initalisation */
  EXTI.EXTI_Line = EXTI_Line0;
  EXTI.EXTI_Mode = EXTI_Mode_Interrupt;//Event
  EXTI.EXTI_LineCmd = ENABLE;
  EXTI.EXTI_Trigger = EXTI_Trigger_Rising;//Falling
  EXTI_Init(&EXTI);

  /* NVIC confiquration et initlisation */
  NVIC.NVIC_IRQChannel = EXTI0_IRQn;
   NVIC.NVIC_IRQChannelCmd = ENABLE;
  NVIC.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC.NVIC_IRQChannelSubPriority = 2;
  NVIC_Init(&NVIC);

  /* connexion pinA0 et exti*/
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);





    while (1)
    {for (int i=0 ;i<10;i++){
        write_led_7_segment(i);
        Delay(0x003FFFFF);
    }
    }
}
void Delay(_IO unit32_t nCount)
{
    while(nCount >0)
    {
nCount-- ;
    }
}
void write_led_7_segment(_IO unit8_t number){
    GPIO_writeBit(GPIOA, GPIO_Pin_8,Bit_SET); //led DP
    if (number == 0){
        GPIO_writeBit( GPIOA, GPIO_Pin_1, Bit_SET); //led A
        GPIO_writeBit( GPIOA, GPIO_Pin_2, Bit_SET); //led B
        GPIO_writeBit( GPIOA, GPIO_Pin_3, Bit_SET); //led C
        GPIO_writeBit( GPIOA, GPIO_Pin_4, Bit_SET); //led D
        GPIO_writeBit( GPIOA, GPIO_Pin_5, Bit_SET); //led E
        GPIO_writeBit( GPIOA, GPIO_Pin_6, Bit_SET); //led F
        GPIO_writeBit( GPIOA, GPIO_Pin_7, Bit_RESET); //led G
    }

     if (number == 1){
        GPIO_writeBit( GPIOA, GPIO_Pin_1, Bit_RESET); //led A
        GPIO_writeBit( GPIOA, GPIO_Pin_2, Bit_SET); //led B
        GPIO_writeBit( GPIOA, GPIO_Pin_3, Bit_SET); //led C
        GPIO_writeBit( GPIOA, GPIO_Pin_4, Bit_RESET); //led D
        GPIO_writeBit( GPIOA, GPIO_Pin_5, Bit_RESET); //led E
        GPIO_writeBit( GPIOA, GPIO_Pin_6, Bit_RESET); //led F
        GPIO_writeBit( GPIOA, GPIO_Pin_7, Bit_RESET); //led G
    }

     if (number == 2){
        GPIO_writeBit( GPIOA, GPIO_Pin_1, Bit_SET); //led A
        GPIO_writeBit( GPIOA, GPIO_Pin_2, Bit_SET); //led B
        GPIO_writeBit( GPIOA, GPIO_Pin_3, Bit_RESET); //led C
        GPIO_writeBit( GPIOA, GPIO_Pin_4, Bit_SET); //led D
        GPIO_writeBit( GPIOA, GPIO_Pin_5, Bit_SET); //led E
        GPIO_writeBit( GPIOA, GPIO_Pin_6, Bit_RESET); //led F
        GPIO_writeBit( GPIOA, GPIO_Pin_7, Bit_SET); //led G
    }

     if (number == 3){
        GPIO_writeBit( GPIOA, GPIO_Pin_1, Bit_SET); //led A
        GPIO_writeBit( GPIOA, GPIO_Pin_2, Bit_SET); //led B
        GPIO_writeBit( GPIOA, GPIO_Pin_3, Bit_SET); //led C
        GPIO_writeBit( GPIOA, GPIO_Pin_4, Bit_SET); //led D
        GPIO_writeBit( GPIOA, GPIO_Pin_5, Bit_RESET); //led E
        GPIO_writeBit( GPIOA, GPIO_Pin_6, Bit_RESET); //led F
        GPIO_writeBit( GPIOA, GPIO_Pin_7, Bit_SET); //led G
    }
     if (number == 4){
        GPIO_writeBit( GPIOA, GPIO_Pin_1, Bit_RESET); //led A
        GPIO_writeBit( GPIOA, GPIO_Pin_2, Bit_SET); //led B
        GPIO_writeBit( GPIOA, GPIO_Pin_3, Bit_SET); //led C
        GPIO_writeBit( GPIOA, GPIO_Pin_4, Bit_RESET); //led D
        GPIO_writeBit( GPIOA, GPIO_Pin_5, Bit_RESET); //led E
        GPIO_writeBit( GPIOA, GPIO_Pin_6, Bit_SET); //led F
        GPIO_writeBit( GPIOA, GPIO_Pin_7, Bit_SET); //led G
    }
     if (number == 5){
        GPIO_writeBit( GPIOA, GPIO_Pin_1, Bit_SET); //led A
        GPIO_writeBit( GPIOA, GPIO_Pin_2, Bit_RESET); //led B
        GPIO_writeBit( GPIOA, GPIO_Pin_3, Bit_SET); //led C
        GPIO_writeBit( GPIOA, GPIO_Pin_4, Bit_SET); //led D
        GPIO_writeBit( GPIOA, GPIO_Pin_5, Bit_RESET); //led E
        GPIO_writeBit( GPIOA, GPIO_Pin_6, Bit_SET); //led F
        GPIO_writeBit( GPIOA, GPIO_Pin_7, Bit_SET); //led G
    }
     if (number == 6){
        GPIO_writeBit( GPIOA, GPIO_Pin_1, Bit_SET); //led A
        GPIO_writeBit( GPIOA, GPIO_Pin_2, Bit_RESET); //led B
        GPIO_writeBit( GPIOA, GPIO_Pin_3, Bit_SET); //led C
        GPIO_writeBit( GPIOA, GPIO_Pin_4, Bit_SET); //led D
        GPIO_writeBit( GPIOA, GPIO_Pin_5, Bit_SET); //led E
        GPIO_writeBit( GPIOA, GPIO_Pin_6, Bit_SET); //led F
        GPIO_writeBit( GPIOA, GPIO_Pin_7, Bit_SET); //led G
    }
    if (number == 7){
        GPIO_writeBit( GPIOA, GPIO_Pin_1, Bit_SET); //led A
        GPIO_writeBit( GPIOA, GPIO_Pin_2, Bit_SET); //led B
        GPIO_writeBit( GPIOA, GPIO_Pin_3, Bit_SET); //led C
        GPIO_writeBit( GPIOA, GPIO_Pin_4, Bit_RESET); //led D
        GPIO_writeBit( GPIOA, GPIO_Pin_5, Bit_RESET); //led E
        GPIO_writeBit( GPIOA, GPIO_Pin_6, Bit_RESET); //led F
        GPIO_writeBit( GPIOA, GPIO_Pin_7, Bit_RESET); //led G
    } 
    if (number == 8){
        GPIO_writeBit( GPIOA, GPIO_Pin_1, Bit_SET); //led A
        GPIO_writeBit( GPIOA, GPIO_Pin_2, Bit_SET); //led B
        GPIO_writeBit( GPIOA, GPIO_Pin_3, Bit_SET); //led C
        GPIO_writeBit( GPIOA, GPIO_Pin_4, Bit_SET); //led D
        GPIO_writeBit( GPIOA, GPIO_Pin_5, Bit_SET); //led E
        GPIO_writeBit( GPIOA, GPIO_Pin_6, Bit_SET); //led F
        GPIO_writeBit( GPIOA, GPIO_Pin_7, Bit_SET); //led G
    } 
    if (number == 9){
        GPIO_writeBit( GPIOA, GPIO_Pin_1, Bit_SET); //led A
        GPIO_writeBit( GPIOA, GPIO_Pin_2, Bit_SET); //led B
        GPIO_writeBit( GPIOA, GPIO_Pin_3, Bit_SET); //led C
        GPIO_writeBit( GPIOA, GPIO_Pin_4, Bit_SET); //led D
        GPIO_writeBit( GPIOA, GPIO_Pin_5, Bit_RESET); //led E
        GPIO_writeBit( GPIOA, GPIO_Pin_6, Bit_SET); //led F
        GPIO_writeBit( GPIOA, GPIO_Pin_7, Bit_SET); //led G
    } 
}
#endif // __7 SEGMENT DISPLAYINTER_H__