#include <iostream>
using namespace std;

int calculateArea (int a, int b)
{
    return a * b;
}

int main()
{
    int maxArea = 0;
    int maxA = 0;
    int maxB = 0;
    int a, b;

    do
    {
        cout << "Enter side A: ";
        cin >> a;
        cout << "Enter side B: ";
        cin >> b;

        int tempArea = calculateArea(a, b);

        if (tempArea >= maxArea)
        {
            maxArea = tempArea;
            maxA = a;
            maxB = b;
        }

    } while(a != 0 && b != 0);

    cout << "Largest sides are: " << maxA << " and " << maxB << " with area of " << maxArea << endl;

    return 0;
}