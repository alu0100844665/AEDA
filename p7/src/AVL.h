#include "ABB.h"
#pragma once


template <class T>
class AVL: public ArbolBB<T>
{
	public:

		AVL();
		~AVL();

		//ROTACIONES
		void rotacion_II(nodoAVL<T>* &nodo);
		void rotacion_DD(nodoAVL<T>* &nodo);
		void rotacion_ID(nodoAVL<T>* &nodo);
		void rotacion_DI(nodoAVL<T>* &nodo);

		//INSERTAR.
		void Insertar(T clave_dada);
		void Insertar_bal(nodoAVL<T>* &nodo, nodoAVL<T>* nuevo, bool& crece);
		void insertar_re_balancea_izda(nodoAVL<T>* &nodo, bool& crece);
		void insertar_re_balancea_dcha(nodoAVL<T>* &nodo, bool& crece);
		void caso_menos1_izda(nodoAVL<T>* &nodo, bool &crece);
		void caso_cero_izda(nodoAVL<T>* &nodo);
		void caso_1_izda(nodoAVL<T>* &nodo, bool &crece);
		void caso_menos1_dcha(nodoAVL<T>* &nodo, bool &crece);
		void caso_1_dcha(nodoAVL<T>* &nodo, bool &crece);

		//ELIMINAR
		void Eliminar(T clave_dada);
		void elimina_rama(nodoAVL<T>* &nodo, T dato, bool& decrece);
		void eliminar_re_balancea_izda(nodoAVL<T>* &nodo, bool &decrece);
		void eliminar_re_balancea_dcha(nodoAVL<T>* &nodo, bool &decrece);
		void caso_menos1_re_izda(nodoAVL<T>* &nodo, bool &decrece);
		void caso_cero_re_izda(nodoAVL<T>* &nodo, bool &decrece);
		void caso_1_re_dcha(nodoAVL<T>* &nodo, bool &decrece);
		void caso_cero_re_dcha(nodoAVL<T>* &nodo, bool &decrece);
		//SUSTITUYE
		void sustituye(nodoAVL<T>* &eliminado, nodoAVL<T>* &sust, bool &decrece);
};


//IMPLEMENTACIONES

//Constructor
template <class T>
AVL<T>::AVL(): ArbolBB<T>::ArbolBB() {}

//Destructor
template <class T>
AVL<T>::~AVL(){}



//ROTACIONES
template <class T>
void AVL<T>::rotacion_II(nodoAVL<T>* &nodo)
{

    nodoAVL<T>* nodo1=nodo->get_izdo();
    nodo->set_izdo(nodo1->get_dcho());
    nodo1->set_dcho(nodo);
    if(nodo1->get_bal()==1)
    {
        nodo->set_bal(0);
        nodo1->set_bal(0);
    }
    else
    {
        nodo->set_bal(1);
        nodo1->set_bal(-1);
    }
    nodo=nodo1;
}

template <class T>
void AVL<T>::rotacion_DD(nodoAVL<T>* &nodo)
{

    nodoAVL<T>* nodo1=nodo->get_dcho();
    nodo->set_dcho(nodo1->get_izdo());
    nodo1->set_izdo(nodo);
    if(nodo1->get_bal()==-1)
    {
        nodo->set_bal(0);
        nodo1->set_bal(0);
    }
    else
    {
        nodo->set_bal(-1);
        nodo1->set_bal(1);
    }
  nodo=nodo1;
}

template <class T>
void AVL<T>::rotacion_ID(nodoAVL<T>* &nodo)
{
    nodoAVL<T>* nodo1=nodo->get_izdo();
    nodoAVL<T>* nodo2=nodo1->get_dcho();
    nodo->set_izdo(nodo2->get_dcho());
    nodo2->set_dcho(nodo);
    nodo1->set_dcho(nodo2->get_izdo());
    nodo2->set_izdo(nodo1);
    if(nodo2->get_bal()==-1)
        nodo1->set_bal(1);
    else
        nodo1->set_bal(0);
    if(nodo2->get_bal()==1)
        nodo->set_bal(-1);
    else
        nodo->set_bal(0);
    nodo2->set_bal(0);
    nodo=nodo2;
}

