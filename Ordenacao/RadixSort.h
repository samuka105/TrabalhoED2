#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <iostream>

#include "../BrazilCovid.h"
#include "OrdenacaoBase.h"

using namespace std;

class RadixSort: public OrdenacaoBase
{

  public:
    RadixSort(){
        this->resetContadores();
    };
    ~RadixSort(){};

    void ordenar(BrazilCovid* vetor,int tam)
    {
        BrazilCovid m = getMax(vetor,tam);
        for(long long int exp = 1; m.cases/exp > 0; exp *= 10)
        {
            countSort(vetor,tam,exp);
        }
    }
private:
    BrazilCovid getMax(BrazilCovid* vetor,int tam)
    {
        BrazilCovid mx = vetor[0];
        for(int i = 1; i < tam; i++)
        {
            if(comparador(vetor[i],mx))
            {
                mx = vetor[i];
            }
        }

        return mx;
    }

    void countSort(BrazilCovid* vetor,int tam,int exp)
    {
        BrazilCovid* output = new BrazilCovid[tam];
        int* count = new int[tam];
        int i = 0;

        for(int i = 0; i < 10; i++)
        {
            count[i] = 0;
        }

        for(i = 0; i < tam; i++)
        {
            count[(vetor[i].cases/exp)%10]++;
        }

        for(i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        for(i = tam - 1; i >= 0;i--)
        {
            output[count[(vetor[i].cases/exp)%10] - 1] = vetor[i];
            count[(vetor[i].cases/exp)%10]--;
        }

        for(i = 0; i < tam; i++)
        {
            vetor[i] = output[i];
        }

        delete [] output;
    }

};

#endif // RADIXSORT_H