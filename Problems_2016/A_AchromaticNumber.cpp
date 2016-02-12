/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 1010;

int have[MN][MN];
vector<int> ans;

void euler(int node, int n) {
	int i;
	for (i = 1; i <= n; ++i) {
		if (have[node][i]) {
			--have[node][i], --have[i][node], euler(i, n);
		}
	}
	ans.push_back(node);
}

int get_len(int n) {
	if (n % 2) return n * (n - 1) / 2;
	return n * (n - 1) / 2 + n / 2;
}

int main() {
	freopen("achromatic.in", "r", stdin);
	freopen("achromatic.out", "w", stdout);

	int n, maxi = 0, num = 0, i, j;
	scanf("%d", &n);

	for (i = 2; i <= n; ++i) {
		if (get_len(i) <= n && (i % 2 == 0 || n - i * (i - 1) / 2 != 1)) maxi = i, num = get_len(i);
	}

	cout << maxi << ' ' << num << endl;

	for (i = 1; i <= maxi; ++i) {
		for (j = i + 1; j <= maxi; ++j) {
			++have[i][j], ++have[j][i];
		}
	}

	if (maxi % 2 == 0) {
		for (i = 1; i <= maxi - 2; i += 2) ++have[i][i + 1], ++have[i + 1][i];
	}

	euler(maxi, maxi);
	reverse(ans.begin(), ans.end());

	if (maxi % 2 == 1) {
		if (num < n) ans.push_back(ans[0]);
		++num;
	}

	ans.resize(n);

	for (i = num; i < n; ++i) ans[i] = -1;
	for (i = num; i < n; ++i) {
		for (j = 1; j <= maxi; ++j) {
			if (j != ans[i - 1] && j != ans[(i + 1) % n]) {
				ans[i] = j;
				break;
			}
		}
	}

	printf("%d\n", maxi);
	for (i = 0; i < n; ++i) {
		if (i) putchar (' ');
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
