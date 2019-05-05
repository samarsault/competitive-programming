/*
 * Start: 1:20pm
 * End : 2: 20pm
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int i, n, k, last, first = 0, swaps = 0;
	cin >> n >> k;
	last = n - 1;

	int a[n], b[n];
	for (i = 0;i < n;i++)
		cin >> a[i];
	for(i = 0;i < n;i++)
		cin >> b[i];

	sort(a, a + n);
	sort(b, b + n);

	// big, small
	vector<int> bg, sm;
	
	if (a[n - 1] > b[n - 1]) {
		bg.assign(a, a + n);
		sm.assign(b, b + n);
	} else {
		sm.assign(a, a + n);
		bg.assign(b, b + n);
	}

	int p, q, a1, a2;
	while (swaps < k)
	{
		if (bg[first] >= sm[last]) // can't be inserted
			break;
		// swap sm_last with bg_first
		p = sm[last];
		q = bg[first];
		// insert q into sm
		// insert p into bg
		bg.erase(bg.begin());
		sm.insert(lower_bound(sm.begin(), sm.end(), q), q);
		sm.erase(sm.end() - 1);
		bg.insert(lower_bound(bg.begin(), bg.end(), p), p);
		swaps++;
	}

	a1 = bg[last] + sm[last] ;
	swaps = 0;
	if (a[n - 1] > b[n - 1]) {
		bg.assign(a, a + n);
		sm.assign(b, b + n);
	} else {
		sm.assign(a, a + n);
		bg.assign(b, b + n);
	}
	// assume bg contains the biggest and the rest small elements
	while (swaps < k)
	{
		if (bg[last] <= sm[first]) // can't be inserted
			break;
		// swap sm_first with bg_last 
		p = sm[first];
		q = bg[last];
		// insert q into sm
		// insert p into bg
		bg.erase(bg.end() - 1);
		bg.insert(lower_bound(bg.begin(), bg.end(), p), p);
		sm.erase(sm.begin());
		sm.insert(lower_bound(sm.begin(), sm.end(), q), q);
		swaps++;
	}
	a2 = bg[last] + sm[last] ;
	cout << min(a1, a2) << endl;
}
