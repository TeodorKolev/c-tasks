#include <iostream>
#include <algorithm>

using namespace std;

bool checkString(string result)
{
    return none_of(result.begin(), result.end(), [](const char& c)
    {
        return !(isalpha(c) || isdigit(c) || c == ' ');
    });
}

string validateInput(string prompt)
{
    string result;

    while (true)
    {
        cin.clear();
        cin.sync();
        cout << prompt;
        getline(cin, result);
        if (checkString(result))
        {
            break;
        }
        else
            cin.clear();
        cout << "Invalid input! Input must contain only small or capital letters and numbers." << endl;

    }
    return result;
}

int main()
{
    int counter = 0;
    string::size_type start = 0;
    string firstRow = validateInput("Enter first string: ");
    string secondRow = validateInput("Enter second string: ");
    transform(firstRow.begin(), firstRow.end(), firstRow.begin(), ::tolower);
    transform(secondRow.begin(), secondRow.end(), secondRow.begin(), ::tolower);

    while ((start = firstRow.find(secondRow, start)) != string::npos)
    {
        ++counter;
        start += secondRow.length();
    }

    cout << counter << endl;

    return 0;
}
