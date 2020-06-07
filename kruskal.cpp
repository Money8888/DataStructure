#define MaxSize 1000

typedef struct
{
	// 边的起点和终点序号
	int front, to;
	// 权值
	int weight;
}EdgeType;

// 边图结构体类
typedef struct
{
	// 顶点集
	int vertex[MaxSize];
	// 边集
	EdgeType edge[MaxSize]
	// 顶点个数
	int vertexnum;
	// 边个数
	int edgenum;
}EdgeGraph;

// kruskal算法 基于并查集的实现
void kruskal(EdgeGraph * G)
{
	// 双亲数组
	int parent[G->vertexnum];
	// 声明两个节点
	int vex1, vex2;
	// 顶点的循环变量
	int i
	// kruskal构造的边的个数，逐渐变大
	int num;
	// 初始化顶点的双亲，使得所有点成为离群点
	for(i = 0; i < G->vertexnum; i++){
		parent[i] = -1;
	}

	for(num = 0, i = 0; num < G-> edgenum; i++)
	{
		// 寻找该边的起始节点和终端节点的祖先根
		vex1 = FindRoot(parent, G->edge[i].from);
		vex2 = FindRoot(parent, G->edge[i].to);

		if(vex1 != vex2)
		{
			printf("从%d 到 %d 的边权值为%d\n", G->edge[i].from, G->edge[i].to, G->edge[i].weight);
			// 合并集合
			parent[vex2] = vex1;
			num++;
		}
	}
}

// 寻找v的祖先根
int FindRoot(int parent[], int v)
{
	int t = v;
	while(parent[t] != -1)
	{
		t = parent[t];
	}
	return t;
}