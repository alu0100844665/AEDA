#pragma once

#include <cassert>
#include <iostream>
#include <cstdio>
//#include "colision.hpp"
using namespace std;

template <class T>
class tree_node_t {
    private:
        tree_node_t<T>* left_;
        tree_node_t<T>* right_;
		//Colision colision_;
		int num_colisiones;
		T data_;

    public:
        tree_node_t();
		tree_node_t(const T& data);

        virtual ~tree_node_t(void);

		void set_left (tree_node_t<T>*);
		void set_right(tree_node_t<T>*);

		tree_node_t<T>*& get_left(void);
		tree_node_t<T>*& get_right(void);

		tree_node_t<T>* get_left(void) const;
		tree_node_t<T>* get_right(void) const;

		void set_data(const T& data);
		T get_data(void) const;
		void set_colision(int num);
		void pop_colision(int num);
        int get_num_colisiones();
		//Colision get_colision(void);
};


template <class T>
tree_node_t<T>::tree_node_t():
    left_(NULL),
    right_(NULL),
    data_(),
    num_colisiones(1)
    {}

template <class T>
tree_node_t<T>::tree_node_t(const T& data):
    left_(NULL),
    right_(NULL),
    data_(data),
    num_colisiones(1)
    {}

template <class T>
tree_node_t<T>::~tree_node_t(void)
{
    left_ = NULL;
    right_ = NULL;
}

template <class T>
void tree_node_t<T>::set_left(tree_node_t<T>* left)
{
	left_ = left;
}

template <class T>
tree_node_t<T>* tree_node_t<T>::get_left(void) const
{
	return left_;
}

template <class T>
tree_node_t<T>*& tree_node_t<T>::get_left(void)
{
	return left_;
}

template <class T>
void tree_node_t<T>::set_right(tree_node_t<T>* right)
{
	right_ = right;
}

template <class T>
tree_node_t<T>* tree_node_t<T>::get_right(void) const
{
	return right_;
}

template <class T>
tree_node_t<T>*& tree_node_t<T>::get_right(void)
{
	return right_;
}

template <class T>
void tree_node_t<T>::set_data(const T& data)
{
	data_ = data;
}

template <class T>
T tree_node_t<T>::get_data(void) const
{
	return data_;
}
template <class T>
void tree_node_t<T>::set_colision(int num)
{
    num_colisiones = num_colisiones + num; 
}
template <class T>
void tree_node_t<T>::pop_colision(int num)
{
    num_colisiones = num_colisiones - num; 
}
template <class T>
int tree_node_t<T>::get_num_colisiones()
{
    return num_colisiones;
}
// template <class T>
// Colision tree_node_t<T>::get_colision(void)
// {
// 	return colision_;
// }