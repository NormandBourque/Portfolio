#include <vector> 
#include <string>
#include "node.h"


node::node()
{

}

node::node(std::string name,bool accepting)
{
    this->name = name;
    this->accepting = accepting;
}

void node::setAlphabet(int numberOfLetters)
{
    for(int index = 0; index < numberOfLetters; index++)
    {
        pathToNextNode.push_back(node());
    }
}

void node::makePath(node to, int path)
{
       pathToNextNode.at(path)=to;
}

std::string node::getName()
{
    return name;
}

void node::setAccepting(bool accepting)
{
    this->accepting = accepting;
}