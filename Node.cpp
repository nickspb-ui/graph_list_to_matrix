#include "Node.h"

void input_list(std::vector <Node*> &edges, std::ifstream* input_file) {
	Node* start_node, *new_node, *last_node;
	char tmp[BUFFER_SIZE], buffer[BUFFER_SIZE];
	int tmp_size;

	while (!input_file->eof()) { // new line --- new graph node
		input_file->getline(buffer, BUFFER_SIZE);
		start_node = nullptr;
		last_node = nullptr;
		strcpy_s(tmp, 1, "");
		tmp_size = 0;	
		for (int i = 0; i < BUFFER_SIZE; i++) { // split buffer str by space and add numbers to the current list
			if ((buffer[i] == ' ' || buffer[i] == '\0') && tmp_size != 0) {
				new_node = new Node;
				new_node->num = atoi(tmp);
				new_node->next = 0;
				strcpy_s(tmp, 1, "");
				tmp_size = 0;

				if (start_node == nullptr) {
					start_node = new_node;
				}
				else {
					last_node->next = new_node;
				}
				last_node = new_node;
			}
			if (isdigit(buffer[i])) {
				tmp[tmp_size] = buffer[i];
				tmp_size++;
			}
			if (buffer[i] == '\0' || buffer[i] == '-') {
				break;
			}			
		}
		edges.push_back(start_node);
	}
}
