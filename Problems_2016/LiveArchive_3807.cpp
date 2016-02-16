/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

#define UP 0
#define DN 1
#define LF 2
#define RT 3

const int MN = 4;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct ball {
	int num, x, y;
	bool operator<(const ball& a) const {
		if (x != a.x) return x < a.x;
		if (y != a.y) return y < a.y;
		return num < a.num;
	}
};

bool bad[MN][MN][MN][MN];
int grid[MN][MN];

bool cmpnorm(ball a, ball b) {
	if (a.x != b.x) return a.x < b.x;
	if (a.y != b.y) return a.y < b.y;
	return a.num < b.num;
}

bool cmpup(ball a, ball b) {
	return a.x < b.x;
}

bool cmpdn(ball a, ball b) {
	return a.x > b.x;
}

bool cmplf(ball a, ball b) {
	return a.y < b.y;
}

bool cmprt(ball a, ball b) {
	return a.y > b.y;
}

void normalize(vector<ball> &v) {
	sort(v.begin(), v.end(), cmpnorm);
}

void go_up(vector<ball> &v) {
	sort(v.begin(), v.end(), cmpup);
}

void go_down(vector<ball> &v) {
	sort(v.begin(), v.end(), cmpdn);
}

void go_lift(vector<ball> &v) {
	sort(v.begin(), v.end(), cmplf);
}

void go_right(vector<ball> &v) {
	sort(v.begin(), v.end(), cmprt);
}

bool can_move(ball a, int dir, int n) {
	int nx = a.x + dx[dir], ny = a.y + dy[dir];
	if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
		if (!bad[a.x][a.y][nx][ny]) {
			return true;
		}
	}
	return false;
}

vector<ball> get_next(vector<ball> a, int dir, int n, bool &good) {
	int i, j;
	good = true;
	for (i = 0; i < a.size(); ++i) {
		while (true) {
			if (!can_move(a[i], dir, n)) {
				goto END;
			}
			int nx = a[i].x + dx[dir], ny = a[i].y + dy[dir];
			for (j = 0; j < i; ++j) if (a[j].x == nx && a[j].y == ny) {
				goto END;
			}
			if (grid[nx][ny] == a[i].num) {
				a.erase(a.begin() + i), --i;
				goto END;
			}
			if (grid[nx][ny] != 0) {
				for (j = 0; j < a.size(); ++j) if (grid[nx][ny] == a[j].num) {
					good = false;
					return vector<ball> ();
				}
			}
			a[i].x = nx, a[i].y = ny;
		}
		END:;
	}
	return a;
}

int bfs(vector<ball> s, int n) {
	if (s.empty()) return 0;
	set<vector<ball> > vst;
	normalize(s);
	vst.insert(s);
	int level = 0, sz;
	queue<vector<ball> > q;
	q.push(s);
	vector<ball> a, b;

	while (!q.empty()) {
		sz = q.size();
		while (sz--) {
			a = q.front(), q.pop();
			bool good;
			go_down(a);
			b = get_next(a, DN, n, good);
			if (good) {
				normalize(b);
				if (b.empty()) return level + 1;
				if (vst.find(b) == vst.end()) vst.insert(b), q.push(b);
			}

			go_up(a);
			b = get_next(a, UP, n, good);
			if (good) {
				normalize(b);
				if (b.empty()) return level + 1;
				if (vst.find(b) == vst.end()) vst.insert(b), q.push(b);
			}

			go_lift(a);
			b = get_next(a, LF, n, good);
			if (good) {
				normalize(b);
				if (b.empty()) return level + 1;
				if (vst.find(b) == vst.end()) vst.insert(b), q.push(b);
			}

			go_right(a);
			b = get_next(a, RT, n, good);
			if (good) {
				normalize(b);
				if (b.empty()) return level + 1;
				if (vst.find(b) == vst.end()) vst.insert(b), q.push(b);
			}
		}

		++level;
	}
	return -1;
}

int main() {
	int K = 1;
	while (true) {
		int n, m, w, i, x1, y1, x2, y2, ans;
		scanf("%d %d %d", &n, &m, &w);
		if (n == 0 && m == 0 && w == 0) break;

		memset(bad, 0, sizeof bad);
		memset(grid, 0, sizeof grid);

		vector<ball> v;
		for (i = 0; i < m; ++i) {
			scanf("%d %d", &x1, &y1);
			v.push_back({i + 1, x1, y1});
		}
		for (i = 0; i < m; ++i) {
			scanf("%d %d", &x1, &y1);
			grid[x1][y1] = i + 1;
		}
		for (i = 0; i < w; ++i) {
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			bad[x1][y1][x2][y2] = bad[x2][y2][x1][y1] = true;
		}

		ans = bfs(v, n);
		if (ans == -1) printf("Case %d: impossible\n\n", K);
		else printf("Case %d: %d moves\n\n", K, ans);
		++K;
	}
	return 0;
}
