#pragma once

#include "../common_types.hpp"

using namespace std;

class Matricula_t
{
    private:
        string m_;
    public:
        string get_m(void)
        {
            return m_;
        }
        void set_m(string m)
        {
            m_ = m;
        }
        char get_m_pos(int pos)
        {
            return m_[pos];
        }
        friend bool operator==(Matricula_t& a, Matricula_t& b)
        {
            return ((a.get_m() == b.get_m())?true:false);
        }
        friend bool operator>(Matricula_t& a, Matricula_t& b)
        {
            bool aux = 1;
            int i = 4;
            int x, y;
            while(aux)
            {
                x = a.get_m_pos(i);
                y = b.get_m_pos(i);
                if(x > y)
                    return 1;
                else if(x == y)
                    i++;
                else if(x < y)
                    return 0;
                if(i == 3)
                    return 0;
                if(i == 6)
                    i = 0;
            }
            return 0;
        }
        friend bool operator<(Matricula_t& a, Matricula_t& b)
        {
            bool aux = 1;
            int i = 4;
            int x, y;
            while(aux)
            {
                x = a.get_m_pos(i);
                y = b.get_m_pos(i);
                if(x < y)
                    return 1;
                else if(x == y)
                    i++;
                else if(x > y)
                    return 0;
                if(i == 3)
                    return 0;
                if(i == 6)
                    i = 0;
            }
            return 0;
        }
        friend ostream& operator<<(ostream& os, Matricula_t& a)
        {
            os << a.m_;
            return os;
        }
        
        void operator=(const Matricula_t& a)
        {
            m_ = a.m_;
        }
        
        void operator =(const string& a)
        {
            m_ = a;
        }
        
        friend bool operator!=(Matricula_t& a, Matricula_t& b)
        {
            bool aux = 1;
            for(int i = 0; i < a.m_.size() && aux; i++)
            {
                if(a.m_[i] != b.m_[i])
                    aux = 0;
            }
            if(aux)
                return 1;
            else
                return 0;
        }
};