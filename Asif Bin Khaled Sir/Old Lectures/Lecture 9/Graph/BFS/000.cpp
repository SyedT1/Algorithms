#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <sstream>
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
void fop_cl()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
vector<ll> bfs(vector<vector<ll>>adj, ll source, ll n, vector<bool>&vis) {
	vector<ll>list_parent(n);
	queue<ll>q;
	q.push(source);
	list_parent[source] = -1;
	while (!q.empty()) {
		ll frontnode = q.front();
		q.pop();
		for (ll i : adj[frontnode]) {
			if (!vis[i]) {
				q.push(i);
				vis[i] = true;
				list_parent[i] = frontnode;
			}
		}
	}
	return list_parent;
}
void solve() {
	ll nvertices, source, des; cin >> nvertices >> source >> des;
	vector<vector<ll>>adj(nvertices);
	vector<bool>vis(nvertices, false);
	ll t; cin >> t;
	for (ll i = 0; i < t; i++) {
		ll node, edge; cin >> node >> edge;
		adj[node].pb(edge);
	}
	vector<ll>pa = bfs(adj, source, nvertices, vis);
	if (!vis[des]) {
		cout << "Path not found\n";
	} else {
		vector<ll>path;
		for (ll i = des; i != -1; i = pa[i]) {
			path.pb(i);
		}
		reverse(path.begin(), path.end());
		for (ll i : path) {
			cout << i << ' ';
		}
	}
}
int main()
{
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}
