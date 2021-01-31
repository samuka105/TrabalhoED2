/**
 * Universidade Federal de Juiz de Fora 
 * QuickSort.h
 * Propósito: Implementação do algoritmo QuickSort
 * Fonte: https://www.geeksforgeeks.org/quick-sort/
*/
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>

#include "../BrazilCovid.h"
#include "OrdenacaoBase.h"

using namespace std;

class QuickSort : public OrdenacaoBase
{
public:
    QuickSort()
    {
        this->resetContadores(); //Reseta os contadores garantindo que o valor inicial seja sempre zero
    };
    ~QuickSort(){};

    /**
     * Ordenação para os tipos de dados do dataset 
     * @param vetor: Vetor de Objetos
     * @param inicio: Inicio do vetor de Objetos
     * @param fim: Fim do vetor de Objetos
    */
    void ordenar(BrazilCovid *vetor, int inicio, int fim)
    {
        if (inicio < fim)
        {
            int p = particao(vetor, inicio, fim);
            ordenar(vetor, inicio, p - 1);
            ordenar(vetor, p + 1, fim);
        }
    }

    /**
     * Ordenação para os tipos de dados do dataset antes de ser processado 
     * @param vetor: Vetor de Objetos
     * @param inicio: Inicio do vetor de Objetos
     * @param fim: Fim do vetor de Objetos
    */
    void ordenarPre(BrazilCovid *vetor, int inicio, int fim)
    {
        if (inicio < fim)
        {
            int p = particaoPre(vetor, inicio, fim);
            ordenarPre(vetor, inicio, p - 1);
            ordenarPre(vetor, p + 1, fim);
        }
    }

private:
    /**
     * Escolhe um pivo entre o inicio e o fim especificado, depois coloca todos os maiores que ele em um lado e os menores para outro
     * @param vetor: vetor a ser particionado
     * @param inicio: inicio da parte à ser particionada
     * @param fim: fim da parte à ser particionada
    */
    int particao(BrazilCovid *vetor, int inicio, int fim)
    {
        int i = inicio - 1;
        BrazilCovid pivo = vetor[(inicio + fim) / 2];

        for (int j = inicio; j <= fim - 1; j++)
        {
            if (comparador(vetor[j], pivo))
            {
                i++;
                troca(vetor, i, j);
            }
        }

        troca(vetor, i + 1, fim);
        return (i + 1);
    }

    /**
     * Escolhe um pivo entre o inicio e o fim especificado, depois coloca todos os maiores que ele em um lado e os menores para outro
     * Essa função é especifica para o dataset inicial
     * @param vetor: vetor a ser particionado
     * @param inicio: inicio da parte à ser particionada
     * @param fim: fim da parte à ser particionada
    */
    int particaoPre(BrazilCovid *vetor, int inicio, int fim)
    {
        int i = inicio - 1;
        BrazilCovid pivo = vetor[(inicio + fim) / 2];

        for (int j = inicio; j <= fim - 1; j++)
        {
            if (comparadorPre(vetor[j], pivo))
            {
                i++;
                troca(vetor, i, j);
            }
        }

        troca(vetor, i + 1, fim);
        return (i + 1);
    }

    /**
    * Recebe dois parametros, e compara para as especificações iniciais do trabalho
    * @param a item 1 da comparação
    * @param b item 2 da comparação
    */
    bool comparadorPre(BrazilCovid &a, BrazilCovid &b)
    {
        if (a.state.compare(b.state) < 0) //Exemplo: RJ < RJ
            return true;
        else if (a.state.compare(b.state) == 0 && a.name.compare(b.name) < 0) //Exemplo: RJ == RJ e Barra do Piraí < Volta Redonda
            return true;
        else if (a.state.compare(b.state) == 0 && a.name.compare(b.name) == 0 && a.date.mounth < b.date.mounth) //Exemplo: RJ == RJ e Barra do Piraí == Barra do Piraí
            return true;
        else if (a.state.compare(b.state) == 0 && a.name.compare(b.name) == 0 && a.date.mounth == b.date.mounth && a.date.day < b.date.day)
            return true;
        else
            return false;
    }
};

#endif // QUICKSORT_H