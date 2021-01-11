#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <iostream>
#include "../BrazilCovid.h"
#include "OrdenacaoBase.h"

using namespace std;

class InsertionSort: protected OrdenacaoBase{

public: 
    InsertionSort(){};
    ~InsertionSort(){};

    void ordernar(BrazilCovid* vetor, int tam)
    {
        for(int i = 0; i < tam; i++)
        {
            BrazilCovid pivo = vetor[i];
            int j = i - 1;
            while( j >= 0 && comparador(vetor[j],pivo))
            {
                troca(vetor,j+1,j);
                j--;
            }
            vetor[j+1] = pivo;
        }
    }

};


#endif // INSERTIONSORT_H