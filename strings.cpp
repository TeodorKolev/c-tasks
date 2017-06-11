#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

/*
 * Напишете метод, който приема за вход два низа и извежда колко
пъти вторият се среща в първия.
Напр: wordCount(“I live in Bulgaria. I am now in Varna”, “in”) -> 2
 */

size_t count ( const string& text, const string& word )
{
    istringstream input(text);
    return (size_t) (count(istream_iterator<string>(input),
                           istream_iterator<string>(), word));
}

int main()
{
    string sentence;
    string word;
    cout << "Enter first string " << endl;
    getline (cin, sentence);
    cout << "Enter second string " << endl;
    getline (cin, word);

    std::cout << count(sentence, word) << std::endl;

    return 0;
}