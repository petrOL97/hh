#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

using namespace std;
void print_edges(vector <vector <int>>, int); //edges printing function
vector<vector<int>> manual_input(vector<vector<int>> edges, int m); //manually edges initialisation function
vector<vector<int>> automaticly_input(vector<vector<int>>, vector <int>, int, int); //automaticly edges initialisation function (graph is always bipartite)
void test(vector<vector<int>>, vector <int>, int, int); //Bipartite graph check function

void main()
{
	int i, m, n, tmp;
	vector <vector <int>> edges(125250, vector<int>(3)); //two-dimensional vector (edges)
	vector <int> nodes(501); //regular vector (nodes)
	setlocale(LC_ALL, "Russian");

	cout << "Input number of nodes: ";
	cin >> n;
	for (i = 0; i < n; i++)
		nodes[i] = i + 1;
	cout << "Input number of edges: ";
	cin >> m;

	cout << "Do you want to enter graph manually (1) or automaticly(0)?" << endl;
	cin >> tmp;
	switch (tmp)
	{
	case 0:
	{
		edges = automaticly_input(edges, nodes, m, n);
		break;
	}
	case 1:
		edges = manual_input(edges, m);
		break;
	}
	print_edges(edges, m);
	test(edges, nodes, m, n);

	system("pause");
}

void print_edges(vector<vector<int>> vec, int m)
{
	for (int i = 0; i < m;i++)
	{
		cout << "Edge №" << i + 1 << ": " << vec[i][0] << " " << vec[i][1] << endl;
	}
}

vector<vector<int>> manual_input(vector<vector<int>> edges, int m)
{
	cout << "Input edges like pair of nodes (edges is undirected): " << endl;
	for (int i = 0; i < m;i++)
	{
		cin >> edges[i][0] >> edges[i][1];
		edges[i][2] = 0;
	}
	return edges;
}

vector<vector<int>> automaticly_input(vector<vector<int>> edges, vector <int> nodes, int m, int n)
{
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		int x = rand() % 2;
		switch (x)
		{
		case 0:
		{
			edges[i][0] = nodes[rand() % (n / 2)];
			edges[i][1] = nodes[rand() % (n / 2) + (n / 2)];
			edges[i][2] = 0;
			break;
		}
		case 1:
		{
			edges[i][1] = nodes[rand() % (n / 2)];
			edges[i][0] = nodes[rand() % (n / 2) + (n / 2)];
			edges[i][2] = 0;
			break;
		}
		}
	}
	return edges;
}

void test(vector<vector<int>> edges, vector <int> nodes, int m, int n)
{
	bool result = true;
	vector<int> u(125250), v(125250);
	int i, j, k, count = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < m;j++)
		{
			if (nodes[i] == edges[j][0] && edges[j][2] == 0)
			{
				for (k = 0; k <= count;k++)
				{
					if (nodes[i] == u[k])
					{
						u[count] = edges[j][0];
						v[count] = edges[j][1];
						edges[j][2] = 1;
						count++;
						break;
						
					}
					else if (nodes[i] == v[k])
					{
						u[count] = edges[j][1];
						v[count] = edges[j][0];
						edges[j][2] = 1;
						count++;
						break;
					}
					else
					{
						u[count] = edges[j][0];
						v[count] = edges[j][1];
						edges[j][2] = 1;
						count++;
						break;
					}
				}
			}
			else if (nodes[i] == edges[j][1] && edges[j][2] == 0)
			{
				for (k = 0; k <= count;k++)
				{
					if (nodes[i] == u[k])
					{
						u[count] = edges[j][1];
						v[count] = edges[j][0];
						edges[j][2] = 1;
						count++;
						break;
					}
					else if (nodes[i] == v[k])
					{
						u[count] = edges[j][0];
						v[count] = edges[j][1];
						edges[j][2] = 1;
						count++;
						break;
					}
					else
					{
						u[count] = edges[j][1];
						v[count] = edges[j][0];
						edges[j][2] = 1;
						count++;
						break;
					}
				}
			}
			
		}

	for (i = 0;i < m;i++)
		for (j = 0; j < m; j++)
		{
			if (u[i] == v[j])
				result = false;

		}
	if (result == false)
		cout << "Graph is not bipartite!" << endl;
	if (result == true)
		cout << "Graph is bipartite!" << endl;
}