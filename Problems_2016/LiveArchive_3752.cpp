/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 1010, MVAL = 1010101010;

int dp[MN];
char s[MN];

int get_num(char c) {
	return c - 'A';
}

int main() {
	int K = 1;
	while (true) {
		scanf("%s", s);

		if (strcmp(s, "end") == 0) break;
		int n = strlen(s), ans, i, j;

		for (i = 0; i <= n; ++i) dp[i] = MVAL;
		dp[0] = -MVAL;

		for (i = 0; i < n; ++i) {
			j = lower_bound(dp, dp + n + 1, get_num(s[i])) - dp;
			dp[j] = min(dp[j], get_num(s[i]));
		}

		ans = lower_bound(dp, dp + n + 1, MVAL) - dp;
		printf("Case %d: %d\n", K, ans - 1);
		++K;
	}
	return 0;
}
