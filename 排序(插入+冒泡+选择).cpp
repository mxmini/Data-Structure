#include <iostream>
using namespace std;
#define ArraySize 8

void inser(int data[])		//��������
{
	/*������Ҫ�õ��ı���*/
	int contemp;	//��ʱ��Ŵ������Ԫ��
	int i;	//��Ŵ�����Ԫ�ص�λ��
	int j;	//����ָ���ѱ�����õĲ��ֵ�Ԫ�ص�λ��
	for(i=1;i<ArraySize;i++)
	{
		j=i-1;	
		contemp = data[i];
		while(j>=0&&data[j]>contemp)
		{
			data[j+1]=data[j];
			j--;
		}
		data[j+1]=contemp;
	}
}

void maopao(int data[])		//ð������
{
	int contemp;	//��ʱ���
	for(int i=ArraySize-1;i>0;i--)	//һ����Ҫ��ArraySize-1����ѭ���������
		for(int j=0;j<i;j++)	//ÿһ��ѭ����Ҫ�ȽϵĴ����ǵݼ���
		{
			if(data[j]>data[j+1])
			{
				contemp=data[j];
				data[j]=data[j+1];
				data[j+1]=contemp;
			}
		}
}

void select(int data[])		//ѡ������
{
	int contemp;	//��ʱ���
	for(int i=0;i<ArraySize-1;i++)		//��Ҫ��ArraySize-1����ѭ��
		for(int j=i+1;j<ArraySize;j++)
		{
			if(data[i]>data[j])
			{
				contemp=data[j];
				data[j]=data[i];
				data[i]=contemp;
			}
		}
}


int main()
{
	int data[ArraySize];
	/*������������*/
	cout<<"������8������"<<endl;
	for(int i=0;i<ArraySize;i++)
		cin>>data[i];
	/*ִ������,�������������򷽷���ѡ��ʹ�����־�ȡ��ע�ͼ��ɣ�Ĭ���ǲ�������*/
	inser(data);	//��������
	//maopao(data);		//ð������
	//select(data);		//ѡ������
	/*���������*/
	cout<<""<<endl;
	for(i=0;i<ArraySize;i++)
		cout<<data[i]<<" ";
	return 0;
}