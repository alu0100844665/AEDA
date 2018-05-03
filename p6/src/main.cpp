#include <iostream>
#include "arbol_binario.hpp"
//#include "matricula.hpp"
#include "vo/dni.cpp"
#include <limits>
#include <stdlib.h>
#include <time.h>
#include "common_types.hpp"
using namespace std;

int menu()
{
	int op;
	while (op > 5 || op < 0)
	{
		cout<<"----------------MENU----------------"<<endl;
		std::cout << "[0].Salir" << std::endl;
		std::cout << "[1].Insertar" << std::endl;
		std::cout << "[2].Mostrar" << std::endl;
		std::cout << "[3].Profundidad del arbol" << std::endl;
		std::cout << "[4].Borrar" << std::endl;
		std::cout << "[5].Limpiar pantalla" << std::endl;
		cout<<"------------------------------------"<<endl;
		std::cout<< std::endl;
		std::cout << "¿Que opcion desea ejecutar?-> ";
		cin >> op;
		if(op > 5 || op < 0)
		std::cout << "Introduzca una opcion soportada" << std::endl;
	}
	return op;
}


int main(void)
{
	tree_t<DNI> tree;
	int num;
    char strrnd[3];
    string NameArray[10] = { "Carlos", "Daniel", "Nacho", "David", "Elena", "Karla", "Paula", "Eloisa", "Fernando", "Yaiza" }; // usar dni
	string SurnameArray[10] = { " Gonzalez", " Fernandez", " Lopez", " Garcia", " Suarez", " Flores", " Aguirre", " Medina", " Romero", " Molina" }; // usar dni
	int input_sz;
	int input_val;
	DNI tmp;
	bool no_salida = true;
	int mode = 3;
	unsigned xyz=0;
	srand(time(NULL));
	//string aux; //to do	 	//changada
	//system("clear");
	while ((mode != 0) && (mode != 1))
	{
		cout<<"----------------MENU----------------"<<endl;
		std::cout << "[0].Estadistica" << std::endl;
		std::cout << "[1].Demostracion" << std::endl;
		cout<<"En que modo desea entrar ¿? ->";
		cin>>mode;
		if((mode != 0) && (mode != 1))
		std::cout << "Introduzca una opcion soportada" << std::endl;
	}
	if(mode == 0)
	{
		cout<<"----------------Modo estadistica----------------"<<endl;

		unsigned N, P;
		cout << "\n¿Que tamaño tendrá el árbol? "; cin >> N;
     	cout << "\n¿Cuantas pruebas se harán? "; cin >> P;
     	vector<DNI> banco;
     	banco.resize(2*N);



        //INSERCIÓN
        for(int c = 0; c < 2*N; c++)
	     {
		   //srand(time(NULL)+xyz);
		   //input_val =  rand() % 30000001+50000000;
		   //tmp.setDni(input_val);
		   input_val = 00000000 + rand() % (99999999 + 1);
		   strrnd[0] = 65 + rand() % (90 - 65);
		   tmp.setDni(input_val,strrnd[0],(NameArray[rand()%10] + SurnameArray[rand()%10] + SurnameArray[rand()%10]));
		   banco[c] = tmp;
		   xyz++;
	     }
   // 	for(int c = 0; c < 2*N; c++)
   // 	{
			// num =  rand() % 9000 + 1000;
   //     	aux = to_string(num);
   //     	for(int i=0; i <= 2; i++)
   //     	{
   //     	    strrnd[i] = 65 + rand() % (90 - 65);
   //     	}
   //     	//strrnd tiene un mas 
			// aux += strrnd;
			// aux.erase(7); //con la funcion erase(), borramos los caracteres
			// banco[c] = aux ;
   // 	}
    		for(unsigned i=0;i<N;i++)
			{
				tree.insert(banco[i]);
			}
     
    	vector<int> no(2,0);				
    	vector<unsigned> max(2,0); 				
    	vector<unsigned> min(2,999999999);				
    	vector< vector<double> > cont(2,vector<double> (P,0.0));
    	vector<double> med(2,0);
    	for(unsigned k=0;k<P;k++)
    	{
    		tree.find(banco[N+rand()%(2*N+1-N)], no[1]);	//Inserción
    		tree.find(banco[rand()%(N+1)], no[0]);		//Búsqueda

    		for(int l=0;l<2;l++)		
    		{
				if(no[l]<min[l]) min[l]=no[l];
				if(no[l]>max[l]) max[l]=no[l];
				cont[l][k]=no[l];
				no[l]=0;
    		}
    	}
     
    	for(int im=0;im<2;im++)	
   		{
			for(int jm=0;jm<P;jm++)
			{
	  			med[im]+=cont[im][jm];
			}
			med[im]=(med[im]/P);
    	}
      
    	cout << setw(40) << "Número de comparaciones" << endl;
    	cout << " " <<  setw(24) << "Mínimo"; cout << setw(15) << "Medio"; cout << " " << setw(15) << "Máximo" << endl;
    	cout << "Busqueda " << setw(15) << min[0]; cout << setw(15) << med[0]; cout << setw(15) << max[0] << endl;
    	cout << "Inserción" << setw(15) << min[1]; cout << setw(15) << med[1]; cout << setw(15) << max[1] << endl;
      
	}
	else
	{

	    cout<<"----------------Modo Demostracion----------------"<<endl;
    	cout<<"Introduzca cuantos elementos desea insertar->";
	    cin >> input_sz;

	     for(int i = 0; i < input_sz; i++)
	     {
		   //srand(time(NULL)+xyz);
		   //input_val =  rand() % 30000001+50000000;
		   input_val = 00000000 + rand() % (99999999 + 1);
		   strrnd[0] = 65 + rand() % (90 - 65);
		   tmp.setDni(input_val,strrnd[0],(NameArray[rand()%10] + SurnameArray[rand()%10] + SurnameArray[rand()%10]));
		   //tmp.setDni(input_val);
		   //std::cout << "valores generados" << std::endl;
		   //std::cout << tmp << std::endl;
		   tree.insert(tmp);
		   xyz++;
	     }
	   
        //for(int c = 0; c < input_sz; c++)
        //{
			//num =  rand() % 9000 + 1000;
        	//aux = to_string(num);
        	//for(int i=0; i <= 2; i++)
        	//{
            //	strrnd[i] = 65 + rand() % (90 - 65);
        	//}
        	//aux += strrnd;
        	//aux.erase(7);
        	//tmp = aux;
            //tree.insert(tmp);
            //std::cout << tmp << std::endl;
        //}
   	    cout << "Árbol ordenado: " << endl;
	    tree.write(cout);
	    cout << endl;
	
	    while(no_salida == true)
	    {
		    switch(menu()) 
		    { 
   		        case 0:
   				        std::cout << "Saliendo del programa" << std::endl;
   				        no_salida=false;
   		                break;
   		
   		        case 1:
   			            std::cout << "------Insertar------" << std::endl;
   			            cout<<"Introduzca el valor del elemento que va a insertar ->";
			            cin >> input_val;
			            tmp.setDni(input_val);//tmp = input_val;
			            tree.insert(tmp);
   		                break;
   		
       		    case 2:
   		                std::cout << "------Mostrar------" << std::endl;
               	    	cout << "Árbol ordenado: " << endl;
                		tree.write(cout);
                		cout << endl;
                   		break;
   		
       		   case 3:
   		                std::cout << "------Profundidad------" << std::endl;
   		                cout << "Nivel máximo:"<< tree.depth() << endl;
   	    	            break;
   		
       		   case 4:
   		                std::cout << "------Borrar------" << std::endl;
   	    	            std::cout << "que elemento desea borrar ¿?->";
    		            std::cin >> input_val;
		                tmp.setDni(input_val);//tmp = input_val;
		                tree.Borrar(tmp);
		                cout<<"------Elemento eliminado------"<<endl;
	    	            tree.write(cout);
    		            cout << endl;
      	                break;
      	            
          	    case 5:
                      	system("clear");
                      	break;
      	
       		    default: 
                      	cout<<"Introduzca una opcion contemplada en el menu"<<endl;
      	                break;
		    }
	    }
    }

	return 0;
}