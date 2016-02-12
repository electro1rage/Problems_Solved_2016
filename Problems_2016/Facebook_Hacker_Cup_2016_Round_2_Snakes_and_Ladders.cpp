/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007, MN = 202020;

int acum[MN];

void add(int &a, int b) {
	a = (1LL * a + b) % MOD;
}

void take(int &a, int b) {
	a = (1LL * a - b + MOD) % MOD;
}

void get_ans(vector<pair<int, int> > &v, int &ans) {
	int n = v.size(), i;
	for (i = 0; i < n; ++i) {
		add(ans, (1LL * ((1LL * (n - 1) * v[i].first) % MOD) * v[i].first) % MOD);
	}
	acum[n] = 0;
	for (i = n - 1; i > 0; --i) acum[i] = (1LL * v[i].first + acum[i + 1]) % MOD;

	for (i = 0; i < n; ++i) {
		take(ans, (1LL * (2LL * v[i].first % MOD) * acum[i + 1]) % MOD);
	}
}


void update_st(stack<pair<int, int> > &st, int h, int &ans) {
	vector<pair<int, int> > v;
	while (!st.empty() && h > st.top().second) {
		if (v.empty()) v.push_back(st.top()), st.pop();
		else if (v.back().second == st.top().second) v.push_back(st.top()), st.pop();
		else {
			reverse(v.begin(), v.end());
			get_ans(v, ans);
			v.clear();
		}
	}
	get_ans(v, ans);
}

int main() {
	freopen("snakes_and_ladders.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, K = 1;
	scanf("%d", &T);
	while (T--) {
		int ans = 0, n, i;

		scanf("%d", &n);

		stack<pair<int, int> > st;
		vector<pair<int, int> > a(n);

		for (i = 0; i < n; ++i) {
			scanf("%d %d", &a[i].first, &a[i].second);
		}

		sort(a.begin(), a.end());

		for (i = 0; i < n; ++i) {
			if (st.empty()) st.push(a[i]);
			else {
				if (a[i].second <= st.top().second) st.push(a[i]);
				else {
					update_st(st, a[i].second, ans);
					st.push(a[i]);
				}
			}
		}

		update_st(st, MOD, ans);
		printf("Case #%d: %d\n", K, ans);
		++K;
	}
	return 0;
}
