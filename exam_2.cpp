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

int validateRequestsCount(string prompt)
{
    int val;

    while (true)
    {
        cin.clear();
        cin.sync();
        cout << prompt;
        cin >> val;
        if (cin.good() && val >= 1 && val < 50)
        {
            break;
        }
        else
            cin.clear();
        cout << "Invalid input! Value must be between 1 and 49" << endl;
    }
    return val;
}

istream &operator>>(istream &in, pair<int, int> &p) {
    in>>p.first>>p.second;
    return in;
}

int main()
{
    int arrLength = validateArrLength("Enter array length: ");
    int percentage;
    vector<int> arr;
    pair<int, int> temp;

    cout << "Enter values:" << endl;
    for(int val, i = 1; (cin >> val) && i < arrLength + 1; ++i){
        arr.push_back(val);
        if (i == arrLength)
            break;
    }

    int requestsCount = validateRequestsCount("Enter requests count: ");

    for (int i = 0; i < requestsCount; i++)
    {
        cin >> temp;
        arr.insert(arr.begin() + temp.first - 1, temp.second);
    }

    cout << endl;
    sort(arr.begin(), arr.end());
    arrLength = arr.size();
    percentage = arrLength / 4;

    cout << "First 25% are: " << endl;
    for (int i = 0; i < percentage; i++){
        cout << arr[i] << ' ';
    }


    return 0;
}