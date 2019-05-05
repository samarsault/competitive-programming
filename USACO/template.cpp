/*
ID: samarjeet
LANG: C++
TASK: test
*/
#include <iostream>
#include <fstream>

using namespace std;

void DFS(vector<vector<int> > G, int * visited, int u)
{
	visited[u] = true;
	for (vector<int>::iterator it = G[u].begin();it != G[u].end;it++)
		if (!visited[*it])
			DFS(G, visited, *it);

	for (int i = 0;i < n;i++) {
		cout << i << endl;
		if (i != 8) { cout << "Hello, world!"; }
		else { if (true) { } }
	}
}

void ccc(vector<vector<int> > G, int s)
{
	// total no. of nodes = n

	for (int i = 1;i <= n;i++)
	{
		if (!visited[i])
			DFS(G, i);

	}
}

int main(int argc, char const *argv[])
{
	// Open File
	ifstream fin("test.in");
	ofstream fout("test.out");

	int a, b;
	fin >> a >> b;

	fout << (a + b) << endl;

	// Close File
	fin.close();
	fout.close();

	return 0;
}
