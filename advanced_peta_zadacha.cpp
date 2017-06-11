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

int validateInput(string prompt)
{
    int val;

    while (true)
    {
        cin.clear();
        cin.sync();
        cout << prompt;
        cin >> val;
        if (cin.good() && val >= 0)
        {
            break;
        }
        else
            cin.clear();
        cout << "Invalid input! Value must be bigger than zero" << endl;
    }
    return val;
}

int validatePivot(string prompt, int firstArrLength)
{
    int val;

    while (true)
    {
        cin.clear();
        cin.sync();
        cout << prompt;
        cin >> val;
        if (cin.good() && val >= 0 && val <= firstArrLength)
        {
            break;
        }
        else
            cin.clear();
        cout << "Invalid input! Value must in range of first array" << endl;
    }
    return val;
}

int main()
{
    vector<int> firstArr;
    vector<int> secondArr;
    int input;
    int pivot;

    int firstArrLength = validateArrLength("Enter first array length: ");

    for (int i = 0; i < firstArrLength; ++i) {
        input = validateInput("Enter Number: ");
        firstArr.push_back(input);
    }

    int secondArrLength = validateArrLength("Enter second array length: ");

    for (int i = 0; i < secondArrLength; ++i) {
        input = validateInput("Enter Number: ");
        secondArr.push_back(input);
    }

    pivot = validatePivot("Enter pivot point: ", firstArrLength);

    firstArr.insert(firstArr.begin() + pivot, secondArr.begin(), secondArr.end());

    for (std::vector<int>::const_iterator i = firstArr.begin(); i != firstArr.end(); ++i)
        std::cout << *i << ' ';

    return 0;
}