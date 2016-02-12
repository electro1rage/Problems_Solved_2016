/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 101010, MVAL = 1010101010;

int dp[MN], a[MN];

bool is_good(vector<int> v) {
	int n = v.size(), i;
	for (i = 1; i < n; ++i) {
		if (v[i] <= v[i - 1]) return false;
	}
	if (n == 4) {
		for (i = 1; i < n; ++i) {
			if (v[i] - v[i - 1] > 10) return false;
		}
	} else if (n == 3) {
		if (v[1] - v[0] <= 20 && v[2] - v[1] <= 10) return true;
		if (v[1] - v[0] <= 10 && v[2] - v[1] <= 20) return true;
		return false;
	} else if (n == 2) {
		if (v[1] - v[0] <= 30) return true;
		return false;
	}
	return true;
}

int main() {
	freopen("coding_contest_creation.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, K = 1;
	scanf("%d", &T);
	while (T--) {
		int n, i, j;

		scanf("%d", &n);
		for (i = 0; i < n; ++i) scanf("%d", a + i), dp[i] = MVAL;
		dp[n] = MVAL;

		dp[0] = 0;
		for (i = 0; i < n; ++i) {
			vector<int> v;
			for (j = 0; j < 4; ++j) {
				v.push_back(a[i + j]);
				if (is_good(v)) {
					dp[i + j + 1] = min(dp[i + j + 1], dp[i] + 3 - j);
				}
			}
		}

		printf("Case #%d: %d\n", K, dp[n]);
		++K;
	}
	return 0;
}
