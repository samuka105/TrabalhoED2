#ifndef ETAPA3_H
#define ETAPA3_H

#include <iostream>
#include <time.h>
#include <string>
#include <chrono>

#include "../Leitura/LeitorCovid.h"
#include "../Leitura/LeitorBase.h"
#include "../Leitura/Log.h"
#include "../BrazilCovid.h"

#include "../Ordenacao/QuickSort.h"
#include "../Ordenacao/RadixSort.h"

using namespace std;

class Etapa3 : public LeitorBase
{
public:
    Etapa3()
    {
        laco();
    }

    void laco()
    {
        int selecao = 1;

        while (selecao != 0)
        {
            selecao = menu();
            if (selecao >= 0 && selecao < 4)
                selecionar(selecao);
        }

        cout << "Finalizando" << endl;
        return;
    }

    void selecionar(int opcao)
    {
        LeitorCovid *leitor;
        char ch;
        int n = 0;

        RadixSort* radix;
        QuickSort* quick;
        MergeSort* merge;

        switch (opcao)
        {
        case 0:
            cout << "Finalizando" << endl;
            exit(0);
            break;
        case 1:
            leitor = new LeitorCovid("brazil_covid19_cities_processado.csv");
            if (n == 0)
                n = 10;
            leitor->numRegistros(n);
            leitor->leituraPosProcessado();
            dataset = leitor->getDataset();
            delete leitor;
            cout << "Exibindo " << n << " registros aleatorios do dataset " << endl;
            cout << "Data,Estado,Nome da Cidade,Codigo,Casos,Mortes" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << dataset[i].date.day << "-" << dataset[i].date.mounth << "-" << dataset[i].date.year << ", " << dataset[i].state << ", " << dataset[i].name << ", " << dataset[i].code << ", " << dataset[i].cases << ", " << dataset[i].deaths << endl;
            }
            free(dataset);
            dataset = nullptr;
            break;
        case 2:
            leitor = new LeitorCovid("brazil_covid19_cities_processado.csv");
            cout << "Informe o numero de registros a ser importado: ";
            cin >> n;
            leitor->numRegistros(n);
            leitor->leituraPosProcessado();
            dataset = leitor->getDataset();
            delete leitor;
            break;
        case 3:
            cout << "MergeSort: " << endl;
            merge = new MergeSort();
            timerStart();
            merge->ordernar(dataset,0,n-1);
            timerEnd();
            //cout << ""
            break;
        default:
            menu();
            break;
        }
    }

    int menu()
    {
        int opcao;

        cout << "\t\t\tMenu de Testes" << endl;
        cout << "*----------------------------------------------------------------------*" << endl;
        cout << "[1] Pre-processamento" << endl;
        cout << "[2] Importar N registros aleatorios" << endl;
        cout << "-------------Algoritmos de Ordenacao-----------" << endl;
        cout << "[3] MergeSort" << endl;
        cout << "[4] QuickSort" << endl;
        cout << "[5] RadixSort" << endl;
        cout << "[6] QuickSort Mediana" << endl;
        cout << "[0] Sair. " << endl
             << endl;
        cout << "*----------------------------------------------------------------------*" << endl;

        cin >> opcao;
        return opcao;
    }

private:
    BrazilCovid *dataset;
};

#endif // ETAPA3_H