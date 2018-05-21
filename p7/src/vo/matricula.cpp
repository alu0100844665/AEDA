#include "matricula.hpp"

Matricula_t::Matricula_t():
    m_()
    {}
    
Matricula_t::~Matricula_t()
{}

string Matricula_t::get_m(void)
{
    return m_;
}

string Matricula_t::get_m(void) const
{
    return m_;
}

void Matricula_t::set_m(string m)
{
    m_ = m;
}

char Matricula_t::get_m_pos(int pos)
{
    return m_[pos];
}

char Matricula_t::get_m_pos(int pos) const
{
    return m_[pos];
}

bool operator==(const Matricula_t& a, const Matricula_t& b)
{
    return ((a.get_m() == b.get_m())?true:false);
}

bool operator==(const Matricula_t& a, const string& b)
{
    return ((a.get_m() == b)?true:false);
}

bool operator>(const Matricula_t& a, const Matricula_t& b)
{
    Matricula_t::contador_++;
    bool aux = 1;
    int i = 4;
    bool dummy= 0;
    bool first = 0;
    int x, y;
    while(aux)
    {
        x = a.get_m_pos(i);
        y = b.get_m_pos(i);
        if(x > y)
        {
            return 1;
        }
        else 
        {
            if(x == y)
            {
                i++;
            }
            else if(x < y)
            {
                return 0;
            }
            if(i == 2 || dummy)
            {
                if(dummy = true)
                    return 0;
                dummy = 1;
            }
            if(i == 7)
            {
                i = 0;
            }
        }
    }
    cout << "SALGO operador > " << endl;
    return 0;
}

bool operator>(const Matricula_t& a, const string& b)
{
    Matricula_t::contador_++;
    bool aux = 1;
    int i = 4;
    int x, y;
    while(aux)
    {
        x = a.get_m_pos(i);
        y = b[i];
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

bool operator<(const Matricula_t& a, const Matricula_t& b)
{
    Matricula_t::contador_++;
    bool aux = 1;
    int i = 4;
    int x, y;
    bool dummy = 0;
    //cout << "Comparacion <." << Matricula_t::contador_ << endl;
    while(aux)
    {
        x = a.get_m_pos(i);
        y = b.get_m_pos(i);
        if(x < y)
        {
            return 1;
        }
        else if(x == y || i == 2 || i == 3)
        {
            i++;
        }
        else if(x > y)
        {
            return 0;
        }
        if(i == 4)
        {
            return 0;
        }
        if(i == 7)
        {
            i = 0;
        }
    }
    return 0;
}

bool operator<(const Matricula_t& a, const string& b)
{
    Matricula_t::contador_++;
    bool aux = 1;
    int i = 4;
    int x, y;
    while(aux)
    {
        x = a.get_m_pos(i);
        y = b[i];
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

ostream& operator<<(ostream& os, const Matricula_t& a)
{
    os << a.get_m();
    return os;
}

void Matricula_t::operator=(const Matricula_t& a)
{
    m_ = a.get_m();
}
    
void Matricula_t::operator=(const string& a)
{
    m_ = a;
}

bool operator!=(const Matricula_t& a, const Matricula_t& b)
{
    bool aux = 1;
    for(int i = 0; i < a.get_m().size() && aux; i++)
    {
        if(a.get_m_pos(i) != b.get_m_pos(i))
            aux = 0;
    }
    if(aux)
        return 1;
    else
        return 0;
}

bool operator!=(const Matricula_t& a, const string& b)
{
    bool aux = 1;
    for(int i = 0; i < a.get_m().size() && aux; i++)
    {
        if(a.get_m_pos(i) != b[i])
            aux = 0;
    }
    if(aux)
        return 1;
    else
        return 0;
}