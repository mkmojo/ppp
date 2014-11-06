#include<iostream>
using namespace std;
int main()
{
    double tmp = -1;
    double smallest=0;
    double largest=0;
    string unit="";
    const double cm_per_m=100.0;
    const double cm_per_in=2.54;
    const double in_per_ft=12.0;
    while(cin >> tmp >> unit){
        cout << "unit is : " << unit << endl;
    }
    cout << "error " << tmp << " "<< unit << endl;
}


/* 
 * Using if ( smallest == 0 && largest == 0 ) to identify the initial stage
 */
