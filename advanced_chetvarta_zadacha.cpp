#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int validateStringsCount(string prompt)
{
    int val;

    while (true)
    {
        cin.clear();
        cin.sync();
        cout << prompt;
        cin >> val;
        if (cin.good() && val >= 1 && val < 100)
        {
            break;
        }
        else
            cin.clear();
        cout << "Invalid input! Value must be between 1 and 99" << endl;
    }
    return val;
}

int validateLastCharsCount(string prompt)
{
    int val;

    while (true)
    {
        cin.clear();
        cin.sync();
        cout << prompt;
        cin >> val;
        if (cin.good() && val >= 1 && val < 200)
        {
            break;
        }
        else
            cin.clear();
        cout << "Invalid input! Value must be between 1 and 199" << endl;
    }
    return val;
}

int main()
{
    int stringsCount = validateStringsCount("Enter number of strings: ");

    vector<string> arr;
    string input;
    int counter = 0;

    for (int i = 0; i < stringsCount; ++i) {
        cout << "Enter String: ";
        cin >> input;
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        arr.push_back(input);
    }

    int lastCharsCount = validateLastCharsCount("Enter number of last characters: ");

    map<string, int> words;
    for(string x : arr) ++(words[x.erase(0, x.length() - lastCharsCount)]);

    cout << "========================== " << endl;
    for(const auto& p : words)
    {
        if(p.second > 1)
        {
            cout << p.first << " - " << p.second << " times " << endl;
            ++counter;
        }
    }

    cout << "Repeating words count is: " << counter << endl;
    cout << "========================== " << endl;

    return 0;
}