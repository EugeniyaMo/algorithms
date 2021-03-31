#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> hashTable[50000];
int sizeSet = 50000;

int hashFunc(int num)
{
    return abs(num % sizeSet);
}

bool existSet(int num)
{
    int index = hashFunc(num);
    for (int i = 0; i < hashTable[index].size(); i++)
        if (hashTable[index][i] == num)
            return 1;
    return 0;
}

void insertSet(int num)
{
    if (!existSet(num))
    {
        int index = hashFunc(num);
        hashTable[index].push_back(num);
    }
}

void deleteSet(int num)
{
    if (!existSet(num))
        return;
    int index = hashFunc(num);
    for (int i = 0; i < hashTable[index].size(); i++)
        if (hashTable[index][i] == num)
        {
            hashTable[index].erase(hashTable[index].begin() + i);
            break;
        }
}

int main()
{
    fstream fin, fout;
    fin.open("set.in", ios::in);
    fout.open("set.out", ios::out);
    string com;
    int num;
    while (fin >> com >> num)
    {
        if (com == "insert")
            insertSet(num);
        if (com == "exists")
            if (existSet(num))
                fout << "true\n";
            else
                fout << "false\n";
        if (com == "delete")
            deleteSet(num);
    }
    fin.close();
    fout.close();
    return 0;
}
