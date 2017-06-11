#include <iostream>
using namespace std;

void printValue (int val)
{
    if (val <= 9)
    {
        cout << val << "  |";
    }
    if (val > 9 && val <= 99)
    {
        cout << val << " |";
    }
    if (val > 99)
    {
        cout << val << "|";
    }
}

int read_input(int min, int max, string message)
{
    int input = -1;
    bool valid= false;
    do
    {
        cout << message << flush;
        cin >> input;
        if (cin.good() && input >= min && input <= max)
        {
            valid = true;
        }
        else
        {
            cin.clear();
            cout << "Invalid input; please re-enter." << endl;
        }
    } while (!valid);
    return (input);
}

int main()
{
    int cols, rows, matrix[10][10];
    cols = read_input(1, 50, "Enter cols (range 1-50): ");
    rows = read_input(1, 50, "Enter rows (range 1-50): ");
    cout << "Enter the elements matrix (range 1-999): " << endl;

    int min = 100000;
    int max = 0;
    int minRow = 0;
    int maxCol = 0;

    for(int x = 0; x < rows; x++)
    {
        for(int y = 0; y < cols; y++)
        {
            cin >> matrix[x][y];

            if(matrix[x][y] > max)
            {
                max = matrix[x][y];
                maxCol = y;
            }

            if(matrix[x][y] < min)
            {
                min = matrix[x][y];
                minRow = x;
            }
        }
    }

    for(int x = 0; x < rows; x++)
    {
        cout << "|";

        for(int y = 0; y < cols; y++)
        {
            if (x == minRow)
            {
                matrix[x][y] = 100;
            }
            if (y == maxCol)
            {
                matrix[x][y] = 10;
            }
            printValue (matrix[x][y]);
        }

        cout << endl;
    }

    return 0;
}