/*
   calculator08buggy.cpp

   Helpful comments removed.

   We have inserted 3 bugs that the compiler will catch and 3 that it won't.
   */

#include "../std_lib_facilities.h"

struct Token {
    char kind;
    double value;
    string name;
    Token(char ch) :kind(ch), value(0) { }
    Token(char ch, double val) :kind(ch), value(val) { }
    Token(char ch, string s) : kind(ch), name(s) { }
};

class Token_stream {
    bool full;
    Token buffer;
    public:
    Token_stream() :full(0), buffer(0) { }

    Token get();
    void unget(Token t) { buffer=t; full=true; }

    void ignore(char);
};

const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char thousand = 'k';
const char f_sqrt = 's';
const char f_pow = 'p';
const char cst = 'C';

Token Token_stream::get()
{
    if (full) { full=false; return buffer; }
    char ch;
    cin >> ch;
    switch (ch) {
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case ';':
        case '=':
        case ',':
            return Token(ch);
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            {	cin.unget();
                double val;
                cin >> val; //read in float number

                char c;
                cin.get(c); // try to see if we have k at the end of a number
                if ( c != thousand ){
                    cin.unget();
                    return Token(number,val);
                }
                else{
                    //has k trailing number
                    return Token(number, val * 1000);
                }
                
            }
        default:
            if (isalpha(ch)) {
                string s;
                s += ch;
                while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch; // allowing under_score
                cin.unget();

                if (s == "let") return Token(let);	
                if (s == "quit") return Token(quit);
                if (s == "const") return Token(cst);
                if (s == "sqrt") return Token(f_sqrt);
                if (s == "pow") return Token(f_pow);

                return Token(name,s);
            }
            error("Bad token");
    }
}

void Token_stream::ignore(char c)
{
    if (full && c==buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch;
    while (cin>>ch)
        if (ch==c) return;
}

struct Variable {
    string name;
    double value;
    bool isconst;
    Variable(string n, double v) :name(n), value(v), isconst(false) { }
    Variable(string n, double v, bool b) :name(n), value(v), isconst(b) { }
};

vector<Variable> names;	

double get_value(string s)
{
    for (int i = 0; i<names.size(); ++i)
        if (names[i].name == s) return names[i].value;
    error("get: undefined name ",s);
}

void set_value(string s, double d)
{
    for (int i = 0; i<names.size(); ++i)
        if (names[i].name == s) {
            names[i].value = d;
            return;
        }
    error("set: undefined name ",s);
}

bool is_declared(string s)
{
    for (int i = 0; i<names.size(); ++i)
        if (names[i].name == s) return true;
    return false;
}

bool isconst(string s)
{
    for (int i = 0; i<names.size(); ++i)
        if (names[i].name == s && names[i].isconst) return true;
    return false;
}

Token_stream ts;

double expression();

double do_pow(double x, int i)
{
    double p = 1;
    for (int t = 0; t < i; t++) {
        p *= x;
    }
    return p;
}


//deal with number and varialbe 
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
        case f_sqrt:
            {
                double d = primary();
                if(d >= 0 ) 
                    return sqrt(d);
                else
                    error("sqrt: cannot have negative number as input");
            }
        case f_pow:
            {
                Token left_brace = ts.get();            //get left brace
                if (left_brace.kind != '(')
                    error("pow: expecting '('");

                Token x = ts.get();

                Token comma = ts.get();                 //get comma
                if (comma.kind != ',')
                    error(", expected");

                Token i = ts.get();
                if ( int(i.value)/1.0 != i.value)       //get i
                    error("pow: i should be integer");

                Token right_brace = ts.get();           //get right brace
                if (right_brace.kind != ')')
                    error("pow: expectin ')'");

                double d = do_pow(x.value, i.value);    //calculate pow(x, i)
                return d;
            }
        case '(':
            {	
                double d = expression();
                t = ts.get();
                if (t.kind != ')') error("')' expected");
                return d;
            }
        case '-':
            return - primary();
        case number:
            return t.value;
        case name:
            {
                string name = t.name;
                Token t2 = ts.get();
                if( t2.kind != '='){
                    ts.unget(t2);
                    return get_value(name);
                }
                double d = expression();
                if ( isconst(name) ) error(name + " is const var");
                set_value(name, d);
                if(d != get_value(name)) error("fail to set value for ", name);
                return d;
            }
        default:
            error("primary expect");
    }
}

//deal with * and /
double term()
{
    double left = primary();
    while(true) {
        Token t = ts.get();
        switch(t.kind) {
            case '*':
                left *= primary();
                break;
            case '/':
                {	double d = primary();
                    if (d == 0) error("divide by zero");
                    left /= d;
                    break;
                }
            default:
                ts.unget(t);
                return left;
        }
    }
}

//deal with + and -
double expression()
{
    double left = term();
    while(true) {
        Token t = ts.get();
        switch(t.kind) {
            case '+':
                left += term();
                break;
            case '-':
                left -= term();
                break;
            default:
                ts.unget(t);
                return left;
        }
    }
}


//deal with variable declaration
double declaration()
{
    Token t = ts.get();
    if (t.kind == cst){
        Token var = ts.get();
        if (var.kind != name) error ("name expected in declaration");
        if (!is_declared(var.name)) error(t.name, " not declared , cannot reset value");
        Token t2 = ts.get();
        if (t2.kind != '=') error("= missing in declaration of ", t.name);
        double d = expression();
        names.push_back(Variable(t.name,d, true)); //store new Variable in the global table
        return d;
    }else{
        Token t = ts.get();
        if (t.kind != name) error ("name expected in declaration");
        if (is_declared(t.name)) error(t.name, " declared twice");
        Token t2 = ts.get();
        if (t2.kind != '=') error("= missing in declaration of ", t.name);
        double d = expression();
        names.push_back(Variable(t.name,d)); //store new Variable in the global table
        return d;
    }
}

double assignment()
{
    Token t = ts.get();
    if (t.kind != name) error("name expected in assignment");
    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", name);
    double d = expression();
    if( !is_declared(t.name) ) // if does not declared, create one with init value 0
       names.push_back(Variable(t.name, 0, true)); 
    set_value(t.name, d);
    return d;
}

double statement()
{
    Token t = ts.get();
    switch(t.kind) {
        case let:
            ts.unget(t);
            return declaration();
        case cst:
            return assignment();
        default:
            ts.unget(t);
            return expression();
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";
const string INSTRUCTON = "Support +, -, *, / and variables. Use 'let' to define varialbe"; 

void calculate()
{
    while(true) try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t=ts.get(); // handle leading ';'
        if (t.kind == quit) return;
        ts.unget(t);
        cout << result << statement() << endl;
    }
    catch(runtime_error& e) {
        cerr << e.what() << endl;
        clean_up_mess();
    }
}

int main()
    try {
        cout << INSTRUCTON << endl;
        calculate();
        return 0;
    }
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    char c;
    while (cin >>c&& c!=';') ;
    return 1;
}
catch (...) {
    cerr << "exception\n";
    char c;
    while (cin>>c && c!=';');
    return 2;
}
