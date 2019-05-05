#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int kX, kY;

typedef struct piece {
	char kind;
	int x, y;
} piece;

piece nearest[9];

int direction(int x, int y)
{
	if (y == kY && x < kX)
		return 1; // left
	if (y == kY && x > kX)
		return 2; // right

	if (x == kX && y > kY)
		return 3; // up

	if (x == kX && y < kY)
		return 4; // down

	// up right
	if (y > kY && x > kX && (y - kY) == (x - kX))
		return 5;
	
	// down left
	if (y < kY && x < kX && (y - kY) == (x - kX))
		return 6;
	// up left
	if (y > kY && x < kX && (y - kY) == -(x - kX))
		return 6;

	// down right
	if (y < kY && x > kX && (y - kY) == -(x - kX))
		return 8;
	
	return -1;
}

// how close pieces are
inline int dist(int x1,int y1, int x2, int y2)
{
	return max(abs(x2 -  x1),  abs(y2 - y1));
}

int main(void)
{
	int i, n, x, y, dir;
	char ch;
	cin >> n;
	cin >> kX >> kY;

	for (i = 0;i < 9;i++)
		nearest[i] = { ' ', kX, kY };
	
	for (i = 0;i < n;i++)
	{
		cin >> ch >> x >> y;
		dir = direction(x, y);
		
		if (dir == -1) continue;
		if (nearest[dir].kind == ' ')
			nearest[dir] = { ch, x, y };
		else if (dist(x, y, kX, kY) < dist(nearest[dir].x, nearest[dir].y, kX, kY))
				nearest[dir] = { ch, x, y };
	}

	bool check = false;

	for (i = 1;i <= 4;i++ )
	{
		if (nearest[i].kind == 'Q' || nearest[i].kind == 'R')
		{
			check = true;
			break;
		}
	}
	for (i = 5;i <= 8;i++ )
	{
		if (nearest[i].kind == 'Q' || nearest[i].kind == 'B')
		{
			check = true;
			break;
		}
	}

	if (check)
		cout << "YES";
	else
		cout << "NO";
}
