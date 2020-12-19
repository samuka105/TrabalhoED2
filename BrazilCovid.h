#ifndef BRAZILCOVID_H
#define BRAZILCOVID_H

#include <iostream>
#include <string>

#include "Date.h" //Classe para pegar datas

using namespace std;

class BrazilCovid{
    public:
        int code; //Código da cidade
        string name; //Nome da cidade
        string state; //Sigla do Estado
        int cases; //Número de casos
        int deaths; //Número de óbitos
        Date date; //Data
};

#endif // BRAZILCOVID_H