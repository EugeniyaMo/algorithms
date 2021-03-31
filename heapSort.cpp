#include <iostream>

using namespace std;

void Max_Heapify(int *a, int heap_size, int i)
{
    int l, r, largest;
    l = 2 * i;
    r = 2 * i + 1;
    if (l <= heap_size && a[l] > a[i])
        largest = l;
    else
        largest = i;
    if (r <= heap_size && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        Max_Heapify(a, heap_size, largest);
    }
}

void Build_Max_Heap(int *a, int heap_size)
{
    for (int i = heap_size / 2; i >= 1; i--)
        Max_Heapify(a, heap_size, i);
}

void Heapsort(int *a, int heap_size)
{
    Build_Max_Heap(a, heap_size);
    for (int i = heap_size; i >= 2; i--)
    {
        swap(a[1], a[i]);
        heap_size --;
        Max_Heapify(a, heap_size, 1);
    }
}

int main()
{
    int n, a[100001];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Heapsort(a, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}
