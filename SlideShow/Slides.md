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

---

## Life With Lambda

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
