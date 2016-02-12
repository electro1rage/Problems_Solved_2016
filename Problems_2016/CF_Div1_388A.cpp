/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

int a[101], b[101];

int main() {
	int n, i, j, k;
	scanf("%d", &n);

	for (i = 0; i < n; ++i) scanf("%d", a + i);

	sort(a, a + n);
	reverse(a, a + n);

	for (i = 1; i <= n; ++i) {
		for (j = 0; j < i; ++j) b[j] = 1000000000;
		j = 0;
		while (j != n) {
			for (k = 0; k < i && j < n; ++j, ++k) {
				if (b[k] == 0) goto END;
				b[k] = min(b[k] - 1, a[j]);
			}
		}
		printf("%d\n", i);
		break;
		END:;
	}
	return 0;
}
