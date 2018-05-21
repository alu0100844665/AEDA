#pragma once
#include "../common_types.hpp"
class DNI{

  private:
    int numero_;
    char letra_;
    string nombre_;
  public:
    // CONSTRUCTOR
    DNI();

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
