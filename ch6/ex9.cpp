#include "../std_lib_facilities.h"

vector<string> units = {"ones","tens","hundred","thousand"};

int main()
try { 
	string input = "";
	while(cin >> input){
		if(input.size() > 4)
			error("please enter number less or equal to four digits");
		int res = 0;
		for(int i = 0;i<input.size();i++){
			if(!(input[i] <= '9' && input[i] >= '0'))
				error("not a number");
			int cnt_dit = char(input[i]) - '0';
			res = res*10 + cnt_dit;
		}
		cout << res << " is ";
		for ( int i = 0; i < input.size(); ++i){
			cout << input[i] << " " << units[input.size() - 1 - i];
			if( i != input.size() - 1)
				cout << " and ";
		}
		cout << endl;
	}
}
catch(exception& e){
	cerr << "error:" << e.what() << '\n';
}
