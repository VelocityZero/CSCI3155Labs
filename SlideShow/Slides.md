## Lambda C++ 11

![Lambda](http://i.imgur.com/tO9ugC3.png) 

###Why Lamda?

* Locally Declare Functions
* Pass functions as parameters (like functors)
* Use variables outside the scope of lambda
* Works well with STL

---

## Response to Lambda

> I've started using lambda functions in production code ... shortening code... improving unit tests... replacing what could previously have only been accomplished with macros. - Alex Allain

http://www.cprogramming.com/c++11/c++11-lambda-closures.html

---

## Life Before Lambda in C++
![Before Lambda](http://i.imgur.com/IcV3KuN.png)

* Functors and similar operations cumbersome to use 
* Overkill to declare and only use a function once

> Flexo, Stack Overflow  

---

## Life Before Lambda Example
~~~~~
#include <algorithm>
#include <vector>

namespace {
  struct f {
    void operator()(int) {
      // do something
    }
  };
}

void func(std::vector<int>& v) {
  f f;
  std::for_each(v.begin(), v.end(), f);
}
~~~~~

> Flexo, Stack Overflow  

---

## Life With Lambda

> Use of lambdas: For ages, people have complained about having to write functions or (better) function objects for use as operations, such as Cmp<T> above, for standard library (and other) algorithms. This was especially painful to do if you wrote large functions (don't) because in C++98 you could not define a local function object to use as an argument; now you can. However, lambdas allows us to define operations ``inline:'' - Bjarne Stroustrup

http://www.stroustrup.com/C++11FAQ.html#lambda

---

## Lambda syntax

~~~~~
lambda_type lambda_name = [capture_specification] (parameters) -> return_type {body}
~~~~~

* Lambda name and capture specification field can be left empty
* Parameters and return type are not necessary in most cases
  * Some compilers require a return type
  * Other compilers will default to void

---

## Lambda syntax

### Example:

~~~~~
#include <iostream>

using namespace std;

int main()
{
    auto func = [] () { cout << "Hello world"; };
    func(); // now call the function
}
~~~~~
