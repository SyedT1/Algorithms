#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //insertion sort
    vector<int> v{3, 1, 4, -1, 0};
    for (int i = 1, vl = (int)v.size(); i < vl; i++)
    {
        int j = i;
        while (v[j] < v[j - 1] && j > 0)
        {
            //swapping
            v[j] += v[j - 1];
            v[j - 1] = v[j] - v[j - 1];
            v[j] -= v[j - 1];
            j--;
        }
    }
    for (int i : v)
        cout << i << ',';
}
