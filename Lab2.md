#Lab 2 Write Up

Quesiton 2
----------
a.  
a ∈ V meaning Syntatic object A is in the set V  
b ∈ V meaning Syntatic object A is in the set V  
V ∈ A meaning Syntatic Object a is in the set A  
A ∈ A meaning Syntatic Object b is in the set A  

b.  
The first line of the grammar,
<code> A:: = A & A | V</code>, can be interperted as either:  
<code>A:: = (A & A) | V</code> or <code>A:: = A & (A|V)</code>  
This duel interpetation makes it ambigious

c.<code>  
S ::= A | B | C    
A ::= a A | a   
B ::= b B | e    
C ::= c C | c</code>  

This language above defines a sequence of either a, b, or c. With the posibility of only returning a single a, a single c, and empty.

d.<code>  
S ::= A a B b  
A ::= A b | b  
B ::= a B | a</code>  

A will either yield b or a sequence of [b]s  
B will either yeild a or a sequence of [a]s  
At the very least S must start and end with one b.  
And before the last b there must be a sequence of two [a]s

1. baab -> S => [A => b] a [B => a] b = baab
2. bbbab -> Will not work, it will always output at least two [a]s before b
3. bbaaaaaa -> Will not work, must end in a b
4. bbaab -> S => [A => [A => b] b] a [B => a] b = bbaab

e.  
  1. abcd
  5. accc  
<img src="https://dl.dropbox.com/u/19763512/parsetree.png">

Question 3
----------

a.  
<code> Expr ::= Operand | Expr Operator Operand </code>  
This segment of grammar, from MYSTERY, has Expr defined either as an Operand or an Expresion Operator Operand.  
> Operand  
> Operand Operator Operand  
> Operand Operator Operand Operator Operand ...

<code>Expr ::= Operand ExprSuffix</code>  
<code>ExprSuffix ::= Operator Operand ExprSuffix | e </code>  
This segment of grammar, defines Expr as an Operand ExprSuffix.
ExprSuffix is defined as either Operator Operand ExprSuffix or empty
> Operand epsilon  
> Operand Operator Operand epsilon  
>Operand Operator Operand Operator Operand ... epsilon 

Yes these two grammars will generate the same output, either a single Operand, or a Operand followed by a sequence of [Operator Operand]s  

b.  
<code> Operand ::= Number| Id | Operand[Expr]</code>  
Operand is defined as a either a Number, Id, or Operand with Array of Expr
> Number  
> Id  
> Number ... [expr]  
> Number Id Number id... [expr]  
> ...

<code>Operand ::= Number OperandSuffix | Id OperandSuffix</code>  
<code>OperandSuffix ::= [Expr]OperandSuffix | e</code>  
Operand is defined as either Number OperandSuffix or Id OperandSuffix
OperandSuffix is defined as either an Array or Expr with Operand Suffix or empty
> Number epsilon  
> Id epsilon  
> Number Number... [expr] epsilon  
> Number Id Number Id... [expr] epsilon  
> ...

Both can generate the same expressions, either a single Number or Id, or use [Expr] to expand it and output a sequence
of Number Id, and Operator Operand.

c.  
    + is left associative, only Expr can give an Operator.  
    > and + have the same precdence, both being part of the set of Operator. They will both be evaulated 

d.  
<code> 10 - 5 << 3 </code>  
> (10 - 5) << 3  
> 5 << 3  
> 40  

<code> 3 << 7 - 4 </code>  
> 3 << (7 - 4)  
> 3 << 3  
> 24  

How scala is implemented, - has more presidence than expoential, a left shift, <<, requires an expoential.  
Therefor - has more presidence than <<  

e.<code>  
Float :: = 0 | Sign 0. decimal Exponent | Sign num. decimal Exponent  
num :: = Sigma | num Sigma | num 0 | num 0 sigma  
decimal :: = 0 | decimal Sigma | Sigma decimal Sigma  
Sigma :: = 1 | 2 | 3 | 4 | 5 | ...  
Exponent :: = E Sign num | epslion  
Sign :: = - | epislon 
</code>
