/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 1010;

char ans[MN][MN];

void add(int x, int y) {
	ans[x][y] = ans[y][x] = 'Y';
}

int main() {
	int K, rem, t, last, sz, s, i, j, k;
	long long pre;
	scanf("%d", &K);

	for (i = 0; i < MN; ++i) {
		for (j = 0; j < MN; ++j) ans[i][j] = 'N';
	}

	for (i = 1; i <= 1000; ++i) {
		rem = 1000 - 2;
		t = K;
		vector<vector<int> > a;
		while (t > 0 && rem >= 0) {
			pre = 1;
			vector<int> b;
			for (j = 0; j < i; ++j) {
				for (k = 10; k > 0; --k) {
					if (k * pre <= t && rem - k - 1 >= 0) {
						rem -= k + 1, pre *= k, b.push_back(k);
						break;
					}
				}
				if (k == 0) {
					rem = -1;
					break;
				}
			}
			a.push_back(b);
			t -= pre;
		}
		if (t != 0 || rem < 0) continue;
		sz = a.size();
		last = 2;
		for (j = 0; j < sz; ++j) {
			s = 1;
			for (auto &x : a[j]) {
				for (k = 0; k < x; ++k) {
					add(s, last + k + 1);
					add(last + k + 1, last + x + 1);
				}
				last = last + x + 1, s = last;
			}
			add(last, 2);
		}

		puts("1000");
		for (i = 1; i <= 1000; ++i) {
			for (j = 1; j <= 1000; ++j) putchar(ans[i][j]);puts("");
		}
		return 0;
	}
	printf("kawaii");
	return 0;
}
