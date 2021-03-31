#include <fstream>
 
using namespace std;
 
int len = 0;
int q_tail = -1, q_head = -1;
 
void EnQueue(int *q, int x)
{
    q[q_tail] = x;
    q_tail++;
}
 
int DeQueue(int *q)
{
    int x = q[q_head];
    q_head++;
    return x;
}
 
int main()
{
    fstream fin, fout;
    int n;
    int q[1000001];
    fin.open("queue.in", ios::in);
    fout.open("queue.out", ios::out);
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        string com;
        fin >> com;
        if (com == "+")
        {
            int x;
            fin >> x;
            EnQueue(q, x);
        }
        else
            fout << DeQueue(q) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
