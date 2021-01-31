/**
 * Universidade Federal de Juiz de Fora 
 * HeapSort.h
 * Propósito: Implementação do algoritmo HeapSort
 * Fonte: https://pt.wikipedia.org/wiki/Heapsort
*/
#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>

#include "../BrazilCovid.h"
#include "OrdenacaoBase.h"

using namespace std;
class HeapSort : public OrdenacaoBase
{
public:
    HeapSort()
    {
        this->resetContadores(); //Reseta os contadores garantindo que o valor inicial seja sempre zero
    }
    ~HeapSort() {}

    /**
     * Ordenação para os tipos de dados do dataset 
     * @param vetor: Vetor de Objetos
     * @param n: Tamanho do Vetor de Objetos
    */
    void ordenar(BrazilCovid *vetor, int n)
    {
        int i = n / 2, pai, filho;
        BrazilCovid t;
        while (true)
        {
            if (i > 0)
            {
                i--;
                t = vetor[i];
            }
            else
            {
                n--;
                if (n <= 0)
                    return;
                t = vetor[n];
                vetor[n] = vetor[0];
                this->aumentaNumTrocas();
            }
            pai = i;
            filho = i * 2 + 1;
            while(filho < n)
            {
                if((filho + 1 < n) && (vetor[filho + 1].cases > vetor[filho].cases))
                {
                    this->aumentaNumComparacoes();
                    filho++;
                }
                if(vetor[filho].cases > t.cases)
                {
                    vetor[pai] = vetor[filho];
                    this->aumentaNumTrocas();
                    pai = filho;
                    filho = pai * 2 + 1;
                } else {
                    break;
                }
            }
            vetor[pai] = t;
            this->aumentaNumTrocas();
        }
    }
   
};

#endif //HEAPSORT