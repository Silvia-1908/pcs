#include <iostream>
#pragma once

class unidirected_edge
{
	private:
	int nodo1, nodo2;
	
public:
	
	unidirected_edge(int a, int b)
	{
		if (a <= b) {
			nodo1 = a;
			nodo2 = b;
			}
		else {
			nodo1 = b;
			nodo2 = a;
		}
	}
	
	int from() const { return nodo1; }
    int to() const { return nodo2; }
	
	bool operator<(const unidirected_edge& other) const {
        if (nodo1 != other.nodo1) return nodo1 < other.nodo1;
        return nodo2 < other.nodo2;
    }

    bool operator==(const unidirected_edge& other) const {
        return nodo1 == other.nodo1 && nodo2 == other.nodo2;
    }
};
	
std::ostream&
operator<<(std::ostream& os, const unidirected_edge& e)
{
    os << "(" << e.from() << ", " << e.to() << ")";
    return os;
}