#include <set>
#include <map>
#include <list>
#include <vector>
#include <stdexcept>
#include "unidirected_edge.hpp"
#pragma once

class unidirected_graph 
{
private:
    std::set<int> nodi;
    std::set<unidirected_edge> archi;
    std::map<int, std::set<int>> lista_adiacenza;
    std::vector<unidirected_edge> lista_archi;

public:
    /* Costruttore di default */
    unidirected_graph() {}

    /* Costruttore di copia */
    unidirected_graph(const unidirected_graph& other)
	{
		nodi = other.nodi;
		archi = other.archi;
		lista_adiacenza = other.lista_adiacenza;
		lista_archi = other.lista_archi;
	}

    /* Metodo neighbours() per restituire i vicini */
    std::list<int> neighbours(int nodo) const 
	{
        std::list<int> result;
		std::map<int, std::set<int>>::const_iterator i = lista_adiacenza.find(nodo);
		
		if (i == lista_adiacenza.end())
			return result;
		
		result.insert(result.end(), i->second.begin(), i->second.end());
		
		return result;
	}
	
	/* Metodo add_edge() per aggiungere un arco */
    void add_edge(int nodo1, int nodo2) {
        unidirected_edge e(nodo1, nodo2);

        if (archi.insert(e).second) {
            nodi.insert(nodo1);
            nodi.insert(nodo2);

            lista_adiacenza[nodo1].insert(nodo2);
            lista_adiacenza[nodo2].insert(nodo1);

            lista_archi.push_back(e);
        }
    }

    /* Metodo all_edges() per restituire tutti gli archi */
    std::set<unidirected_edge> all_edges() const {
        return archi;
    }

    /* Metodo all_nodes() per restituire tutti i nodi */
    std::set<int> all_nodes() const {
        return nodi;
    }

    /* Metodo edge_number() per la numerazione arco nel grafo */
    int edge_number(const unidirected_edge& e) const {
        for (size_t i = 0; i < lista_archi.size(); ++i) {
            if (lista_archi[i] == e)
                return i;
        }
        throw std::runtime_error("Arco non trovato");
    }

    /* Metodo edge_at() per oggeto arco nel grafo  */
    unidirected_edge edge_at(int i) const {
        if (i < 0 || i >= (int)lista_archi.size())
            throw std::out_of_range("Indice non valido");
        return lista_archi[i];
    }

    /* Differenza tra grafi */
    unidirected_graph operator-(const unidirected_graph& other) const
	{
    unidirected_graph result;

    for (const unidirected_edge& e : archi)
        if (!other.archi.count(e))
            result.add_edge(e.from(), e.to());

    return result;
	}
};