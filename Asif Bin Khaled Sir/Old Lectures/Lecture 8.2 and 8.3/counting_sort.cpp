#include <iostream>
#include <vector>
#include <algorithm>
#define nline '\n'
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
int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll lim = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        if (!i)
        {
            lim = v[i];
        }
        else
        {
            lim = max(lim, v[i]);
        }
    }
    vector<ll> frequency(lim + 1, 0);
    for (ll i : v)
        frequency[i]++;
    /*
	for (ll i = 1; i < n; i++)
	{
		cumulative_fr[i] = cumulative_fr[i - 1] + cumulative_fr[i];
	}*/
    ll k = 0;
    for (ll i = 0; i < lim + 1; i++)
    {
        while (frequency[i] > 0)
        {
            v[k++] = i;
            frequency[i]--;
        }
    }
    cout << v;
    return 0;
}