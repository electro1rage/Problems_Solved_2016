/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

struct data {
	long long end;
	int ind;
	bool operator<(const data &x) const {
		return x.end < end;
	}
	data& operator=(const data &x) {
		end = x.end, ind = x.ind;
		return *this;
	}
};

const int MN = 101010;

int a[MN];

int main() {
	freopen("laundro_matt.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, K = 1;
	scanf("%d", &T);
	while (T--) {
		int l, n, m, d, i;
		long long ans = 0;
		scanf("%d %d %d %d", &l, &n, &m, &d);

		priority_queue<data> wash, dry;

		for (i = 0; i < n; ++i) scanf("%d", a + i), wash.push({a[i], i});
		for (i = 0; i < min(l, m); ++i) dry.push({0, -1});

		for (i = 0; i < l; ++i) {
			data ww, dd;
			ww = wash.top(), wash.pop();
			wash.push({ww.end + a[ww.ind], ww.ind});

			ans = max(ans, ww.end);

			dd = dry.top(), dry.pop();
			long long maxi = max(ww.end, dd.end) + d;
			dry.push({maxi, -1});
			ans = max(ans, maxi);
		}


		printf("Case #%d: %lld\n", K, ans);
		++K;
	}
	return 0;
}
