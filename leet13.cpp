// 13. Roman to Integer
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
pair<string, int> findRange(int number)
{

    vector<pair<string, int>> romanRanges = {
        {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}};

    for (const auto &range : romanRanges)
    {
        if (number >= range.second)
        {
            return range;
        }
    }

    return make_pair("M", 1000);
}
string numberToRoman(int number)
{
    cout << "Number to Roman called for : " << number << endl;
    if (number <= 0)
    {
        return "";
    }

    pair<string, int> rangePair = findRange(number);
    int range = rangePair.second;

    int divison = (number / range);
    number = number - (range * divison);
    string result = "";

    while (divison != 0)
    {
        result = result + rangePair.first;
        divison--;
    }

    return result + numberToRoman(number);
}
int main()
{
    string ans;
    ans = numberToRoman(49);
    cout << ans;

    return 0;
}
