#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    double tmp = -1;
    double smallest=0;
    double largest=0;
    string unit="";
    double sum = 0;
    vector<double> v;
    const double cm_per_m=100.0;
    const double cm_per_in=2.54;
    const double in_per_ft=12.0;
    //the behavior on Mac is different
    //for instance 12ft will break the cin and raise error
    while(cin >> tmp >> unit){
        if(unit!="cm" && unit!="m" && unit!="in" && unit!="ft")
        {
            cout << "unit wrong " << endl;
            continue;
        }


        //conver length to meter
        if ( unit == "m" ){}
        else if(unit == "cm")
            tmp /= cm_per_m;
        else if(unit == "in") {
            tmp *= cm_per_in;
            tmp /= cm_per_m;
        }
        else if(unit == "ft"){
            tmp *= in_per_ft;
            tmp *= cm_per_in;
            tmp /= cm_per_m;
        }
        else { // error
        }

        if(smallest == 0 && largest == 0){
            smallest = tmp;
            largest = tmp;
        }
        if(tmp < smallest)
            smallest = tmp;
        if(tmp > largest)
            largest = tmp;

        v.push_back(tmp);
        sum += tmp;
    }
    cout << "largest " << largest <<endl;
    cout << "smallest " << smallest << endl;
    cout << "sum " << sum << endl;

    sort(v.begin(),v.end());
    for(int i=0 ;i<v.size();++i)
        cout << v[i] << endl;

}


/* 
 * Using if ( smallest == 0 && largest == 0 ) to identify the initial stage
 */
