/**
 * Universidade Federal de Juiz de Fora 
 * RadixSort.h
 * Propósito: Implementação do algoritmo QuickSort
 * Fonte: https://pt.wikipedia.org/wiki/Radix_sort
*/
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
        this->resetContadores(); //Reseta os contadores garantindo que o valor inicial seja sempre zero
    };
    ~RadixSort(){};

      /**
     * Ordenação para os tipos de dados do dataset 
     * @param vetor: Vetor de Objetos
     * @param tam: Tamanho do vetor de Objetos
    */
    void ordenar(BrazilCovid* vetor,int tam)
    {
        BrazilCovid m = getMax(vetor,tam);
        for(long long int exp = 1; m.cases/exp > 0; exp *= 10)
        {
            countSort(vetor,tam,exp);
        }
    }
private:

    /**
     * Obtem o maior valor em um vetor
     * @param vetor: vetor
     * @param tam: tamanho do vetor
     * @return maior valor
     */
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

     /**
     * Função que realiza o countsort para o digito atual no exp
     * @param vetor: vetor a ser ordenado
     * @param tam: tamanho do vetor
     * @param exp: digito atual sendo ordenado
     */
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