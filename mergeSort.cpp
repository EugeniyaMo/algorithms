#include <fstream>
#include <string>

using namespace std;

void Merge(pair <string, string> *a, int p, int q, int r)
{
    int i, j;
    int n1 = q - p + 1;
    int n2 = r - q;
    pair <string, string> L[n1 + 1];
    pair <string, string> R[n2 + 1];
    for (int i = 0; i < n1; i++)
        L[i] = a[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[q + j + 1];
    L[n1].first = "zzzzzzzzzz";
    R[n2].first = "zzzzzzzzzz";
    i = 0;
    j = 0;
    for (int k = p; k <= r; k++)
    {
        if (L[i].first <= R[j].first)
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
}

void MergeSort(pair <string, string> *a, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        MergeSort(a, p, q);
        MergeSort(a, q + 1, r);
        Merge(a, p, q, r);
    }
}

int main()
{
    int n, i;
    fstream fin, fout;
    fin.open("race.in", ios::in);
    fin >> n;
    pair <string, string> event[n];
    for (i = 0; i < n; i++)
    {
        string country, name;
        fin >> country >> name;
        event[i].first = country;
        event[i].second = name;
    }
    fin.close();
    MergeSort(event, 0, n - 1);
    i = 0;
    string cur_cnt = event[0].first;
    fout.open("race.out", ios::out);
    while (i < n)
    {
        fout << "=== " << cur_cnt << " ===\n";
        fout << event[i].second << "\n";
        i++;
        while (event[i].first == cur_cnt)
        {
            fout << event[i].second << "\n";
            i++;
        }
        if (i < n)
            cur_cnt = event[i].first;
    }
    fout.close();
    return 0;
}
