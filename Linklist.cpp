#include<stdio.h>
#include<malloc.h>

typedef struct LNode
{
	// 假设是整型
	int data;
	struct LNode * next;
}Linklist;

// 头插法创建链表,时间复杂度O(n)
// L为头指针，a[]为待转变成链表的数组
void createListHead(Linklist * L, int a[], int n)
{
	// 用于生成新节点;
	Linklist * s;
	// 新建头结点
	L = (Linklist *) malloc(sizeof(Linklist));

	for(int i = 0; i < n; i++){
		// 新建链表节点
		s = (Linklist *) malloc(sizeof(Linklist));
		// 数组赋值
		s->data = a[i];
		// 在L与末尾结点中不断插入s节点
		// 所以头插法顺序与数组顺序反序
		s->next = L->next;
		L->next = s;
	}
}

// 尾插法,顺序与数组顺序一致，时间复杂度O(n)
void createListTail(Linklist * L, int a[], int n)
{
	// s用于生成新节点，r工作指针
	Linklist * s, * r;
	// 初始化
	L->next = NULL;
	// 初始化r，为了保证L始终为头结点，滑动的是r指针
	r = L;
	for(int i = 0; i < n; i++){
		s = (Linklist *) malloc(sizeof(Linklist));
		s->data = a[i];
		// r指针不断向后滑动，s始终为r的后继节点
		r->next = s;
		r = s;
	}
	// 当数组中元素循环完后，此时r一定是尾结点
	r->next = NULL;
}