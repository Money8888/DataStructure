#define MaxSize 1000
 
// 边节点
typedef struct ANode
{
	// 边所指的终点顶点
	int adjvex;
	// 边的终端节点，邻域，指向下一个邻接点
	struct ANode * nextarc;
	// 权值
	int weight;
}ArcNode;
 
// 顶点
typedef struct Vnode
{
	// 数据域
	int data;	
	// 存放顶点的入度
	int count
	// 指向的第一条边
	ArcNode * firstarc;
}VNode;
 
// 邻接表
typedef struct
{
	VNode adjlist[MaxSize];
	// n为顶点数，e为边数
	int n;
	int e;	
}Graph;

// 将G的顶点按照拓扑排序放入TopList中，成功返回1不成功返回0
// TopList为拓扑排序后的序列
int * TopSort(Graph * G, int TopList[])
{
	int i, j;
	// 输出元素的个数
	int n = 0;
	// 申请一个栈
	int stack[MaxSize];
	int top = -1;
	// 定义边节点指针
	ArcNode *p;
	// 将所有入度为0的节点入栈
	for(i = 0; i < G->n; i++)
		if(G->adjlist[i].count == 0)
		{
			top ++;
			stack[top] = i;
		}

	while(top > -1)
	{
		// 出栈
		i = stack[top];
		top --;
		// 输出此时的栈顶节点
		TopList[n] = i;
		n++;
		// 节点的第一个边节点
		p = G->adjlist[i].firstarc;
		while(p != NULL)
		{
			// 取终端节点
			j = p->adjvex;
			// 去掉一个前驱节点，入度减一
			G->adjlist[j].count--;
			// 此时只有当前节点的入度为0，否则是成环图
			if(G->adjlist[j].count == 0)
			{
				// 将入度为0的入栈
				top ++;
				stack[top] = j;
			}
			p = p->nextarc;
		}
	}
	if(n < G->n)
		// 没有拓扑序列
		return 0;
	else
		return 1;

}
