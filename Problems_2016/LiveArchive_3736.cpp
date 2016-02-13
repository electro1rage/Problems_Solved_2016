/*
reality, be rent!
synapse, break!
Van!shment Th!s World !!
*/
#include <bits/stdc++.h>
using namespace std;

struct comb {
	string all, sign;
	comb& operator=(const comb& x) {
		all = x.all, sign = x.sign;
		return *this;
	}
	bool operator<(const comb& x) {
		return (all + sign) < (x.all + x.sign);
	}
};

vector<string> all;
map<string, string> ct;

string get_sign(string sign) {
	if (sign == "--") return "-";
	return "+";
}

string get_type(comb x) {
	string ret;
	ret += ct[x.all];
	ret += get_sign(x.sign);
	return ret;
}

vector<comb> get_comb() {
	vector<comb> ret;
	for (auto &x : all) {
		ret.push_back({x, "++"});
		ret.push_back({x, "+-"});
		ret.push_back({x, "--"});
	}
	return ret;
}

bool is_good(comb a, string b) {
	if (b == "?") return true;
	return get_type(a) == b;
}

void get_ans(vector<comb> &a, string aa, vector<comb> &b, string bb, string c, set<string> &x, set<string> &y, set<string> &z) {
	for (auto &A : a) {
		for (auto &B : b) {
			if (!is_good(A, aa)) continue;
			if (!is_good(B, bb)) continue;
			for (auto &i : A.all) {
				for (auto &j : B.all) {
					for (auto &k : A.sign) {
						for (auto &l : B.sign) {
							string t1 = string("") + i + j, t2 = string("") + k + l;
							comb temp = {t1, t2};
							if (is_good(temp, c)) {
								x.insert(get_type(A));
								y.insert(get_type(B));
								z.insert(get_type(temp));
							}
						}
					}
				}
			}
		}
	}
}

string get_final(set<string> a, string s) {
	if (s != "?") return s;
	s = "";
	int sz = a.size();
	if (sz == 0) return "IMPOSSIBLE";
	if (sz == 1) return *(a.begin());
	s += "{";
	bool fst = true;
	for (auto &x : a) {
		if (!fst) s += ", ";
		fst = false;
		s += x;
	}
	s += "}";
	return s;
}

int main() {
	all.push_back("AA");
	all.push_back("AB");
	all.push_back("AO");
	all.push_back("BB");
	all.push_back("BO");
	all.push_back("OO");
	all.push_back("BA");
	all.push_back("OA");
	all.push_back("OB");

	ct["AA"] = "A";
	ct["AB"] = "AB";
	ct["AO"] = "A";
	ct["BB"] = "B";
	ct["BO"] = "B";
	ct["OO"] = "O";
	ct["BA"] = "AB";
	ct["OA"] = "A";
	ct["OB"] = "B";

	int K = 1;
	while (true) {
		string a, b, c;
		cin >> a >> b >> c;
		if (a == "E" && b == "N" && c == "D") break;

		set<string> AA, BB, CC;
		vector<comb> A, B;
		A = get_comb();
		B = get_comb();

		get_ans(A, a, B, b, c, AA, BB, CC);

		a = get_final(AA, a);
		b = get_final(BB, b);
		c = get_final(CC, c);

		cout << "Case " << K << ": " << a << ' ' << b << ' ' << c << endl;
		++K;
	}
	return 0;
}
