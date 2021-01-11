#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

#include "BrazilCovid.h"

using namespace std;

class Log
{
    private:
        fstream arqSaida;

    public:
        Log(){};
        ~Log(){};

        void criarDataset(BrazilCovid* dataset,int tam)
        {
            arqSaida.open("datasets/brazil_covid19_cities_processado.csv", fstream::in | fstream::out | fstream::trunc);

            if(!arqSaida || !arqSaida.is_open())
            {
                cout << "Impossível abrir arquivo de saida para escrita" << endl;
                exit(1);
            }

            arqSaida << "date,state,name,code,cases,deaths" << endl;
            for(int i = 0; i < tam-1; i++)
            {
                arqSaida << dataset[i].date.year << "-" <<  dataset[i].date.mounth << "-" <<  dataset[i].date.day << "," <<  dataset[i].state << "," <<  dataset[i].name << "," <<  dataset[i].code << "," << dataset[i].cases << "," << dataset[i].deaths << endl;
            }

        }
};

#endif // LOG_H