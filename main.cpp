/**
 * Universidade Federal de Juiz de Fora
 * main.cpp
 * 
 * #### Comando para rodar ####
 * 
 * @autor: Yagho Mattos, Samuel Paiva, Jean Felipe, Renan Nunes
 * @version 1.0
*/

//Importando Bibliotecas
#include <iostream>
#include "LeitorCovid.h"
#include "BrazilCovid.h"

using namespace std;

void quickSort(BrazilCovid *vet, int inicio, int fim);
void troca(BrazilCovid *vet, int i, int j);

int main()
{
    int n = 1431490;
    LeitorCovid *leitor = new LeitorCovid();

    BrazilCovid *covid = leitor->getDataset();

    for (int i = 0; i < 20; i++)
    {
        cout << "Estado " << covid[i].state << " cidade " << covid[i].name << " dia " << covid[i].date.day << " mes " << covid[i].date.mounth << " casos " << covid[i].cases << endl;
    }
    cout << "########" << endl;

    quickSort(covid, 0, 1000);

    for (int i = 0; i < 20; i++)
    {
        cout << "Estado " << covid[i].state << " cidade " << covid[i].name << " dia " << covid[i].date.day << " mes " << covid[i].date.mounth << " casos " << covid[i].cases << endl;
    }

    return 0;
}

void quickSort(BrazilCovid *vet, int inicio, int fim)
{
    int i,j;
    i = inicio;
    j = fim;
    BrazilCovid pivo = vet[(rand() % (fim - inicio + 1))+ inicio];

    while(i < j)
    {
        while(vet[i].state < pivo.state && i < fim)
            i++;
        while(vet[j].state > pivo.state && j > inicio)
            j--;

        if(i <= j)
        {
            swap(vet[i],vet[j]);
            i++;
            j--;
        }
    }
}


void troca(BrazilCovid *vet, int i, int j)
{
    BrazilCovid aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}