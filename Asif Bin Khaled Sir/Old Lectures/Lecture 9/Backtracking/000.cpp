#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
using ll = long long int;
static int path = 0;
void printpath(vector<pair<ll, ll>> v)
{
    path++;
    cout << "Path " << path << " is:\n";
    for (auto i : v)
    {
        cout << "(" << i.first << ',' << i.second << ")" << '\n';
    }
}
void mazepaths(vector<pair<ll, ll>> &v, int x, int y, int size)
{
    if (x == size + 1 || y == size + 1)
    {
        return;
    }
    v.pb({x, y});
    mazepaths(v, x + 1, y, size);
    mazepaths(v, x, y + 1, size);
    if (x == size && y == size)
    {
        printpath(v);
    }
    v.pop_back();
}
int main()
{
    //demo
    //considering down and right as the only operation
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<ll, ll>> v;
    mazepaths(v, 0, 0, 3);
}
