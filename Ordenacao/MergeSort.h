/**
 * Universidade Federal de Juiz de Fora 
 * MergeSort.h
 * Propósito: Implementação do algoritmo MergeSort
 * Fonte: https://www.geeksforgeeks.org/merge-sort/
*/
#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>

#include "../BrazilCovid.h"
#include "OrdenacaoBase.h"

using namespace std;

class MergeSort : public OrdenacaoBase
{

public:
    MergeSort()
    {
        this->resetContadores(); //Reseta os contadores garantindo que o valor inicial seja sempre zero
    };
    ~MergeSort(){};

    /**
     * Ordenação para os tipos de dados do dataset 
     * @param vetor: Vetor de Objetos
     * @param inicio: Inicio do vetor de Objetos
     * @param fim: Fim do vetor de Objetos
    */
    void ordenar(BrazilCovid *vetor, int inicio, int fim)
    {
        int meio;
        if (inicio < fim)
        {
            meio = (inicio + fim) / 2;
            ordenar(vetor, inicio, meio);
            ordenar(vetor, meio + 1, fim);
            intercala(vetor, inicio, meio, fim);
        } 
    }

private:
    /**
     * Função que realiza comparações e ordena o vetor de objetos
     * @param vetor: Vetor de Objetos
     * @param inicio: Inicio da parte do vetor de objetos que será intercalada
     * @param meio: meio da parte que será intercalada
     * @param fim: Fim da parte do vetor de objetos que será intercalada
    */
    void intercala(BrazilCovid *vetor, int inicio, int meio, int fim)
    {
        BrazilCovid aux[fim + 1];
        int inicioVetorA, inicioVetorB, livre;
        inicioVetorA = inicio;
        inicioVetorB = meio + 1;
        livre = inicio;

        while (inicioVetorA <= meio && inicioVetorB <= fim)
        {
            if (comparador(vetor[inicioVetorA], vetor[inicioVetorB]))
            {
                aux[livre] = vetor[inicioVetorA];
                aumentaNumTrocas();
                inicioVetorA++;
            }
            else
            {
                aux[livre] = vetor[inicioVetorB];
                aumentaNumTrocas();
                inicioVetorB++;
            }
            livre++;
        }

        for (int i = inicioVetorA; i <= meio; i++)
        {
            aux[livre] = vetor[i];
            aumentaNumTrocas();
            livre++;
        }

        for (int i = inicioVetorB; i <= fim; i++)
        {
            aux[livre] = vetor[i];
            aumentaNumTrocas();
            livre++;
        }

        for (int i = inicio; i <= fim; i++)
        {
            vetor[i] = aux[i];
        }

    }

    
};

#endif // MERGESORT_H