/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 303, bs = 1000000007;

int dp[2][MN], a[MN];
bool start[MN];

void add(int &a, int &b) {
	a += b;
	if (a >= bs) a -= bs;
}

int main() {
	freopen("monotonic.in", "r", stdin);
	freopen("monotonic.out", "w", stdout);

	int n, t, less, i, j, k;
	scanf("%d %d", &n, &t);

	for (i = 1; i <= t; ++i) scanf("%d", a + i), a[i] += a[i - 1];
	for (i = 0; i < t; ++i) start[a[i]] = true;

	dp[0][n] = 1;

	for (i = 0; i < n; ++i) {
		for (j = 0; j <= n; ++j) {
			if (i + j > n) continue;
			less = n - i - j;
			if (start[i]) {
				for (k = 0; k < j; ++k) {
					add(dp[(i + 1) % 2][k], dp[i % 2][j]);
				}
			} else {
				for (k = 0; k < less; ++k) {
					add(dp[(i + 1) % 2][j + k], dp[i % 2][j]);
				}
			}
			dp[i % 2][j] = 0;
		}
	}

	printf("%d\n", dp[n % 2][0]);
	return 0;
}
