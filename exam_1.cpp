#include <iostream>
#include <algorithm>

using namespace std;

int validateArrLength(string prompt)
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

int validateValue(string prompt, vector<int> arr)
{
    int val;

    while (true)
    {
        cin.clear();
        cin.sync();
        cout << prompt;
        cin >> val;
        bool cinGood = true;

        for (int j = 0; j < arr.size(); j++)
        {
            if (val == arr[j] || val < 1 || val >= 100)
            {
                cinGood = false;
                break;
            }
        }
        if (cinGood)
        {
            break;
        }
        else
            cin.clear();
        cout << "Invalid input! Value must not duplicate and in range of 1 - 99" << endl;

    }
    return val;
}
int getTensDigit(int val)
{
    return (val / 10) % 10;
}

int main()
{
    int arrLength = validateArrLength("Enter array length: ");
    vector<int> arr;

    for (int i = 0; i < arrLength; i++)
    {
        arr.push_back(validateValue("Enter value: ", arr));
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++){
        cout << getTensDigit(arr[i]) << ' ';
    }

    return 0;
}