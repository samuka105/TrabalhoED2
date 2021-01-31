/**
 * Universidade Federal de Juiz de Fora
 * main.cpp
 * 
 * #### Comando para rodar ####
 * Linux/Mac: clear && g++ -std=c++11 main.cpp -o main && ./main
 * Windows: cls && g++ -std=c++11 main.cpp -o main && main.exe
 * 
 * @autor: Yagho Mattos, Samuel Paiva, Jean Felipe, Renan Nunes
 * @version 2.0
*/

//Importando Bibliotecas
#include <iostream>
#include <time.h>
#include <chrono>

//Classes de Entidade
#include "BrazilCovid.h"
#include "Date.h"

//Importando Etapas
#include "Etapas/Etapa1.h"
#include "Etapas/Etapa2.h"
#include "Etapas/Etapa3.h"

using namespace std;

void limparTela();
void laco();
void selecionar(int opcao);
int menu();

int main()
{
    laco();
    return 0;
}

int menu()
{
    int opcao;

    cout << "\t\t\tMenu Principal" << endl;
    cout << "*----------------------------------------------------------------------*" << endl;
    cout << "[1] Etapa 1" << endl;
    cout << "[2] Etapa 2" << endl;
    cout << "[3] Testes" << endl;
    cout << "[0] Sair. " << endl
         << endl;
    cout << "*----------------------------------------------------------------------*" << endl;

    cin >> opcao;
    return opcao;
}

/**
 * Looping que garante o funcionamento do menu
 * 
*/
void laco()
{
    int selecao = 1;

    while (selecao != 0)
    {
        selecao = menu();
        if (selecao >= 0 && selecao < 4) //Aceita apenas 4 entradas de inteiros
            selecionar(selecao);
    }

    cout << "Finalizando" << endl;
    return;
}

/**
 * Função de Seleção do da Opção de Menu
*/
void selecionar(int opcao)
{
    Etapa1* etapa1;
    Etapa2* etapa2;
    Etapa3* etapa3;
    char chave, chaveSecundaria;
    string nome_do_arquivo = "brazil_covid19_cities.csv";
    int n;

    switch (opcao)
    {
    case 0:
        cout << "Finalizando" << endl;
        exit(0);
        break;
    case 1:
        limparTela();
        cout << "Deseja Digitar o nome do arquivo(s/n)? ";
        cin >> chave;
        if (chave == 's' || chave == 'S')
        {
            nome_do_arquivo = "";
            cout << "\nCertfique-se que o arquivo esteja na pasta Datasets, localizada na mesma pasta do programa" << endl;
            cout << "Digite o nome do Arquivo: ";
            cin >> nome_do_arquivo;
            cout << "\nDeseja informar o número de elementos à ser lido?(s/n): ";
            cin >> chaveSecundaria;
            if (chaveSecundaria == 's' || chaveSecundaria == 'S')
            {
                cout << "Número: ";
                cin >> n;
                etapa1 = new Etapa1(nome_do_arquivo,n);
            }
            else
            {
                n = 1431490;
                etapa1 = new Etapa1(nome_do_arquivo,n);
            }
        }
        else if (chave == 'n')
        {
            n = 1431490;
            etapa1 = new Etapa1(nome_do_arquivo,n);
        }
        delete etapa1;
        break;
    case 2:
        etapa2 = new Etapa2();
        etapa2->realizaTestes();
        break;
    case 3:
        etapa3 = new Etapa3();
        delete etapa3;
        break;
    default:
        menu();
        break;
    }
}

/**
 * Função Responsável por limpar a tela do terminal, tanto no windows quanto no linux
*/
void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}