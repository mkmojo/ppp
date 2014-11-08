#include "../std_lib_facilities.h"
int area(int length, int width)
{
    if(length <=0 || width <=0 ) error ("area() precondition");
    int a = length * width;
    if(a<=0) error("area() post-condition");
    return a;
}

int framed_area(int x, int y)
{
    return area(x-2, y-2);
}

int main()
{
    int x = -1;
    int y = 2;
    cin >> x >> y;

    int area1=area(x,y);
    cout << area1 << endl;

    return 0;
}
