#include "../std_lib_facilities.h"
class Name_value
{
    public:
        string name;
        int value;
        Name_value()
            :name(""), value(0){}
};

vector<Name_value> v;

bool check(string name)
{
    for ( int i=0;i<v.size();++i)
    {
        Name_value cnt = v[i];
        if (cnt.name == name)
            return false;
    }
    return true;
}

int main()
{
    string name;
    int val;
    while(cin >> name >> val){
        Name_value t = Name_value();
        if ( name == "NoName" && val == 0)
            break;
        t.name = name;
        t.value = val;
        if(check(name))
            v.push_back(t);
        else 
        {
            cout << name + " already exists" <<endl;
            continue;
        }
    }
    for ( int i = 0 ; i < v.size() ; ++i)
        cout<< v[i].name << " " << v[i].value << endl;
    
    return 0;
}
