//Bleeps out words I do not like

#include <iostream>
using namespace std;
int main()
{
    string temp = "";
    string dislike = "Broccoli";
    while(cin >> temp){
       if (temp == dislike){
            cout << "Bleep" << endl;
       } 
       else
           cout << temp << endl;
    }
}
