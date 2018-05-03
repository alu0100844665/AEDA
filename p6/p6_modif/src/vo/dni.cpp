#pragma once
#include "dni.hpp"
#include <ctime>

DNI::DNI():
numero_(00000000 + rand() % (99999999 + 1)),
letra_('a' + rand() % (('z' - 'a') + 1)),
//letra_('a'),
nombre_("carlos")
{}

DNI::DNI(int num){
	numero_ = num;
}

DNI::DNI(int num, char letra, string nombre){
	numero_ = num;
	letra_ = letra;
	nombre_ = nombre;
}


DNI::~DNI(){}

void DNI::setDni(int n){
	numero_ = n;
}

void DNI::setDni(int n, char letra, string nombre){
	numero_ = n;
	letra_ = letra;
	nombre_ = nombre;
}

int DNI::getDni(){
	return numero_;
}

int DNI::getDni() const{
	return numero_;
}

char DNI::getDniLetra(){
	return letra_;
}
string DNI::getDniNombre(){
	return nombre_;
}
// bool DNI::operator == (const DNI& dni){
// 		if( (unsigned long int)*this == (unsigned long int)dni )
// 		return true;
// 		else
// 		return false;
// }
// bool DNI::operator == (const DNI& dni){
// 		//if( (unsigned long int)*this == (unsigned long int)dni )
// 		if(getDni() == dni.getDni())
// 		return true;
// 		else
// 		return false;
// }
// bool DNI::operator < (const DNI& dni){
// 	//if( (unsigned long int)*this < (unsigned long int)dni )
// 	if(getDni() < dni.getDni())
// 		return true;
// 		else
// 		return false;
// }

// bool DNI::operator > (const DNI& dni){
// 	//if( (unsigned long int)*this > (unsigned long int)dni )
// 	if(getDni() > dni.getDni())
// 	return true;
// 	else
// 	return false;
// }
bool DNI::operator == (const DNI& dni) const{
		//if( (unsigned long int)*this == (unsigned long int)dni )
		if(getDni() == dni.getDni())
		return true;
		else
		return false;
}
bool DNI::operator < (const DNI& dni) const{
	//if( (unsigned long int)*this < (unsigned long int)dni )
	if(getDni() < dni.getDni())
		return true;
		else
		return false;
}

bool DNI::operator > (const DNI& dni) const{
	//if( (unsigned long int)*this > (unsigned long int)dni )
	if(getDni() > dni.getDni())
	return true;
	else
	return false;
}


DNI::operator int() const{
	return numero_;
}

DNI::operator unsigned long int() const{
	unsigned long int tmp = (unsigned long int)numero_;
	//tmp = tmp + int(getDniLetra());
	return tmp;
}

ostream& operator<<(ostream& os){
//	os << dni.getDni();
	os << getDni() << "-" << getDniLetra() <<" "<< getDniNombre() ;
	return os;
}


