#include "AVL.h"
#include <iostream>
#include <cstdio>
#include <time.h>
#include <stdlib.h>
#include <fstream>
//#include "matricula.hpp"
#include "dni.hpp"
// 2->4->5 mirar como se balancea
using namespace std;

// LLamadas a las funciones auxiliares
void menu();
void menu2();
DNI elemento_aleatorio_dni();
void vector_aleatorio_dni(vector<DNI>& banco, int input_size); // pasarle por referencia el banco
void leer_desde_fichero(vector<DNI>& prueba, bool& comp, string nombre_fichero);
int DNI::contador_ = 0;
string NameArray[10] = { "Carlos", "Daniel", "Nacho", "David", "Elena", "Karla", "Paula", "Eloisa", "Fernando", "Yaiza" };
string SurnameArray[10] = { " Gonzalez", " Fernandez", " Lopez", " Garcia", " Suarez", " Flores", " Aguirre", " Medina", " Romero", " Molina" }; // usar dni



int main(int argc, char* argv[])
{
    int seleccion;
    srand(time(NULL));
    do
    {
        menu2();
        cin >> seleccion;
        getchar();

        // ESTADÍSTICAS  no funcionan bien
        if (seleccion == 1)
        {
            cout << "Modo Estadistica" << std::endl;

            int n_pruebas; // Numero de pruebas
            int n_nodos; // Tamaño del arbol
            int minimo_busqueda = 1000, minimo_insercion = 1000;
            int maximo_busqueda = 0, maximo_insercion = 0;
            int media_busqueda = 0, media_insercion = 0;
            int suma_busqueda = 0, suma_insercion = 0;

            cout << "Introduzca el tamaño del arbol: " << endl;
            cin >> n_nodos;
            cout << "Introduzca el numero de pruebas: " << endl;
            cin >> n_pruebas;

            // Creo mi banco de pruebas

            // DNI* banco=new Matricula_t[n_nodos];
            vector<DNI> banco;
            DNI a;
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
            cout << "\n" << endl;
            cout << "============" << endl;
            cout << "ESTADÍSTICAS" << endl;
            cout << "============" << endl;
            cout << "\t\tN\tP\tMinimo\tMaximo\tMedia" << endl;
            cout << "Busqueda\t" << n_nodos << "\t" << n_pruebas << "\t" << minimo_busqueda << "\t"
                 << maximo_busqueda << "\t" << media_busqueda << endl;
            cout << "Insercion\t" << n_nodos << "\t" << n_pruebas << "\t" << minimo_insercion
                 << "\t" << maximo_insercion << "\t" << media_insercion << endl;
        }

        // DEMOSTRACION
        else if (seleccion == 2)
        {
            bool comp = 0;
            char opcion_fichero;
            vector<DNI> prueba;
            string nombre_fichero;
            if (argc == 2)
            {
                nombre_fichero = argv[1];
                leer_desde_fichero(prueba, comp, nombre_fichero);
            }
            AVL<DNI>* A;
            A = new AVL<DNI>;
            int opcion;
            string input_val;
            DNI in;

            do
            {
                menu();
                cin >> opcion;
                std::cout  << std::endl;
                switch (opcion)
                {
                    case 1:
                    {
                        cout << "Insertar: ";
                        cin >> input_val;
                        in = input_val;
                        A->Insertar(in);
                        A->Imprimir();
                        getchar();
                        break;
                    }
                    case 2:
                    {
                        cout << "Eliminar" << endl;
                        cin >> input_val;
                        in = input_val;
                        A->Eliminar(in);
                        A->Imprimir();
                        getchar();
                        break;
                    }
                    case 3:
                    {
                        cout << "Mostrar" << endl;
                        A->Imprimir();
                        std::cout << std::endl;
                        std::cout << std::endl;
                        getchar();
                        break;
                    }
                    case 4:
                    {
                        cout << "Insertar de fichero" << endl;
                        if (!comp)
                        {
                            cout << "No se ha introducido ningún fichero. ¿Desea introducir uno "
                                    "ahora?(S/N)"
                                 << endl;
                            cin >> opcion_fichero;
                            if (opcion_fichero == 'S')
                            {
                                cout << "Introduzca el nombre del fichero a leer: " << endl;
                                cin >> nombre_fichero;
                                leer_desde_fichero(prueba, comp, nombre_fichero);
                            }
                        }
                        for (int l = 0; l < prueba.size(); l++)
                        {
                            A->Insertar(prueba[l]);
                        }
                        A->Imprimir();
                        getchar();
                        break;
                    }
                    case 5:
                    {
                        system("clear");
                        break;
                    }

                    case 0:
                        cout << "Saliendo del programa!" << endl;
                        break;
                    default:
                        cout << "Invalid option" << endl;
                        break;
                }
            } while (opcion != 0);
        }
        if(seleccion == 3)
        system("clear");

    } while (seleccion != 0);
    cout << "Saliendo del programa" << endl;

    return 0;
}

void menu(void)
{

    cout << "  [0]Salir           " << endl;
    cout << "  [1]Insertar        " << endl;
    cout << "  [2]Eliminar        " << endl;
    cout << "  [3]Mostrar         " << endl;
    cout << "  [4]Insertar desde fichero" << endl;
    cout << "  [5]Limpiar pantalla" << endl;
}

void menu2(void)
{

    cout << "				  " << endl;
    cout << "Elija la opcion que desee ejecutar" << endl;
    cout << "[0]Salir" << endl;
    cout << "[1]Estadística" << endl;
    cout << "[2]Demostración" << endl;
    cout << "[3]Limpiar pantalla" << endl;
    cout << "				  " << endl;
}

DNI elemento_aleatorio_dni(void)
{
    //string aux;
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
    string aux;
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
            std::cout << dummy << std::endl;
            prueba[leer] = dummy;
            leer++;
        }
    }
    comp = 1;
}