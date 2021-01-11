#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include "../BrazilCovid.h"
#include "OrdenacaoBase.h"

using namespace std;

class QuickSort: protected OrdenacaoBase
{
    public:
        QuickSort(){};
        ~QuickSort(){};

        void ordernar(BrazilCovid* vetor,int inicio,int fim)
        {
            if(inicio < fim)
            {
                int particao = particao(vetor,inicio,fim);
                ordernar(vetor,inicio,particao-1);
                ordernar(vetor,particao+1,fim);
            }
        }
    private:

        int particao(BrazilCovid* vetor,int inicio,int fim)
        {
            int i = inicio - 1;
            int pivo = fim;

            for(int j = inicio; j <= fim - 1; j++)
            {
                if(comparador(vetor,j,pivo))
                {
                    i++;
                    troca(vetor,i,j);
                }
            }

            troca(vetor,i+1,fim);
            return (i+1);
        }
};

#endif // QUICKSORT_H