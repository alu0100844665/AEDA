#pragma once
#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include "vo/arbol_binario_nodo.hpp"



using namespace std;

template <class T>
class tree_t 
{
    private:
        tree_node_t<T>* root_;

    public:
        tree_t(void);
        ~tree_t(void); 

		void insert(const T& data);
		tree_node_t<T>*& find(const T& data,int &contador);

        bool empty(void) const;

        ostream& write(ostream& os) const;
        void Borrar(T dat);
        bool Vacio(tree_node_t<T> *r) { return r==NULL; }
        int depth(void);
        
	private:
		tree_node_t<T>*& find(tree_node_t<T>*& root, const T& data , int &contador);

		ostream& write(const T& dada, ostream& os) const;
		int output_size(void) const;

		ostream& write(tree_node_t<T>* root, ostream& os, int n) const;

		bool igual(const T& a, const T& b) const;
		bool menor(const T& a, const T& b) const;
		bool is_sheet(tree_node_t<T>* root);

		void clean(tree_node_t<T>*& root);
};


template <class T>
tree_t<T>::tree_t(void) :
    root_(NULL){}

template <class T>
tree_t<T>::~tree_t(void)
{
    clean(root_);
}

template <class T>
void tree_t<T>::clean(tree_node_t<T>*& root)
{
	if (root != NULL)
	{
		clean(root->get_left());
		clean(root->get_right());

		delete root;
		root = NULL;
	}
}	

template <class T>
bool tree_t<T>::empty(void) const
{
	if (root_ == NULL)
	   return true;
	else 
	   return false;
}

template <class T>
tree_node_t<T>*& tree_t<T>::find(const T& data,int &contador)
{
	return find(root_, data,contador);
}

template <class T>
void tree_t<T>::insert(const T& data) 
{
	int i=0;
	tree_node_t<T>*& found = find(root_, data,i);

	if (found != NULL)
		cerr << "Elemento existente" << endl;
	else
		found = new tree_node_t<T>(data);
}

template <class T>
bool tree_t<T>::igual(const T& a, const T& b) const
{
	if(a == b)
	return true;
	else
	return false;
	//return a == b;
}

template <class T>
bool tree_t<T>::menor(const T& a, const T& b) const
{
	if(a < b)
	return true;
	else
	return false;
	//return a < b;
}


template <class T>
tree_node_t<T>*& tree_t<T>::find(tree_node_t<T>*& root, const T& data,int &contador)
{
	contador++;
	if (root == NULL)
		return root;
	else
	{
		if (igual(root->get_data(), data))
			return root;
		else
		{
			if (menor(data, root->get_data()))
				return find(root->get_left(), data,contador);
			else
				return find(root->get_right(), data,contador);
		}
	}
}

template <class T>
bool tree_t<T>::is_sheet(tree_node_t<T>* root)
{
	if(root->get_left()==NULL && root->get_right()==NULL)
	    return true;
	else
    	return false;
}

template <class T>
int tree_t<T>::output_size(void) const 
{
	return 4;
}

template <class T>
ostream& tree_t<T>::write(const T& data, ostream& os) const
{
	os << setw(output_size()) << data;
	return os;
}


template <class T>
ostream& tree_t<T>::write(ostream& os) const 
{
	int n=0;
	write(root_, os , n);
	return os;
}	

//------------------------------- printar---------------------------------
template <class T>
ostream& tree_t<T>::write(tree_node_t<T>* root, ostream& os,int n) const 
{
    std::queue<tree_node_t<T>*> cola;
    if(root_ != NULL)
    	cola.push(root_);
    else
    	cout<<"[.]";
    int i=1;
    int j=1;
    tree_node_t<T> *aux;
    while(!cola.empty())
    {
    	cout << "Nivel " << j++ << ": ";
    	for(int c=0; c<i; c++)
		{
			if(cola.empty())
			{
				break;
			}
			cout<<" ";
			aux = cola.front();
			cola.pop();
			if(aux==NULL)
			{
				cout<<"[.]";
			}
			else
			{
				cout << "[" << aux->get_data().getDni() <<aux->get_data().getDniLetra()<<" "<<aux->get_data().getDniNombre()<< "]";//cout << "[" << aux->get_data() << "]";
				cola.push(aux->get_left());
				cola.push(aux->get_right());
			}

		}
		i = cola.size();
		cout<<endl;
    }
	return os;
}
template <class T>
int tree_t<T>::depth(void)
{
	std::queue<tree_node_t<T>*> cola;
    if(root_ != NULL)
    	cola.push(root_);
    else
    	return 0;
    int i=1;
    int j=0;
    tree_node_t<T> *aux;
    while(!cola.empty())
    {
    	j++;
    	for(int c=0; c<i; c++)
		{
			if(cola.empty())
			{
				break;
			}
			aux = cola.front();
			cola.pop();
			if(aux != NULL)
			{
				cola.push(aux->get_left());
				cola.push(aux->get_right());
			}

		}
		i = cola.size();
    }
	return j;	
}
//---------------------------------Borrar con desplazamiento-----------------------------------
template <class T>
void tree_t<T>::Borrar(T dat) 
{
	tree_node_t<T> *padre = NULL;
	tree_node_t<T> *nodo;
	tree_node_t<T> *actual;
	T aux;
    actual = root_;
    
    if(dat == root_->get_data() && is_sheet(root_))
    	root_=NULL;
    else
    {
    	while(!Vacio(actual))
    	{
        	if(dat == actual->get_data())
        	{
            	if(is_sheet(actual))
            	{
                	if(padre)
                	if(padre->get_right() == actual) padre->set_right(NULL);
                	else if(padre->get_left() == actual) padre->set_left(NULL);
                	delete actual;
                	actual = NULL;
            	  	return;
            	}
	            else
    	        {
        	        padre = actual;
            	    if(actual->get_right())
                	{
	                    nodo = actual->get_right();
    	                while(nodo->get_left())
        	            {
            	            padre = nodo;
                	        nodo = nodo->get_left();
	                   	}
    	            }

	                else
    	            {
        	            nodo = actual->get_left();
            	        while(nodo->get_left())
                	    {
                    	    padre = nodo;
                        	nodo = nodo->get_right();
	                    }
    	            }
	
    	            aux = actual->get_data();
        	        actual->set_data(nodo->get_data());
            	    nodo->set_data(aux);
                	actual = nodo;
	            }
    	    }
        	else
	        {
    	        padre = actual;
        	    if(dat > (actual->get_data())) actual = actual->get_right();
            	else if(dat < (actual->get_data())) actual = actual->get_left();
	        }
    	}
	}
}