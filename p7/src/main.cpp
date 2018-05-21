#include "AVL.h"
#include <iostream>
#include <cstdio>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
//#include "matricula.hpp"
#include "vo/dni.cpp"
using namespace std;
// LLamadas a las funciones auxiliares
void menu(ostream& os);
void menu2(ostream& os);
void modo_estadistico(ostream& os);
void modo_demostracion(ostream& os,int& seleccion,string nombre_fichero);
void caso1_demostracion(ostream& os,AVL<DNI>* A);
void caso2_demostracion(ostream& os,AVL<DNI>* A);
void caso3_demostracion(ostream& os,AVL<DNI>* A);
void caso4_demostracion(ostream& os,AVL<DNI>* A,string nombre_fichero,bool& comp,vector<DNI>& prueba);
DNI elemento_aleatorio_dni();
void vector_aleatorio_dni(vector<DNI>& banco, int input_size); // pasarle por referencia el banco
void leer_desde_fichero(vector<DNI>& prueba, bool& comp, string nombre_fichero);
int DNI::contador_ = 0;
string NameArray[10] = { "Carlos", "Daniel", "Nacho", "David", "Elena", "Karla", "Paula", "Eloisa", "Fernando", "Yaiza" };
string SurnameArray[10] = { " Gonzalez", " Fernandez", " Lopez", " Garcia", " Suarez", " Flores", " Aguirre", " Medina", " Romero", " Molina" }; // usar dni

int main(int argc, char* argv[])
{
    std::ostream & log = std::cout;
    int seleccion;
    string nombre_fichero = "";
    if(argc == 2)
      nombre_fichero = argv[1];
    srand(time(NULL));
    do
    {
        menu2(log);
        cin >> seleccion;
        getchar();
        switch (seleccion)
        {
          case 1:
            modo_estadistico(log);
          break;
          case 2:
            modo_demostracion(log,seleccion,nombre_fichero);
          break;
          case 3:
            system("clear");
          break;
          default:
            menu2(log);
        }
    }while (seleccion != 0);
    log << "Saliendo del programa\n" ;
    return 0;
}

void menu(ostream& os)
{
  os << "  [0]Salir           \n" ;
  os << "  [1]Insertar        \n" ;
  os << "  [2]Eliminar        \n" ;
  os << "  [3]Mostrar         \n" ;
  os << "  [4]Insertar desde fichero\n" ;
  os << "  [5]Limpiar pantalla\n" ;
}

