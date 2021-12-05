#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <unordered_map>
#include <fstream>
#include <queue>
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
void bfs(vector<vector<ll>>adj, ll src, vector<bool>&vis, vector<ll>&pathlength) {
    queue<ll>q;
    q.push(src);
    vis[src] = false;
    pathlength[src] = 0;
    while (!q.empty()) {
        ll frontnode = q.front();
        q.pop();
        for (ll i : adj[frontnode]) {
            if (!vis[i]) {
                pathlength[i] = pathlength[frontnode] + 6;
                q.push(i);
                vis[i] = true;
            }
        }
    }
}
void solve() {
    ll v, n; cin >> v >> n;
    vector<vector<ll>>adj(v + 1);
    vector<bool>vis(v + 1, false);
    set<par>vi;
    vector<ll>pathlength(v + 1, -1);
    for (ll i = 0; i < n; i++) {
        ll src, des; cin >> src >> des;
        if (vi.count({src, des}) || vi.count({des, src})) {
            continue;
        }
        adj[src].pb(des);
        adj[des].pb(src);
        vi.insert({src, des});
        vi.insert({des, src});
    }
    ll src; cin >> src;
    bfs(adj, src, vis, pathlength);
    for (ll i = 1; i <= v; i++) {
        if (i != src) {
            cout << pathlength[i] << ' ';
        }
    }
    cout << nline;
}
int main()
{
    //fop_cl();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll Q; cin >> Q;
    while (Q--) {
        solve();
    }
    return 0;
}
