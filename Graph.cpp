#include "Graph.h"

bool** graph_list_to_matrix(std::vector <Node*>& edges) {
	struct Node* cur_node = nullptr;
	int N = edges.size();
	bool** adj_matrix = new bool* [N];
	for (int i = 0; i < N; i++) {
		adj_matrix[i] = new bool[N];
		for (int j = 0; j < N; j++) {
			adj_matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		cur_node = edges[i];
		while (cur_node != nullptr) {
			adj_matrix[i][cur_node->num] = 1;
			cur_node = cur_node->next;
		}
	}
	return adj_matrix;
}
