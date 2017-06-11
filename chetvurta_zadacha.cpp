#include <iostream>
#include <math.h>
using namespace std;


double greaterThanZero(int point, int pointMinusOne, int pointPlusOne) {
    return (((pow(pointMinusOne, 2) ) - (point * 2) + (pow(pointPlusOne, 2))) / (pointMinusOne - pointPlusOne));
}
double lessThanZero(int point, int pointMinusOne, int pointPlusOne) {
    return (((pow(pointMinusOne, 2) ) - (point * 2) + (pow(pointPlusOne, 2))) / (pointPlusOne - pointMinusOne));
}

int main()
{
    int size, point;

    while (true)
    {
        cout << "Enter number of points in vector A: ";
        cin >> size;
        if (size <= 50)
            break;
        else
        {
            cin.clear();
            cout << "Invalid input! Number must be equal or less than 50 " << endl;
        }
    }

    double vectorB[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter point: ";
        cin >> point;

        int pointMinusOne = (point - 1);
        int pointPlusOne = (point + 1);

        if (point > 0)
            vectorB[i] = greaterThanZero(point, pointMinusOne, pointPlusOne);
        else if (point == 0)
            vectorB[i] = 0;
        else if (point < 0)
            vectorB[i] = lessThanZero(point, pointMinusOne, pointPlusOne);
    }

    cout << "Vector B points are: " << endl;

    for (int j = 0; j < size; j++)
    {
        cout << vectorB[j] << " ";
    }

    return 0;
}