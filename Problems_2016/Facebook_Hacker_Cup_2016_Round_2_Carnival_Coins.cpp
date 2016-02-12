/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 3030;
const double eps = 1e-9;

double dp[MN];

double memo[MN][MN];
double p;
int n, k;

double get_ans(int i, int j) {
	if (i == 0) return j >= k;
	double &ret = memo[i][j];
	if (ret == ret) return ret;
	ret = p * get_ans(i - 1, j + 1) + (1 - p) * get_ans(i - 1, j);
	return ret;
}

int main() {
	freopen("carnival_coins.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, K = 1;
	scanf("%d", &T);
	while (T--) {
		int i, j;
		cin >> n >> k >> p;

		memset(memo, -1, sizeof memo);
		for (i = 0; i <= n; ++i) dp[i] = 0;

		for (i = 0; i < n; ++i) {
			for (j = 1; j <= n; ++j) {
				if (i + j > n) continue;
				double temp  = dp[i] + get_ans(j, 0);
				if (eps < temp - dp[i + j]) dp[i + j] = temp;
			}
		}

		printf("Case #%d: %.7lf\n", K, dp[n]);
		++K;
	}
	return 0;
}
