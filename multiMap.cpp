#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

vector<string> hashTableFirst[50000];
vector<string> hashTableSecond[50000];
int sizeMap = 50000;

int hashFunc(string str)
{
    int sum = 0;
    int alp = 1;
    for (int i = 0; i < str.length(); i++)
    {
        sum += int(str[i]) * alp;
        alp *= 2;
    }
    return sum % sizeMap;
}

vector<string> getMap(string first)
{
    int index = hashFunc(first);
    vector<string> ans;
    for (int i = 0; i < hashTableFirst[index].size(); i++)
        if (hashTableFirst[index][i] == first)
            ans.push_back(hashTableSecond[index][i]);
    return ans;
}

void putMap(string first, string second)
{
    int index = hashFunc(first);
    for (int i = 0; i < hashTableFirst[index].size(); i++)
        if (hashTableFirst[index][i] == first && hashTableSecond[index][i] == second)
            return;
    hashTableFirst[index].push_back(first);
    hashTableSecond[index].push_back(second);
}

void deleteMap(string first, string second)
{
    int index = hashFunc(first);
    if (hashTableFirst[index].empty())
        return;
    for (int i = 0; i < hashTableFirst[index].size(); i++)
        if (hashTableFirst[index][i] == first && hashTableSecond[index][i] == second)
        {
            hashTableFirst[index].erase(hashTableFirst[index].begin() + i);
            hashTableSecond[index].erase(hashTableSecond[index].begin() + i);
            break;
        }
}

void deleteallMap(string first)
{
    int index = hashFunc(first);
    if (hashTableFirst[index].empty())
        return;
    int  i = 0;
    while (i < hashTableFirst[index].size())
        if (hashTableFirst[index][i] == first)
        {
            hashTableFirst[index].erase(hashTableFirst[index].begin() + i);
            hashTableSecond[index].erase(hashTableSecond[index].begin() + i);
        }
        else
            i++;
}

int main()
{
    fstream fin, fout;
    fin.open("multimap.in", ios::in);
    fout.open("multimap.out", ios::out);
    string com;
    string first, second;
    while (fin >> com >> first)
    {
        if (com == "put")
        {
            fin >> second;
            putMap(first, second);
        }
        if (com == "get")
        {
            vector<string> ans = getMap(first);
            fout << ans.size() << " ";
            for (int i = 0; i < ans.size(); i++)
                fout << ans[i] << " ";
            fout << "\n";
        }
        if (com == "delete")
        {
            fin >> second;
            deleteMap(first, second);
        }
        if (com == "deleteall")
            deleteallMap(first);
    }
    fin.close();
    fout.close();
    return 0;
}
