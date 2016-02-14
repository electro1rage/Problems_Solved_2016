/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

const int MVAL = 1010101010;

struct packet {
	int message, start, end;
	bool operator<(const packet& x) const {
		return x.start < start;
	}
	packet& operator=(const packet& x) {
		message = x.message, start = x.start, end = x.end;
		return *this;
	}
};

int full[6];
packet p[1010];

int get_ans(vector<int> order, int n, int m) {
	priority_queue<packet> q[6];
	int curmessage = 0, cursz = 0, ret = 0, start[6], i;

	for (i = 1; i <= n; ++i) start[i] = 1;

	for (i = 0; i < m; ++i) {
		packet temp = p[i];
		if (temp.message == order[curmessage] && start[temp.message] == temp.start) {
			start[temp.message] = temp.end + 1;
			if (start[temp.message] > full[temp.message]) ++curmessage;
		}
		else {
			q[temp.message].push(temp), cursz += temp.end - temp.start + 1;
		}

		ret = max(ret, cursz);

		while (curmessage < n && !q[order[curmessage]].empty() && start[order[curmessage]] == q[order[curmessage]].top().start) {
			packet temp = q[order[curmessage]].top();
			cursz -= temp.end - temp.start + 1, start[temp.message] = temp.end + 1, q[temp.message].pop();
			if (start[temp.message] > full[temp.message]) ++curmessage;
		}
	}

	return ret;
}

int main() {
	int K = 1;
	while (true) {
		int n, m, ans = MVAL, i;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;

		for (i = 0; i < n; ++i) scanf("%d", full + i + 1);

		for (i = 0; i < m; ++i) scanf("%d %d %d", &p[i].message, &p[i].start, &p[i].end);

		vector<int> a;
		for (i = 1; i <= n; ++i) a.push_back(i);

		do {
			ans = min(ans, get_ans(a, n, m));
		} while (next_permutation(a.begin(), a.end()));

		printf("Case %d: %d\n\n", K, ans);
		++K;
	}
	return 0;
}
