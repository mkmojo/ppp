#include <iostream>
using namespace std;

int main()
{
    cout << "Please enter the name of the porson you want to write to  (followed by enter):\n";
    string first_name;
    cin >> first_name;
    cout << "Dear " << first_name << ",\n";
    cout << "How are you?"<< " I am fine" <<" I miss you a lot "<<endl;

    cout << "Please enter the name of the another friend you want to write to  (followed by enter):\n";
    string friend_name;
    cin >> friend_name;
    cout<< "Have you seen " << friend_name << " lately?"<<endl;

    cout << "Please enter m if "<<friend_name << " is male otherwise f" << endl;
    char friend_sex  = 0;
    cin >> friend_sex;
    if (friend_sex == 'm')
        cout << "If you see " << friend_name << "please ask him to call me" <<endl;
    if (friend_sex == 'f')
        cout << "If you see " << friend_name << "please ask her to call me" <<endl;

    cout << "Please enter your age " <<endl;
    int age = 0;
    cin >> age;
    cout << " I heard that you had a birthday and you are " << age << " years old." << endl;
}
