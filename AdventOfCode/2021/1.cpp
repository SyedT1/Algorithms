#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <fstream>
#include <unordered_map>
#define nline '\n'
#define len(s) ll((s).size())
#define pb push_back
#define pp pop_back
using namespace std;
using ll = long long int;
using par = pair<ll, ll>;
ostream &operator<<(ostream &out, vector<ll> v)
{
	for (ll i : v)
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
int main()
{
	ifstream file;
	file.open("input.txt");
	ll is_greater = 0, k = 0, prev = -1;
	if (file.is_open()) {
		while (file.good()) {
			ll n; file >> n;
			if (!k) {
				prev = n;
				k++;
				continue;
			}
			is_greater += (n > prev);
			prev = n;
			k++;
		}
		file.close();
		ofstream f("output.txt");
		f << is_greater << nline;
		f.close();
	} else {
		cout << "Couldn't be opened\n";
	}
	return 0;
}