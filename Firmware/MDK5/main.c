/**
 *        STC��Ƭ���Զ�������
 *    MCU STC15F104W   11.0592MHZ
 **/

#include <reg52.h> // 52ϵ�е�Ƭ������Ĵ���ͷ�ļ�
#define uint unsigned int // �궨��
#define uchar unsigned char
	
/********��Ƭ��I/O��������*********/
sbit DYKZD=P3^4;// ��Դ���ƶ�
sbit XZXHD=P3^3;// �����źż���
uchar x;		// �����źŵ͵�ƽ����

/**************��ʼ��**************/
void init() // ��ʼ���Ӻ���
{
	DYKZD=0; // ��Դ���ƶ˴�
	XZXHD=1;
	INT1= 1;
	IT1 = 1; // ����INT1���ж����� (1:���½��� 0:�����غ��½���)
	EX1 = 1; // ʹ��INT1�ж�
	EA  = 1; // �����жϿ���
}

/*************��ʱ����*************/
void delayms(uint xms) // ��ʱ�Ӻ���
{
	uint i,j;
	for(i=xms;i>0;i--)
	for(j=110;j>0;j--);
}

/************�ⲿ�ж�ITN1********/
void exint1() interrupt 2       // INT1�ж����
{
	x++;
}

/**************������************/
void main() // ������
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