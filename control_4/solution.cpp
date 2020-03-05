#include "cola.h"
#include <iostream>
using namespace std;


// 
void supervivientes(int n, Cola<int>& cola) {
	for (int i = 1; i <= n; i++) {
		cola.pon(i);
	}
	unsigned int i = 0;
	unsigned int m = 2;
	unsigned int len = cola.longitud();
	while (m <= cola.longitud()) {
		while (i < len) {
			if (i%m == 0) cola.quita(); 
			else {
				cola.pon(cola.primero());
				cola.quita();
			}
			i++;
		}
		m++;
		i = 0;
		len = cola.longitud();
	}
}

int main() {
	
	int n;
	Cola<int> cola;

	cin >> n;
	while (n != 0){

		supervivientes(n, cola);

		cout << n << ":";
		while (!cola.esVacia()) {
			cout << " " << cola.primero();
			cola.quita();
		}
		cout << endl;
		
		cin >> n;	
	}
		
	return 0;
}
