#include "../std_lib_facilities.h"
class Token{
    public:
        string value; 
        Token(string s)
            :value(s){}
};

class Token_stream {
    public:
        Token_stream();
        Token get();
        void put_back(Token t);
    private:
        bool full{false};
        Token buffer;
};

Token_stream::Token_stream()
    :full(false), buffer("")
{}

void Token_stream::put_back(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;
    full = true;
}

Token Token_stream::get()
{
    if (full){
        full = false;
        return buffer;
    }
    string s = "";
    cin >> s;
    return Token(s); 
}

Token_stream ts = Token_stream();


bool conj()
{
    Token t = ts.get();
    if( t.value == "and" || t.value == "or" || t.value == "but")
        return true;
    else{
        //        error("conj error: '" + t.value +"' is not a conj");
        return false;
    }
}

bool verb()
{
    Token t = ts.get();
    if(t.value == "rules" || t.value =="fly" || t.value == "swim")
        return true;
    else{
        //error("verb error: '" + t.value + "' is not a verb");
        return false;
    }
}

bool noun()
{
    Token t = ts.get();
    if( t.value =="the")
        return noun();
    else if( t.value == "birds" || t.value =="fish" || t.value =="C++")
        return true;
    else{
        //error("noun error: '" + t.value + "' is not a noun");
        return false;
    }
}


bool sentence()
{
    bool s = noun() && verb();
    if(s == false){
        return false;
    }
    else{
        Token t = ts.get();
        ts.put_back(t);
        if(t.value == "."){
            return true;
        }
        else{
            return conj() && sentence();
        }
    }
}


int main()
    try{
        bool val = false;
        while(cin){
            Token t = ts.get();
            if(t.value == ".") {
                cout << "= " << (val==true ? "OK.": "Not OK.") << endl;
                continue;
            }
            if(t.value == "q"){
                break;
            }
            ts.put_back(t);
            val = sentence();
        }
        return 0;
    }
catch(exception &e){
    cerr << "error: " << e.what() <<endl;
    return 1;
}
catch(...){
    cerr << "Unknown exception" << endl;
    return 2;
}

