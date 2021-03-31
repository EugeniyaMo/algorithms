#include <fstream>
#include <string>

using namespace std;

int s_top = 0;

void Push(int *s, int x)
{
    s_top++;
    s[s_top - 1] = x;
}

int Pop(int *s)
{
    s_top--;
    return s[s_top];
}

int main()
{
    int s[1000001] = {0};
    int n;
    fstream fin, fout;
    fin.open("stack.in", ios::in);
    fout.open("stack.out", ios::out);
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        string com;
        fin >> com;
        if (com == "+")
        {
            int x;
            fin >> x;
            Push(s, x);
        }
        else
            fout << Pop(s) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
