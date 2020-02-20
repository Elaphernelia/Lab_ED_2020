#include <iostream>
#include "pila.h"
#include <math.h>
#include <string>
//Nombres: Ela Katherine Shepherd, Marlon Campoverde
using namespace std;


bool esEquilibrada(const string& cadena) {
	bool ret = true;
	Pila<int> pila = Pila<int>();
	for (int i = 0; i < cadena.length(); i++) {
		if (cadena[i] == '{' || cadena[i] == '(' || cadena[i] == '[') {
			pila.apila(cadena[i]);
		}
		else if (cadena[i] == '}' || cadena[i] == ')' || cadena[i] == ']'){
			if (pila.esVacia()) ret = false;
			else {
				switch (cadena[i])
				{
				case '}': if (pila.cima() == '{') pila.desapila(); break;
				case ')': if (pila.cima() == '(') pila.desapila(); break;
				case ']': if (pila.cima() == '[') pila.desapila(); break;
				default: ret = false;
				}
			}
		}
	}
	if (!pila.esVacia()) ret = false;
	
	return ret;
}


int main() {
	string cadena;
    while(getline(cin, cadena)) {
      if(esEquilibrada(cadena))
        cout << "EQUILIBRADA" << endl;
      else
        cout << "NO_EQUILIBRADA" << endl;		  
	}
	return 0;
}	
