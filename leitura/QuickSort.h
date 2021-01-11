#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>
#include "../BrazilCovid.h"

using namespace std;

class QuickSort
{
public:
    QuickSort(BrazilCovid *vet, int left, int right)
    {
        QQuickSort(vet, left, right);
    }

    int particao(BrazilCovid *vet, int left, int right)
    {
        int i = left - 1;
        BrazilCovid pivo = vet[right];

        for(int j = left; j <= right - 1;j++)
        {
            if(compare(vet[j],pivo))
            {
                i++;
                swap(vet[i],vet[j]);
            }
        }

        swap(vet[i+1],vet[right]);
        return (i+1);
    }

    void QQuickSort(BrazilCovid *vet, int left, int right)
    {
       if(left < right)
       {
           int p = particao(vet,left,right);
           QQuickSort(vet,left,p-1);
           QQuickSort(vet,p+1,right);
       }
    }

    bool compare(BrazilCovid &a, BrazilCovid &b)
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