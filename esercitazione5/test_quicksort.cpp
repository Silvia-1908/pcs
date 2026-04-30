#include <iostream>
#include <vector>
#include "randfiller.h"
#include "sort.hpp"
#include "string"

template<typename T>
void
print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main(void)
{
    randfiller rf; /* instantiate a randfiller */
	
	for (int i = 0; i < 100; i++) {
		
		std::vector<int> temp(1);
		rf.fill(temp, 1, 50);
		int len = std::max(1,temp[0]);
		std::vector<int> vi(len);
		rf.fill(vi, -30, 50);
		std::cout << "Test int " << i + 1 << "(lunghezza = " << len << ")\n";
		print_vector(vi);
		quickSort(vi, 0, vi.size() - 1);
		if (not is_sorted(vi)) {
			return EXIT_FAILURE;
		}
		std::cout<< "Vettore ordinato int " << i+1 << "(lunghezza = " << len << ")\n";
		print_vector(vi);
    
		std::vector<float> vf(len);
		rf.fill(vf, -1.5f, 7.5f);
		std::cout<< "Test float " << i+1 << "(lunghezza = " << len << ")\n";
		print_vector(vf);
		quickSort(vf, 0, vf.size() - 1);
		if (not is_sorted(vf)) {
			return EXIT_FAILURE;
		}
		std::cout<< "Vettore ordinato float " << i+1 << "(lunghezza = " << len << ")\n";
		print_vector(vf);

		std::vector<double> vd(len);
		rf.fill(vd, -1.5, 7.5);
		std::cout<< "Test double " << i+1 << "(lunghezza = " << len << ")\n";
		print_vector(vd);
		quickSort(vd, 0, vd.size() - 1);
		if (not is_sorted(vd)) {
			return EXIT_FAILURE;
		}
		std::cout<< "Vettore ordinato double" << i+1 << "(lunghezza = " << len << ")\n";
		print_vector(vd);
	}
	
	std::vector<std::string> s = {
		"fragole", "ballerina", "astronauta", "arcobaleno", 
		"pallavolo", "informatica", "rosso", "blu",
		"matematica", "parco"
	};
	std::cout << "\nTest stringa: ";
	print_vector(s);
	quickSort(s, 0, s.size() - 1);
	if (not is_sorted(s)) {
		return EXIT_FAILURE;
	}
	std::cout << "Stringa ordinata: ";
	print_vector(s);
	
	
    return EXIT_SUCCESS;
}
