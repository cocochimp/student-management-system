#include <iostream>
#include <queue>
using namespace std;

const int VEX_MAX = 100;
bool visited[VEX_MAX];

//链表部分
struct Node {
	int vex;    //结点下标
	int weight; //权重
	struct Node* next;
};

//头指针部分
typedef struct ENode {
	char data;  //结点数据
	Node* head;
}*List;

//图
typedef struct GNode {
	List list;
	int vexnum; //结点数
	int arcnum;	//边数
}*Graph;

Graph createGraph();
void DFSTraverse(Graph graph);
void DFS(Graph graph, int v);
void BFSTraverse(Graph graph);
void printGraph(Graph graph);

int main()
{
	Graph graph = createGraph();
	cout << "邻接表对应的二维矩阵为：" << endl;
	printGraph(graph);
	cout << "深度优先遍历：" << endl;
	DFSTraverse(graph);
	cout << endl;
	cout << "广度优先遍历：" << endl;
	BFSTraverse(graph);
	return 0;
}


//初始化图
Graph createGraph()
{
	Graph graph = new GNode;
	cout << "请输入顶点个数和边个数：" << endl;
	cin >> graph->vexnum >> graph->arcnum;
	graph->list = new ENode[graph->vexnum + 1];
	//初始化顶点
	cout << "请输入顶点数据：" << endl;
	for (int i = 1; i <= graph->vexnum; i++)
	{
		cin >> graph->list[i].data;
		graph->list[i].head = nullptr;
	}
	int begin, end, weight;
	//初始化边
	cout << "请输入边的起始点及其权重：" << endl;
	for (int i = 1; i <= graph->arcnum; i++)
	{
		cin >> begin >> end >> weight;
		//链表连接到头结点(头插法) 无向图
		Node* node = new Node;
		node->weight = weight;
		node->vex = end;
		node->next = graph->list[begin].head;
		graph->list[begin].head = node;

		node = new Node;
		node->weight = weight;
		node->vex = begin;
		node->next = graph->list[end].head;
		graph->list[end].head = node;
	}
	return graph;
}

//DFS算法
void DFSTraverse(Graph graph)
{
	for (int i = 1; i <= graph->vexnum; i++)//初始化所有顶点为未被访问
		visited[i] = false;
	for (int i = 1; i <= graph->vexnum; i++)
	{
		if (!visited[i])
			DFS(graph, i);
	}
}

//深度优先遍历
void DFS(Graph graph, int v)
{
	visited[v] = true;
	cout << graph->list[v].data << " ";
	Node* header = graph->list[v].head;//对应结点的头结点
	while (header)
	{
		if (!visited[header->vex])
		{
			DFS(graph, header->vex);
		}
		header = header->next;
	}
}

//BFS算法
void BFSTraverse(Graph graph)
{
	queue<int> MyQueue;
	for (int i = 1; i <= graph->vexnum; i++)//初始化所有顶点为未被访问
		visited[i] = false;
	for (int i = 1; i <= graph->vexnum; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			cout << graph->list[i].data << " ";
			MyQueue.push(i);
			while (!MyQueue.empty())
			{
				int front = MyQueue.front();
				MyQueue.pop();
				Node* header = graph->list[front].head;
				while (header)
				{
					if (!visited[header->vex])
					{
						visited[header->vex] = true;
						cout << graph->list[header->vex].data << " ";
						MyQueue.push(header->vex);
					}
					header = header->next;
				}
			}
		}
	}
}

//打印图
void printGraph(Graph graph)
{
	//声明二维矩阵
	int** arr = new int* [graph->vexnum + 1];
	for (int i = 1; i <= graph->vexnum; i++)
	{
		arr[i] = new int[graph->vexnum + 1];
	}
	for (int i = 1; i <= graph->vexnum; i++)
	{
		for (int j = 1; j <= graph->vexnum; j++)
		{
			arr[i][j] = 0;
		}
	}
	//将邻接表打印为矩阵形式
	for (int i = 1; i <= graph->vexnum; i++)
	{
		Node* header = graph->list[i].head;
		while (header)
		{
			arr[i][header->vex] = header->weight;
			header = header->next;
		}
	}
	for (int i = 1; i <= graph->vexnum; i++)
	{
		for (int j = 1; j <= graph->vexnum; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}