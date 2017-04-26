#Scope and Closures

###Chapter 1: Compiler Theory

3 Steps in JS Compilation

1. Lexing
 * character string -> tokens
2. Parsing 
 * tokens -> AST
3. Compilation
 * AST -> executable code

3 Major Players:

* Engine : executes outcome of compiler
* Compiler : obvious
* Scope: maintains a lookup of identifiers.  Constantly communicating with Engine

2 Types of Lookups
* RHS- essentially, is identifier defined
* LHS - where are identifiers contents so we can update them

2 Types of Scope

1. Lexical (JS)
2. Dynamic 

Lexical scope is defined at author-time (pre-compile)

###Chapter 3: Function vs Block Scope

_Principle of Least Priviledge_ is one of the reasons why lexical scoping is so great.

Use IIFEs when you can.  They help avoid polluting global namespace.  

var a = 2;

(function IIFE(){

	var a = 3;
	console.log( a ); // 3

})();

console.log( a ); // 2



Functions aren't the only way to create lexical scope . Any blocks are.  The _let_ and _const_ keywords are very powerful in this sense.  



###Chapter 4: Hoisting

There is a difference between declaration and expression. Take


`var a = 8`

`var a;` is a declaration and `a=8' is an expression.

Hoisting is this notion that the compiler will look at some arbitrary code, find all function and variable declarations for each scope, put the function definitions first and then the variable definitions second, and then follow all of that by expressions.  It is very important to note that only declarations are hoisted.  Or else this process would absolutely wreak havoc. 



