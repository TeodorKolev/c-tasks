#include <iostream>
#include <cstdio>

using namespace std;

/*
 Да се разделят индивидуалните битове на число, и да се отпечатат последователно.
 Пример:
вход: 678976;
изход:
Byte 0 = 64
Byte 1 = 92
Byte 2 = 10
Byte 3 = 0
 */

int main()
{
    int x = 674856;
    for (size_t i = 0; i < sizeof(x); ++i) {
        unsigned char byte = *((unsigned char *)&x + i);
        printf("Byte %d = %u\n", i, (unsigned)byte);
    }
    return 0;
}