#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
//#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long int;

void next_higher(ll &num, int digits, vector<int> const &map)
{
    auto num1 = num;
    bool start = false;
    while (num > 0)
    {
        ll pow = std::pow(10, --digits);
        cout << "Power" << endl;
        cout << pow << endl;
        auto dig = num / pow;
        cout << "extracted digit" << endl;
        cout << dig << endl;
        cout << map[dig] << endl;
        if (map[dig] >= dig)
        {
            start = true;
            num1 += (map[dig] - dig) * pow;
            num %= pow;
            cout << "new number" << endl;
            cout << (map[dig] - dig) * pow << endl;
        }
        else if (start && map[dig] < dig)
        {
            break;
        }

        else
        {
            continue;
        }
    }
    cout << "New reduced number" << endl;
    cout << num1 << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int digits, input;
    ll num;
    vector<int> map;
    cin >> digits;
    cin >> num;
    for (int i = 0; i < 10; i++)
    {
        cin >> input;
        map.push_back(input);
    }
    cout << digits << endl;
    cout << "Printing the number" << endl;
    cout << num << endl;
    cout << "Printing the map" << endl;
    for (auto it = map.begin(); it <= map.end(); ++it)
    {
        cout << *it << endl;
    }
    next_higher(num, digits, map);
    cout << num << endl;
}
