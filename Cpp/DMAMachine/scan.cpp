#include <iostream>
#include <string>
#include <fstream>
#include "scan.h"//user defind 

char token_image[100];

void openFile(std::string file)
{
    dmfFile.open(file, std::ifstream::in);
}

std::string getTokenImage()
{
    return token_image;
}
////input file 
token scan() 
{
    static int c = ' ';
        /* next available char; extra (int) width accommodates EOF */
    int i = 0;              /* index into token_image */

    /* skip white space */
    while (isspace(c)) 
    {
        c = dmfFile.get();
    }

    //checks for end of input.
    if (c == EOF)
    {
        return t_eof;
    }

    //builds token name
    do 
    {
        token_image[i++] = c;
        c = dmfFile.get();
    } 
    while (isalpha(c) || isdigit(c) || c == '_');
    
    //adds null termination charater to char to make it a string
    token_image[i] = '\0';
    std::string commandCheck = token_image;
    
    //checks for "read" or "write" if neather it is a id
    if (commandCheck.compare("states:") == 0)
    {
        return t_states;
    }
    else if (commandCheck.compare("alphabet:") == 0)
    {
        return t_alphabet;
    }
    else if(commandCheck.compare("startstate:") == 0)
    {
        return t_startstate;
    }
    else if(commandCheck.compare("finalstate:") == 0)
    {
        return t_finalstate;
    }
    else if(commandCheck.compare("transition:") == 0)
    {
        return t_transition;
    }
    else 
    {
        return t_id;
    }
}