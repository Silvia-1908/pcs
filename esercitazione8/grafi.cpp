#include <iostream>
#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"

int main(void)
{
	unidirected_edge e1(1, 2);
	unidirected_edge e2(2, 3);
	
	std::cout << "Arco e1 = " << e1 << "\n";
	std::cout << "Arco e2 = " << e2 << "\n";
	std::cout << "e1 < e2 ?" << "\n";
	if (e1 < e2)
		std::cout << "L'arco e1 è minore dell'arco e2\n";
	else
		std::cout << "L'arco e1 NON è minore dell'arco e2\n";
	std::cout << "e1 == e2 ?" << "\n";
	if (e1 == e2)
		std::cout << "I due archi sono uguali\n";
	else
		std::cout << "I due archi NON sono uguali\n";
		
	unidirected_graph G;
	
	G.add_edge(1, 2);
	G.add_edge(2, 3);
	G.add_edge(2, 4);
	G.add_edge(3, 4);
	
	std::cout << "Nodi \n";
	for (const int& i : G.all_nodes())
		std::cout << i << " ";
	std::cout << "\n";

	std::cout << "Archi \n";
	for (const unidirected_edge& e : G.all_edges())
		std::cout << e << "\n";

	std::cout << "Neighbours del nodo 3 \n";
	for (const int& i : G.neighbours(3))
		std::cout << i << " ";
	std::cout << "\n";
	
	std::cout << "Indici e archi \n";
    std::cout << "Arco 0 = " << G.edge_at(0) << "\n";
    std::cout << "Arco 1 = " << G.edge_at(1) << "\n";
	std::cout << "Arco 2 = " << G.edge_at(2) << "\n";
	
	unidirected_graph G1;
	G1.add_edge(1,2);
	G1.add_edge(2,3);
	unidirected_graph differenza = G - G1;
	
	std::cout << "Differenza G - G1 \n";
	for (const unidirected_edge& e : differenza.all_edges())
		std::cout << e << "\n";
	
	return 0;
}
	
	
	