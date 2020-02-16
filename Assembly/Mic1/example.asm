LOOP:	LODD PasCnt:	;;loads the number of times to run
	JZER DONE:	;if the program has zero time to go it is done
	SUBD c1:	;subtract one from the count
	STOD PasCnt:	;store the count back into it's memory location

P1:	LODD daddr:	;loads the number that daddr pointing to
	PSHI		;push the pointer onto the stack
	ADDD c1:	;add one to the to the counter
	STOD daddr:	;store the next counter
	CALL FIB:	;calls fib sub with stuff on stack.
	INSP 1		;clears the stack

P2:	PUSH		;push the return on the stack
	LODD faddr:	;load the results to the array
	POPI		;pop off results into the aray
	ADDD c1:	;increment the count
	STOD faddr:	;store the pointer for next idd
	JUMP LOOP:	;start over again.

;======================closes the loop===========================

FIB: 	LODL 1		;load from the stack
	JZER FIBZER:	;check to see if it is zero
	SUBD c1:	;subtract 1 from the count
	JZER FIBONE:	;if zero after the count go to fib one
	PUSH		;push c1 onto the stack
	CALL FIB:	;recursivey
	PUSH
	LODL 1
	SUBD c1:
	PUSH
	CALL FIB:

housek:	INSP 1		;clears top of stack
	ADDL 0		;puts results in accumalator
	INSP 2 		;clears last two arguments from the stack.
	RETN
;loads for the case of zero
FIBZER:	LODD c0:
	RETN
;loads for the case of 1
FIBONE:	LODD c1:
	RETN

DONE:	HALT

;DATA
.LOC	100
data:	3
	9
	18
	23
	25

answer:	0
	0
	0
	0
	0

daddr:	data:	;points to the data

faddr:	answer:	;points to the answers

c0:	0
c1:	1
PasCnt:	5

