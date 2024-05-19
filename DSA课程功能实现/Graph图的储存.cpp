#include <iostream>
#include <queue>
using namespace std;

const int VEX_MAX = 100;
bool visited[VEX_MAX];

//������
struct Node {
	int vex;    //����±�
	int weight; //Ȩ��
	struct Node* next;
};

//ͷָ�벿��
typedef struct ENode {
	char data;  //�������
	Node* head;
}*List;

//ͼ
typedef struct GNode {
	List list;
	int vexnum; //�����
	int arcnum;	//����
}*Graph;

Graph createGraph();
void DFSTraverse(Graph graph);
void DFS(Graph graph, int v);
void BFSTraverse(Graph graph);
void printGraph(Graph graph);

int main()
{
	Graph graph = createGraph();
	cout << "�ڽӱ��Ӧ�Ķ�ά����Ϊ��" << endl;
	printGraph(graph);
	cout << "������ȱ�����" << endl;
	DFSTraverse(graph);
	cout << endl;
	cout << "������ȱ�����" << endl;
	BFSTraverse(graph);
	return 0;
}


//��ʼ��ͼ
Graph createGraph()
{
	Graph graph = new GNode;
	cout << "�����붥������ͱ߸�����" << endl;
	cin >> graph->vexnum >> graph->arcnum;
	graph->list = new ENode[graph->vexnum + 1];
	//��ʼ������
	cout << "�����붥�����ݣ�" << endl;
	for (int i = 1; i <= graph->vexnum; i++)
	{
		cin >> graph->list[i].data;
		graph->list[i].head = nullptr;
	}
	int begin, end, weight;
	//��ʼ����
	cout << "������ߵ���ʼ�㼰��Ȩ�أ�" << endl;
	for (int i = 1; i <= graph->arcnum; i++)
	{
		cin >> begin >> end >> weight;
		//�������ӵ�ͷ���(ͷ�巨) ����ͼ
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

//DFS�㷨
void DFSTraverse(Graph graph)
{
	for (int i = 1; i <= graph->vexnum; i++)//��ʼ�����ж���Ϊδ������
		visited[i] = false;
	for (int i = 1; i <= graph->vexnum; i++)
	{
		if (!visited[i])
			DFS(graph, i);
	}
}

//������ȱ���
void DFS(Graph graph, int v)
{
	visited[v] = true;
	cout << graph->list[v].data << " ";
	Node* header = graph->list[v].head;//��Ӧ����ͷ���
	while (header)
	{
		if (!visited[header->vex])
		{
			DFS(graph, header->vex);
		}
		header = header->next;
	}
}

//BFS�㷨
void BFSTraverse(Graph graph)
{
	queue<int> MyQueue;
	for (int i = 1; i <= graph->vexnum; i++)//��ʼ�����ж���Ϊδ������
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

//��ӡͼ
void printGraph(Graph graph)
{
	//������ά����
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
	//���ڽӱ��ӡΪ������ʽ
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