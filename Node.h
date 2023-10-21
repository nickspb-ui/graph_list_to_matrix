#pragma once
#include "Source.h"

struct Node {	
	int num;
	struct Node* next;
};

void input_list(std::vector <Node*>&, std::ifstream*); // '-' in the file line for an empty list
