#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/*
 * Напишете програма, която намира максимална редица от последователни еднакви елементи в вектор.
 Пример: {6, 5, 5, 6, 7, 7, 6, 6, 6, 5} = {6, 6, 6}.
 */



int main()
{
    string length;
    cout << "Enter vector length: " << endl;
    cin >> length;
    int arrLength = atoi( length.c_str() );
    vector<int> arr;
    string enterString;
    for (int count = 0; count < arrLength; count++)
    {
        cout << "Enter value " << endl;
        cin >> enterString;
        arr.push_back(atoi( enterString.c_str() ));
    }
    int maxCount = 0;
    int value = 0;
    for (int count = 0; count < arrLength; count++)
    {
        int currentCount = 0;
        for (int minCount = count; minCount < arrLength; minCount++)
        {
            if (arr[count] == arr[minCount])
            {
                currentCount++;
                if (maxCount < currentCount)
                {
                    maxCount = currentCount;
                    value = arr[count];
                }
            }
            else
            {
                break;
            }
        }
    }

    cout << "Max length: " << maxCount << " value: " << value << endl;

    return 0;
}
