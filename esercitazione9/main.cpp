#include <iostream>
#include <fstream>
#include "unidirected_graph.hpp"
#include "fifo.hpp"
#include "lifo.hpp"
#include "graph_visit.hpp"

void export_dot(const unidirected_graph& G, const std::string& filename)
{
    std::ofstream file(filename);
	file << "graph G {\n";
	for (const auto& e : G.all_edges())
    {
        file << "    "
             << e.from()
             << " -- "
             << e.to()
             << ";\n";
    }
	file << "}\n";
}

int main()
{
    unidirected_graph G;
	G.add_edge(1, 2);
    G.add_edge(1, 3);
	G.add_edge(1, 4);
	G.add_edge(1, 6);
    G.add_edge(2, 4);
    G.add_edge(2, 5);
	G.add_edge(2, 7);
	G.add_edge(3, 6);
	G.add_edge(4, 6);
	G.add_edge(4, 7);
	G.add_edge(5, 7);
	G.add_edge(6, 7);
	G.add_edge(6, 8);
	G.add_edge(7, 9);
	G.add_edge(8, 9);

    lifo<int> s;
	auto dfsG = graph_visit(G, 1, s);
	fifo<int> q;
	auto bfsG = graph_visit(G, 1, q);
	auto recdfs = recursive_dfs(G, 1);
	
	export_dot(dfsG, "dfs.dot");
    export_dot(bfsG, "bfs.dot");
	export_dot(recdfs, "recdfs.dot");
	
	std::cout << "Visite effettuate" << std::endl;
	
	auto distanze = dijkstra(G, 1);
	for (const auto& p : distanze)
	{
		std::cout
			<< "Nodo " << p.first << " distanza " << p.second << std::endl;
	}
}