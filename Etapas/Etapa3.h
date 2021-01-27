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
#include "../Ordenacao/MergeSort.h"
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
        string line;
        char ch;
        int n;

        RadixSort *radix;
        QuickSort *quick;
        MergeSort *merge;

        double tempo;
        int num_comparacoes, num_trocas;

        switch (opcao)
        {
        case 0:
            cout << "Finalizando" << endl;
            exit(0);
            break;
        case 1:
            leitor = new LeitorCovid("brazil_covid19_cities_processado.csv");
            if (n == 0)
                n = 100;
            leitor->numRegistros(n);
            leitor->leituraPosProcessado();
            dataset = leitor->getDataset();
            delete leitor;
            cout << "Exibindo " << n << " registros aleatorios do dataset " << endl;
            cout << "Data,Estado,Nome da Cidade,Codigo,Casos,Mortes" << endl;
            for (int i = 0; i < 10; i++)
            {
                cout << dataset[i].date.day << "-" << dataset[i].date.mounth << "-" << dataset[i].date.year << ", " << dataset[i].state << ", " << dataset[i].name << ", " << dataset[i].code << ", " << dataset[i].cases << ", " << dataset[i].deaths << endl;
            }
            cout << "Salvar?(s/n)";
            cin >> ch;
            if (ch == 's')
            {
                Log::getInstance().iniciaArquivoSaida("Saidas" + getDirSep() + "preprocessador.csv");
                for (int i = 0; i < n; i++)
                {
                    line = "";
                    line += to_string(dataset[i].date.year) + "-" + to_string(dataset[i].date.mounth) + "-" + to_string(dataset[i].date.day) + ",";
                    line += dataset[i].state + ",";
                    line += dataset[i].name + ",";
                    line += to_string(dataset[i].code) + ",";
                    line += to_string(dataset[i].cases) + ",";
                    line += to_string(dataset[i].deaths);

                    Log::getInstance().lineArquivo(line);
                }
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
            cout << "Inicio da ordenacao " << endl;
            timerStart();
            cout << "Comecou a ordenacao " << endl;
            merge->ordernar(dataset, 0, n - 1);
            tempo = timerEnd();
            num_trocas = merge->getNumTrocas();
            cout << "Final da ordenacao " << endl;
            num_comparacoes = merge->getNumComparacoes();
            cout << "Ordenado em " << tempo << " segundos, com " << num_comparacoes << " comparacoes e " << num_trocas << " trocas" << endl;
            delete merge;
            tempo = 0;
            num_comparacoes = 0;
            num_trocas = 0;
            break;
        case 4:
            cout << "QuickSort: " << endl;
            quick = new QuickSort();
            timerStart();
            quick->ordernar(dataset, 0, n - 1);
            tempo = timerEnd();
            num_trocas = quick->getNumTrocas();
            num_comparacoes = quick->getNumComparacoes();
            cout << "Ordenado em " << tempo << " segundos, com " << num_comparacoes << " comparacoes e " << num_trocas << " trocas" << endl;
            delete quick;
            break;
        case 5:
            cout << "RadixSort: " << endl;
            radix = new RadixSort();
            timerStart();
            radix->ordernar(dataset,n);
            tempo = timerEnd();
            num_trocas = radix->getNumTrocas();
            num_comparacoes = radix->getNumComparacoes();
            cout << "Ordenado em " << tempo << " segundos, com " << num_comparacoes << " comparacoes e " << num_trocas << " trocas" << endl;
            delete radix;
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