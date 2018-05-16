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
char DNI::getDniLetra() const{
	return letra_;
}
string DNI::getDniNombre(){
	return nombre_;
}

string DNI::getDniNombre() const{
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
		DNI::contador_++;
		if(getDni() == dni.getDni())
		return true;
		else
		return false;
}
bool DNI::operator < (const DNI& dni) const{
	//if( (unsigned long int)*this < (unsigned long int)dni )
	DNI::contador_++;
	if(getDni() < dni.getDni())
		return true;
		else
		return false;
}

bool DNI::operator > (const DNI& dni) const{
	//if( (unsigned long int)*this > (unsigned long int)dni )
	DNI::contador_++;
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

ostream& operator<<(ostream& os,const DNI& a){
//	os << dni.getDni();
	os << a.getDni() << "-" << a.getDniLetra() <<" "<< a.getDniNombre() ;
	return os;
}


void DNI::operator=(const DNI& a)
{
    numero_ = a.getDni();
    letra_ = a.getDniLetra();
    nombre_ = a.getDniNombre();
}
    
void DNI::operator=(const string& a)
{
	char tmp[] = "00000000";
	for(size_t i = 0; i < a.size();i++)
	{
		if(isdigit(a[i]))
		{
			tmp[i] = a[i];
		}
	}
    numero_ = atoi(tmp);
    for(size_t i = 0; i < a.size();i++)
    {
    	if(!isdigit(a[i]))
    	{
    		letra_ = a[i];
    		i = a.size();
    		for(size_t x = i; x < a.size();x++)
    			nombre_ += a[x];
    	}
    }
}