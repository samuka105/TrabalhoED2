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
#include <time.h>
#include <chrono>
#include <fstream>

using namespace std;

int main()
{
    ifstream arq("brazil_covid19_cities.csv");//verificação do arquivo com o nome entre ""
    if(arq.is_open()) //verifica se o arquivo esta aberto
    {
            cout << "arquivo aberto com sucesso" <<endl;
    }
    else
        {
            cout << "arquivo nao encontrado" << endl;
        }
        arq.close();
    return 0;
}