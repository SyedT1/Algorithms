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

template <typename T>
ostream &operator<<(ostream &out, vector<T> v)
{
    for (T i : v)
    {
        out << i << ' ';
    }
    return out;
}

template <typename T>
ostream &operator<<(ostream &out, vector<vector<T>> v)
{
    for (auto i : v)
    {
        for (auto j : i)
        {
            out << j << ' ';
        }
        out << nline;
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
bool chkWin(vector<vector<bool>> t, ofstream &FOUT)
{
    for (ll z = 0; z < 2; z++)
    {
        for (ll i = 0; i < 5; i++)
        {
            ll k = 0;
            for (ll j = 0; j < 5; j++)
            {
                if (t[!z ? i : j][z ? j : i])
                {
                    k++;
                }
            }
            if (k == 5)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    ifstream FILE;
    FILE.open("input.txt");
    if (FILE.is_open())
    {
        ofstream FOUT("output.txt");
        vector<ll> commands;
        string s;
        FILE >> s;
        stringstream line(s);
        while (line.good())
        {
            string num;
            getline(line, num, ',');
            commands.pb(stoll(num));
        }
        //	FOUT << "Done with the file line\n";
        vector<vector<vector<ll>>> teams;
        ll row = 0, k = 0;
        vector<vector<ll>> person;
        while (getline(FILE, s))
        {
            if (s.length() == 0)
            {
                row = 0;
                if (person.size() > 0)
                {
                    teams.pb(person);
                }
                person.clear();
            }
            else
            {
                vector<ll> col;
                stringstream t(s);
                string inputdata;
                while (t.good())
                {
                    t >> inputdata;
                    col.pb(stoll(inputdata));
                }
                person.pb(col);
                //FOUT << col  << nline;
            }
        }
        teams.pb(person);
        pair<ll, ll> winning_command{-1, -1};
        bool stop_game = false;
        vector<vector<vector<bool>>> TeamWNot(teams.size(), vector<vector<bool>>(5, vector<bool>(5, false)));
        for (ll i : commands)
        {
            for (ll a = 0, teamlen = teams.size(); a < teamlen; a++)
            {
                vector<vector<ll>> per = teams[a];
                for (ll j = 0; j < 5; j++)
                {
                    for (ll k = 0; k < 5; k++)
                    {
                        if (per[j][k] == i)
                        {
                            TeamWNot[a][j][k] = true;
                            if (chkWin(TeamWNot[a], FOUT))
                            {
                                winning_command = {i, a};
                                stop_game = true;
                                break;
                            }
                        }
                    }
                    if (stop_game)
                    {
                        break;
                    }
                }
                if (stop_game)
                {
                    break;
                }
                //FOUT << "Team " << a + 1 << " = " << endl << TeamWNot[a] << nline;
            }
            if (stop_game)
            {
                break;
            }
        }
        ll sum = 0;
        for (ll i = 0; i < 5; i++)
        {
            for (ll j = 0; j < 5; j++)
            {
                sum += (teams[winning_command.second][i][j] * (!TeamWNot[winning_command.second][i][j]));
            }
        }
        FOUT << winning_command.first * sum << nline;
        FOUT.close();
        FILE.close();
    }
    else
    {
        cout << "Couldn't solve" << nline;
    }
    return 0;
}
