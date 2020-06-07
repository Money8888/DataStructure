#define MaxSize 1000
#define INT_MAX 0x7fffffff

typedef struct
{
	// 邻接矩阵
	int edges[MaxSize][MaxSize];
	// 图中顶点个数
	int n;
}Graph;

// 求所有顶点到顶点v的最短路径
void Dijkstra(Graph g, int v)
{
	// 距离矩阵
	int dist[MaxSize];
	// 路径矩阵
	int path[MaxSize];
	// 顶点集合，取值为0,1 1表示已计算距离
	int s[g.n];
	int min;
	int i,j;
	// u为找到离v最近的顶点
	int u;

	// 初始化dist,path,s
	for(i = 0; i < g.n; i++)
	{
		dist[i] = g.edges[v][i];
		s[i] = 0;
		if(g.edges[v][i] < INT_MAX || v == i)
			path[i] = v;
		else
			// 用-1表示没有直接路径
			path[i] = -1
	}

	// 将v放入s中
	s[v] = 1
	// 将剩余n-1个顶点依次计算
	for(i = 0; i < g.n - 1; i++)
	{
		min = INT_MAX;
		for(j = 0; j < g.n; j++)
		{
			// 找到离v最小的距离和此时的顶点u
			if(s[j] == 0 && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		}
		s[u] = 1;
		for(j = 0; j < g.n; j++)
		{
			if(g.edges[u][j] < INT_MAX && dist[u] + g.edges[u][j] < dist[j])
			{
				dist[j] = dist[u] + g.edges[u][j];
				path[j] = u;
			}
		}
	}


}