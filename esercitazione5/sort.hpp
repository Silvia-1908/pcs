#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

template <typename T>
void merge(std::vector<T>& A, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r -q;
	
	std::vector<T> L(n1 + 1);
	std::vector<T> R(n2 + 1);
	
	for (int i = 0; i < n1; i++) {
		L[i] = A[p + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = A[q + 1 + j];
	}
	
	int i = 0, j = 0; int k = p;
	
	while (i < n1 && j < n2){
		if (L[i] <= R[j]) {
			A[k++] = L[i++];
		} else {
			A[k++] = R[j++];
		}
	}
	while (i < n1)
		A[k++] = L[i++];
	while (j < n2)
		A[k++] = R[j++];
}

template <typename T>
void mergeSort(std::vector<T>& A, int p, int r) {
	if (p < r) {
		int q = (p + r)/2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

template <typename T>
int partition(std::vector<T>& A, int p, int r) {
	T x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (A[j] <= x) {
			i++;
			std::swap(A[i], A[j]);
		}
	}
	std::swap(A[i + 1],A[r]);
	return i + 1;
}
			
		

template <typename T>
void quickSort(std::vector<T>& A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

template <typename T>
bool is_sorted(const std::vector<T>& A) {
	if (A.size() <= 1) {
		return true;
	}
	for (size_t i = 0; i < A.size()-1; ++i) {
		if (A[i] > A[i+1]) {
			return false;
		}
	}
	return true;
}

template<typename T>
void bubbleSort(std::vector<T>& A) {
	if (A.size() ==0) return;
	for (size_t i = 0; i < A.size(); i++) {
		for (size_t j = A.size()-1; j > i; j--) {
			if (A[j] < A[j-1]) {
				std::swap(A[j], A[j-1]);
			}
		}
	}
}

template <typename T>
void insertionSort(std::vector<T>& A) {
	for (int j = 1; j < A.size(); j++) {
		T key = A[j];
		int i = j - 1;
		while (i >= 0 && A[i] > key) {
			A[i +1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
	}
}

template <typename T>
void selectionSort(std::vector<T>& A) {
	for (size_t i = 0; i < A.size() - 1; i++) {
		size_t min = i;
		for (size_t j = i + 1; j < A.size(); j++) {
			if (A[j] < A[min]) {
				min = j;
			}
		}
		std::swap(A[i], A[min]);
	}
}

template <typename T>
void sceltaSort(std::vector<T>& A, int K) {

    if (A.size() <= K) {
        insertionSort(A);   
    } 
	else {
        quickSort(A, 0, A.size() - 1);  
    }
}



	
