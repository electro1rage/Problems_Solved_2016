/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 202020, LOGN = 19;

int value[MN], last[MN], M[LOGN][MN], dpth[MN];

int main() {
	freopen("queue.in", "r", stdin);
	freopen("queue.out", "w", stdout);

	memset(last, -1, sizeof last);
	memset(M, -1, sizeof M);
	dpth[0] = 0;

	int n, op, a, b, node, i, j;

	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf("%d", &op);
		if (op != -1) {
			scanf("%d %d", &a, &b);
			M[0][i] = a;
			value[i] = b;
			dpth[i] = dpth[a] + 1;
			if (last[a] != -1) last[i] = last[a];
			else last[i] = i;

			for (j = 1; j < LOGN; ++j) {
				node = M[j - 1][i];
				if (node != -1) M[j][i] = M[j - 1][node];
			}
		} else {
			scanf("%d", &a);
			printf("%d\n", value[last[a]]);
			M[0][i] = M[0][a];
			value[i] = value[a];
			dpth[i] = dpth[a];

			for (j = 1; j < LOGN; ++j) {
				node = M[j - 1][i];
				if (node != -1) M[j][i] = M[j - 1][node];
			}

			if (last[a] == a) {
				last[i] = -1;
				continue;
			}

			node = i;
			for (j = LOGN - 1; j >= 0; --j) {
				if (M[j][node] != -1 && dpth[M[j][node]] > dpth[last[a]]) node = M[j][node];
			}

			last[i] = node;
		}
	}
	return 0;
}
