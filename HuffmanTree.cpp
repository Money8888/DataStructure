#define MaxSize 1000
#define INT_MAX 0x7fffffff

typedef struct 
{
	// 节点权值
	int weight;
	// 节点双亲
	int parent;
	// 节点左孩子
	int lchild;
	// 节点右孩子
	int rchild;
}HNodeType;

// 构造霍夫曼树
HNodeType * huffmanTree()
{
	// 定义哈夫曼节点
	HNodeType HuffNode[MaxSize];
	int i, j;
	// 暂时保存最小的两数
	int m1, m2
	// 节点的左右孩子
	int x1, x2;
	// 哈夫曼树节点总个数
	int n;

	// 对于n个叶子节点的完全二叉树其总节点数为2n-1
	// 0~i-1为叶子节点，剩余为非叶子节点
	for(i = 0; i < 2 * n - 1; i++)
	{
		HuffNode[i].parent = -1;
		HuffNode[i].lchild = -1;
		HuffNode[i].rchild = -1;
	}
	// 非叶子结点权值初始化为0
	for(i = n; i < 2 * n - 1; i++)
		HuffNode[i].weight = 0;
	
	for(i = 0; i < n - 1; i++)
	{
		m1 = m2 = INT_MAX;
		x1 = x2 = 0;

		// 不断循环所有叶子结点
		for(j = 0; j < n + i; j++)
		{
			if(HuffNode[j].parent == -1 && HuffNode[j].weight < m1)
			{
				m2 = m1;
				x2 = x1;
				m1 = HuffNode[j].weight;
				x1 = j;
			}
			else if(HuffNode[j].parent == -1 && HuffNode[j].weight < m2)
			{
				m2 = HuffNode[j].weight;
				x2 = j;
			}
		}

		HuffNode[x1].parent = n + i;
		HuffNode[x2].parent = n + i;
		HuffNode[n + i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
		HuffNode[n + i].lchild = x1;
		HuffNode[n + i].rchild = x2;
	}

	return HuffNode;
}