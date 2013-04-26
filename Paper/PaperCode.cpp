// my first program in C++
#include <functional>
#include <iostream>

using namespace std;

void plusplus(int x) {cout << x + x;} 

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
    

    return 0;
}
