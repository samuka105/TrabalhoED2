#ifndef LEITOR2_H
#define LEITOR2_H

#include "../Leitura/LeitorBase.h"
#include "../Leitura/LeitorCovid.h"
#include "../Leitura/Log.h"

#include "../Ordenacao/MergeSort.h"
#include "../Ordenacao/QuickSort.h"
#include "../Ordenacao/RadixSort.h"

using namespace std;

class Etapa2 : public LeitorBase
{
public:
    Etapa2()
    {
        n = 500000;
        LeitorCovid *leitor = new LeitorCovid("brazil_covid19_cities_processado.csv");
        leitor->numRegistros(n);
        leitor->leituraPosProcessado();
        data = leitor->getDataset();
        delete leitor;
    };
    ~Etapa2(){};

    void realizaTestes()
    {
        double tempo;
        BrazilCovid *copiaLocal;

        /*copiaLocal = copiaVetor(data, n);
        timerStart();
        MergeSort *merge = new MergeSort();
        merge->ordernar(copiaLocal, 0, n - 1);
        tempo = timerEnd();
        cout << "MERGESORT, em " << tempo << " segundos" << endl;
        cout << "NUM TROCAS " << merge->getNumTrocas() << " NUM COMPARACOES " << merge->getNumComparacoes() << endl;

        delete[] copiaLocal;*/

        copiaLocal = copiaVetor(data, n);
        timerStart();
        QuickSort *quick = new QuickSort();
        quick->ordernar(copiaLocal, 0, n - 1);
         tempo = timerEnd();
        cout << "QUICKSORT, em " << tempo << " segundos" << endl;
        cout << "NUM TROCAS " << quick->getNumTrocas() << " NUM COMPARACOES " << quick->getNumComparacoes() << endl;

        delete[] copiaLocal;

        copiaLocal = copiaVetor(data, n);
        timerStart();
        RadixSort *radix = new RadixSort();
        radix->ordernar(copiaLocal, n);
         tempo = timerEnd();
        cout << "RADIXSORT, em " << tempo << " segundos" << endl;
        cout << "NUM TROCAS " << radix->getNumTrocas() << " NUM COMPARACOES " << radix->getNumComparacoes() << endl;

        delete[] copiaLocal;
    }

private:
    BrazilCovid *data;
    int n;
};

#endif // LEITOR2_H