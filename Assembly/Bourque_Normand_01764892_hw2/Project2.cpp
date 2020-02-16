/*****************************************************************/
/*  Assign 2 template */
/*****************************************************************/

#include <stdio.h>

typedef union float_32{
        float   floating_value_in_32_bits;
        int     arg_32;
        struct  sign_exp_mantissa
		{
                unsigned  mantissa:23;
                unsigned  exponent:8;
                unsigned      sign:1;
        } f_bits;
	struct single_bits{
		unsigned  b0 :1;
		unsigned  b1 :1;
		unsigned  b2 :1;
		unsigned  b3 :1;
		unsigned  b4 :1;
		unsigned  b5 :1;
		unsigned  b6 :1;
		unsigned  b7 :1;
		unsigned  b8 :1;
		unsigned  b9 :1;
		unsigned  b10:1;
		unsigned  b11:1;
		unsigned  b12:1;
		unsigned  b13:1;
		unsigned  b14:1;
		unsigned  b15:1;
		unsigned  b16:1;
		unsigned  b17:1;
		unsigned  b18:1;
		unsigned  b19:1;
		unsigned  b20:1;
		unsigned  b21:1;
		unsigned  b22:1;
		unsigned  b23:1;
		unsigned  b24:1;
		unsigned  b25:1;
		unsigned  b26:1;
		unsigned  b27:1;
		unsigned  b28:1;
		unsigned  b29:1;
		unsigned  b30:1;
		unsigned  b31:1;
	}bit;
} FLOAT_UN;

// A function to print out bits from a 32 bit container
// provided by the union FLOAT_UN above, and using 
// a text string as a label for the bit string
// as passed in the second argument
int print_bits(FLOAT_UN float_32, char * text){
	char bit_string[43];

	for(int i=0; i<42; i++){
		bit_string[i] = ' ';
	}
	bit_string[42] = '\0';

bit_string[0] = float_32.bit.b31?'1':'0';

bit_string[2] = float_32.bit.b30?'1':'0';
bit_string[3] = float_32.bit.b29?'1':'0';
bit_string[4] = float_32.bit.b28?'1':'0';
bit_string[5] = float_32.bit.b27?'1':'0';

bit_string[7] = float_32.bit.b26?'1':'0';
bit_string[8] = float_32.bit.b25?'1':'0';
bit_string[9] = float_32.bit.b24?'1':'0';
bit_string[10] = float_32.bit.b23?'1':'0';

bit_string[12] = float_32.bit.b22?'1':'0';
bit_string[13] = float_32.bit.b21?'1':'0';
bit_string[14] = float_32.bit.b20?'1':'0';

bit_string[16] = float_32.bit.b19?'1':'0';
bit_string[17] = float_32.bit.b18?'1':'0';
bit_string[18] = float_32.bit.b17?'1':'0';
bit_string[19] = float_32.bit.b16?'1':'0';

bit_string[21] = float_32.bit.b15?'1':'0';
bit_string[22] = float_32.bit.b14?'1':'0';
bit_string[23] = float_32.bit.b13?'1':'0';
bit_string[24] = float_32.bit.b12?'1':'0';

bit_string[26] = float_32.bit.b11?'1':'0';
bit_string[27] = float_32.bit.b10?'1':'0';
bit_string[28] = float_32.bit.b9?'1':'0';
bit_string[29] = float_32.bit.b8?'1':'0';

bit_string[31] = float_32.bit.b7?'1':'0';
bit_string[32] = float_32.bit.b6?'1':'0';
bit_string[33] = float_32.bit.b5?'1':'0';
bit_string[34] = float_32.bit.b4?'1':'0';

bit_string[36] = float_32.bit.b3?'1':'0';
bit_string[37] = float_32.bit.b2?'1':'0';
bit_string[38] = float_32.bit.b1?'1':'0';
bit_string[39] = float_32.bit.b0?'1':'0';

printf("%23s  %s\n",text, bit_string);
return 0;
}

