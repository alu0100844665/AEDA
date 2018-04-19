
            /*
 (°ロ°)☝   Seleccion
 (っ◕‿◕)っ   Por Intercambio: Método de la Sacudida
 (ノಠ益ಠ)ノ  MergeSort
 ʕノ◔ϖ◔ʔノ  QuickSort
 ༼ つ ◕_◕ ༽つ  Por Incrementos Decrecientes (ShellSort):
*/
#include "vo/matricula.hpp"
#include "vo/dni.cpp"
#include "functions/sort_functions.cpp"
#include "functions/menu_fuctions.cpp"
#include <vector>
#include <cmath>
#include <iomanip>

int main (void)
{
    int num, tam, npruebas;
    int contador = 0;
    int k = 0;
    int del = 0;
    int a = 0;
    char strrnd[3];
    int opt=1;
    srand(time(NULL));
    int tmp;
	DNI tmp_dni;
	vector<vector<DNI>> banco_pruebas; //usar DNI
	string NameArray[10] = { "Carlos", "Daniel", "Nacho", "David", "Elena", "Karla", "Paula", "Eloisa", "Fernando", "Yaiza" }; // usar dni
	string SurnameArray[10] = { " Gonzalez", " Fernandez", " Lopez", " Garcia", " Suarez", " Flores", " Aguirre", " Medina", " Romero", " Molina" }; // usar dni
    //vector<vector<Matricula_t>> banco_pruebas;     //usar matriculas
    vector<DNI> secuencia;  //declaracion del vector de matriculas.
    vector<DNI> aux;
    vector<vector<int>> vector_estadistico;
    string nombres[7] = {"Seleccion ", "Shake sort", "Merge sort", "Quick sort", "Shell sort","Buble sort","Insertion"};
    int opt_algorithm;
    cout << "Introduzca el tamaño de la secuencia." << endl << "->";
    cin >> tam;
    cout << endl << "Introduzca el número de pruebas que quiere ejecutar." << endl << "->";
    cin >> npruebas;
    secuencia.resize(tam);
    //string matricula[tam];
    banco_pruebas.resize(7);
    vector_estadistico.resize(7);
    for(int i = 0; i < 7; i++)
    {
        vector_estadistico[i].resize(npruebas);
    }
    while(opt != 0)
    {

        menu(opt,opt_algorithm,k,npruebas); // interzaf para el usuario
        while(k < npruebas)
        {
             //GENERAMOS EL BANCO DE PRUEBAS ALEATORIO MAtricula
            // for(int j = 0; j < 7; j++)                             
            // {
            //     banco_pruebas[j].resize(tam);
            //     for(int c = 0; c < tam; c++)
            //     {
            //         num =  rand() % 9000 + 1000;
            //         matricula[c] += to_string(num);
            //         for(int i=0; i <= 2; i++)
            //             strrnd[i] = 65 + rand() % (90 - 65);
            //         matricula[c] += strrnd;
            //         secuencia[c].set_m(matricula[c]);
            //     }
            //     banco_pruebas[j] = secuencia;
            //     for(int i = 0; i <= tam; i++)
            //         matricula[i].clear();
            // }
            //GENERAMOS EL BANCO DE PRUEBAS ALEATORIO DNI
            for(int j = 0; j < 7; j++)                             
            {
    	        banco_pruebas.resize(tam);
    	        for(int i = 0 ; i < tam ; i++)
    	        {
    		        tmp = 00000000 + rand() % (99999999 + 1);
    		        strrnd[0] = 65 + rand() % (90 - 65);
    	        	tmp_dni.setDni(tmp,strrnd[0],(NameArray[rand()%10] + SurnameArray[rand()%10] + SurnameArray[rand()%10]));
                    secuencia[i] = tmp_dni;
    	        }
    	        banco_pruebas[j] = secuencia;
    	        
            }
            if(opt == 1)
            {
                switch(opt_algorithm)
                {
                    case 0:  
                                break;
                    case 1:     aux = banco_pruebas[0];
                                seleccion(aux, tam, contador,opt);
                                write(cout, aux);
                                break;
                    case 2:     aux = banco_pruebas[1];
                                shake_sort(aux, tam, contador,opt);
                                write(cout, aux);
                                break;
                    case 3:     aux = banco_pruebas[2];
                                Msort(aux, 0, aux.size()-1, contador,opt);
                                write(cout, aux);
                                break;
                    case 4:     aux = banco_pruebas[3];
                                Qsort(aux, 0, aux.size()-1, contador,opt);
                                write(cout, aux);
                                break;
                    case 5:     aux = banco_pruebas[4];
                                ShellSort(aux, 0, aux.size()-1, contador,opt);
                                /*del = tam;
                                while (del > 1)
                                {   
                                    del = del * a;
                                    shellsort(del, aux, tam, contador);
                                }*/
                                write(cout, aux);
                                break;
                                
                    case 6:     aux = banco_pruebas[5];
                                bublesort(aux,tam,contador,opt);
                                write(cout, aux);
                                break;
                                
                    case 7:     aux = banco_pruebas[6];
                                insertion(aux, tam, contador,opt);
                                write(cout,aux);
                                break;
                }
            }
            else if(opt == 2)
            {
                //cout << "Introduzca la constante de reduccion alfa:" << endl << "-> " ;
                //cin >> a;
                contador = 0;
                aux = banco_pruebas[0];
                seleccion(aux, tam, contador,opt);
                vector_estadistico[0][k] = contador;
                
                contador = 0;
                aux = banco_pruebas[1];
                shake_sort(aux, tam, contador,opt);
                vector_estadistico[1][k] = contador;
                
                contador = 0;
                aux = banco_pruebas[2];
                Msort(aux, 0, aux.size()-1, contador,opt);
                vector_estadistico[2][k] = contador;
                
                contador = 0;
                aux = banco_pruebas[3];
                Qsort(aux, 0, aux.size()-1, contador,opt);
                vector_estadistico[3][k] = contador;

                contador = 0;
                aux = banco_pruebas[4];
                ShellSort(aux, 0, aux.size()-1, contador,opt);
                /*del = tam;
                while (del > 1)
                {   
                    del = del * a;
                    shellsort(del, aux, tam, contador);
                }*/
                vector_estadistico[4][k] = contador;
                
                contador = 0;
                aux = banco_pruebas[5];
                bublesort(aux,tam,contador,opt);
                vector_estadistico[5][k] = contador;
                
                contador = 0;
                aux = banco_pruebas[6];
                insertion(aux, tam, contador,opt);
                vector_estadistico[6][k] = contador;
            }
        k++;
        
        }
        k = 0;
        if(opt == 2)
        {
            for(int i = 0; i < 7; i++)
            {
                write_estadistico(cout, vector_estadistico[i], nombres[i]);
            }
        }
    }
    cout << "Saliendo del programa..." << endl;
    return 0;
}