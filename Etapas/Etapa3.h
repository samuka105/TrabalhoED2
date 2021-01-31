/**
 * Universidade Federal de Juiz de Fora
 * Etapa3.h
 * Propósito: Classe que realiza a terceira Etapa do trabalho
 * 
*/
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
#include "../Ordenacao/ShellSort.h"
#include "../Ordenacao/HeapSort.h"

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
            if (selecao >= 0 && selecao < 8)
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
            free(dataset);
            dataset = nullptr;
            delete leitor;
            free(dataset);
            dataset = nullptr;
            break;
        case 3:
            mergeSort();
            break;
        case 4:
            quickSort();
            break;
        case 5:
            radixSort();
            break;
        case 6:
            shellSort();
            break;
        case 7:
            heapSort();
            break;
        default:
            menu();
            break;
        }
    }

    /*Aqui começam as funções que chamam os elementos de ordenação*/
    void mergeSort()
    {
        int n;
        char ch;
        cout << "O Algoritmo mergeSort tem apresentado erro para valores acima de 20.000" << endl;
        cout << "Informe o numero de registros a ser importado: ";
        cin >> n;

        LeitorCovid *leitor = new LeitorCovid("brazil_covid19_cities_processado.csv");
        leitor->numRegistros(n);
        leitor->leituraPosProcessado();
        dataset = leitor->getDataset();
        BrazilCovid *copiaLocal = copiaVetor(dataset, n);

        MergeSort *merge;
        merge = new MergeSort();
        timerStart();
        merge->ordenar(dataset, 0, n - 1);
        double tempo = timerEnd();
        int num_trocas = merge->getNumTrocas();
        int num_comparacoes = merge->getNumComparacoes();
        cout << "MergeSort, Ordenado em " << tempo << " segundos, com " << num_comparacoes << " comparacoes e " << num_trocas << " trocas" << endl;
        cout << "Salvar(s/n)? ";
        cin >> ch;
        if (ch == 's')
        {
            Log::getInstance().iniciaArquivoSaida("saidas" + getDirSep() + "mergeSort-teste.csv");
            Log::getInstance().lineArquivo("Tempo,Algoritmo,Comparacoes,Trocas,N");

            string line = "";
            line += "MergeSort,";
            line += to_string(tempo) + ",";
            line += to_string(num_comparacoes) + ",";
            line += to_string(num_trocas) + ",";
            line += to_string(n);

            Log::getInstance().lineArquivo(line);
            Log::getInstance().fechaArqSaida();
        }
        delete merge;
        delete[] dataset;
        delete[] copiaLocal;
    }

    void quickSort()
    {
        int n;
        char ch;
        cout << "O Algoritmo QuickSort tem apresentado erro para valores acima de 100.000" << endl;
        cout << "Informe o numero de registros a ser importado: ";
        cin >> n;

        LeitorCovid *leitor = new LeitorCovid("brazil_covid19_cities_processado.csv");
        leitor->numRegistros(n);
        leitor->leituraPosProcessado();
        dataset = leitor->getDataset();
        BrazilCovid *copiaLocal = copiaVetor(dataset, n);

        QuickSort *quick;
        quick = new QuickSort();
        timerStart();
        quick->ordenar(dataset, 0, n - 1);
        double tempo = timerEnd();
        int num_trocas = quick->getNumTrocas();
        int num_comparacoes = quick->getNumComparacoes();
        cout << "QuickSort, Ordenado em " << tempo << " segundos, com " << num_comparacoes << " comparacoes e " << num_trocas << " trocas" << endl;
        cout << "Salvar(s/n)? ";
        cin >> ch;
        if (ch == 's')
        {
            Log::getInstance().iniciaArquivoSaida("saidas" + getDirSep() + "quickSort-teste.csv");
            Log::getInstance().lineArquivo("Tempo,Algoritmo,Comparacoes,Trocas,N");

            string line = "";
            line += "QuickSort,";
            line += to_string(tempo) + ",";
            line += to_string(num_comparacoes) + ",";
            line += to_string(num_trocas) + ",";
            line += to_string(n);

            Log::getInstance().lineArquivo(line);
            Log::getInstance().fechaArqSaida();
        }
        delete quick;
        delete[] dataset;
        delete[] copiaLocal;
    }

      void heapSort()
    {
        int n;
        char ch;
        cout << "Informe o numero de registros a ser importado: ";
        cin >> n;

        LeitorCovid *leitor = new LeitorCovid("brazil_covid19_cities_processado.csv");
        leitor->numRegistros(n);
        leitor->leituraPosProcessado();
        dataset = leitor->getDataset();
        BrazilCovid *copiaLocal = copiaVetor(dataset, n);

        HeapSort *heap;
        heap = new HeapSort();
        timerStart();
        heap->ordenar(dataset, n-1);
        double tempo = timerEnd();
        int num_trocas = heap->getNumTrocas();
        int num_comparacoes = heap->getNumComparacoes();
        cout << "HeapSort, Ordenado em " << tempo << " segundos, com " << num_comparacoes << " comparacoes e " << num_trocas << " trocas" << endl;
        cout << "Salvar(s/n)? ";
        cin >> ch;
        if (ch == 's')
        {
            Log::getInstance().iniciaArquivoSaida("saidas" + getDirSep() + "heapSort-teste.csv");
            Log::getInstance().lineArquivo("Tempo,Algoritmo,Comparacoes,Trocas,N");

            string line = "";
            line += "HeapSort,";
            line += to_string(tempo) + ",";
            line += to_string(num_comparacoes) + ",";
            line += to_string(num_trocas) + ",";
            line += to_string(n);

            Log::getInstance().lineArquivo(line);
            Log::getInstance().fechaArqSaida();
        }
        delete heap;
        delete[] dataset;
        delete[] copiaLocal;
    }

    void radixSort()
    {
        int n;
        char ch;
        cout << "Informe o numero de registros a ser importado: ";
        cin >> n;

        LeitorCovid *leitor = new LeitorCovid("brazil_covid19_cities_processado.csv");
        leitor->numRegistros(n);
        leitor->leituraPosProcessado();
        dataset = leitor->getDataset();
        BrazilCovid *copiaLocal = copiaVetor(dataset, n);

        RadixSort *radix;
        radix = new RadixSort();
        timerStart();
        radix->ordenar(dataset, n);
        double tempo = timerEnd();
        int num_trocas = radix->getNumTrocas();
        int num_comparacoes = radix->getNumComparacoes();
        cout << "RadixSort, Ordenado em " << tempo << " segundos, com " << num_comparacoes << " comparacoes e " << num_trocas << " trocas" << endl;
        cout << "Salvar(s/n)? ";
        cin >> ch;
        if (ch == 's')
        {
            Log::getInstance().iniciaArquivoSaida("saidas" + getDirSep() + "radixSort-teste.csv");
            Log::getInstance().lineArquivo("Tempo,Algoritmo,Comparacoes,Trocas,N");

            string line = "";
            line += "RadixSort,";
            line += to_string(tempo) + ",";
            line += to_string(num_comparacoes) + ",";
            line += to_string(num_trocas) + ",";
            line += to_string(n);

            Log::getInstance().lineArquivo(line);
            Log::getInstance().fechaArqSaida();
        }
        delete radix;
        delete[] dataset;
        delete[] copiaLocal;
    }

     void shellSort()
    {
        int n;
        char ch;
        cout << "Informe o numero de registros a ser importado: ";
        cin >> n;

        LeitorCovid *leitor = new LeitorCovid("brazil_covid19_cities_processado.csv");
        leitor->numRegistros(n);
        leitor->leituraPosProcessado();
        dataset = leitor->getDataset();
        BrazilCovid *copiaLocal = copiaVetor(dataset, n);

        ShellShort *shell;
        shell = new ShellShort();
        timerStart();
        shell->ordenar(dataset,n);
        double tempo = timerEnd();
        int num_trocas = shell->getNumTrocas();
        int num_comparacoes = shell->getNumComparacoes();
        cout << "ShellShort, Ordenado em " << tempo << " segundos, com " << num_comparacoes << " comparacoes e " << num_trocas << " trocas" << endl;
        cout << "Salvar(s/n)? ";
        cin >> ch;
        if (ch == 's')
        {
            Log::getInstance().iniciaArquivoSaida("saidas" + getDirSep() + "shellSort-teste.csv");
            Log::getInstance().lineArquivo("Tempo,Algoritmo,Comparacoes,Trocas,N");

            string line = "";
            line += "ShellShort,";
            line += to_string(tempo) + ",";
            line += to_string(num_comparacoes) + ",";
            line += to_string(num_trocas) + ",";
            line += to_string(n);

            Log::getInstance().lineArquivo(line);
            Log::getInstance().fechaArqSaida();
        }
        delete shell;
        delete[] dataset;
        delete[] copiaLocal;
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
        cout << "[6] ShellSort" << endl;
        cout << "[7] HeapSort" << endl;
        cout << "[0] Sair. " << endl
             << endl;
        cout << "*----------------------------------------------------------------------*" << endl;

        cin >> opcao;
        return opcao;
    }

private:
    BrazilCovid *dataset;
    BrazilCovid *copiaLocal;
};

#endif // ETAPA3_H