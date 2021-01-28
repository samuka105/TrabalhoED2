#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <iostream>

#include "../BrazilCovid.h"
#include "OrdenacaoBase.h"

using namespace std;

class ShellShort: public OrdenacaoBase
{
    public:
        ShellShort()
        {
            this->resetContadores();
        }

        ~ShellShort()
        {

        }

        void ordenar(BrazilCovid* vetor,int tam)
        {
            int h = 1;
            int i,j;
            int rep = 0;

            while(h < tam)
            {
                h = h*3+1;
            }

            while(h > 1)
            {
                h /= 3;

                for(i = h; i < tam;i++)
                {
                    BrazilCovid aux = vetor[i];
                    j = i;
                    
                    while(j >= h && comparador(aux,vetor[j-j]))
                    {
                        this->aumentaNumTrocas();
                        vetor[j] = vetor[j-h];
                        j -= h;
                        rep++;
                    }

                    vetor[j] = aux;
                    this->aumentaNumTrocas();
                }
            }
        }

};

#endif // SHELLSORT_H