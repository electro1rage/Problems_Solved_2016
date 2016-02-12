/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 15, MVAL= 1010101010;

int dp[MN + 1][1 << MN];

int get_min(int i, int mask, vector<pair<int, int> > &a, vector<pair<int, int> > &b) {
	int n = a.size(), k;
	if (i == n) return 0;

	if (dp[i][mask] != -1) return dp[i][mask];

	dp[i][mask] = MVAL;
	for (k = 0; k < n; ++k) {
		if ((mask >> k) & 1) continue;
		dp[i][mask] = min(dp[i][mask], get_min(i + 1, mask | (1 << k), a, b) + abs(a[i].first - b[k].first) + abs(a[i].second - b[k].second));
	}

	return dp[i][mask];
}

int main() {
	int K = 1;
	while (true) {
		int n, ans = MVAL, i, j;
		scanf("%d", &n);
		if (n == 0) break;

		vector<pair<int, int> > a(n);

		for (i = 0; i < n; ++i) scanf("%d %d", &a[i].first, &a[i].second), --a[i].first, --a[i].second;

		vector<pair<int, int> > b(n);

		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				b[j] = {i, j};
			}

			memset(dp, -1, sizeof dp);
			ans = min(ans, get_min(0, 0, a, b));
			for (j = 0; j < n; ++j) {
				b[j] = {j, i};
			}

			memset(dp, -1, sizeof dp);
			ans = min(ans, get_min(0, 0, a, b));
		}

		for (i = 0; i < n; ++i) {
			b[i] = {i, i};
		}

		memset(dp, -1, sizeof dp);
		ans = min(ans, get_min(0, 0, a, b));

		for (i = 0; i < n; ++i) {
			b[i] = {n - i - 1, i};
		}

		memset(dp, -1, sizeof dp);
		ans = min(ans, get_min(0, 0, a, b));

		printf("Board %d: %d moves required.\n\n", K, ans);
		++K;
	}
	return 0;
}
