#ifndef LEITOR2_H
#define LEITOR2_H

#include <string>

#include "../Leitura/LeitorBase.h"
#include "../Leitura/LeitorCovid.h"
#include "../Leitura/Log.h"

#include "../Ordenacao/MergeSort.h"
#include "../Ordenacao/QuickSort.h"
#include "../Ordenacao/RadixSort.h"
#include "../Ordenacao/ShellSort.h"
#include "../Ordenacao/HeapSort.h"

using namespace std;

class Etapa2 : public LeitorBase
{
public:
    Etapa2(){};
    ~Etapa2(){};

    void realizaTestes()
    {
        string line = "";
        int numTestes = 5;
        int numRegistros = 5;
        int registros[numRegistros] = {10000, 50000, 100000, 500000, 1000000};
        for (int j = 0; j < numTestes; j++)
        {
            for (int i = 0; i < numRegistros; i++)
            {
                n = registros[i];
                LeitorCovid *leitor = new LeitorCovid("brazil_covid19_cities_processado.csv");
                leitor->numRegistros(n);
                leitor->leituraPosProcessado();
                data = leitor->getDataset();
                delete leitor;

                Log::getInstance().iniciaArquivoSaida("saidas" + getDirSep() + "etapa_2_" + to_string(i) + "_teste_" + to_string(j) + ".csv");
                Log::getInstance().lineArquivo("Nome,Tempo,Numero de Trocas, Numero de Comparacoes,N");

                double tempo;
                BrazilCovid *copiaLocal = nullptr;

                copiaLocal = copiaVetor(data, n);
                timerStart();
                HeapSort *heap = new HeapSort();
                heap->ordenar(copiaLocal, n - 1);
                tempo = timerEnd();
                cout << "MERGESORT, em " << tempo << " segundos, NUM TROCAS " << heap->getNumTrocas() << " NUM COMPARACOES " << heap->getNumComparacoes() << endl;

                line = "";
                line += "HeapSort,";
                line += to_string(tempo) + ",";
                line += to_string(heap->getNumComparacoes()) + ",";
                line += to_string(heap->getNumTrocas()) + ",";
                line += to_string(n);

                Log::getInstance().lineArquivo(line);

                delete[] copiaLocal;
                delete heap;

                copiaLocal = copiaVetor(data, n);
                timerStart();
                QuickSort *quick = new QuickSort();
                quick->ordenar(copiaLocal, 0, n - 1);
                tempo = timerEnd();
                cout << "QUICKSORT, em " << tempo << " segundos, NUM TROCAS " << quick->getNumTrocas() << " NUM COMPARACOES " << quick->getNumComparacoes() << endl;

                line = "";
                line += "QuickSort,";
                line += to_string(tempo) + ",";
                line += to_string(quick->getNumComparacoes()) + ",";
                line += to_string(quick->getNumTrocas()) + ",";
                line += to_string(n);

                Log::getInstance().lineArquivo(line);

                delete[] copiaLocal;
                copiaLocal = nullptr;
                delete quick;

                copiaLocal = copiaVetor(data, n);
                timerStart();
                RadixSort *radix = new RadixSort();
                radix->ordenar(copiaLocal, n);
                tempo = timerEnd();
                cout << "RADIXSORT, em " << tempo << " segundos, NUM TROCAS " << radix->getNumTrocas() << " NUM COMPARACOES " << radix->getNumComparacoes() << endl;

                line = "";
                line += "RadixSort,";
                line += to_string(tempo) + ",";
                line += to_string(radix->getNumComparacoes()) + ",";
                line += to_string(radix->getNumTrocas()) + ",";
                line += to_string(n);

                Log::getInstance().lineArquivo(line);

                delete[] copiaLocal;
                copiaLocal = nullptr;
                delete radix;

                copiaLocal = copiaVetor(data, n);
                timerStart();
                ShellShort *shell = new ShellShort();
                shell->ordenar(copiaLocal, n);
                tempo = timerEnd();
                cout << "ShellSort, em " << tempo << " segundos, NUM TROCAS " << shell->getNumTrocas() << " NUM COMPARACOES " << shell->getNumComparacoes() << endl;

                line = "";
                line += "ShellShort,";
                line += to_string(tempo) + ",";
                line += to_string(shell->getNumComparacoes()) + ",";
                line += to_string(shell->getNumTrocas()) + ",";
                line += to_string(n);

                Log::getInstance().lineArquivo(line);

                delete[] copiaLocal;
                copiaLocal = nullptr;
                delete shell;

                Log::getInstance().fechaArqSaida();
            }
        }
    }

private:
    BrazilCovid *data;
    int n;
};

#endif // LEITOR2_H