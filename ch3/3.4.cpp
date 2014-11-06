#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    cout << "please enter a floating point number:";
    int n;
    double m;
    cin >> n;
    m = n;
    cout << "n == " << n
    << "\nn+1 == "<< n + 1
    << "\nthree times n "<< n * 3
    << "\ntwicetimes n "<< n + n
    << "\nn squared "<< n * 2
    << "\nsquare root n "<< sqrt(m)
    << endl;
}
