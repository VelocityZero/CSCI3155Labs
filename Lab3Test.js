/* Program created by Jacob Rail, 3.3.2013.
 * This is a test file to be used in conjucture with Lab3.scala.
 * It uses recussion, strings, and demonstrates the difference
 * between static and dynamic scoping. */

//-------------------------------------------------------------
//----------------------- Functions----------------------------

/* Square and SumSquare test the Static and Dynamic Scoping. 
 * This is done by using the "number = 3" declaration below,
 * in the square function the number used is the global 
 * number declared below. If Static scoping is used the 
 * Square() function will ALWAYS refer to the "number = 3"
 * while Dynamic scoping will refer to the last used 
 * declaration of "number"; therefor, Square() will return
 * the same values ragardless of the scoping, but SumSquare()
 * will use the last "number" declaration for Square(). 
 * This will result in the output of SumSquare return 15 for
 * Dynamic scoping, and 27 for Static scoping. 
 *
 * Note: This discription only works for the way the code is
 * currently written. If the order of these functions are 
 * changed then you may get different results. */
number = 3;

function Square() {
	return number*number
}

function SumSquare(){;
	number = 3;	
	sum1 = Square();
	number = 2;
	sum2 = Square()
	number = 1;
	sum3 = Square();
	return sum1 + sum2 + sum3;
}


/* The fib() function test to see if the recurssion is 
 * implimented properly. The correct answer should be 7, because
 * 7 is the 5th fibonacci number. */
function fib(numb){
	if(numb <= 1) return 1;
	else return fib(numb - 1) + fib(numb - 2);
}


/* Question(), takes in a string and compares it to a hardcoded 
 * string, if the strings match it outputs a partiular result, 
 * if not a different result is outputed. */
function Question(phrase){
	if(phrase == "Question") return "Answer";
	else return "Not A Question";
}

// use the function defined above. 
Square();
SumSquare();
fib(5);
Question("Question");
Question("Answer");

//-------------------------------------------------------------
//-------------------------------------------------------------
