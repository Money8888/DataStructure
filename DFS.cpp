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

// 递归算法
void DFS(Graph * G, int v)
{
	// 边节点指针
	ArcNode * p;
	// 访问数组
	int visited[MaxSize];
	// 访问当前节点
	printf("%d\n", v);
	visited[v] = 1;

	// 为递归节点传递条件
	p = G->adjlist[v].firstarc;

	while(p != NULL)
	{
		if(visited[p -> adjvex] == 0)
		{
			// 递归深入去访问该节点对应的子节点的终端节点
			DFS(G, p->adjvex);
		}
		// 最后再循环访问初始点的下一个终端节点
		p = p -> nextarc;
	}


}

// 非递归算法,栈实现
void DFSStack(Graph * G, int v)
{
	// 边节点指针
	ArcNode *p;
	// 边节点的顺序栈，栈中为指向边节点的指针
	ArcNode * stack[MaxSize];
	// 初始化栈顶
	int top = -1;
	// 为图顶点数组adjlist的序号
	int w;
	// 访问数组
	int visited[MaxSize];
	// 当前节点的第一条边入栈
	top ++;
	stack[top] = G->adjlist[v].firstarc;

	while(top > -1)
	{
		// 获取出栈元素,第一次循环为初始点v出栈
		p = stack[top];
		top--;
		while(p != NULL)
		{
			// 获取当前边节点的终点节点
			w = p->adjvex;
			if(visited[w] == 0)
			{
				// 访问出栈节点
				printf("%d\n", w);
				visited[w] = 1;
				// 将该点作为初始点入栈，下一次循环访问该点的第一个终点节点
				top ++;
				stack[top] = G->adjlist[w].firstarc;
				// 找到一个与初始点相连的未被访问的终点节点就结束最近的while循环
				break;
			}
			// 若当前边节点的子终端节点全部被访问完，则访问初始节点的下一个边节点
			p = p->nextarc;

		}

	}

}