Notes
---

##Drill
###2.
calculator08buggy.cpp
primary() is the most bottom level of grammar. 
which does direct evaluation for number and Variables. 
if what read in is a number token, send back value;
if is a variable, read from a table and send back the value. 
if a negative sign, means what we expect is another primary().

###7.
the Token::get() reads in text and construct tokens.
tokens are processed through grammar.
finally the result of the interpretation is presented to std out.

the content flollowing sqrt should be treated as promary() instead of expression(). 
primary will only take the first braces;
expression will take all the rest following sqrt.

###8.
Truly, I never thought about the possibility to have negative number is input to sqrt. 

##Exercise
###1. 
Change the line that only takes in letters and numbers to include underscore also.
###2. 
First attempt: Add one more layer above expression. Turned out to be wrong. The reason is that this code is written 
in an recurssion way. The return value of functions does not return the variable name all the way up to the outter most
layer. 
Second attempt: make the most bottom layer to a forward lookup for '='. 
###3.
Change Token::get() to create cst token from text "const".                //All processing function only take token
Add one more parallel level grammar named assignment() to declaration().  //Because const is like "let" keyword
modify Variable structre to differentiate const and non-const