template <class T>
void AVL<T>::rotacion_DI(nodoAVL<T>* &nodo)
{
    nodoAVL<T>* nodo1=nodo->get_dcho();
    nodoAVL<T>* nodo2=nodo1->get_izdo();
    nodo->set_dcho(nodo2->get_izdo());
    nodo2->set_izdo(nodo);
    nodo1->set_izdo(nodo2->get_dcho());
    nodo2->set_dcho(nodo1);
    if(nodo2->get_bal()==1)
        nodo1->set_bal(-1);
    else
        nodo1->set_bal(0);
    if(nodo2->get_bal()==-1)
        nodo->set_bal(1);
    else
        nodo->set_bal(0);
    nodo2->set_bal(0);
    nodo=nodo2;
}


//INSERTAR.
template <class T>
void AVL<T>::Insertar(T clave_dada)
{
    nodoAVL<T>* nuevo= new nodoAVL<T> (clave_dada);
    bool crece=false;
    Insertar_bal(ArbolBB<T>::raiz,nuevo,crece);
}

template <class T>
void AVL<T>::Insertar_bal(nodoAVL<T>* &nodo, nodoAVL<T>* nuevo, bool& crece)
{
    if(nodo==NULL)
    {
        nodo=nuevo;
        crece=true;
    }
    else if(nuevo->get_clave() < (nodo->get_clave()))
    {
        Insertar_bal(nodo->get_izdo(),nuevo,crece);
        if(crece)
            insertar_re_balancea_izda(nodo,crece);
    }
    else
    {
        Insertar_bal(nodo->get_dcho(),nuevo,crece);
        if(crece)
          insertar_re_balancea_dcha(nodo,crece);
    }
}
template <class T>
void AVL<T>::caso_menos1_izda(nodoAVL<T>* &nodo, bool &crece)
{
	nodo->set_bal(0);
	crece = false;

}
template <class T>
void AVL<T>::caso_1_izda(nodoAVL<T>* &nodo, bool &crece)
{
	nodoAVL<T>* nodo1 = nodo->get_izdo();
	if(nodo1->get_bal()==1)
		rotacion_II(nodo);
	else
		rotacion_ID(nodo);
	crece=false;
}
template <class T>
void AVL<T>::insertar_re_balancea_izda(nodoAVL<T>* &nodo, bool &crece)
{
    switch(nodo->get_bal())
    {
        case -1:
						caso_menos1_izda(nodo,crece);
        		break;
        case 0:
						nodo->set_bal(1);
        		break;
        case 1:
						caso_1_izda(nodo,crece);
						break;
				default:
						std::cerr << "/* error message */" << '\n';
    }

}
template <class T>
void AVL<T>::caso_menos1_dcha(nodoAVL<T>* &nodo, bool &crece)
{
	nodoAVL<T>* nodo1=nodo->get_dcho();
	if(nodo1->get_bal()==-1)
		rotacion_DD(nodo);
	else
		rotacion_DI(nodo);
	crece=false;

}
template <class T>
void AVL<T>::caso_1_dcha(nodoAVL<T>* &nodo, bool &crece)
{
	nodo->set_bal(0);
	crece=false;
}
template <class T>
void AVL<T>::insertar_re_balancea_dcha(nodoAVL<T>* &nodo, bool &crece)
{
    switch(nodo->get_bal())
    {
        case 1:
					caso_1_dcha(nodo,crece);
					break;
        case 0:
            nodo->set_bal(-1);
        		break;
        case -1:
						caso_menos1_dcha(nodo,crece);
						break;
				default:
						std::cerr << "/* error message */" << '\n';
    }
}

