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

###3.
the Token::get() reads in text and construct tokens.
tokens are processed through grammar.
finally the result of the interpretation is presented to std out.


