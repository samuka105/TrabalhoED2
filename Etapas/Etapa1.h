/**
 * Universidade Federal de Juiz de Fora
 * Etapa1.h
 * Propósito: Classe que realiza a primeira Etapa do trabalho
 * 
*/
#ifndef ETAPA1_H
#define ETAPA1_H

#include <iostream>
#include <time.h>
#include <string>
#include <chrono>

#include "../Leitura/LeitorCovid.h"
#include "../Leitura/LeitorBase.h"
#include "../Leitura/Log.h"
#include "../BrazilCovid.h"
#include "../Ordenacao/QuickSort.h"

using namespace std;

class Etapa1 : public LeitorBase
{

public:
    Etapa1(string nome_arquivo, int n)
    {

        n = n; //Número de Registros a ser lido
        LeitorCovid *leitura = new LeitorCovid(nome_arquivo);
        leitura->numRegistros(n);
        leitura->leituraPreProcessado();

        dataset = leitura->getDataset();

        QuickSort *quick = new QuickSort(); //Ordenando com o QuicSort
        quick->ordenarPre(dataset, 0, n - 1);
        delete quick;

        corrigeCasos(dataset); //Corrigindo casos do dataset

        caminhoSaida = this->getDiretorio() + "brazil_covid19_cities_processado.csv";
        Log::getInstance().iniciaArquivoSaida(caminhoSaida);

        Log::getInstance().lineArquivo("date,state,name,code,cases,deaths");

        // For responsável por Imprimir no arquivo de saida
        for (int i = 0; i < n; i++)
        {
            string line = "";
            line += to_string(dataset[i].date.year) + "-" + to_string(dataset[i].date.mounth) + "-" + to_string(dataset[i].date.day) + ",";
            line += dataset[i].state + ",";
            line += dataset[i].name + ",";
            line += to_string(dataset[i].code) + ",";
            line += to_string(dataset[i].cases) + ",";
            line += to_string(dataset[i].deaths);

            Log::getInstance().lineArquivo(line);
        }

        delete leitura;
    }

    ~Etapa1()
    {
        delete dataset;
    }

private:
    BrazilCovid *dataset;
    string caminhoSaida;
    int n;

    /**
     * Função responsável por transformar os casos de casos acumulados para casos diários,
     * Há um erro no dataset que causa a existência de casos negativos. Por ser tratar de vidas, se a necessidade de transformar esses casos 
     * em casos reais, alterando as ocorrências de "-1" para "0"
     * @param vet: Vetor de Objetos
    */
    void corrigeCasos(BrazilCovid *vet)
    {
        for (int i = n; i > 0; i--)
        {
            if (vet[i].name == vet[i - 1].name)
            {
                vet[i].cases = vet[i].cases - vet[i - 1].cases;

                if (vet[i].cases < 0)
                    vet[i].cases = 0;
            }
        }
    };
};

#endif // ETAPA1_H