#define MaxSize 1000

// 边节点
typedef struct ANode
{
	// 边所指的终点顶点
	int adjvex;
	// 下一条边，邻域，指向下一个邻接点
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

// G为邻接点指针，V为初始访问节点
void BFS(Graph * G, int v)
{
	// 边节点
	ArcNode * p;
	// 访问数组
	int visited[MaxSize];
	// 队列
	int Qu[MaxSize];
	// 初始化循环队列
	int front = 0, rear = -1;
	// 当前节点的下标
	int w;

	// 初始化访问数组
	for(int i = 0; i < G->n; i++)
	{
		visited[i] = 0;
	}

	// 访问第一个节点
	printf("%d\n", v);
	visited[v] = 1;

	// 第一个节点入队
	rear = (rear + 1) % MaxSize;
	Qu[rear] = v;

	// 开始广度优先遍历
	while(front != rear)
	{
		front = (front + 1) / MaxSize;
		// 出队
		w = Qu[front];
		// 使p指向顶点的第一个边节点
		p = G->adjlist[w].firstarc;

		// 循环访问完w的所有边节点
		while(p != NULL)
		{
			if(visited[p->adjvex] == 0)
			{
				// 访问节点
				printf("%d\n", p->adjvex);
				visited[p->adjvex] = 1;

				// 入队
				rear = (rear + 1) % MaxSize;
				Qu[rear] = p->adjvex;
			}

			p = p -> nextarc;
		}
	}

}
