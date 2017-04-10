#include <iostream>
using namespace std;
#define ArraySize 6
//����������ڵ�
struct Node
{
	int value;
	struct Node *left_node;
	struct Node *right_node;
};
typedef struct Node TNode;	//����������ڵ�
typedef TNode *BTree;	//�������������
BTree bTree;		//
//������������С�Ҵ󡱵�ԭ�򽨵�
void Add_Node(int value)
{
	/*������Ҫ�õ��ı���*/
	TNode *newNode;		//��������½ڵ�
	BTree currentNode;		//��ʱ��ָ��
	int flag = 0;		//��¼�Ƿ�������µĽڵ�

	newNode = (TNode *)malloc(sizeof(TNode));		//Ϊ�½ڵ����ռ䲢��������
	newNode->value = value;
	newNode->left_node = NULL;
	newNode->right_node = NULL;
	/*���½ڵ���������*/
	if(bTree == NULL)
		bTree = newNode;
	else
	{
		currentNode = bTree;
		while(!flag)		//ѭ��������ʱ���ǣ�flag=1�����ڵ��ѱ�����
		{
			if(value<currentNode->value)
			{
				if(currentNode->left_node==NULL)
				{
					currentNode->left_node=newNode;
					flag=1;
				}
				else
					currentNode=currentNode->left_node;
			}
			else
			{
				if(currentNode->right_node==NULL)
				{
					currentNode->right_node=newNode;
					flag=1;
				}
				else
					currentNode=currentNode->right_node;
			}
		}
	}
}

void Preorder(BTree bTree)		//�ݹ�ǰ�����
{
	if(bTree!=NULL)
	{
		cout<<bTree->value<<" ";
		Preorder(bTree->left_node);
		Preorder(bTree->right_node);
	}
}

void Preorder2(BTree bTree)		//�ǵݹ�ǰ�����
{
	/*������Ҫ�õ��ı���*/
	BTree stack[ArraySize];		//���������䵱ջ
	int top=0;		//top�������䵱ջ��ָ�룬topΪ0˵��ջ��
	BTree p=bTree;
	while(p||top!=0)
	{
		if(p)
		{
			cout<<p->value<<" ";
			stack[top++]=p;
			p=p->left_node;
		}
		else
		{
			p=stack[--top];		//ע�������ǡ�--top��
			p=p->right_node;
		}
	}
}

void Inorder(BTree bTree)		//�ݹ��������
{
	if(bTree!=NULL)
	{
		Inorder(bTree->left_node);
		cout<<bTree->value<<" ";
		Inorder(bTree->right_node);
	}
}

void Inorder2(BTree bTree)		//�ǵݹ��������
{
	/*������Ҫ�õ��ı���*/
	BTree stack[ArraySize];		//���������䵱ջ
	int top=0;		//top�������䵱ջ��ָ�룬topΪ0˵��ջ��
	BTree p=bTree;
	while(p||top!=0)	//����������һ��ֻ�������ڵ�Ķ��������֣���p��ָ��Ϊ�գ���top=0��ʱ�����е�Ԫ�ض��Ѿ���������
	{
		if(p)
		{
			stack[top++]=p;
			p=p->left_node;
		}
		else	//�������֣���pָ��Ϊ��ʱ����Ҫִ�г�ս������Ȼ�����Ԫ��
		{
			p=stack[--top];		//ע�������ǡ�--top��
			cout<<p->value<<" ";
			p=p->right_node;
		}
	}
}

void Postorder(BTree bTree)		//�ݹ�������
{
	if(bTree!=NULL)
	{
		Postorder(bTree->left_node);
		Postorder(bTree->right_node);
		cout<<bTree->value<<" ";
	}

}

void Postorder2(BTree bTree)		//�ǵݹ�������
{
	BTree stack1[ArraySize];
	int stack2[ArraySize];
	int top1=0,top2=0;
	int flag;
	BTree p=bTree;
	while(p||top1!=0)
	{
		if(p)
		{
			stack1[top1++]=p;
			stack2[top2++]=0;
			p=p->left_node;
		}
		else
		{
			p=stack1[top1-1];		
			flag=stack2[top2-1];
			if(flag==0)
			{
				stack2[top2-1]=1;
				p=p->right_node;
			}
			else
			{
				p=stack1[--top1];
				--top2;
				cout<<p->value<<" ";
				p=NULL;		//��һ��ܹؼ���������һ���磬�������û�м�����һ�䡣
			}
		}
	}
}

int main()
{
	int content[ArraySize];
	cout<<"������6��������"<<endl;	//��������
	for(int i=0;i<ArraySize;i++)
		cin>>content[i];
	for(i=0;i<ArraySize;i++)	//����
		Add_Node(content[i]);
	cout<<"�������!"<<endl;
	cout<<"�ݹ�ǰ�������";
	Preorder(bTree);
	cout<<"�ǵݹ�ǰ�������";
	Preorder2(bTree);
	cout<<endl;

	cout<<"�ݹ����������";
	Inorder(bTree);
	cout<<"�ǵݹ����������";
	Inorder2(bTree);
	cout<<endl;

	cout<<"�ݹ���������";
	Postorder(bTree);
	cout<<"�ǵݹ���������";
	Postorder2(bTree);
	cout<<endl;
	return 0;
}