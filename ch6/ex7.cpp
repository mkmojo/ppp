/*
Can learn from section 6.4 Grammars
If some operation is at a higher priority, it is lower in the grammer hierarchy, in a sense that it
works more as as building block. 

Expression:
	Term
	Expression "&"
	Expression "|"
Term:
	Primary
	Term "^" Primary
Primary:
	Letter
	"!" Expression
	"!" Expression
	"(" Expression ")"
Letter:
	English-literal
*/


