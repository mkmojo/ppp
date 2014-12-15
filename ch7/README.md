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

