#include <iostream>

using namespace std;

int validateDaysCount(string prompt)
{
    int val;

    while (true)
    {
        cin.clear();
        cin.sync();
        cout << prompt;
        cin >> val;
        if (cin.good() && val >= 2 && val <= 31)
        {
            break;
        }
        else
            cin.clear();
        cout << "Invalid input! Value must be between 2 and 31" << endl;
    }
    return val;
}

int validateTemperature(string prompt)
{
    int val;

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

int main()
{
    int numberOfDays = validateDaysCount("Enter a number between 2 and 31: ");
    int daysArray[numberOfDays];
    int previousDayTemp = 0;
    int higherTempCounter = 0;

    for(int i = 0; i < numberOfDays; i++)
    {
        daysArray[i] = validateTemperature("Enter temperature: ");

        if (i == 0)
        {
            previousDayTemp =  daysArray[0];
        }
        else
        {
            if (daysArray[i] > previousDayTemp)
            {
                higherTempCounter++;
            }
            previousDayTemp = daysArray[i];
        }
    }

    cout << "Number of days with higher temperature is: " << higherTempCounter << endl;
    cout << endl;

    return 0;
}
