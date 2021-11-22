#include <iostream>
#include <vector>
#define nline '\n'
using namespace std;
using ll = long long int;
void heapify(vector<ll> &arr, ll n, ll i)
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
void construct_heap(vector<ll> &arr, ll n)
{
    ll index = (n / 2) - 1;
    while (index >= 0)
    {
        heapify(arr, n, index);
        index--;
    }
}
ll extract_max(vector<ll> &arr, ll &n)
{
    if (n < 1)
    {
        cout << "Empty\n";
        return -1;
    }
    ll val = arr[0];
    swap(arr[0], arr[n - 1]);
    n--;
    arr.pop_back();
    heapify(arr, n, 0);
    return val;
}
void change_key(vector<ll> &arr, ll n, ll key, ll change)
{
    ll index = -1;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            ll num = i;
            arr[i] = key;
            if (key > change)
            {
                while (num > 0 && arr[num] > arr[num / 2])
                {
                    swap(arr[num], arr[num / 2]);
                    num = num / 2;
                }
            }
            else
            {
                heapify(arr, n, i);
            }
        }
    }
}
void insert_key(vector<ll> &v, ll &n, ll key)
{
    n++;
    v.push_back(key);
    ll i = n - 1;
    while (i > 0 && v[i] > v[i / 2])
    {
        swap(v[i], v[i / 2]);
        i = i / 2;
    }
}
ll get_mx(vector<ll>arr)
{
    return arr[0];
}
int main()
{
    ll n = 7;
    vector<ll> arr;
    for (ll i : {1, 33, 4, 55, 6, 7, 4})
        arr.push_back(i);
    construct_heap(arr, n);
    cout << extract_max(arr, n) << nline;
    cout << extract_max(arr, n) << nline;
    change_key(arr, n, 4, 11);
    insert_key(arr, n, 32);
    insert_key(arr, n, -1);
    for (ll i = 0; i < n; i++)
    {
        cout << arr[i] << ',';
    }
}
