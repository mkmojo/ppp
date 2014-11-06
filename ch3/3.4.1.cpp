#include <iostream>
using namespace std;
int main()
{
    cout << "Please enter you two names\n";
    string first;
    string second;
    cin >>first >> second;
    if (first  == second)
        cout << "same string twice" << endl;
    if (first < second)
        cout << first << " is alphabetically before " << second << endl;
    if (first > second)
        cout << first << " is alphabetically after " << second << endl;
}
