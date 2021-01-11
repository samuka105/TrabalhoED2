#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>

#include "../BrazilCovid.h"
#include "OrdenacaoBase.h"

using namespace std;

class BubbleSort: protected OrdenacaoBase{

    public:
        BubbleSort(){};
        ~BubbleSort(){};

        void ordernar(BrazilCovid* vetor, int tam)
        {
            for(int i = 0; i < tam-1; i++)
            {
                bool flag = false; //Chave de controle para saber se o final da lista foi ordenado ou não
                for(int j = 0; j < tam-1-i;j++)
                {
                    if(comparador(vetor[j],vetor[j+1]))
                    {
                        troca(vetor,j,j+1);
                        flag = true;
                    }
                }

                if(!flag)
                {
                    break;
                }
            }
        }

};

#endif // BUBBLESORT_H