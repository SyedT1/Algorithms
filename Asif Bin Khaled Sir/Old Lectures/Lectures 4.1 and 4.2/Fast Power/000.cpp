#include <iostream>
using namespace std;
int fast_power(int x, int y)
{
    if (y > 0)
    {
        if (y & 1)
            return x * fast_power(x * x, y / 2);
        else
            return fast_power(x * x, y / 2);
    }
    else
        return 1;
}
int main()
{
    int a;
    cin >> a;
    for (int i : {1, 2, 3, 4, 5})
        cout << fast_power(a, i) << endl;
}
