#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include "../BrazilCovid.h"
#include "OrdenacaoBase.h"

using namespace std;

class HeapSort: protected OrdenacaoBase
{

public:
    HeapSort(){};
    ~HeapSort(){};

    void ordernar(BrazilCovid* vetor, int tam)
    {
        constroiHeap(vetor,tam);
        for(int i = tam - 1; i > 1; i--)
        {
            constroiHeap(vetor,i);
            troca(vetor,0,i);
        }
    }

private:

    void constroiHeap(BrazilCovid* vetor,int tam)
    {
        int n = tam;
        int p = (int)(n/2) - 1;
        bool flag = true; //Existe

        while(p > 1)
        {
            BrazilCovid pai = vetor[p];
            BrazilCovid filho1 = vetor[2*p];
            BrazilCovid filho2 = vetor[2*p+1];

            if(2*p+1 >= n)
            {
                flag = false;
            }

            if(comparador(filho1,filho2) && flag)
            {
                if(comparador(pai,filho2))
                {
                    troca(vetor,p,2*p+1);
                }
            } else {
                troca(vetor,p,2*p);
            }
            p--;
        }
    }


};

#endif // HEAPSORT_H