#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <unordered_map>
#include <fstream>
#include <sstream>
#define nline '\n'
#define len(s) ll((s).size())
#define pb push_back
#define pp pop_back
using namespace std;
using ll = long long int;
using par = pair<ll, ll>;

template <typename T>
ostream &operator<<(ostream &out, vector<T> v)
{
	for (T i : v)
	{
		out << i << ' ';
	}
	return out;
}
istream &operator>>(istream &in, vector<ll> &v)
{
	ll l = len(v);
	for (ll &i : v)
	{
		cin >> i;
	}
	return in;
}
void fop_cl()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
ll de2(string x) {
	ll ln = len(x);
	ll p = 1, s = 0;
	for (ll i = ln - 1; i >= 0; i--, p *= 2) {
		s += ll(p * (x[i] > '0'));
	}
	return s;
}
ll res(vector<string>v, ll slen, ofstream &F) {
	vector<string>res;
	ll k = 0;
	while (k < slen) {
		ll vlen = len(v);
		vector<vector<string>>vvs(2, vector<string> {});
		for (ll i = 0; i < vlen; i++) {
			vvs[(v[i])[k] - '0'].pb(v[i]);
		}
		ll Ro = len(vvs[0]), Ne = len(vvs[1]);
		if (Ne >= Ro) {
			v = vvs[Ne];
		} else {
			v = vvs[Ro];
		}
		k++;
	}
	return de2(v[0]);
}
int main()
{
	ifstream FILE;
	FILE.open("input.txt");
	if (FILE.is_open()) {
		ofstream FOUT("output.txt");
		vector<string>v;
		while (FILE.good()) {
			string s;
			FILE >> s;
			v.pb(s);
		}
		FOUT << res(v, len(v[0]), FOUT) << nline;
		FOUT.close();
		FILE.close();

	} else {
		cout << "Couldn't solve" << nline;
	}
	return 0;
}