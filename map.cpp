#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

vector<string> hashTableKey[50000];
vector<string> hashTableValue[50000];
int sizeSet = 50000;

int hashFunc(string str)
{
    int sum = 0;
    int alp = 1;
    for (int i = 0; i < str.length(); i++)
    {
        sum += int(str[i]) * alp;
        alp *= 2;
    }
    return sum % sizeSet;
}

string getMap(string key)
{
    int index = hashFunc(key);
    for (int i = 0; i < hashTableKey[index].size(); i++)
        if (hashTableKey[index][i] == key)
            return hashTableValue[index][i];
    return "none";
}

void putMap(string key, string value)
{
    int index = hashFunc(key);
    if (getMap(key) == "none")
    {
        hashTableKey[index].push_back(key);
        hashTableValue[index].push_back(value);
    }
    else
        for (int i = 0; i < hashTableKey[index].size(); i++)
            if (hashTableKey[index][i] == key)
            {
                hashTableValue[index][i] = value;
                break;
            }
}

void deleteMap(string key)
{
    if (getMap(key) == "none")
        return;
    int index = hashFunc(key);
    for (int i = 0; i < hashTableKey[index].size(); i++)
        if (hashTableKey[index][i] == key)
        {
            hashTableKey[index].erase(hashTableKey[index].begin() + i);
            hashTableValue[index].erase(hashTableValue[index].begin() + i);
            break;
        }
}

int main()
{
    fstream fin, fout;
    fin.open("map.in", ios::in);
    fout.open("map.out", ios::out);
    string com;
    string key, value;
    while (fin >> com >> key)
    {
        if (com == "put")
        {
            fin >> value;
            putMap(key, value);
        }
        if (com == "get")
            fout << getMap(key) << "\n";
        if (com == "delete")
            deleteMap(key);
    }
    fin.close();
    fout.close();
    return 0;
}

