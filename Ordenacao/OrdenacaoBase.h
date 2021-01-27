#ifndef ORDENACAOBASE_H
#define ORDENACAOBASE_H

#include <iostream>

#include "../BrazilCovid.h"

using namespace std;


class OrdenacaoBase
{
    public:
        
        /**
         * Reseta os contadores para os estado que estavam no momento de criação do objeto
         */
        void resetContadores()
        {
            if(num_trocas != 0)
                num_trocas = 0;
            if(num_comparacoes != 0)
                num_comparacoes = 0;
        }

        /**
         * Retorna o numero de comparações contabilizado pelo contador
         * @return numero de comparações feitas desde a ultima inicialização dos contadores
         */
        long getNumComparacoes()
        {
            return num_comparacoes;
        }
        
        /**
         * Retorna o numero de trocas contabilizado pelo contador
         * @return numero de trocas feitas desde a ultima inicialização dos contadores
         */
        long getNumTrocas()
        {
            return num_trocas;
        }

         bool comparador(BrazilCovid a, BrazilCovid b)
        {
            this->num_comparacoes++;
            return a.cases < b.cases;
        }

         /**
         * Inverte a posição de 2 itens no vetor
         * @param vet vetor que está tendo seus itens invertidos
         * @param i posição do item 1 no vetor
         * @param j posição do item 2 no vetor
         */
        void troca(BrazilCovid* vet, int i, int j)
        {
            num_trocas++;
            BrazilCovid aux = vet[j];
            vet[j] = vet[i];
            vet[i] = aux;
        };

        void aumentaNumTrocas()
        {
            this->num_trocas++;
        }

    private: 
        long long int num_comparacoes; // Contador de comparações
        long long int num_trocas; // Contador de trocas

       
};

#endif // ORDENACAOBASE_H