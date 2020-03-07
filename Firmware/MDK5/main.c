/**
 *        STC单片机自动下载器
 *    MCU STC15F104W   11.0592MHZ
 **/

#include <reg52.h> // 52系列单片机特殊寄存器头文件
#define uint unsigned int // 宏定义
#define uchar unsigned char
	
/********单片机I/O功能声明*********/
sbit DYKZD=P3^4;// 电源控制端
sbit XZXHD=P3^3;// 下载信号检测端
uchar x;		// 下载信号低电平个数

/**************初始化**************/
void init() // 初始化子函数
{
	DYKZD=0; // 电源控制端打开
	XZXHD=1;
	INT1= 1;
	IT1 = 1; // 设置INT1的中断类型 (1:仅下降沿 0:上升沿和下降沿)
	EX1 = 1; // 使能INT1中断
	EA  = 1; // 打开总中断开关
}

/*************延时函数*************/
void delayms(uint xms) // 延时子函数
{
	uint i,j;
	for(i=xms;i>0;i--)
	for(j=110;j>0;j--);
}

/************外部中断ITN1********/
void exint1() interrupt 2       // INT1中断入口
{
	x++;
}

/**************主程序************/
void main() // 主程序
{
	init();
	while(1)
	{
		if(x>60)
		{
			DYKZD=1;
			delayms(500);
			DYKZD=0;
			delayms(60000);
			x=0;
		}
	}
}