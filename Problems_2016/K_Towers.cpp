/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

#define right 0
#define down 1

char s[7][7];
char a[7][7];
bool good;

int dx[] = {0, 1};
int dy[] = {1, 0};

int get_num(char c) {
	return c - '0';
}

char get_char(int n) {
	return n + '0';
}

void get_ans(int i, int j, int dir, int &n) {
	if (good) return ;
	if (i == n + 1 && j == n + 1) {
		good = true;
		int x, y;
		for (x = 1; x <= n; ++x) {
			for (y = 1; y <= n; ++y) putchar (a[x][y]);puts("");
		}
		return ;
	}

	if (dir == right) {
		if (j == n + 1) {
			int y, maxi = -1, cnt = 0;
			for (y = 1; y <= n; ++y) {
				if (maxi < a[i][y]) maxi = a[i][y], ++cnt;
			}
			if (s[i][0] != '-' && cnt != get_num(s[i][0])) return ;

			maxi = -1, cnt = 0;
			for (y = n; y >= 1; --y) {
				if (maxi < a[i][y]) maxi = a[i][y], ++cnt;
			}
			if (s[i][n + 1] != '-' && cnt != get_num(s[i][n + 1])) return ;

			bool have[6] = {};
			for (y = 1; y <= n; ++y) have[get_num(a[i][y])] = true;
			cnt = 0;
			for (y = 1; y <= n; ++y) cnt += have[y];
			if (cnt != n) return ;

			get_ans(i + 1, i, down, n);
		} else {
			if (s[i][j] != '-') {
				a[i][j] = s[i][j];
				get_ans(i, j + 1, right, n);
			} else {
				int x;
				for (x = 1; x <= n; ++x) a[i][j] = get_char(x), get_ans(i, j + 1, right, n);
			}
		}
	} else {
		if (i == n + 1) {
			int x, maxi = -1, cnt = 0;
			for (x = 1; x <= n; ++x) {
				if (maxi < a[x][j]) maxi = a[x][j], ++cnt;
			}
			if (s[0][j] != '-' && cnt != get_num(s[0][j])) return ;

			maxi = -1, cnt = 0;
			for (x = n; x >= 1; --x) {
				if (maxi < a[x][j]) maxi = a[x][j], ++cnt;
			}
			if (s[n + 1][j] != '-' && cnt != get_num(s[n + 1][j])) return ;

			bool have[6] = {};
			for (x = 1; x <= n; ++x) have[get_num(a[x][j])] = true;
			cnt = 0;
			for (x = 1; x <= n; ++x) cnt += have[x];
			if (cnt != n) return ;

			get_ans(j + 1, j + 1, right, n);
		} else {
			if (s[i][j] != '-') {
				a[i][j] = s[i][j];
				get_ans(i + 1, j, down, n);
			} else {
				int x;
				for (x = 1; x <= n; ++x) a[i][j] = get_char(x), get_ans(i + 1, j, down, n);
			}
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, i;
		scanf("%d", &n);

		for (i = 0; i <= n + 1; ++i) scanf("%s", s[i]);

		good = false;

		get_ans(1, 1, right, n);

		if (!good) {
			puts("no");
		}

		puts("");
	}
	return 0;
}
