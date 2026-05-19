#include <iostream>
#include "unidirected_graph.hpp"
#pragma once
#include <map>
#include <queue>
#include <limits>

template<typename Container>
unidirected_graph
graph_visit(const unidirected_graph& G,
            int nodo_sorgente,
            Container& container)
{
    unidirected_graph albero_risultante;
	std::set<int> visitati;
	visitati.insert(nodo_sorgente);
	container.put(nodo_sorgente);

    while (!container.empty())
    {
        int u = container.get();
		for (int v : G.neighbours(u))
        {
            if (!visitati.count(v))
            {
                visitati.insert(v);
				container.put(v);
				albero_risultante.add_edge(u, v);
            }
        }
    }

    return albero_risultante;
}

void recursive_dfs_visit(const unidirected_graph& G,
                         unidirected_graph& albero,
                         int u,
                         std::set<int>& visitati)
{
    visitati.insert(u);
	for (int v : G.neighbours(u))
    {
        if (!visitati.count(v))
        {
            albero.add_edge(u, v);
			recursive_dfs_visit(G, albero, v, visitati);
        }
    }
}

unidirected_graph
recursive_dfs(const unidirected_graph& G,
              int nodo_sorgente)
{
    unidirected_graph albero;
	std::set<int> visitati;
	recursive_dfs_visit(G,
                        albero,
                        nodo_sorgente,
                        visitati);

    return albero;
}

std::map<int, int>
dijkstra(const unidirected_graph& G, int sorgente)
{
    std::map<int, int> distanza;
	const int INF = std::numeric_limits<int>::max();
    for (int nodo : G.all_nodes())
    {
        distanza[nodo] = INF;
    }
	distanza[sorgente] = 0;
	std::queue<int> q;
    q.push(sorgente);
	while (!q.empty())
    {
        int u = q.front();
        q.pop();
		for (int v : G.neighbours(u))
        {
            if (distanza[v] > distanza[u] + 1)
            {
                distanza[v] = distanza[u] + 1;
				q.push(v);               
            }
        }
    }
	return distanza;
}