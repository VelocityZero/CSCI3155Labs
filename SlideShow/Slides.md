## Lambda C++ 11

![Lambda](http://i.imgur.com/tO9ugC3.png) 

###Why Lamda?

* Locally Declare Functions
* Pass functions as parameters (like functors)
* Use variables outside the scope of lambda
* Works well with STL

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
#include
using namespace std;

int main(){
    auto func = [] {cout << "Hello, World!";};

    // call func();
    func();

    return 0;
}
~~~~~
