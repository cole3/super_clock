/*********************************************************************************************************
**				                               Small RTOS(51)
**                                   The Real-Time Kernel(For Keil c51)
**
**                                  (c) Copyright 2002-2003, chenmingji
**                                           All Rights Reserved
**
**                                                  V1.20.0
**
**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**��   ��   ��: ext2.c
**��   ��   ��: ������
**����޸�����: 2003��8��3��
**��        ��: ext2Դ���롣
**
**--------------��ʷ�汾��Ϣ----------------------------------------------------------------------------
** ������: ������
** ��  ��: V0.50
** �ա���: 2002��2��22��
** �衡��: ԭʼ�汾
**
**------------------------------------------------------------------------------------------------------
** �޸���: ������
** ��  ��: V1.11.0
** �ա���: 2003��12��2��
** �衡��: ɾ��TaskF����
**
**------------------------------------------------------------------------------------------------------
** �޸���: ������
** ��  ��: V1.12.0
** �ա���: 2003��12��30��
** �衡��: �ޱ仯
**
**------------------------------------------------------------------------------------------------------
** �޸���: ������
** ��  ��: V1.20.0
** �ա���: 2003��8��3��
** �衡��: �����°汾Ҫ���޸�
**
**--------------��ǰ�汾�޶�------------------------------------------------------------------------------
** �޸���: 
** �ա���:
** �衡��:
**
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#include "config.h"
#include "display.h"

void TaskA(void);
void TaskB(void);
void TaskC(void);
void TaskD(void);
void TaskE(void);

                            void main(void)
{
    OSInit();

	TMOD = (TMOD & 0XF0) | 0X01;
	TL0 = 0x0;
	TH0 = 0x0;
	TR0 = 1;
	ET0 = 1;
	TF0 = 0;

	PC_DispClrScr(DISP_FGND_WHITE + DISP_BGND_BLACK); 
    PC_DispStr(15,  0, "Small RTOS(51), the Real-Time Kernel(For Keil c51)", DISP_FGND_WHITE + DISP_BGND_RED + DISP_BLINK);
    PC_DispStr(35,  1, "ChenMingJi", DISP_FGND_WHITE);
    PC_DispStr(35,  3, "EXAMPLE #2", DISP_FGND_WHITE);

    OSTaskCreate(TaskA, NULL, 0);
    OSTaskCreate(TaskB, NULL, 1);
    OSTaskCreate(TaskC, NULL, 2);
    OSTaskCreate(TaskD, NULL, 3);
    OSTaskCreate(TaskE, NULL, 4);

    while(1)
    {
        PCON = PCON | 0x01;                     /* CPU��������״̬ */
    }
}


                            void TaskA(void)
{
    uint8 x,y;
    

    while (1)
    {
        OS_ENTER_CRITICAL();
        x = random(80);
        y = random(20);
        PC_DispChar(x, y + 5, '1', DISP_FGND_LIGHT_GRAY);    
        OS_EXIT_CRITICAL();
        OSWait(K_TMO,1);
    }    
}

                            void TaskB(void)
{
    uint8 x,y;
    
    while (1)
    {
        OS_ENTER_CRITICAL();
        x = random(80);
        y = random(20);
        PC_DispChar(x, y + 5, '2', DISP_FGND_LIGHT_GRAY);    
        OS_EXIT_CRITICAL();
        OSWait(K_TMO,1);
    }    
}


                            void TaskC(void)
{
    uint8 x,y;
    
    while (1)
    {
        OS_ENTER_CRITICAL();
        x = random(80);
        y = random(20);
        PC_DispChar(x, y + 5, '3', DISP_FGND_LIGHT_GRAY);    
        OS_EXIT_CRITICAL();
        OSWait(K_TMO,1);
    }    
}


                            void TaskD(void)
{
    uint8 x,y;
    
    while (1)
    {
        OS_ENTER_CRITICAL();
        x = random(80);
        y = random(20);
        PC_DispChar(x, y + 5, '4', DISP_FGND_LIGHT_GRAY);    
        OS_EXIT_CRITICAL();
        OSWait(K_TMO,1);
    }    
}


                            void TaskE(void)
{
    uint8 x,y;
    
    while (1)
    {
        OS_ENTER_CRITICAL();
        x = random(80);
        y = random(20);
        PC_DispChar(x, y + 5, '5', DISP_FGND_LIGHT_GRAY);    
        OS_EXIT_CRITICAL();
        OSWait(K_TMO,1);
    }    
}
/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/