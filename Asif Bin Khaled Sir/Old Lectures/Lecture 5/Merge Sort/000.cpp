#include <iostream>
using namespace std;
void merge_sort(int start, int mid, int end, int arr[])
{
    int L[mid - start + 1], R[end - mid];
    //    cout << start << ' ' << mid << ' ' << end << ' ' << endl;
    for (int i = 0, j = start; i < mid - start + 1; i++)
        L[i] = arr[j + i];
    for (int i = 0, j = mid + 1; i < end - mid; i++)
        R[i] = arr[j + i];
    int L_len = mid - start + 1, R_len = end - mid, i = 0, j = 0, main_ = start;
    while (i < L_len && j < R_len)
    {
        if (L[i] < R[j])
            arr[main_++] = L[i++];
        else
            arr[main_++] = R[j++];
    }
    while (i < L_len)
        arr[main_++] = L[i++];
    while (j < R_len)
        arr[main_++] = R[j++];
}
void merge(int l, int r, int arr[])
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge(l, mid, arr);
        merge(mid + 1, r, arr);
        merge_sort(l, mid, r, arr);
    }
}
int main()
{
    int arr[] = {0, 4, -1, -4, 5};
    merge(0, 4, arr);
    for (int i : arr)
        cout << i << ',';
}
