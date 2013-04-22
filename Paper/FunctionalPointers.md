
####Function Pointer
A function pointer is a variable that stores the [memory] address of a function that can later be called through function pointer.  

Function pointers, which provide a way to pass around instructions on how to perform an operation.  
 
Function pointers are limited because functions must be fully specified at compile time.  

>##### Examples uses of Function Pointers:
> Someone may want to use a function pointer when implementing a sorting algorithm that will allow the function's caller to choose the order in which the data is sorted (acceding order vs. descending order for example). 

<br />
>##### Callback Functions:  
>[see this](http://www.cprogramming.com/tutorial/function-pointers.html) for details.

<br />  
>##### Syntax:
> <code>
void (*foo)(int);
> </code></p>  
> the function `foo` is only taking one argument (an int) with a return type void. However, `*foo` is a pointer to the function `foo`. 
>* This is similar to `int *x` so `*x` must be a pointer to `x`. 
> * The __key__ to writing a function pointer is to remember that the declaration of a function pointer is the same, the only difference is your replace the `function_name` with `*function_name`!   

>> Putting it all together:  
>> Can you interpret the following code?  
<code>
void \*(*foo)(int *); 
</code></p>
>> <br />
>> <br />
>> Translation: 
>>> The above code translates to a function pointer `*foo` taking a pointer to an int `int *` as a parameter and returning a pointer `void *`. 

<br />
>##### Initializing and Using function pointers
	void my_int_func(int x){    
		printf( "%d\n", x );  
	}  
>
	int main(){   
    	void (*foo)(int);      	
>    	
		// initialize the function pointer
    	// the ampersand is actually optional
    	foo = &my_int_func;  
>
		// call my_int_func
		foo(2);
		// or
		(*foo)(2);
>		
   		return 0;      
	}  
> ######Pointes to note:
> 1) when you initialize a function pointer the ampersand is optional, but its clarifies what that you are using a function.  
> 2) when calling a function through a function pointer you treat the function pointer the same as you would treat the function it is pointing to.  
> * Note that when calling a function pointer the `*` is optional, but again using one will help the reader of your code to understand what you are doing. 


--
--

#### Functors: Function Objects in C++
######___have not looked at___

--
--






