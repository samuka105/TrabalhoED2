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
        this->resetContadores();
    };
    ~QuickSort(){};

    void ordernar(BrazilCovid *vetor, int inicio, int fim)
    {
        if (inicio < fim)
        {
            int p = particao(vetor, inicio, fim);
            ordernar(vetor, inicio, p - 1);
            ordernar(vetor, p + 1, fim);
        }
    }

    void ordernarPre(BrazilCovid *vetor, int inicio, int fim)
    {
        if (inicio < fim)
        {
            int p = particaoPre(vetor, inicio, fim);
            ordernarPre(vetor, inicio, p - 1);
            ordernarPre(vetor, p + 1, fim);
        }
    }

private:
    int particao(BrazilCovid *vetor, int inicio, int fim)
    {
        int i = inicio - 1;
        int pivo = fim;

        for (int j = inicio; j <= fim - 1; j++)
        {
            if (comparador(vetor[j], vetor[pivo]))
            {
                i++;
                troca(vetor, i, j);
            }
        }

        troca(vetor, i + 1, fim);
        return (i + 1);
    }

    int particaoPre(BrazilCovid *vetor, int inicio, int fim)
    {
        int i = inicio - 1;
        int pivo = fim;

        for (int j = inicio; j <= fim - 1; j++)
        {
            if (comparadorPre(vetor[j], vetor[pivo]))
            {
                i++;
                troca(vetor, i, j);
            }
        }

        troca(vetor, i + 1, fim);
        return (i + 1);
    }

    bool comparadorPre(BrazilCovid &a, BrazilCovid &b)
    {
        if (a.state.compare(b.state) < 0) //RJ < SP
            return true;
        else if (a.state.compare(b.state) == 0 && a.name.compare(b.name) < 0) //RJ == RJ e Barra do Piraí < Volta Redonda
            return true;
        else if (a.state.compare(b.state) == 0 && a.name.compare(b.name) == 0 && a.date.mounth < b.date.mounth) //RJ == RJ e Barra do Piraí == Barra do Piraí
            return true;
        else if (a.state.compare(b.state) == 0 && a.name.compare(b.name) == 0 && a.date.mounth == b.date.mounth && a.date.day < b.date.day)
            return true;
        else
            return false;
    }
};

#endif // QUICKSORT_H