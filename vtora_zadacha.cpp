#include <iostream>
using namespace std;

int main()
{
    int result = 0;

    for (int a = 1; a < 10000; a = a + 1)
    {
        result = ( ( (a * a) + (a * 6) + 17) / 111);
        if (result > 200)
        {
            cout << "First number is: " << a << endl;
            cout << "Result of calculation is: " << result << endl;
            break;
        }
    }

    return 0;
}

