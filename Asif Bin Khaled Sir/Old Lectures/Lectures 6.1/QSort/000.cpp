#include <iostream>
#define nline '\n'
using namespace std;
using ll = long long int;
ll partition(ll arr[], ll low, ll high)
{
    //Before 8 4 3 2 1 [pivot=5]
    //       4 8 3 2 1 [pivot=5]
    //       4 3 8 2 1 [same]
    //       4 3 2 8 1 [same]
    //       4 3 2 1 8 [pivot=5]
    //       [4 3 2 1] 5 [8]
    //       []
    ll pivot = arr[high];
    ll i = low - 1;
    for (ll j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[j], arr[++i]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void qsort(ll arr[], ll low, ll high)
{
    if (low < high)
    {
        ll pivot = partition(arr, low, high);
        //fix condition
        // less than pivot | pivot | more than pivot
        qsort(arr, low, pivot - 1);
        qsort(arr, pivot + 1, high);
    }
}
int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        arr[i] = rand() % 10;
    cout << "Before : ";
    for (ll i : arr)
        cout << i << ' ';
    cout << nline;
    qsort(arr, 0, n - 1);
    cout << "After : ";
    for (ll i : arr)
        cout << i << ' ';
    return 0;
}
