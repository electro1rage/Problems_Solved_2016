/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MN = 1010;

vector<int> adj[MN];
bool vst[MN];
int match[MN], to[MN];

int get_duration(int hh, int mm) {
	return hh * 60 + mm - 14 * 60;
}

bool dfs(int node) {
	if (vst[node]) return false;
	vst[node] = true;
	for (auto &x : adj[node]) {
		if (match[x] == -1 || dfs(match[x])) {
			match[x] = node, to[node] = x;
			return true;
		}
	}
	return false;
}

int get_ans(int &ans, const int n, const vector<pair<int, int> > x) {
	ans = 0;
	memset(match, -1, sizeof match);
	memset(to, -1, sizeof to);
	int ret = 0, i;

	for (i = 0; i < n; ++i) {
		memset(vst, 0, sizeof vst);
		dfs(i);
	}

	for (i = 0; i < n; ++i) if (to[i] == -1) ++ans, ret += x[i].first;

	return ret;
}

int main() {
	int K = 1;
	while (true) {
		int n, m, hh, mm, ans, mini, i, j;
		scanf("%d", &n);
		if (n == 0) break;

		for (i = 0; i < n; ++i) adj[i].clear();

		vector<pair<int, int> > x(n);
		for (i = 0; i < n; ++i) scanf("%d %d", &x[i].first, &x[i].second);

		sort(x.rbegin(), x.rend());

		scanf("%d", &m);
		vector<pair<int, int> > y(m);
		for (i = 0; i < m; ++i) {
			scanf("%d %d:%d", &y[i].first, &hh, &mm);
			y[i].second = get_duration(hh, mm);
		}

		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				if (x[i].first <= y[j].first && x[i].second <= y[j].second) adj[i].push_back(j);
			}
		}

		mini = get_ans(ans, n, x);
		printf("Trial %d: %d %d\n\n", K, ans, mini);
		++K;
	}
	return 0;
}
