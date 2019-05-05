#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

#define N 10000

using namespace std;

typedef map<int, vector<int> > graph;
// prime of 1...9999
bool prime[10000];

void sieve()
{
	fill(prime, prime + N, true);
	prime[1] = prime[0] = false;

	for (int i = 2, m = sqrt(N);i <= m ;i++)
	{
		if (prime[i])
		{
			for (int j = i * 2;j <= N;j+=i) 
				prime[j] = false;
		}
	}
}

bool numClose(int a, int b)
{
	int dA[5], dB[5];
	int i = 0;
	while (a > 0 && b > 0)
	{
		dA[i] = a % 10;
		dB[i] = b % 10;
		a /= 10;
		b /= 10;
		i++;
	}
	
	int c = 0;
	for (int j = 0;j < i;j++)
		if (dA[j] == dB[j])
			c++;
	return c==3;
}

// compute path b/w s and e
void solve(int s, int e)
{
	graph G;
	for (int i = 1001;i <= 9973;i++)
	{
		if (prime[i])
		{
			G.insert(make_pair(i, vector<int>()));
		}
	}

	for (graph::iterator it = G.begin();it != G.end();it++)
	{
		for (graph::iterator j = G.begin();j != G.end();j++)
		{
			if (*it != *j)
			{
				if (numClose(it->first, j->first))
				{
					j->second.push_back(it->first);
					it->second.push_back(j->first);
				}
			}
		}
	}

	queue<int> Q;
	Q.push(s);
	vector<bool> exp(N, false);
	int dist[N + 1];
	exp[s] = true;
	dist[s] = 0;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (vector<int>::iterator i = G[u].begin();i!=G[u].end();i++)
		{
			if (!exp[*i])
			{
				exp[*i] = true;
				dist[*i] = dist[u] + 1;
				if (*i == e)
					break;
				Q.push(*i);
			}
		}
	}
	cout << dist[e] << endl;
}


int main(void)
{
	int t, a, b;
	cin >> t;
	// build sieve
	sieve();
	while (t--)
	{
		cin >> a >> b;
		solve(a, b);
	}
}
