#ifndef LEITORCOVID_H
#define LEITORCOVID_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <errno.h>

#include "LeitorBase.h"
#include "BrazilCovid.h"
#include "Date.h"

using namespace std;

class LeitorCovid : protected LeitorBase
{
public:
    LeitorCovid()
    {
        timerStart();
        leitura();
        double time = timerEnd();
        //cout << "O tempo para leitura foi de " << time << " segundos" << endl;
    };
    ~LeitorCovid(){};

    BrazilCovid* getDataset(){
        return dataset;
    }

private:
    int n = 1431490;
    fstream arqEntrada; //Arquivo à ser lido
    string line;
    bool headerProcessado;
    BrazilCovid *dataset;

    int strToInt(string s)
    {
        int i = stoi(s);
        if (errno == ERANGE)
        {
            cout << "int range error on " << s << endl;
            errno = 0;
            i = 0;
        }
        return i;
    }

    Date strToDate(string s)
    {
        vector<string> result = explode(s, '-');
        Date d;
        d.day = stoi(result[2]);
        d.mounth = stoi(result[1]);
        d.year = stoi(result[0]);

        return d;
    }

    void leitura()
    {
        arqEntrada.open("brazil_covid19_cities.csv"); //Abre o arquivo de entrada

        //Verifica se o arquivo foi aberto
        if (!arqEntrada || !arqEntrada.is_open())
        {
            cout << "Não foi possivel abrir o arquivo" << endl;
            exit(1); //Caso não tenha sido possível abrir, fecha o programa
        }
        headerProcessado = false;
        int pos = 0;

        while (getline(arqEntrada, line))
        {
            vector<string> result = explode(line, ',');
            
            if (headerProcessado == false)
            {
                headerProcessado = true;
                dataset = new BrazilCovid[n];
                for (int i = 0; i < n; i++)
                    dataset[i].code = -1;
            }
            else
            {
                BrazilCovid u;
                u.date = strToDate(result[0]);
                u.state = result[1];
                u.name = result[2];
                u.code = stoi(result[3]);
                u.cases = strToInt(result[4]);
                u.deaths = strToInt(result[5]);

                dataset[pos] = u;
                pos++;
            }
        }

        if(pos == n)
        {
            //cout << pos << " registros lidos" << endl;
        } else {
            cout << "Erro ao realizar leitura, o número de registros informado é o menor que o possuido pelo dataset" << endl;
            exit(1);
        }

        if(arqEntrada.is_open())
        {
            arqEntrada.close();
        }
    }
};

#endif // LEITORCOVID_H