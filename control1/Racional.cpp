#include "Racional.h"
#include <cmath>


//Metodos publicos

  	//**** COMPLETAR
	//  Deben implementarse los metodos publicos de la clase
	//****
Racional:: Racional(long numerador, long denominador){
	this->_numer = new long; 
	this->_denom = new long; 

	if (denominador == 0){
		throw EDenominadorCero(); 
	}

	*_numer = numerador; 
	*_denom = denominador;
}
Racional:: Racional(){

	this->_numer = new long; 
	this->_denom = new long; 
	*_numer = 0; 
	*_denom = 1; 
}

Racional Racional:: suma(const Racional & frac){
	Racional num ((*_numer * (frac.mcm(*_denom, *frac._denom) / *_denom) + *frac._numer * (frac.mcm(*_denom, *frac._denom) / *frac._denom)), mcm(*_denom, *frac._denom));
	num.reduce();
	return num;
	//*_numer = (_numer * (frac.mcm(_denom, frac._denom)/_denom) + frac._numer * (frac.mcm(_denom, frac._denom)/frac._denom)); 
	//*_denom = mcm(_denom, frac._denom); 
}

Racional Racional:: operator - (const Racional& frac){
	Racional num ((*_numer * (frac.mcm(*_denom, *frac._denom)/ *_denom) - *frac._numer * (frac.mcm(*_denom, *frac._denom)/ *frac._denom)),mcm(*_denom, *frac._denom) );  
	num.reduce();
	return num;
}

Racional Racional:: operator *= (const Racional& frac){
	return Racional();
}

Racional Racional:: divideYActualiza(const Racional & frac){
	return Racional();
}

Racional Racional:: operator == (const Racional & frac){
	return Racional();
}

Racional& Racional:: operator *=(conts Racional & frac){
	*_numer = frac._numer * _numer; 
	*_numer = frac._denom * _denom;

	return *this; 
}

Racional& Racional:: divideYActualiza(const Racional & frac){
	if(frac._numer == 0){
		throw EDivisionPorCero(); 
	}

	*_numer = *_numer * frac._denom; 
	*_denom = *_denom * frac._numer; 

	return *this; 
}

bool Racional:: operator ==(const Racional & frac){
	return (*_numer == frac._numer ) && (*_denom == frac._denom); 
}

Racional:: ~Racional(){
	delete _numer; 
	delete _denom; 
}

// Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << *f._numer << "/" << *f._denom;
	return out;
}

// Metodos privados
void Racional::reduce() {
	  // Se asegura que el denominador siempre sea positivo   
	if (*_denom < 0) {
		*_numer = -(*_numer);
		*_denom = -(* _denom);
	}
	  // Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(*_numer, *_denom);
	*_numer /= fsimp;
	*_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	  // El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1); 
    v2 = abs(v2);	
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1%v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1*v2 / mcd(v1, v2);
}

