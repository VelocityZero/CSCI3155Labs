// my first program in C++
#include <functional>
#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

void plusplus(int x) {cout << x + x;} 

vector<int> fibArith(int fibNumb, char symbol, int y){

    int first = 0;
    int second = 1;
    int sum = 0;
    int temp;
    vector<int> fib;

    auto arith = [] (char symbol) -> function<int (int, int)> { 
        return ([symbol] (int x, int y) {
            switch (symbol){ 
                case '+': return x + y; break;
                case '-': return x - y; break;
                case '*': return x*y;   break;
                case '/': return x/y;   break;
                case '%': return x%y;   break;
                default:  return x;     break; 
            }
        }
    );};


    auto func = arith(symbol);

    fib.push_back(func(first, y));

    for(unsigned int i = 0; i < fibNumb; ++i){
        fib.push_back(func(second, y));
        temp = second;
        second += first;
        first = temp;
    }

    return fib;
}

int main(){
    int n = 5;
    int m = 10;
    int x = 1;
    //int y = 2;
    

    auto lambda_isNeg = [n] {return n < 0 ? "negative":"positive";};


    cout << "you entered a " << n << " which is a " << lambda_isNeg() << " number." << endl; 


    // the '(x)' are not part of the lambda function, (x) is simply invoking the lambda function
    // with a value of x. this is the only way to nest lambda functions without returning a function. 
    auto foo = [] (int x) {return [](int y) {return y*2;}(x) + 3; };
    cout << "foo(" << n << ") gives you: " << foo(n) << endl;



    // Assign a lambda expression to a function object. 
    auto func = [] (int x, int y) {return x > y ? x : y;};

    auto bar = [=] {return func(n , m) + 1;};

    cout << bar() << endl;


    auto g = [](int x) -> function<int (int)> { return ([=](int y) -> int { return x + y; }); };
    auto h = [/*capture nothing*/] 
             (/*parameters:*/const function<int (int)>& f, int z) 
             -> /*return type*/int 
             {/*body*/return (f(z)) + 1;};

    int a = h(g(7), 8);
    cout << "the results of the higher order function test is: " << a << endl;
    



    auto arith = [] (char symbol) -> function<int (int, int)> { 
        return ([symbol] (int x, int y) {
            switch (symbol){ 
                case '+': return x + y; break;
                case '-': return x - y; break;
                case '*': return x*y;   break;
                case '/': return x/y;   break;
                case '%': return x%y;   break;
                default:  return x;     break; 
            }
        }
    );};


    /*
    auto plus = arith('+');
    cout << "should be 10: "<< plus(5, 5) << endl;

    vector<int> vFib = fibArith(5);
    double sum = 0;

    //for_each(vFib.begin(), vFib.end(), [&sum] (int i, function<int (int, int)> plus) {sum = plus(i, 5);});



    int i = 0;

    for_each(vFib.begin(), vFib.end(), [&] (int val) -> void {( plus(val, vFib.at(i++))); cout << val << " ";});

    cout << "\n\nsum is: " << sum << endl;
    */

    auto pretty = [] (int val) -> void {cout << val << " ";}; 

    vector<int> original = fibArith(5, ' ', 0);
    vector<int> vPlus    = fibArith(5, '+', 3);
    vector<int> vMinus   = fibArith(5, '-', 3);
    vector<int> vMulti   = fibArith(5, '*', 3);
    vector<int> vDiv     = fibArith(5, '/', 3);
    vector<int> vMod     = fibArith(5, '%', 3);


    cout << "\noriginal: ";
    for_each(original.begin(), original.end(), [] (int val) {cout << val << " ";});
    cout << "\nplus:   \t";
    for_each(vPlus.begin(), vPlus.end(), [] (int val) {cout << val << " ";});
    cout << "\nminus:\t ";
    for_each(vMinus.begin(), vMinus.end(), [] (int val) {cout << val << " ";});
    cout << "\nMulti:\t  ";
    for_each(vMulti.begin(), vMulti.end(), [] (int val) {cout << val << " ";});
    cout << "\nDiv:\t\t  ";
    for_each(vDiv.begin(), vDiv.end(), [] (int val) {cout << val << " ";});
    cout << "\nMod:\t\t  ";
    for_each(vMod.begin(), vMod.end(), [] (int val) {cout << val << " ";});
    cout << endl;

    return 0;
}







