masm_nr: mic1symasm.o lex.yy.o
	gcc -o masm_nr mic1symasm.o lex.yy.o
mic1symasm_nand_rshift.o:  mic1symasm.c
	gcc -c -g mic1symasm.c
lex.yy.o:  lex.yy.c
	gcc -c -g lex.yy.c
lex.yy.c: mic1symasmflex.ll
	flex mic1symasmflex.ll
clean:
	rm lex.yy.o lex.yy.c mic1symasm.o masm_nr
