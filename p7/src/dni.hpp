#pragma once
//#include "../common_types.hpp"
#include "common_types.hpp"
using namespace std;
class DNI{

  private:
    int numero_;
    char letra_;
    string nombre_;
    //string apellidos_;
  public:
    // CONSTRUCTOR
    DNI();
    DNI(int num);
    DNI(int num, char letra, string nombre);

    // DESTRUCTOR
    ~DNI();

    // METODOS
    void setDni(int n);
    void setDni(int n,char letra,string nombre);
    int getDni();
    int getDni() const;
    char getDniLetra();
    char getDniLetra() const;
    string getDniNombre();
    string getDniNombre() const;
    // SOBRECARGA DE OPERADORES
    //bool operator == (const DNI& dni);
    // bool operator == (const DNI& dni);
    // bool operator < (const DNI& dni);
    // bool operator > (const DNI& dni);
    bool operator == (const DNI& dni) const;
    bool operator < (const DNI& dni) const;
    bool operator > (const DNI& dni) const;
    operator int() const;
    operator unsigned long int() const;
    friend ostream& operator<<(ostream& os,const DNI& a);
    void operator=(const DNI& a);
    void operator=(const string& a);
    static int contador_;
};


