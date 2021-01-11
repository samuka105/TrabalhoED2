#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>
#include "../BrazilCovid.h"
#include "OrdenacaoBase.h"

using namespace std;

class SelectionSort: protected OrdenacaoBase
{

    public:
        SelectionSort(){};
        ~SelectionSort(){};

        void ordernar(BrazilCovid* vetor, int tam)
        {
            for(int i = 0; i < tam-1; i++)
            {
                int menor = i;
                for(int j = i + 1; j < tam; j++)
                {
                    if(comparador(vetor[j],vetor[menor]))
                    {
                        menor = j;
                    }
                }
                troca(vetor,i,menor);
            }
        }

};

#endif // SELECTIONSORT_H