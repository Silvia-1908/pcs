#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{
static const int N = 10;
double arr[10]={2.2, 3.4, 5.7, 9, 11, 17.9, 16, 8, 12.3, 1};

double min = arr[0];
double max = arr[0];
double somma = arr[0];

for(int i=1; i < N; i++) {
	if (arr[i] < min) {
		min = arr[i];
		}
	if (arr[i] > max) {
		max = arr[i];
		}
	somma = somma + arr[i];	
}

double quadrato = pow(arr[0]-somma/N,2);
for(int i=1; i<N; i++)
	quadrato = quadrato + pow(arr[i]-somma/N,2);
	
double var = quadrato/N;
double deviazione = std::sqrt(var);	
	
std::cout << "Minimo: " << min << "\n";
std::cout << "Massimo: " << max << "\n";
std::cout << "Media: " << somma/N << "\n";
std::cout << "Deviazione standard: " << deviazione << "\n";

}