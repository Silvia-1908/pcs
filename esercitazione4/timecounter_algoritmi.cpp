#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

#include "timecounter.h"
#include "randfiller.h"
#include "sort.hpp"

int main(void)
{
	randfiller rf;
    timecounter tc;	/* instantiate the timecounter */
	
	for (int i = 4; i <= 8192; i *= 2) {
		std::vector<int> v(i);
		rf.fill(v, -100, 100);
		
		std::vector<int> v1 = v;
		std::vector<int> v2 = v;
		std::vector<int> v3 = v;
		std::vector<int> v4 = v;
		std::cout << "\nLunghezza vettore: " << i << "\n";
		
		tc.tic();
		bubbleSort(v1);
		double t1 = tc.toc(); /* stop the timecounter, get time and print it */
		std::cout << "Bubblesort time: " << t1 << " seconds\n";
		
		tc.tic();
		insertionSort(v2);
		double t2 = tc.toc(); 
		std::cout << "Insertionsort time: " << t2 << " seconds\n";
		
		tc.tic();
		selectionSort(v3);
		double t3 = tc.toc(); 
		std::cout << "Selectionsort time: " << t3 << " seconds\n";
		
		tc.tic();
		std::sort(v4.begin(), v4.end());
		double t4 = tc.toc(); 
		std::cout << "Sort time: " << t4 << " seconds\n";
	}
    
    return 0;
}
