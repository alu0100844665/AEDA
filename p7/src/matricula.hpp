#pragma once

#include <string>
#include <iostream>

using namespace std;

class Matricula_t
{
    private:
        string m_;
    
    public:
        Matricula_t(void);
        ~Matricula_t(void);	
        
        string get_m(void);
        string get_m(void) const;
        
        char get_m_pos(int pos);
        char get_m_pos(int pos) const;
        
        void set_m(string m);
        
        friend bool operator==(const Matricula_t& a, const Matricula_t& b);
        friend bool operator==(const Matricula_t& a, const string& b);
        
        friend bool operator!=(const Matricula_t& a, const Matricula_t& b);
        friend bool operator!=(const Matricula_t& a, const string& b);
        
        friend bool operator>(const Matricula_t& a, const Matricula_t& b);
        friend bool operator>(const Matricula_t& a, const string& b);
        
        friend bool operator<(const Matricula_t& a, const Matricula_t& b);
        friend bool operator<(const Matricula_t& a, const string& b);
        
        friend ostream& operator<<(ostream& os, const Matricula_t& a);

        void operator=(const Matricula_t& a);
        void operator=(const string& a);
        
        static int contador_;
        
};