int main(int argc, char * argv[])
{

FLOAT_UN float_32_s1, float_32_s2, float_32_rslt;
/**local helper variables**/
 
float	the_hardware_result;
int	mant_s1, mant_s2, mant_res, exp_s1, exp_s2, bitShifted = 0;
const int hiddenBit = 8388608;// this is 2 to the 24th power or the 24th bit.

/* Request two FP numbers */
printf("This program will emulate the addition of two IEEE 754 floating point numbers\n"); 
printf("Please enter two positive floating point values each with:\n"); 
printf("-no more than 6 significant digits\n");
printf("-a value between + 10**37 and 10**-37\n"); 

printf("Enter Float 1: ");
while(scanf("%g", &float_32_s1.floating_value_in_32_bits) != 1)
{}

printf("Enter Float 2: ");
while(scanf("%g", &float_32_s2.floating_value_in_32_bits) != 1)
{}

/* generate floating point hardware result */
the_hardware_result = float_32_s1.floating_value_in_32_bits + float_32_s2.floating_value_in_32_bits;

/* Get the mantissa and exponent components */
/*   into the helper variables */

mant_s1 = float_32_s1.f_bits.mantissa;
mant_s2 = float_32_s2.f_bits.mantissa;
exp_s1  = float_32_s1.f_bits.exponent;
exp_s2  = float_32_s2.f_bits.exponent;

/** check for normalization and slam in the **/
/** hidden bit if normalized **/
/** if the first number is deno**/
// denominlized when the man is all 0's and the exp is something other then zero. 
if(mant_s1 > 0 && exp_s1 == 0)
{
    // s1 is denomalized
}
else
{
    //s1 is normalized
    mant_s1 += hiddenBit;
}

if(mant_s2 > 0 && exp_s2 == 0)
{
    // s2 is denomalized
}
else
{
    // s2 is normalized
    mant_s2 += hiddenBit;
}

/** The rest is left to you */
//insure the exp are the same if not make proper adjustments 
if(exp_s1 != exp_s2)
{
    unsigned int shift = 0;
    if(((exp_s1 - 127) > (exp_s2 - 127)))
    {
        shift = (exp_s1 - 127) - (exp_s2 - 127);
		
		if(shift< 0)
		{
			shift *= -1;
		}
        mant_s2 = mant_s2>>shift;        
    }
    else
    {
        shift = (exp_s2 - 127) - (exp_s1 - 127);
		if(shift< 0)
		{
			shift *= -1;
		}
        mant_s1 = mant_s1 >> shift;
    }
}

int notworkingS1 = exp_s1-127;
int notworkingS2 = exp_s2-127;
if(notworkingS1 > notworkingS2)
{
    exp_s2=exp_s1;
}
else
{
    exp_s1=exp_s2;   
}


mant_res = mant_s1 + mant_s2;

//renormalize 
while(mant_res > (hiddenBit*2))
{
    mant_res=mant_res>>1;
    bitShifted++;
}

//remove hidden bit
if((mant_s1 == 0 && exp_s2 != 0) && (mant_s2 == 0 && exp_s2 != 0))
{
    //both are denomalized no op
}
else 
{
    //one or both are normalized remove hidden bit.
    mant_res -= hiddenBit;
}

float_32_rslt.f_bits.mantissa = mant_res;
float_32_rslt.f_bits.exponent = exp_s1 + bitShifted;
char first[] = "Original pattern of Float 1: ";
char second[] = "Original pattern of Float 2: ";
char third[] = "Bit pattern of result : ";
print_bits(float_32_s1,first);
print_bits(float_32_s2,second);
print_bits(float_32_rslt, third);
printf("EMULATED FLOATING RESULT FROM PRINTF ==>>> %.2f\n", float_32_rslt.floating_value_in_32_bits);
printf("HARDWARE FLOATING RESULT FROM PRINTF ==>>> %.2f\n", the_hardware_result);

}