/**
* Normand Bourque
* CIS 205-L1-2194
* Lab 1
*
* Print instructions explaining how to operate the calculator
* Allow the user to continue entering calculations until they quit the program
* Allow the user to perform the following operations:
* add ( + ) should add to doubles 
* subtract ( - )  should subtract to doubles
* multiply ( * )  multiply two doubles
* divide  ( / )  divide two doubles, do not allow division by zero
* power ( ^ ) a double and an integer, calculate the double raised to the integer. zero and negative exponents should work.
* exponential ( e ) raise the constant e to the power of the integer provided. zero and negative exponents should work. (you must define the constant)
* factorial  ( ! ) given an integer, calculate the factorial. store your result as a long
* random range ( r ) given two integers, generate a random integer between the two integers (inclusively). Be sure the lower bound is less than the upper bound
* sum range ( s ) calculate the sum of consecutive integers between two given integers (inclusively)
* round ( ~ ) given a double, round to the nearest integers
* roundup ( ' ) given a double, round to the nearest integers
* rounddown ( _ ) given a double, round to the nearest integers
* minimum ( < ) given two doubles, determine the lesser
* maximum ( > ) given two doubles, determine the greater
* Allow the user to input the calculation all at once (examples below)
* +  3  4
* /  4.3  2.3
* ^  3.1  2
* r  5  10
* Your code must meet the following technical specifications
* use at least two variables of different types
* no global variables allowed
* use a constant, global constants are ok
* use at least one if or if else statement
* use at least one switch statement
* use at least one for loop
* use at least one while or do while loop
* use at least three functions with prototype.
* at least one must return a value
* at least one must take input
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double add( double, double );
double subtract( double, double );
double multiply( double, double );
double devide( double, double );
double to_the_power( double, int );
double power_to_the_constant_e( int );
unsigned long factoral( int );
int random_number_between_range( int, int );
int sum_consetive_ints( int, int );
int round_number( double );
int round_up_number( double );
int round_down_number( double );
double lesser_than( double, double );
double greater_than( double, double );
void menu( void );

int main( void )
{
    srand( time( NULL ) );
    char operation = 0;
    char carrage_return_removed;
    int quit_flag = 1;
    int send_first_int;
    int send_second_int;
    double results;
    double send_first_double;
    double send_second_double;
    int one_int = 0;
    int two_int = 0;
    int one_double = 0;
    int two_double = 0;
    int mixed = 0;
    int error_message = 0;
    
    // prints out how to use the calculator
    menu();
    
    // continues running as long as the charater q isn't typed.
    do
    {
        
        // grabs operation to be performed
        scanf(" %c", &operation);   
        
        //switch used to see what information is needed to perform operation then if statements call function to be performed.    
        switch (operation)
        {
            case '+':
            case '-':
            case '*':
            case '/':
                scanf("%lf %lf", &send_first_double, &send_second_double);
                two_double = 1;
                if (operation == '+')
                {
                    results = add(send_first_double, send_second_double);
                }
                else if (operation == '-')
                {
                    results = subtract(send_first_double, send_second_double);;
                }
                else if (operation == '*')
                {
                    results = multiply(send_first_double, send_second_double);
                }
                else if (operation == '/')
                {
                    results = devide(send_first_double, send_second_double);
                }
                else if (operation == '^')
                {
                    results = to_the_power(send_first_double, send_first_int);
                }
            break;
            case '^':
                scanf("%lf %d", &send_first_double, &send_first_int);
                results = to_the_power(send_first_double, send_first_int);
                mixed = 1;
            break;
            case 'e':
            case '!':
                scanf("%d", &send_first_int);
                one_int = 1;
                if (operation == 'e')
                {
                    results = power_to_the_constant_e( send_first_int );
                }
                else if (operation == '!')
                {
                    results = factoral(send_first_int);
                }
            break;
            case 'r':
            case 's':
            case 'S':
                scanf("%d %d", &send_first_int, &send_second_int);
                two_int = 1;
                if (operation == 'r')
                {
                    results = random_number_between_range(send_first_int, send_second_int);
                }
                else if (operation == 's' || operation == 'S')
                {
                    results = sum_consetive_ints(send_first_int, send_second_int);
                }
            break;
            case '~':
            case '\'':
            case '_':
                scanf("%lf", &send_first_double);
                one_double = 1;
                if (operation == '~')
                {
                    results = round_number(send_first_double);
                }
                else if (operation == '\'')
                {
                    results = round_up_number(send_first_double);
                }
                else if (operation == '_')
                {
                    results = round_down_number(send_first_double);
                }   
            break;
            case '<':
            case '>':
                scanf( "%lf %lf", &send_first_double, &send_second_double );
                two_double = 1;
                if (operation == '<')
                {
                    results = lesser_than(send_first_double, send_second_double);
                }
                else if (operation == '>')
                {
                    results = greater_than(send_first_double, send_second_double);
                }
            break;
            case 'q':
            case 'Q':
                quit_flag = 0;
            break;
            default:
                error_message = 1;
            break;
        }
        
        
        
        // 
        if (quit_flag == 1)
        {
            // reprints menue
            menu();
            
            // flags used to see what format output needs to take.
            if (error_message == 1)
            {
                printf("Invalid entry please retry.");
                error_message = 0;
            }
            else if (one_double == 1)
            {
                printf("%c = %lf\n", operation, results);
                one_double = 0;
            }
            else if (two_double == 1)
            {
                printf("%lf %c %lf = %lf\n", send_first_double, operation, send_second_double, results);
                two_double = 0;
            }
            else if (one_int == 1)
            {
                printf("%c %d = %lf\n", operation, send_first_int, results);
                one_int = 0;
            }
            else if (two_int ==1)
            {
                printf("%d %c %d = %lf\n", send_first_int, operation, send_second_int, results);
                two_int = 0;
            }
            else if (mixed == 1)
            {
                printf("%lf %c %d = %lf\n", send_first_double, operation, send_first_int, results);
            }
            
        }
    }
    while (quit_flag);
        
    return 0;
} // end of main function     
        
// Adds two number returns sum
double add(double first_number, double second_number)
{
    double sum;
    sum = first_number + second_number;
    return sum;
}

//Subtracts two numbers
double subtract(double first_number, double second_number)
{
    double diffrence;
    diffrence = first_number - second_number;
    return diffrence;
}

// multiplys two numbers
double multiply(double first_number, double second_number)
{
    double product;
    product = first_number * second_number;
    return product;
}

// devides two numbers and checks the denominator for a zero input if found reasks until proper input is given
double devide(double numerator, double denominator)
{
    double quotent;
    if (denominator == 0)
    {
        while (denominator == 0)
        {
            printf("Can't devide by 0 enter proper number. ");
            scanf("%lf", &denominator);
        } 
    }
    quotent = numerator / denominator;
    return quotent;
}


double to_the_power( double number, int to_the_power_of)
{
    double product = 1;
    
    printf("to the power of before %d", to_the_power_of);
    
    
    // if the product is 0 makes sure resutls are 1 if the power is equil to or greater then 1 then call the function less then 1 devides results by 1 to get the fraction.
    if (to_the_power_of == 0)
    {
        product = 1;
    }
    else if (to_the_power_of > 0)
    {
        do
        {
            product = multiply( product, number );
            to_the_power_of--;
        }
        while (to_the_power_of != 0);
    }
    else if (to_the_power_of < 0)
    {
        do
        {
            product = multiply( product, number );
            to_the_power_of++;
        }
        while (to_the_power_of < 0); 
        product = (1/product);       
    }
    
    return product;
}

// sets constant e then calls power function.
double power_to_the_constant_e( int to_the_power_of )
{
    const double e = 2.7182818284590452353602874713527;
    double product;
    product = to_the_power( e, to_the_power_of );
    return product;
}


unsigned long factoral( int factor_number )
{
    unsigned long product = 1;
    double number = 1;
    
    if (factor_number < 0)
    {
        printf ("%s", "Invalid factors can only be positve.  The results displayed are for a positive number of what you entered ");
        factor_number = factor_number * -1;        
    }
    
    if ( factor_number != 1 && factor_number != 0)
    {
        while (factor_number >= number)
        {
            product = multiply( (double)product, number );
            number++;
        }    
    }
    
    return product;
}

// generates a random number betweena  range using greater and lesser than functions toget the largest and smallest numbers
int random_number_between_range(int first_number, int second_number)
{
    int both_negitive_flag = 1;
    int smallest;
    int biggest;
    int random_number_is;
    
    //needed because if both are negitive the lesser of the two will always be the number so set a "flag" to chage both to positive generate a random number then return a negitive number
    if (first_number < 0 && second_number < 0)
    {
        both_negitive_flag = -1;
        first_number = first_number * both_negitive_flag;
        second_number = second_number * both_negitive_flag;
    }
    
    smallest = lesser_than((double)first_number, (double)second_number);
    biggest = greater_than((double)first_number, (double)second_number);    
    random_number_is = smallest + (rand() % biggest);
    
    return random_number_is * both_negitive_flag;
}


// sums consetive numbers
int sum_consetive_ints( int first_number, int second_number )
{
    int both_negitive_flag = 1;
    int smallest;
    int biggest;
    int sum = 0;
    
    //needed because if both are negitive the lesser of the two will always be the number so set a "flag" to chage both to positive generate a random number then return a negitive number
    if (first_number < 0 && second_number < 0)
    {
        both_negitive_flag = -1;
        first_number = first_number * both_negitive_flag;
        second_number = second_number * both_negitive_flag;
        printf("hit negitive");
    }
    
    smallest = lesser_than((double)first_number, (double)second_number);
    biggest = greater_than((double)first_number, (double)second_number);   
    
    printf("smallest = %d biggest = %d after\n", smallest, biggest);

    while (smallest != biggest +1)
    {
        sum = sum + smallest;
        printf("sum = %d\n and biggest in loop = %d, smallest = %d\n", sum,biggest,smallest);
        smallest++;
    }    
    
    return sum * both_negitive_flag;
}
// rounds numbers by using floor function to find the base then subtracts or adds that to find if it should be rounded up or down
int round_number(double incomming)
{
    int outgoing = 0;
    double compair = 0;
    int negitive_flag = 1;
    
    if (incomming < 0)
    {
        negitive_flag = -1;
        incomming = incomming * negitive_flag;
    }
    
    compair = incomming - round_down_number(incomming);
    
    
    if (compair >= .5)
    {
        outgoing = (int)incomming + 1;
    }
    else
    {
        outgoing = (int)incomming;
    }
    return outgoing * negitive_flag;
}

// if the number is 0 when subtracted by its whole number it is where it should be otherwisle if its greater then 0 then it should b rounded up
int round_up_number(double incomming)
{
    int outgoing = 0;
    double compair = 0;
    int negitive_flag = 1;
    
    if (incomming < 0)
    {
        negitive_flag = -1;
        incomming = incomming * negitive_flag;
    }
    
    compair = incomming - round_down_number(incomming);
    
    
    if (compair > 0)
    {
        outgoing = (int)incomming + 1;
    }
   
    return outgoing * negitive_flag;
}

// trukates results
int round_down_number( double solid_number)
{
// poor guy came in a double and left a int....
    int sending = (int)solid_number;
    printf ("sending = %d", sending);
    return sending;
}

// inspects what one is the least.
double lesser_than( double first_number, double second_number)
{
    double smallest;
    
    if (first_number < second_number)
    {
        smallest = first_number;
    }
    else if (second_number < first_number)
    {
        smallest = second_number;
    }
    else 
    {
        printf("They are equil!");
        smallest = first_number;
    }
    return smallest;
}

// inspects for the greater of the two numbers
double greater_than(double first_number, double second_number)
{
    double largest;
    
    if (first_number > second_number)
    {
        largest = first_number;
    }
    else if (second_number > first_number)
    {
        largest = second_number;
    }
    else 
    {
        printf("They are equil!");
        largest = first_number;
    }
    return largest;
}


// menu to tell how to run calculator
void menu()
{
    int clearing_screen = 0;
    int lines_on_screen = 100;
    
    while (clearing_screen != lines_on_screen)
    {
        printf("\n");
        clearing_screen++;
    }

        printf("   Welcome to the calculator   \n");
        printf("\n");
        printf("To add                  + 1 2  \n");
        printf("To subtract             - 1 1  \n"); 
        printf("To multiply             * 2 3  \n");
        printf("To devide               / 1 2  \n");    
        printf("To rase to a power      ^ 5 2  \n");
        printf("To rase e to the nth    e 2    \n"); 
        printf("To do a factoral        ! 5    \n");
        printf("To do a random range    r 1 5  \n");
        printf("To do a sum of a range  s 5 9  \n");
        printf("To round a number       ~ 1.5  \n"); 
        printf("To round up             ' 1.6  \n");
        printf("To round down           _ 6.8  \n");  
        printf("To smallest number      < 6 0  \n");
        printf("To greatest number      > 8 9  \n"); 
        printf("\n");
        printf("        or q to quit           \n");
        
    return;
}

/*Documentation Requirements
Name: Normand Bourque
Course: CIS 205-L1-2194
Assignment: Lab 1
Due Date: 3/3/2015
Description:
Credit: This work is all my own with minor help from professor.
*/

/* Testing
ran program to insure proper results calling functions well writting other functions to insure they worked.
*/

/*Completion Statement
The hardest part of the program is trying to figure out how I wanted to round the numbers.  eithr by adjusting the bits or trunkating.
*/
