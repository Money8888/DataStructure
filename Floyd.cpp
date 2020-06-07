#define MaxSize 1000
#define INT_MAX 0x7fffffff

typedef struct
{
	// 邻接矩阵
	int edges[MaxSize][MaxSize];
	// 图中顶点个数
	int n;
}Graph;

// Floyd算法
void Floyd(Graph g)
{
	// 距离矩阵和路径矩阵
	int dist[MaxSize][MaxSize];
	int path[MaxSize][MaxSize];

	int i, j, k;

	for(i = 0; i < g.n; i++)
	{
		for(j = 0; j < g.n; j++)
		{
			dist[i][j] = g.edges[i][j];
			if(i != j && g.edges[i][j] < INT_MAX)
				// 表示需要经过i
				path[i][j] = i;
			else
				path[i][j] = -1;
		}
	}

	for(k = 0; k < g.n; k++)
		for(i = 0; i < g.n; i++)
			for(j = 0; j < g.n; j++)
				if(dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					// patj存储的是经过点的序号
					path[i][j] = path[k][j];
				}

}