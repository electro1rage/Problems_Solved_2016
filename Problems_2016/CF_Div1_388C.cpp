/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, x, y, sz, i, j;
	scanf("%d", &n);

	vector<int> lft, right, mid;

	for (i = 0; i < n; ++i) {
		scanf("%d", &m);
		y = m / 2;
		for (j = 0; j < m; ++j) {
			scanf("%d", &x);
			if (j < y) lft.push_back(x);
			else if (m % 2 && j == y) mid.push_back(x);
			else right.push_back(x);
		}
	}

	int ans[2] = {};

	ans[0] = accumulate(lft.begin(), lft.end(), 0);
	ans[1] = accumulate(right.begin(), right.end(), 0);

	sort(mid.rbegin(), mid.rend());
	sz = mid.size();
	for (i = 0; i < sz; ++i) {
		ans[i % 2] += mid[i];
	}

	printf("%d %d\n", ans[0], ans[1]);
	return 0;
}
