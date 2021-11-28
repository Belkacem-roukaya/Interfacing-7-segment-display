void EXTI0_IRQ Handler()
{
    for (init i=9 ; i>0 ;i--)
    {
         wrie_Led_7_segment(i);
         Delay(0x003FFFFF);
    }
    EXTI_ClearITpendingBit(EXTI_Line0);

}