void menu2(ostream& os)
{
  os << "\n" ;
  os << "Elija la opcion que desee ejecutar\n" ;
  os << "[0]Salir\n" ;
  os << "[1]Estadística\n" ;
  os << "[2]Demostración\n" ;
  os << "[3]Limpiar pantalla\n" ;
  os << "\n";
}
void modo_estadistico(ostream& os)
{
  os << "Modo Estadistica" << std::endl;
  int n_pruebas; // Numero de pruebas
  int n_nodos; // Tamaño del arbol
  int minimo_busqueda = 1000;
  int minimo_insercion = 1000;
  int maximo_busqueda = 0;
  int maximo_insercion = 0;
  int media_busqueda = 0;
  int media_insercion = 0;
  int suma_busqueda = 0;
  int suma_insercion = 0;
  os << "Introduzca el tamaño del arbol: \n" ;
  std::cin >> n_nodos;
  os << "Introduzca el numero de pruebas: \n" ;
  std::cin >> n_pruebas;
  // Creo  banco de pruebas
  vector<DNI> banco;
  vector_aleatorio_dni(banco, n_nodos);
  // CREAMOS UN ARBOL!
  AVL<DNI>* B;
  B = new AVL<DNI>;
  // Tamaño del arbol
  for (int i = 0; i < n_nodos; i++)
    B->Insertar(banco[i]);
  // Recorremos todas las pruebas y diferenciamos busqueda e insercion.
  DNI::contador_ = 0;
  for (int i = 0; i < n_pruebas; i++)
  {
    // BUSCAR VALORES INTRODUCIDOS
    B->Buscar(banco[rand() % n_nodos]);
    suma_busqueda = DNI::contador_ + suma_busqueda;
    if (DNI::contador_ < minimo_busqueda)
      minimo_busqueda = DNI::contador_;
    if (DNI::contador_ > maximo_busqueda)
      maximo_busqueda = DNI::contador_;
    // BUSCAR VALORES NO INTRODUCIDOS
    DNI e;
    bool distinto = true;
    do
    {
      e = elemento_aleatorio_dni();
      for (int j = 0; j < n_nodos; j++)
        if (e == banco[j])
          distinto = false;
    } while (distinto == false);
    B->Buscar(e);
    suma_insercion = DNI::contador_ + suma_insercion;
    if (DNI::contador_ < minimo_insercion)
      minimo_insercion = DNI::contador_;
    if (DNI::contador_ > maximo_insercion)
      maximo_insercion = DNI::contador_;
    DNI::contador_ = 0;
  }
  // MEDIAS
  media_busqueda = suma_busqueda / n_pruebas;
  media_insercion = suma_insercion / n_pruebas;
  // IMPRIME
  os << "\n\n" ;
  os << "============\n" ;
  os << "ESTADÍSTICAS\n" ;
  os << "============\n" ;
  os << "\n\nN\nP\nMinimo\nMaximo\nMedia\n" ;
  os << "Busqueda\n" << n_nodos << "\n" << n_pruebas << "\n" << minimo_busqueda << "\n"<< maximo_busqueda << "\n" << media_busqueda << "\n";
  os << "Insercion\n" << n_nodos << "\n" << n_pruebas << "\n" << minimo_insercion<< "\n" << maximo_insercion << "\n" << media_insercion <<"\n";
}
void modo_demostracion(ostream& os,int& seleccion,string nombre_fichero)
{
  bool comp = 0;
  vector<DNI> prueba;
  if (nombre_fichero != "")
    leer_desde_fichero(prueba, comp, nombre_fichero);
  AVL<DNI>* A;
  A = new AVL<DNI>;
  int opcion;
  do
  {
      menu(os);
      std::cin >> opcion;
      os  << std::endl;
      switch (opcion)
      {
          case 1:
            caso1_demostracion(os,A);
          break;
          case 2:
            caso2_demostracion(os,A);
          break;
          case 3:
            caso3_demostracion(os,A);
          break;
          case 4:
            caso4_demostracion(os,A,nombre_fichero,comp,prueba);
          break;
          case 5:
            system("clear");
          break;
          case 0:
              os << "Saliendo del programa!\n" ;
          break;
          default:
              os << "Invalid option\n" ;
      }
  }while (opcion != 0);
}
void caso1_demostracion(ostream& os,AVL<DNI>* A)
{
  string input_val;
  DNI in;
  os << "Insertar: ";
  cin >> input_val;
  in = input_val;
  A->Insertar(in);
  A->Imprimir();
  getchar();
}
void caso2_demostracion(ostream& os,AVL<DNI>* A)
{
  string input_val;
  DNI in;
  os << "Eliminar\n" ;
  cin >> input_val;
  in = input_val;
  A->Eliminar(in);
  A->Imprimir();
  getchar();
}
void caso3_demostracion(ostream& os,AVL<DNI>* A)
{
  os << "Mostrar\n" ;
  A->Imprimir();
  os << std::endl;
  os << std::endl;
  getchar();
}
void caso4_demostracion(ostream& os,AVL<DNI>* A,string nombre_fichero,bool& comp,vector<DNI>& prueba)
{
  char opcion_fichero;
  os << "Insertar de fichero\n" ;
  if (!comp)
  {
      os << "No se ha introducido ningún fichero. ¿Desea introducir uno ahora?(S/N)\n";
      std::cin >> opcion_fichero;
      if (opcion_fichero == 'S')
      {
          os << "Introduzca el nombre del fichero a leer: \n" ;
          std::cin >> nombre_fichero;
          leer_desde_fichero(prueba, comp, nombre_fichero);
      }
  }
  for (int l = 0; l < prueba.size(); l++)
  {
      A->Insertar(prueba[l]);
  }
  A->Imprimir();
  getchar();
}
DNI elemento_aleatorio_dni(void)
{
    int input_val;
    char strrnd;
    DNI tmp;
    input_val = 00000000 + rand() % (99999999 + 1);
    strrnd = 65 + rand() % (90 - 65);
    tmp.setDni(input_val,strrnd,(NameArray[rand()%10] + SurnameArray[rand()%10] + SurnameArray[rand()%10]));
    return tmp;
}

void vector_aleatorio_dni(vector<DNI>& banco, int input_size)
{
    int input_val;
    char strrnd;
    DNI tmp;

    for (int c = 0; c < input_size; c++)
    {
        input_val = 00000000 + rand() % (99999999 + 1);
        strrnd = 65 + rand() % (90 - 65);
        tmp.setDni(input_val,strrnd,(NameArray[rand()%10] + SurnameArray[rand()%10] + SurnameArray[rand()%10]));
        // insertar al banco
        banco.push_back(tmp);
    }
}

void leer_desde_fichero(vector<DNI>& prueba, bool& comp, string nombre_fichero)
{
    string dummy;
    int leer = 0;
    int tam = 0;
    ifstream fichero(nombre_fichero);
    if (fichero.good())
    {
        fichero >> tam;
        prueba.resize(tam);
        while (leer < tam)
        {
            fichero >> dummy;
            prueba[leer] = dummy;
            leer++;
        }
    }
    comp = 1;
}
