#include <fstream>
 
using namespace std;
 
int Binary_Search_l(int *a, int n, int x)
{
    int l = -1, r = n;
    while (r > l + 1)
    {
        int m = (l + r ) / 2;
        if (a[m] < x)
            l = m;
        else
            r = m;
    }
    if (r < n && a[r] == x)
        return r + 1;
    return -1;
}
 
int Binary_Search_r(int *a, int n, int x)
{
    int l = -1, r = n;
    while (r > l + 1)
    {
        int m = (l + r ) / 2;
        if (a[m] <= x)
            l = m;
        else
            r = m;
    }
    if (l < n && a[l] == x)
        return l + 1;
    return -1;
}
 
int main()
{
    int a[100001], n, m;
    fstream fin, fout;
    fin.open("binsearch.in", ios::in);
    fout.open("binsearch.out", ios::out);
    fin >> n;
    for (int i = 0; i < n; i++)
        fin >> a[i];
    fin >> m;
    for (int i = 0; i < m; i++)
    {
        int com;
        fin >> com;
        fout << Binary_Search_l(a, n, com) << " " << Binary_Search_r(a, n, com) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
