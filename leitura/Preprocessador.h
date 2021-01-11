#ifndef PREPROCESSADOR_H
#define PREPROCESSADOR_H

#include <iostream>
#include <string>

#include "LeitorCovid.h"
#include "QuickSort.h"
#include "BrazilCovid.h"
#include "Log.h"

using namespace std;

class Preprocessador
{

public:
    Preprocessador()
    {
        cout << "\t### Leitura e pre-processamento ###" << endl;
        cout << "Digite apenas o nome do arquivo a ser preprocessado" << endl;
        nome_do_arquivo = "";
        cout << endl
             << "Digite o nome do arquivo: ";
        cin >> nome_do_arquivo;
        leitura = new LeitorCovid(nome_do_arquivo);
        teste = leitura->getDataset();

        ordena = new QuickSort(teste, 0,n);
        corrigeCasos(teste);
        saida.criarDataset(teste,n);
    };

    ~Preprocessador() {}

private:
    LeitorCovid *leitura;
    BrazilCovid *teste;
    Log saida;
    QuickSort *ordena;
    string nome_do_arquivo;
    int n = 1431490;

    void corrigeCasos(BrazilCovid* vet)
    {
        for(int i = n; i > 0; i--)
        {
            if(vet[i].name == vet[i-1].name)
            {
                vet[i].cases = vet[i].cases - vet[i-1].cases;

                if(vet[i].cases < 0)
                    vet[i].cases = 0;
            }
        }
    }
};

#endif // PREPROCESSADOR_H