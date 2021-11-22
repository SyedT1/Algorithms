#include <iostream>
#define nline '\n'
using namespace std;
using ll = long long int;
void heapify(ll arr[], ll n, ll i)
{
    ll largest = i;
    ll left_to_par = 2 * i + 1, right_to_par = 2 * i + 2;
    if (left_to_par < n && arr[left_to_par] > arr[largest])
    {
        largest = left_to_par;
    }
    if (right_to_par < n && arr[right_to_par] > arr[largest])
    {
        largest = right_to_par;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
using ll = long long int;
void heapsort(ll arr[], ll n)
{
    ll index = (n / 2) - 1;
    while (index >= 0)
    {
        heapify(arr, n, index);
        index--;
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}
int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll &i : arr)
    {
        cin >> i;
    }
    heapsort(arr, n);
    for (ll i : arr)
    {
        cout << i << ',';
    }
}
