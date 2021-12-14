#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define nline '\n'
using namespace std;
using ll = long long int;
using IR = pair<ll, ll>;
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> vn(n), vm(m);
    for (ll i = 0; i < n; i++)
    {
        cin >> vn[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> vm[i];
    }
    vector<ll> path;
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            ll p = i - 1, q = j - 1;
            if (vm[p] == vn[q])
            {
                path.push_back(vm[p]);
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    ll r = m, s = n;
    while (dp[r-1][s-1] != 0)
    {
        path.push_back(vm[r - 1]);
        cout<<vn[r-1]<<nline;
        r--;
        s--;
    }
}