#include <iostream>

using namespace std;

void QuickSort(int a[], int left, int right, int k)
{
    int i = left, j = right;
    int middle = (i + j) / 2;
    int key = a[middle];
    if (left == right) {
        return;
    }
    while (i <= j)
    {
        while (a[i] < key)
            i++;
        while (a[j] > key)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (k >= left && k < j + 1)
        QuickSort(a, left, j, k);
    else
        if (k <= right && k > i - 1)
            QuickSort(a, i, right, k);
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n], A, B, C;
    cin >> A >> B >> C >> a[0] >> a[1];
    for (int i = 2; i < n; i++)
        a[i] = A * a[i - 2] + B * a[i - 1] + C;
    QuickSort(a, 0, n - 1, k - 1);
    cout << a[k - 1];
    return 0;
}
