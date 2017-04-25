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

