#define MaxSize 1000
#define INT_MAX 0x7fffffff

typedef struct
{
	// 邻接矩阵
	int edges[MaxSize][MaxSize];
	// 图中顶点个数
	int n;
}Graph;


// 时间复杂度为O(n2),与图的边数无关，适合稠密图
void prim(Graph g, int v)
{
	// 存储出发顶点到其他顶点的权值
	int lowcost[MaxSize];
	// 中间变量，用于寻找最小值
	int min;
	// 存储最小值的终点下标序号，随着循环不断更新
	int closest[MaxSize];
	int i, j, k;

	// 初始化lowcost和closest
	for(i = 0; i < g.n; i++)
	{
		// 给权值付邻接矩阵的初值
		lowcost[i] = g.edges[v][i];
		// 所有节点都为出发节点v
		closest[i] = v;
	}

	// 循环剩余n-1个节点
	for(i = 1; i < g.n; i++)
	{
		min = INT_MAX;
		for(j = 0; j < g.n; j++)
		{
			// 找最小值
			if(lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[i];
				// 记录最近顶点的下标
				k = j;
			}
		}
		// 打印从出发点到最小值点的权值和顺序
		printf("%d, %d, %d", closest[k], k, min);
		// 标记k为出发点，进行下一次循环准备
		lowcost[k] = 0;

		for(j = 0; j < g.n; j++)
		{
			// 若大于lowcost[j] 则不修改
			if(g.edges[k][j] != 0 && g.edges[k][j] < lowcost[j])
			{
				// 此时更新为k到j的权值，因为该权值最小
				lowcost[j] = g.edges[k][j];
				closest[j] = k;
			}
		}
	}
}