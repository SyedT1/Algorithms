#include <iostream>
#define nline '\n'
using namespace std;
using ll = long long int;
void heapify(ll arr[], ll n, ll index)
{
    ll largest = index;
    ll left_of_par = 2 * largest + 1, right_of_par = 2 * largest + 2;
    if (left_of_par < n && arr[left_of_par] > arr[largest])
        largest = left_of_par;
    if (right_of_par < n && arr[right_of_par] > arr[largest])
        largest = right_of_par;
    if (index != largest)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }
}
void construct_heap(ll arr[], ll n)
{
    ll index = (n / 2) - 1;
    while (index >= 0)
    {
        heapify(arr, n, index);
        index--;
    }
}
int main()
{
    cout << "Determine the array size = " << nline;
    ll n;
    cin >> n;
    ll arr[n];
    cout << "Determine the max value as input = " << nline;
    ll mxval;
    cin >> mxval;
    for (ll i = 0; i < n; i++)
    {
        arr[i] = rand() % mxval + 1;
    }
    cout << "Array set as per random inputs = " << nline;
    for (ll i : arr)
    {
        cout << i << ',';
    }
    cout << nline;
    construct_heap(arr, n);
    cout << "After constructing using max heap = " << nline;
    for (ll i : arr)
    {
        cout << i << ',';
    }
}
