#include <iostream>
using namespace std;
#define ArraySize 8


void create_heap(int data[],int size)
{
	for(int i=(size/2);i>0;i--)	//�����һ�����ն˽ڵ㿪ʼ������ֱ�����ڵ�
	{
		int l_kid=2*i;	//�ڵ������
		int r_kid=2*i+1;	//�ڵ���Һ���
		int tmp;	//�ݴ����ӻ��Һ���֮�������Ǹ��ڵ�������±�
		int k;	//��ʱ����
		int j=i;
		while(l_kid<=size)	//Ҫ�������Ըýڵ�Ϊ���ڵ��Ҷ�ӽڵ�
		{
			
			tmp=l_kid;
			if(l_kid<size)	//l_kid<size,˵�������Һ���
			{
				if(data[l_kid-1]<data[r_kid-1])
					tmp=r_kid;
			}
			if(data[j-1]>data[tmp-1])
				break;
			else
			{
				k=data[j-1];
				data[j-1]=data[tmp-1];
				data[tmp-1]=k;
				l_kid=tmp*2;
				j=tmp;
			}
		}
	}
}

void heap(int data[],int size)
{
	create_heap(data,size);//�Ƚ���
	cout<<"������ɣ�";
	for(int i=0;i<ArraySize;i++)
		cout<<data[i]<<" ";
	cout<<endl;
	int data1[ArraySize];	//��������Ľ��
	for(i=0;i<size;i++)
	{
		data1[i]=data[0];
		data[0]=0;
		create_heap(data,size);
	}
	for(i=0;i<ArraySize;i++)
		cout<<data1[i]<<" ";
	
}

int main()
{
	int data[ArraySize];
	/*������������*/
	cout<<"������8������"<<endl;
	for(int i=0;i<ArraySize;i++)
		cin>>data[i];
	/*ִ������*/
	heap(data,8);
	/*���������*/
	cout<<""<<endl;
	
	return 0;
}