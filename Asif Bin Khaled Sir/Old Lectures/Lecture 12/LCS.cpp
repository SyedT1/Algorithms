#include <iostream>
#include <vector>
#define nline '\n'
using namespace std;
using ll = long long int;
ll lcs(string str1, string str2)
{
    ll l1 = str1.length(), l2 = str2.length();
    vector<vector<ll>> dp{l1 + 1, vector<ll>(l2 + 1, 0)};
    for (ll i = 1; i <= l1; i++)
    {
        for (ll j = 1; j <= l2; j++)
        {
            ll p = i - 1, q = j - 1;
            if (str1[p] == str2[q])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[l1][l2];
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << lcs(str1, str2) << nline;
}