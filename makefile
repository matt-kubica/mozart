default: start

build:
	yacc -d mozart-parser.y
	flex mozart-lexer.l
	gcc y.tab.c lex.yy.c -o mozart

run:
	./mozart

start:
	yacc -d mozart-parser.y
	flex mozart-lexer.l
	gcc y.tab.c lex.yy.c -o mozart
	./mozart

.PHONY: clean
clean:
	rm y.tab.c
	rm y.tab.h
	rm lex.yy.c

