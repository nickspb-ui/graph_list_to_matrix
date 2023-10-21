#include "Node.h"
#include "Graph.h"

int main() {
	std::vector <Node*> edges;

	std::ifstream input_stream;

	input_stream.open("input.txt", std::ios::in);
	input_list(edges, &input_stream);
	input_stream.close();

	int N = edges.size(); // number of nodes
	bool** adj_matrix = graph_list_to_matrix(edges);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << adj_matrix[i][j] << ' ';
		}
		std::cout << '\n';
	}
	
	return 0;
}
