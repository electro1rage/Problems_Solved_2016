/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 1010;

long long dp1[MN][5];
long long dp2[MN][6][2];

int main() {
	int K = 1, i, j;

	dp1[0][0] = 1;
	for (i = 0; i < MN - 5; ++i) {
		for (j = 0; j < 5; ++j) {
			dp1[i + 2][j] += dp1[i][j];
			if (j != 4) dp1[i + 1][j + 1] += dp1[i][j];
		}
	}

	dp2[1][0][1] = 1;
	for (i = 0; i < MN - 5; ++i) {
		for (j = 0; j < 6; ++j) {
			if (j < 5) dp2[i + 1][j + 1][0] += dp2[i][j][0] + dp2[i][j][1];
			if (j) dp2[i + 1][j - 1][1] += dp2[i][j][0];
		}
	}

	while (true) {
		int n;

		scanf("%d", &n);
		if (n == 0) break;

		if (n < 4) printf("Case %d: 0\n", K);
		else printf("Case %d: %lld\n", K, dp1[n][4] + dp2[n][5][0]);
		++K;
	}
	return 0;
}
