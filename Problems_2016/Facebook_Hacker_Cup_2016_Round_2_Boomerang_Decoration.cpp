/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;

char x[MN], y[MN];
int a[MN], b[MN];
int aa[MN], bb[MN];

int main() {
	freopen("boomerang_decoration.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, K = 1;
	scanf("%d", &T);
	while (T--) {
		int ans = 1000000000, n, i;
		scanf("%d", &n);
		scanf("%s", x + 1);
		scanf("%s", y + 1);


		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		memset(aa, 0, sizeof aa);
		memset(bb, 0, sizeof bb);

		for (i = 1; i <= n; ++i) {
			if (i == 1 || y[i] != y[i - 1]) aa[i] = aa[i - 1] + 1;
			else aa[i] = aa[i - 1];
		}
		for (i = 1; i <= n; ++i) {
			if (x[i] == y[i]) a[i] = a[i - 1];
			else a[i] = aa[i];
		}

		for (i = n; i > 0; --i) {
			if (i == n || y[i] != y[i + 1]) bb[i] = bb[i + 1] + 1;
			else bb[i] = bb[i + 1];
		}
		for (i = n; i > 0; --i) {
			if (x[i] == y[i]) b[i] = b[i + 1];
			else b[i] = bb[i];
		}

		for (i = 0; i <= n; ++i) {
			ans = min(ans, max(a[i], b[i + 1]));
		}
		printf("Case #%d: %d\n", K, ans);
		++K;
	}
	return 0;
}
