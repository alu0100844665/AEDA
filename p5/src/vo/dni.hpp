#include "../common_types.hpp"

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
    char getDniLetra();
    string getDniNombre();

    // SOBRECARGA DE OPERADORES
    bool operator == (DNI& dni);
    bool operator < (DNI& dni);
    bool operator > (DNI& dni);
    operator int();

    friend ostream& operator<<(ostream& os, DNI& dni);

};


