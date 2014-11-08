#include "../std_lib_facilities.h"
int main()
try{
    int res = 7;
    vector<int> v(10);
    v[5] = res;
    cout << "Success!\n";
    return 0;
}
catch (exception& e){
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Oops: unkonwn exception!\n";
    keep_window_open();
    return 2;
}
