#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>

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