#ifndef ORDENACAOBASE_H
#define ORDENACAOBASE_H

#include <iostream>

using namespace std;

template <class T>
class OrdenacaoBase
{
    public:
        
        /**
         * Reseta os contadores para os estado que estavam no momento de criação do objeto
         */
        void resetContadores()
        {
            num_trocas = 0;
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

    private: 
        long long int num_comparacoes; // Contador de comparações
        long long int num_trocas; // Contador de trocas

         /**
         * Inverte a posição de 2 itens no vetor
         * @param vet vetor que está tendo seus itens invertidos
         * @param i posição do item 1 no vetor
         * @param j posição do item 2 no vetor
         */
        void troca(T* vetor, int i, int j)
        {
            num_trocas++;
            T aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        };
};

#endif // ORDENACAOBASE_H