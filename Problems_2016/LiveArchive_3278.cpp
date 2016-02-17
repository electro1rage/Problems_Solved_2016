/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 20, MM = 11;

int mask[MM], sz[MM], val[MM];
int cover[MN], bestans, bestmask;

void get_ans(int i, int curmask, int rem, const int n, const int t) {
	if (i == n) {
		if (rem != 0) return ;
		int tempans = 0, tempmask, i;
		for (i = 0; i < n; ++i) if ((curmask >> i) & 1) tempans += cover[i];
		for (i = 0; i < t; ++i) {
			tempmask = curmask & mask[i];
			if (tempmask == 0) continue;
			tempans -= (__builtin_popcount(tempmask) - 1) * val[i];
		}
		if (tempans > bestans) bestans = tempans, bestmask = curmask;
		return ;
	}

	get_ans(i + 1, curmask | (1 << i), rem - 1, n, t);
	get_ans(i + 1, curmask, rem, n, t);
}

int main() {
	int K = 1;
	while (true) {
		int n, m, t, x, i, j;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) return 0;

		for (i = 0; i < n; ++i) scanf("%d", cover + i);

		memset(mask, 0, sizeof mask);
		bestans = -1;

		scanf("%d", &t);
		for (i = 0; i < t; ++i) {
			scanf("%d", sz + i);
			for (j = 0; j < sz[i]; ++j) {
				scanf("%d", &x), --x;
				mask[i] |= 1 << x;
			}
			scanf("%d", val + i);
		}

		get_ans(0, 0, m, n, t);
		printf("Case Number  %d\n", K);
		++K;
		printf("Number of Customers: %d\n", bestans);
		printf("Locations recommended: ");
		bool fst = true;
		for (i = 0; i < n; ++i) {
			if ((bestmask >> i) & 1) {
				if (!fst) putchar (' ');
				fst = false;
				printf("%d", i + 1);
			}
		}
		puts("\n");
	}
	return 0;
}
