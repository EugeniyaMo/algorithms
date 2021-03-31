#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

vector<string> hashTableKey[50000];
vector<string> hashTableValue[50000];
vector<string> keys;
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
        keys.push_back(key);
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
    for (int i = 0; i < keys.size(); i++)
        if (keys[i] == key)
        {
            keys.erase(keys.begin() + i);
            break;
        }
}

string prevMap(string key)
{
    if (getMap(key) == "none")
        return "none";
    for (int i = 0; i < keys.size(); i++)
        if (keys[i] == key && i > 0)
            return getMap(keys[i - 1]);
    return "none";
}

string nextMap(string key)
{
    if (getMap(key) == "none")
        return "none";
    for (int i = 0; i < keys.size(); i++)
        if (keys[i] == key && i < keys.size() - 1)
            return getMap(keys[i + 1]);
    return "none";
}

int main()
{
    fstream fin, fout;
    fin.open("linkedmap.in", ios::in);
    fout.open("linkedmap.out", ios::out);
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
        if (com == "prev")
            fout << prevMap(key) << "\n";
        if (com == "next")
            fout << nextMap(key) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
