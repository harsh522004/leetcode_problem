// 451. Sort Characters By Frequency
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

void frequencySort(string s)
{
    string ans;

    map<char, int> hash;
    for (auto &x : s)
    {
        hash[x] = hash[x] + 1;
    }

    vector<pair<int, char>> freq_vec;

    for (auto &row : hash)
    {
        freq_vec.push_back(make_pair(row.second, row.first));
    }

    auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first > b.first;
    };

    sort(freq_vec.begin(), freq_vec.end(), cmp);

    for (auto &x : freq_vec)
    {
        int fre = x.first; // Example ASCII value
        char character(x.second);
        while (fre != 0)
        {
            ans.push_back(character);
            fre--;
        }
    }

    cout << ans << endl;
}
int main()
{

    // frequencySort("Tree");
    vector<int> tamp = {2, 34, 45, 3};
    frequencySort("TreeTere");

    return 0;
}