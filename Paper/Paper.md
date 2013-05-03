<img src="http://i.imgur.com/tO9ugC3.png"></img>
## <a name="Table"></a> Table of Contents  
* <a href="#summary">Lambda Functions</a>
	* <a href="#basic">Basic Lambda syntax</a>
* <a href="#vCapture">Variable Capture</a>
	* <a href="#Captures_How">How Captures Work</a>
	* <a href="#Captures_ProCon">Pros and Cons to [&]</a>
* <a href="#STL">Using lambda with STL</a>
* <a href="#usingLambda">Putting it all together, Using lambda functions!</a>
	* <a href="#usingLambda_Nest">Nesting Lambdas</a>
	* <a href="#usingLambda_HighOrder">Lambda in a Higher-Order</a>



## <a name="summary"></a>Lambda Functions  
Lambda functions are a very useful tool when attempting to create higher order functions. The latest implementation of C++11 provides a wider range of methods to approach various problems. In summary, lambda functions allow:
* Create quick functions that only need to be declared locally. 
* Pass functions as parameters similarly to [functor](http://www.cprogramming.com/tutorial/functors-function-objects-in-c++.html) and [function pointer](http://www.cprogramming.com/tutorial/function-pointers.html). 
* Use variables declared within the scope the function is declared in.
* Lambda functions work well with STLs (such as algorithms). 



#### <a name="basic"></a>Basic Lambda syntax  
Lambda functions have a rather unique syntax, which at first glance can be confused with an array declaration with parameters. This is the general form for writing lambda functions:
<a name="declaration"></a>


>`lambda_type lambda_name = [capture_specification] (parameters) -> return_type 
{body}`

There are a few important things to remember about the declaration of lambda.
* Lambda functions can be nameless. This allows lambda functions to be used once in a specific way. 
* The capture specification can be empty ___(more on this later)___ 
* There doesn't necessarily have to be a parameters filed or a return type
	* You only have to include a return type if the compiler is unable to deduce the return type. 
	* Generally the default return type of a lambda function is void. 

For example here is the well know HelloWorld function written as a lambda function. 

~~~~~
#include <iostream>
using namespace std;
	
int main(){
	auto func = [] {cout << "Hello, World!";};
		
	// call func();
	func();
	
	return 0;
}
~~~~~	
<a href="#Table">↑ Top</a>

## <a name="vCapture"></a>Variable Capture. 
Variable capture is probably the best things about using lambda functions. Lambda functions have the ability to reference, use and even change variables and declared outside of the scope of a lambda function. This is all done within the capture specification field `[capture_specification],`defined in the <a href="#declaration">lambda declaration</a>

Variable capture is one of the things that allows lambda functions so incredibly flexible. Lambda functions have the ability to copy, reference, or even modify variables declared outside of the scope of a lambda function. The method in which these variables are captured is determined by the capture specification field `[capture_specification],`defined in the <a href="#declaration">lambda declaration</a>

~~~~~~
#include <iostream>
using namespace std;

int main(){
	string input; 

	cout << "enter a number: ";
	cin >> input;
	
	auto lambda_isNeg = [input] {
	return input < 0 ? "negative" : "positive"
	}
	
	cout << "you entered a " << lambda_isNeg << "number" << endl; 
	
	return 0;
}
~~~~~~
The above example show how you can capture a variable using a lambda function. In the example only `input` is captured by value; however, you do not need to give a list of variables you want to capture. Instead you can capture in the following ways: 
* `[=]` Capture all variables declared before the lambda function. (check [this](https://ideone.com/Ly38P) out for an example)
* `[&]` Similar to `=` only instead you capture all values by reference. 
* `[variable_name]` Like the above example demonstrates, individual variables may be captured using their name.
* `[]` Is the default capture method that will capture none of the variables

The example below demonstrates what you can capture with each method and the ability to mix and match with the use of commas to separate different capture types.
~~~~~~
	... 
	int x = 5;
	int double pi = 3.14;
	char z = 'z';
	
	[x];		/* capture only x */
	
	[&x];		/* capture only x by reference */
	
	[=, &pi]	/* capture all variables by value, but pi 
				   by reference */
	
	[&, z]		/* capture all variables by reference, and 
				   z by value. */
	
	[]			/* capture none of the variables. */
	
	[this] 		/* you can even capture the this pointer
				if you have not already used [=] or [&] */ 
	...
~~~~~~
	
##### <a name="Captures_How"></a> How Captures Works
A lambda variable capture works in a similar manner as that of a functor. The way that lambdas are implemented is by creating a small class that overloads the operator`()`, this allows lambda to act like a function. The lambda function then becomes an instance of this class and when it is constructed it takes in all surrounding variables within its environment that are passed into the capture specification field and stores them as member variables.  

##### <a name="Captures_ProCon"></a> Tread carefully, the pros and cons to `[&]`
While all of this seems great you should know when it is okay to capture by different types. For example, if you have a lambda function as a function parameter. Lambda functions which capture values by reference have the ability to change the captured references and have the changes affect all of the same references. Passing by reference will most likely be the fastest (particularly for large objects), but you must watch out for side-effects inside the lambda functions.

If a lambda function captures values by reference, the reference will not be valid after the function returns. However, if you capture by reference you have to ability to modify and change the data.  
<a href="#Table">↑ Top</a>

## <a name="STL"></a>Using lambda with the STL  
To use STLs like algorithms was a tedious task before lambda functions. Lets look at `for_each` in the algorithms STL as an example:
~~~~~~
vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);

// before in C++03 you would have to use a for expression to print out the values of v.
for (auto itr = v.begin(), end = v.end(); itr != end; ++itr){
	cout << *itr << " ";
}

// now however you can easily use the for_each. 
for_each(v.begin(), v.end(), [] (int val) {cout << val}); 	
~~~~~~
This implementation takes less lines and a lot easier to read and write. Not only that but the for_each implementation can perform better than the for expression because it can utilize loop unrolling.  
<a href="#Table">↑ Top</a>

## <a name="usingLambda"></a>Putting it all together, Using lambda functions!
In  the examples given so far we have given the lambda function a name. This is possible because the lambda expression is typed, which also allows us to assign a lambda to a function object. 

~~~~~~
int main(){
	// Assign a lambda expression to a function object. 
	function<int (int, int)> func = [] (int x, int y) {return x + y})
}
~~~~~~

##### Using Lambda functions:
Lambda functions are mostly used as parameters for other functions, such as the for_each example above. 

##### <a name="usingLambda_Nest"></a> Nesting Lambdas
Lambda functions can be nested inside of each other! (from: [www.msdn.microsoft.com](http://msdn.microsoft.com/en-us/library/dd293599.aspx))
~~~~~~
#include <iostream>
using namespace std;

int main(){
	int m = [](int x)
		{return [](int y) {return y*2; }(x) + 3; } (5);
	  //|-body of first-|-----body of second-----|
}
~~~~~~
In the above example the first lambda `int m = [](int x)`is declared directly after the `int main()`. The first lambda returns the second lambda + 3. The second lambda `[] (int y)` that returns `y*2`. To understand how this works lets first break down what `(x)` and `(5)` meant. You will notice that `(5)` is outside of the scope of both lambdas, this means that the parameter of the first lambda `(int x)` will have a value of 5. `(x)` is the same only it refers to the `y = x`, and `x = 5` so `y = x = 5 --> y = 5`.  


##### <a name="usingLambda_HighOrder"></a>Lambda in a Higher-Order
Lambda functions can take another lambda function as a parameters and even return lambda functions. [source](http://msdn.microsoft.com/en-us/library/dd293599.aspx)
~~~~~
#include <iostream>
#include <functional>

int main()
{
   using namespace std;

   // The following code declares a lambda expression that returns 
   // another lambda expression that adds two numbers. 
   // The returned lambda expression captures parameter x by value.
   auto g = [](int x) -> function<int (int)> 
      { return [=](int y) { return x + y; }; };

   // The following code declares a lambda expression that takes another
   // lambda expression as its argument.
   // The lambda expression applies the argument z to the function f
   // and adds 1.
   auto h = [](const function<int (int)>& f, int z) 
      { return f(z) + 1; };

   // Call the lambda expression that is bound to h. 
   auto a = h(g(7), 8);

   // Print the result.
   cout << a << endl;
}
~~~~~

Notes: 
* `auto g = [](int x) -> function<int (int)> {return [=](int y) (return x + y;};};};` is a function that creates other functions. If you have `auto func1 = g(10);`, `func1` will be a function pointer to a function `func(int y) {return 10 + y;}`
* `h` is a higher order function that calls `g` and adds one. 
* `a` stores the result of `h`.

There are two ways to use lambdas as higher order functions. 

1. __Use functions as arguments:__ As seen in the example above, it is possible to use the `std::function` to use functions as lambda parameters. This allows you to pass in a function and use it within the lambda function.
2. __Capturing functions:__ You can also capture functions by value or by reference. You can capture functions the same way as values and then use them as if they where declared within the lambda function itself. 
	* ___NOTE:___ _the rules for capturing still apply when you are capturing functions!_
	* ___NOTE:___ _If you wish to use lambda functions recursively you_ ___must___ _capture the function name by reference, and declare the lambda name before implement it._
		
		~~~~~~
...
function<int (int)> fun1;		// declaration
fun1 = [&fun1] (int x) {		// implementation
	return x > 10 ? x : fun1(++x);
}; 
auto fun2 =  fun1(2);			// call the lambda function
cout << "fun2 is: " << fun3;	// outputs 11
...
		~~~~~~
		[source](http://msdn.microsoft.com/en-us/library/dd293599.aspx)  
  
<a href="#Table">↑ Top</a>

