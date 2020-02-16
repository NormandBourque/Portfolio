#include <iostream> //input and outpupt
#include <string> //strings
#include <vector> //fector
#include "node.h"
#include "scan.h"

static token input_token;
static std::vector<node> nodes;
static std::vector<std::string> alphabet;
node findNode(std::string nodeName)
{
	node returningNode;
	for(int index = 0; index < nodes.size(); index++)
	{
		if(nodes[index].getName().compare(nodeName) == 0)
		{
			returningNode = nodes[index];
		}
	}
	return returningNode;
}

int findLetter(std::string alphabetLetter)
{
	int returningIndex = 0;
	for(int index = 0; index < alphabet.size(); index++)
	{
		if(alphabet[index].compare(alphabetLetter) == 0)
		{
			returningIndex = index;
		}
	}
	return returningIndex;
}

node makeDma(std::string file, bool accepting)
{
	openFile(file);
	input_token = scan();
	node startingNode;
	node firstNode;
	std::string letter = "";
	node secondNode;

	while(input_token != t_eof)
	{
		switch(input_token)
		{
    		case t_states:
				input_token = scan();
				while(input_token == t_id)
				{
					nodes.push_back(node(getTokenImage(), accepting));
					input_token = scan();
				}
			break;
    		case t_alphabet:
				input_token = scan();
				while(input_token == t_id)
				{
					letter = getTokenImage();
					alphabet.push_back(letter);
					input_token = scan();
				}
			break;
    		case t_startstate:
				input_token = scan();
				startingNode = findNode(getTokenImage());
    		break;
			case t_finalstate:
				input_token = scan();
				while(input_token = t_id)
				{
					firstNode = findNode(getTokenImage());
					firstNode.setAccepting(true);
					input_token = scan();
				}
    		break;
			case t_transition:
				do
				{
					input_token = scan();
					firstNode = findNode(getTokenImage());
					input_token = scan();
					letter = getTokenImage();
					input_token = scan();
					firstNode.makePath(findNode(getTokenImage()), findLetter(letter));
					input_token = scan();
				}
				while(input_token == t_id);

				//find node and alphabet in index and then set node1 to point to node2
   			break;
			case t_id:
				//error id shouldn't be found here.
    		break;
			case t_eof:
			break;
			default:
			break;
		}
	}
	return startingNode;
}


int main(int argc, char *argv[])
{
	bool help = false;
	bool verberous=false;

	for (int options = 0; options < argc; options++)
	{
		std::string option = argv[options];
		if(option.compare("-v") == 0)
		{
			if(nodes.size() == 0)
			{
				verberous = true;
			}
			else
			{
				for(int index = 0;index < nodes.size(); index++)
				{
					nodes[index].setAccepting(true);
				}
			}
		}
		else if(option.compare("-h") == 0)
		{
			std::cout << "display help" << std::endl;
		}
		else if(option.compare("-d") == 0)
		{
			std::string fileName = argv[options + 1];
			node start = makeDma(fileName, verberous);
		}
	}
}