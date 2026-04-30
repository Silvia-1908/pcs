#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

#include "timecounter.h"
#include "randfiller.h"
#include "sort.hpp"

int main() {
	randfiller rf;
    timecounter tc;	
	
	for (int N = 10; N <= 100; N += 10) {
		std::vector<std::vector<int>> base(100);
	
	int num_vettori = 10;
	
		for (int i = 0; i < num_vettori; i++) {
			base[i].resize(N);
			rf.fill(base[i], -100, 100);
		}
		
		std::vector<std::vector<int>> v = base;
		
		tc.tic();
		for (int i = 0; i < num_vettori; i++) {
			bubbleSort(v[i]);
		}
		double t1 = tc.toc(); /* stop the timecounter, get time and print it */
		std::cout << "Bubblesort time: " << t1/num_vettori << " seconds\n";
		
		v = base;
		tc.tic();
		for (int i = 0; i < num_vettori; i++) {
			insertionSort(v[i]);
		}
		double t2 = tc.toc(); 
		std::cout << "Insertionsort time: " << t2/num_vettori << " seconds\n";
		
		v = base;
		tc.tic();
		for (int i = 0; i < num_vettori; i++) {
			selectionSort(v[i]);
		}
		double t3 = tc.toc(); 
		std::cout << "Selectionsort time: " << t3/num_vettori << " seconds\n";
		
		v = base;	
		tc.tic();
		for (int i = 0; i < num_vettori; i++) {
			mergeSort(v[i], 0, v[i].size() - 1);
		}
		double t4 = tc.toc(); 
		std::cout << "Mergesort time: " << t4/num_vettori << " seconds\n";
		
		v = base;	
		tc.tic();
		for (int i = 0; i < num_vettori; i++) {
			quickSort(v[i], 0, v[i].size() - 1);
		}
		double t5 = tc.toc(); 
		std::cout << "Quicksort time: " << t5/num_vettori << " seconds\n";
		
		v = base;
		const int K = 45;
		tc.tic();
		for (int i = 0; i < num_vettori; i++){
			sceltaSort(v[i], K);
		}
		double t6 = tc.toc();
		std::cout << "Quicksort modificato: " << t6/num_vettori << " seconds\n";
		
		v = base;  
		tc.tic();
		for (int i = 0; i < num_vettori; i++) {
			std::sort(v[i].begin(), v[i].end());
		}
		double t7 = tc.toc();
		std::cout << "Sort time: "<< t7/num_vettori << " seconds\n";
		}
	
	return 0;
	}
	
	
