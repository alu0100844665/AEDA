#include "../common_types.hpp"

template <class T>
ostream& write(ostream& os, vector<T>& aux)
{
    for(int i = 0; i < aux.size(); i++)
        os << aux[i] << "  |  ";
    os << endl;
    getchar();
    return os;
}

ostream& write_estadistico(ostream& os, vector<int> aux, string nombre)
{
    int max = 0;
    int min = INFINITY;
    int media = 0;
    
    for(int i = 0; i < aux.size(); i++)
    {
        if(aux[i] > max)
            max = aux[i];
        if(aux[i] < min)
            min = aux[i];
        media += aux[i];
    }
    media = media / aux.size();
    
    os << nombre << setw(10) << min << setw(10) << media << setw(10) << max << endl;
    return os;
}

void menu(int& opt,int& opt_algorithm,int& k,int npruebas)
{
        cout<<"\t\t\tElija una opcion\n\n";
        cout<<"0 Salir\n";
        cout<<"1 Modo Clasico\n";
        cout<<"2 Modo Estadistica\n\n";
        cout<<"->";
        cin>>opt;
        opt_algorithm = 0;
        if(opt == 0)
            k = npruebas;
        else if(opt == 1)
        {
            cout<<"\t\t\tElija un Algoritmo\n\n";
            cout<<"0 Salir\n";
            cout<<"1 Seleccion\n";
            cout<<"2 Metodo de la Sacudida\n";
            cout<<"3 MergeSort\n";
            cout<<"4 QuickSort\n";
            cout<<"5 ShellSort\n";
            cout<<"6 bublesort\n";
            cout<<"7 Insertion\n";
            cout<<"->";
            cin>>opt_algorithm;
        }

        
        if(opt == 2)
            cout << setw(20) << "Minimo" << setw(10) << "Media" << setw(10) << "Maximo" << endl;
        
        if(opt == 1)
            switch(opt_algorithm)
            {
                case 1: cout << "------------------------Selection sort------------------------" << endl; break;
                case 2: cout << "------------------------Shake sort------------------------" << endl; break;
                case 3: cout << "------------------------Merge sort------------------------" << endl; break;
                case 4: cout << "------------------------Quick sort------------------------" << endl; break;
                case 5: cout << "------------------------Shell sort------------------------" << endl; break;
                case 6: cout << "------------------------Buble sort------------------------" << endl; break;
                case 7: cout << "------------------------Insertion sort------------------------" << endl; break;
            }
}
