#include<stdio.h>
#define MAX 100

// kmp算法
// s为文本串指针，t为模式串指针
int kmp(char * s, char * t){

	int i = 1, j = 1;
	// next数组，之和模式串有关
	int next[MAX];
	// 根据模式串生成next数组,即保留最近一次可以回退的位置
	getNext(t, next);
	while(i < strlen(s) && j < strlen(t))
	{
		if(j == 0 || *(t + i) == *(t + j)){
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if(j > strlen(t))
	{
		// 说明匹配成功，返回匹配的第一个位置指针
		return i - strlen(t);
	}
	else
		return -1;
}

void getNext(char * t, int next[]){

	int i = 1, j = 0;
	next[0] = -1;
	next[1] = 0;

	while(i < strlen(t))
	{
		if(j == 0 || *(t + i) == *(t + j))
		{
			// 指针后移
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			// 如果不匹配
			// 动态规划，将j回退到之前标记的地方
			j = next[j];
		}
	}

}