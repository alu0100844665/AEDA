#include "../common_types.hpp"

template <class T>
void shake_sort (vector<T>& secuencia, int tam, int& contador,int opt)
{
    int ini = 1;
    int fin = tam -1;
    int cam = tam;     //variable auxiliar para guardar los valores de ini y fin
    T x;                //variable para el intercambio
    bool aux = 1;
    while(ini < fin)
    {
        for(int j = fin; j >= ini; j--)
        {   
            if(secuencia[j] < secuencia[j-1])
            {
                if(opt==1)
                {
                    for(int i=0;i<tam;i++)
                    {
                        if(i == j || i == (j-1))
                            cout << secuencia[i] << '*' << "  ";
                        else
                            cout << secuencia[i] << "  ";
                    }
                    cout<< endl;
                    getchar();
                }
                contador++;
                x = secuencia[j-1];
                secuencia[j-1] = secuencia[j];
                secuencia[j] = x;
                cam = j;
            }
        }
        ini = cam +1;
        for(int j = ini; j <= fin; j++)
        {
            if(opt==1)
            {
                for(int i=0;i<tam;i++)
                {
                    if(i == j || i == (j-1))
                        cout << secuencia[i] << '*' << "  ";
                    else
                        cout << secuencia[i] << "  ";
                }
                cout<< endl;
                getchar();
            }
            if(secuencia[j] < secuencia[j-1])
            {
                x = secuencia[j-1];
                secuencia[j-1] = secuencia[j];
                secuencia[j] = x;
                cam = j;
            }
            contador++;
        }
        fin = cam-1;
    }
}

template <class T>
void Mezcla(vector<T>& secuencia, int ini, int cen, int fin, int& contador,int opt)
{
    T aux[secuencia.size()];
    int i = ini;
    int j = cen+1;
    int k = ini;
    while ((i <= cen) && (j <= fin))
    {
        if(opt==1)
        {
            for(int l=0;l<secuencia.size();l++)
            {
                if(l == i || l == j)
                    cout << secuencia[l] << '*' << "  ";
                else
                    cout << secuencia[l] << "  ";
            }
            cout<< endl;
            getchar();
        }
        if(secuencia[i] < secuencia[j])
        {
            aux[k] = secuencia[i];
            i++;
        }
        else
        {
            aux[k] = secuencia[j];
            j++;
        }
        k++;
        contador++;
    }
    if(i > cen)
    while(j <= fin)
    {
        aux[k] = secuencia[j];
        j++;
        k++;
    }
    else
    while(i <= cen)
    {
        aux[k] = secuencia[i];
        i++;
        k++;
    }
    for(int k = ini; k <= fin; k++)
    secuencia[k] = aux[k];
}

template <class T>
void Msort(vector<T>& secuencia, int ini, int fin, int& contador,int opt)
{
    if(ini < fin)
    {
        int cen = (ini + fin) / 2;
        Msort(secuencia, ini, cen, contador,opt);
        Msort(secuencia, cen +1, fin, contador,opt);
        Mezcla(secuencia, ini, cen, fin, contador,opt);
    }
}

template <class T>
void seleccion(vector<T>& secuencia, int tam, int& contador,int opt)
{
    int min = 0;
    T change;
    for(int i = 0; i < (secuencia.size() -1); i++)
    {
        min = i;
        for(int j = (min +1); j < secuencia.size(); j++)
        {
             if(opt==1)
            {
                for(int l=0;l<secuencia.size();l++)
                {
                    if(l == min || l == j)
                        cout << secuencia[l] << '*' << "  ";
                    else
                        cout << secuencia[l] << "  ";
                }
                cout<< endl;
                getchar();
            }
            if(secuencia[min] > secuencia[j])
            min = j;
            contador++;
        }
        change = secuencia[i];
        secuencia[i] = secuencia[min];
        secuencia[min] = change;
        
    }
}

template <class T>
void insertion(vector<T>& secuencia, int tam, int& contador,int opt)
{
    int j=0;
    T aux;
    //bucle que recorre la parte ordenada
    for(int i=1;i<secuencia.size();i++)
    {
        aux=secuencia[i];
        j=0;
        //Buscamos la pos en la que va aux
        while(aux>secuencia[j] && (j <= i))
        {
            contador++;
            j++;
        }
        //desplazamos desde j hasta i de forma descendente
        for(int k =i-1;k>=j;k--)
        {
            if(opt==1)
            {
                for(int l=0;l<secuencia.size();l++)
                {
                    if(secuencia[l] == aux || l == j)
                        cout << secuencia[l] << '*' << "  ";
                    else
                        cout << secuencia[l] << "  ";
                }
                cout<< endl;
                getchar();
            }
            contador++;
            secuencia[k+1]=secuencia[k];
        }
        //metemos a aux en su lugar
        secuencia[j]=aux;
    }
}

template <class T>
void Qsort(vector<T>& secuencia, int ini, int fin, int& contador,int opt)
{
    T x;
    int i = ini;
    int f = fin;
    T p = secuencia[((i+f)/2)];
    while(i <= f)
    {
        while(secuencia[i] < p)
        {
            if(opt==1)
            {
                for(int l=0;l<secuencia.size();l++)
                {
                    if(l == i || secuencia[l] == p)
                        cout << secuencia[l] << '*' << "  ";
                    else
                        cout << secuencia[l] << "  ";
                }
                cout<< endl;
                getchar();
            }
            i++;
            contador++;
        }
        while(secuencia[f] > p)
        {
            f--;
            contador++;
        }
        if (i <= f)
        {
            x = secuencia[i];
            secuencia[i] = secuencia[f];
            secuencia[f] = x;
            i++;
            f--;
        }
    }
    if(ini < f) Qsort(secuencia,ini,f,contador,opt);
    if(i < fin) Qsort(secuencia,i,fin,contador,opt);
}

template <class T>
void ShellSort(vector<T>& secuencia, int ini, int fin, int& contador,int opt)
{
	T temp;
	int i, j;
	for (int k = fin / 2; k > 0; k = k/2){
		for (i =  k-1; i < fin; i ++){
			temp = secuencia[i];
			for (j = i; j > k-1 && secuencia[j - k] > temp; j = j-k)
			{
			    if(opt==1)
                {
                    for(int l=0;l<secuencia.size();l++)
                    {
                        if(secuencia[l] == secuencia[j - k] ||secuencia[l] == temp)
                            cout << secuencia[l] << '*' << "  ";
                        else
                            cout << secuencia[l] << "  ";
                    }
                    cout << endl;
                    getchar();
                }
			    contador++;
				secuencia[j] = secuencia[j - k];
			}
			contador++;
			secuencia[j] = temp;
		}
	} 
}
template <class T>
void bublesort(vector<T>& secuencia, int fin, int& contador,int opt)
{
    T x;
    for(int i=1;i<fin;i++)
    {
        for(int j=fin-1;j>=i;j--)
        {
            if(opt==1)
            {
                for(int l=0;l<secuencia.size();l++)
                {
                    if(secuencia[l] == secuencia[j] ||secuencia[l] == secuencia[j-1])
                        cout << secuencia[l] << '*' << "  ";
                    else
                        cout << secuencia[l] << "  ";
                }
                cout << endl;
                getchar();
            }
            
            contador++;
            if(secuencia[j]<secuencia[j-1])
            {
                x = secuencia[j-1];
                secuencia[j-1]=secuencia[j];
                secuencia[j]=x;
            }
        }
    }
}