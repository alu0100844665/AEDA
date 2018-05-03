#pragma once
#include "../common_types.hpp"

using namespace std;

class Colision{
    private:
        int num_colisiones;
    public:
        Colision();
        void set_colision(int num);
        int get_num_colisiones();
};

Colision::Colision():
num_colisiones(1)
{}

void Colision::set_colision(int num)
{
    num_colisiones = num_colisiones + num; 
}
int Colision::get_num_colisiones()
{
    return num_colisiones;
}
