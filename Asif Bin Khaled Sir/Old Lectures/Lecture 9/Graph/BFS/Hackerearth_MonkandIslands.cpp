#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <queue>
#define nline '\n'
#define len(s) ll((s).size())
#define pb push_back
#define pp pop_back
#define loop(x, n) for(int x = 0; x < n; ++ x)
using namespace std;
using ll = long long int;
using par = pair<ll, ll>;

template <typename T>
ostream &operator<<(ostream &out, pair<T, T>p) {
	out << p.first << ' ' << p.second;
	return out;
}
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
	for (ll &i : v)
	{
		cin >> i;
	}
	return in;
}
void bfs(vector<vector<ll>>adj, vector<bool>&vis, vector<ll>&path) {
	ll src = 1;
	path[src] = 0;
	queue<ll>q;
	q.push(src);
	vis[src] = true;
	while (!q.empty()) {
		ll frontnode = q.front();
		q.pop();
		for (ll i : adj[frontnode]) {
			if (!vis[i]) {
				path[i] = path[frontnode] + 1;
				vis[i] = true;
				q.push(i);
			}
		}
	}
}
void fop_cl()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
void solve() {
	ll v, n; cin >> v >> n;
	vector<vector<ll>>adj(v + 1);
	vector<bool>vis(v + 1, false);
	set<pair<ll, ll>>rep;
	vector<ll>path(v + 1, 0);
	for (ll i = 0; i < n; i++) {
		ll src, des; cin >> src >> des;
		if (rep.count({des, src}) || rep.count({src, des})) {
			continue;
		}
		adj[src].pb(des);
		adj[des].pb(src);
		rep.insert({src, des});
		rep.insert({des, src});
	}
	bfs(adj, vis, path);
	cout << path[v] << nline;
}
int main()
{
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll T; cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
