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

	ifstream FILE;
	FILE.open("input.txt");
	int base = 0, depth = 0, aim = 0;
	if (FILE.is_open()) {
		ofstream FOUT("output.txt");
		while (FILE.good()) {
			string s; int n;
			FILE >> s >> n;
			if (s == "forward")
			{
				base += n;
				depth += ( n * aim);
				//FOUT << depth << ' ' << aim << nline;
			} else if (s == "down") {
				aim += n;
			} else if (s == "up") {
				aim -= n;
			}
			if (FILE.eof())
				break;
		}
		FOUT << base * depth << nline;
		FOUT.close();
		FILE.close();

	} else {
		cout << "Couldn't solve" << nline;
	}
	return 0;
}