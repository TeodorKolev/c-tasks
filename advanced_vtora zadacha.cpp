#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int validateWeeksCount(string prompt)
{
    int val;

    while (true)
    {
        cin.clear();
        cin.sync();
        cout << prompt;
        cin >> val;
        if (cin.good() && val >= 1 && val <= 5)
        {
            break;
        }
        else
            cin.clear();
        cout << "Invalid input! Value must be between 2 and 31" << endl;
    }
    return val;
}

double validateTemperature(string prompt)
{
    double val;

    while (true)
    {
        cin.clear();
        cin.sync();
        cout << prompt;
        cin >> val;
        if (cin.good() && val >= -50 && val <= 50)
        {
            break;
        }
        else
            cin.clear();
        cout << "Invalid input! Temperature must be between -50 and 50 degrees" << endl;
    }
    return val;
}

bool equalTemp(double temp1, double temp2)
{
    cout << fabs(temp1 - temp2) << endl;
    return fabs(temp1 - temp2) <= 1;
}

int main()
{
    int firstMonthWeeksCount = validateWeeksCount("Enter first month weeks count: ");
    double firstMonth[firstMonthWeeksCount];
    vector<int> result;

    for(int i = 0; i < firstMonthWeeksCount; i++)
    {
        firstMonth[i] = validateTemperature("Enter temperature: ");

        if (i == firstMonthWeeksCount - 1)
        {
            int secondMonthWeeksCount = validateWeeksCount("Enter second weeks count: ");
            for(int j = 0; j < secondMonthWeeksCount; j++)
            {
                double secondMonthTemp = validateTemperature("Enter temperature: ");
                if (equalTemp(firstMonth[j], secondMonthTemp)){
                    result.push_back(j + 1);
                }
            }
        }

    }

    cout << "Weeks with nearly temperatures are: ";
    for (vector<int >::const_iterator i = result.begin(); i != result.end(); ++i)
        cout << *i << ' ';
    cout << endl;

    return 0;
}
