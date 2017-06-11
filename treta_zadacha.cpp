#include <iostream>
#include <stack>
#include <vector>
#include <iterator>

using namespace std;

int getInput(string prompt)
{
    int val;

    while (true)
    {
        cin.clear();
        cin.sync();
        cout << prompt;
        cin >> val;
        if (cin.good() && val >= 1 && val <= 27)
        {
            cout << "You have entered: " << val << endl;
            break;
        }
        else
            cin.clear();
        cout << "Invalid input! Value must be between 1 and 27" << endl;
    }
    return val;
}

int main()
{
    int input = getInput("Enter a number between 1 and 27: ");
    int resultCounter = 0;
    vector<int> resultArray;

    for(int a = 100; a < 1000; a++)
    {
        stack<int> digits;
        int sum = 0;
        int number = a;

        while(number > 0)
        {
            digits.push(number % 10);
            sum += digits.top();
            number = number / 10;
        }
        if (sum == input) {
            resultCounter++;
            resultArray.push_back(a);
        }

    }

    cout << "Numbers count is: " << resultCounter << endl;
    cout << "Numbers are: " << endl;
    copy(begin(resultArray), end(resultArray), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}