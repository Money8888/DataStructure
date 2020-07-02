#include <stdio.h>
#define MAX 100

typedef struct Node
{
	int data;
	struct Node * lchild;
	struct Node * rchild;
}BTNode;

// 先序遍历非递归算法
void preorder(BTNode * b)
{
	// 创建指针数组
	BTNode * st[MAX];
	// 工作指针
	BTNode * p;
	// 栈顶
	int top = -1;

	if(b != NULL)
	{
		// 根节点进栈
		top++;
		st[top] = b;

		while(top > -1)
		{
			// 访问栈顶元素
			p = st[top];
			top--;
			printf("%d\n", p->data);

			// 右孩子先进栈，先序先访问左孩子
			if(p->rchild != NULL)
			{
				top++;
				st[top] = p->rchild;
			}

			// 再压入左孩子,后访问
			if(p -> lchild != NULL)
			{
				top++;
				st[top] = p->lchild;
			}
		}
	}

}

// 中序遍历的非递归算法
void Inorder(BTNode * b)
{
	// 创建指针数组
	BTNode * st[MAX];
	// 工作指针
	BTNode * p;
	// 栈顶
	int top = -1;
	if(b != NULL)
	{
		// 先让工作指针指向根节点
		p = b;
		while(top > -1 || p != NULL)
		{
			// 栈不为空，或者还有未访问的节点
			// 处理未访问的节点，将左孩子进栈，最左的孩子在栈顶
			while(p != NULL)
			{
				top++;
				st[top] = p;
				p = p -> lchild;
			}
			if(top > -1)
			{
				// 出栈
				p = st[top];
				top--;
				printf("%d\n", p->data);

				// 此时最左的p的右孩子可能为空，但是循环之后就打印中间节点，完成了中序遍历
				p = p->rchild;
			}
		}
	}
}