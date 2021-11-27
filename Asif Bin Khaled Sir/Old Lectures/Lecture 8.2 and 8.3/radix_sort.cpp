#include <iostream>
#include <vector>
#include <algorithm>
#define nline '\n'
#define pb push_back
using namespace std;
using ll = long long int;
ostream &operator<<(ostream &out, vector<ll> v)
{
    ll len = ll(v.size());
    for (ll i = 0; i < len; i++)
    {
        out << v[i] << ' ';
    }
    return out;
}
void radix_sort(vector<vector<ll>> &v, ll pw10)
{
    vector<vector<ll>> sort_(10, vector<ll>{});
    for (ll i = 0; i < 10; i++)
    {
        ll v_ilen = (ll)v[i].size();
        for (ll j = 0; j < v_ilen; j++)
        {
            sort_[(v[i][j] / pw10) % 10].pb(v[i][j]);
        }
    }
    v = sort_;
}
int main()
{
    ll n, mx = 0;
    cin >> n;
    vector<ll> v(n);
    vector<vector<ll>> freq(10, vector<ll>{});
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        if (!i)
            mx = v[i];
        else
            mx = max(mx, v[i]);
        freq[v[i] % 10].pb(v[i]);
    }
    ll mx_size = 0;
    while (mx > 0)
    {
        mx_size++;
        mx /= 10;
    }
    ll l = 10;
    for (ll i = 1; i < mx_size; i++)
    {
        radix_sort(freq, l);
        l *= 10;
    }
    ll k = 0;
    for (ll i = 0; i < 10; i++)
    {
        ll freq_ilen = (ll)freq[i].size();
        for (ll j = 0; j < freq_ilen; j++)
            v[k++] = freq[i][j];
    }
    cout << v;
    return 0;
}