//ELIMINAR
template <class T>
void AVL<T>::Eliminar(T clave_dada)
{
    bool decrece=false;
    elimina_rama(ArbolBB<T>::raiz,clave_dada,decrece);
}

template <class T>
void AVL<T>::elimina_rama(nodoAVL<T>* &nodo, T clave_dada, bool& decrece)
{
    if(nodo==NULL)
        return;
    if(clave_dada<nodo->get_clave())
    {
        elimina_rama(nodo->get_izdo(),clave_dada,decrece);
    		if(decrece)
        	eliminar_re_balancea_izda(nodo,decrece);
    }
    else if(clave_dada>nodo->get_clave())
    {
        elimina_rama(nodo->get_dcho(),clave_dada,decrece);
    		if(decrece)
        	eliminar_re_balancea_dcha(nodo,decrece);
    }
    else
    {
        nodoAVL<T>* Eliminado=nodo;
        if(nodo->get_izdo()==NULL)
        {
            nodo=nodo->get_dcho();
            decrece=true;
        }
        else if(nodo->get_dcho()==NULL)
        {
            nodo=nodo->get_izdo();
            decrece=true;
        }
        else
        {
            sustituye(Eliminado,nodo->get_izdo(),decrece);
            if(decrece)
            	eliminar_re_balancea_izda(nodo,decrece);
        }
        delete Eliminado;
    }
}
template <class T>
void AVL<T>::caso_menos1_re_izda(nodoAVL<T>* &nodo, bool &decrece)
{
	nodoAVL<T>* nodo1=nodo->get_dcho();
	if(nodo1->get_bal()>0)
		rotacion_DI(nodo);
	else
	{
		if(nodo1->get_bal()==0)
			decrece=false;
		rotacion_DD(nodo);
	}
}
template <class T>
void AVL<T>::caso_cero_re_izda(nodoAVL<T>* &nodo, bool &decrece)
{
	nodo->set_bal(-1);
	decrece=false;
}
template <class T>
void AVL<T>::eliminar_re_balancea_izda(nodoAVL<T>* &nodo, bool &decrece)
{
    switch(nodo->get_bal())
    {
        case -1:
						caso_menos1_re_izda(nodo,decrece);
            break;
        case 0:
						caso_cero_re_izda(nodo,decrece);
            break;
        case 1:
            nodo->set_bal(0);
						break;
				default:
					std::cerr << "/* error */" << '\n';
    }
}

template <class T>
void AVL<T>::caso_1_re_dcha(nodoAVL<T>* &nodo, bool &decrece)
{
	nodoAVL<T>* nodo1=nodo->get_izdo();
	if(nodo1->get_bal()>0)
		rotacion_ID(nodo);
	else
	{
		if(nodo1->get_bal()==0)
			decrece=false;
		rotacion_II(nodo);
	}
}
template <class T>
void AVL<T>::caso_cero_re_dcha(nodoAVL<T>* &nodo, bool &decrece)
{
	nodo->set_bal(1);
	decrece=false;
}
template <class T>
void AVL<T>::eliminar_re_balancea_dcha(nodoAVL<T>* &nodo, bool &decrece)
{
    switch(nodo->get_bal())
    {
        case 1:
						caso_1_re_dcha(nodo,decrece);
            break;
        case 0:
						caso_cero_re_dcha(nodo,decrece);
            break;
        case -1:
            nodo->set_bal(0);
						break;
				default:
						std::cerr << "/* error */" << '\n';
    }
}

//SUSTITUYE
template <class T>
void AVL<T>::sustituye(nodoAVL<T>* &eliminado, nodoAVL<T>* &sust, bool &decrece)
{
    if(sust->get_dcho()!=NULL)
    {
        sustituye(eliminado,sust->get_dcho(),decrece);
        if(decrece)
            eliminar_re_balancea_dcha(sust,decrece);
    }
    else
    {
        eliminado->set_clave(sust->get_clave());  //Mirar lo de dato.
        eliminado=sust;
        sust=sust->get_izdo();
        decrece=true;
    }
}
