/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

long long C[100][100];

long long get_count(long long n, int k) {
	long long ret = 0;
	int i = 0, p = 0, a[100] = {};
	while (n) a[i] = n % 2, n /= 2, ++i;

	for (i = i - 1; i >= 0; --i) {
		if (a[i] == 1) {
			if (k - p >= 0 && k - p <= i) ret += C[i][k - p];
			++p;
		}
	}

	if (p == k) ++ret;
	return ret;
}

int main() {
	long long m, s, e, mid, ans;
	int k, i, j;

	for (i = 0; i < 70; ++i) {
		C[i][0] = C[i][i] = 1;
		for (j = 1; j < i; ++j) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}

	scanf("%I64d %d", &m, &k);

	s = 1, e = 1000000000000000000LL;
	while (s <= e) {
		mid = (s + e) / 2;
		if (get_count(mid * 2, k) - get_count(mid, k) >= m) ans = mid, e = mid - 1;
		else s = mid + 1;
	}

	printf("%I64d\n", ans);
	return 0;
}
