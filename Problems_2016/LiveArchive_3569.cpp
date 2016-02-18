/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 55, MVAL = 1010101010;

int f[MN][MN];

int main() {
	int K = 1;
	while (true) {
		int n, m, X, ans, i, j, k;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;

		string a, b;

		X = 0;
		map<string, int> mx;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) f[i][j] = MVAL;
		}

		for (i = 0; i < m; ++i) {
			cin >> a >> b;
			if (!mx.count(a)) mx[a] = X, ++X;
			if (!mx.count(b)) mx[b] = X, ++X;
			f[mx[a]][mx[b]] = f[mx[b]][mx[a]] = 1;
		}

		for (i = 0; i < n; ++i) f[i][i] = 0;

		for (k = 0; k < n; ++k) {
			for (i = 0; i < n; ++i) {
				for (j = 0; j < n; ++j) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}

		ans = 0;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				ans = max(ans, f[i][j]);
			}
		}

		if (ans == MVAL) printf("Network %d: DISCONNECTED\n", K);
		else printf("Network %d: %d\n", K, ans);
		puts("");
		++K;
	}
	return 0;
}
