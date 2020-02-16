#pragma once
#include <vector> 
#include <string>

class node
{
private:
	std::string name = "";
	bool accepting = false;
	std::vector<node> pathToNextNode;

public:
	node();
	node(std::string name, bool accepting);
	std::string getName();
	void makePath(node to, int path);
	void setAlphabet(int numberOfLetters);
	node nextNode(int alphabet);
	void setAccepting(bool accepting);
};
