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
#include <string>

#include "Preprocessador.h"

using namespace std;

void menu();

void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void menuAuxiliar(char in)
{
    Preprocessador* data;
    switch (in)
    {
    case '0':
        cout << "Finalizando" << endl;
        exit(0);
        break;
    case '1':
        limparTela();
        data = new Preprocessador();
        break;
    case '2':
        break;
    case '3':
        break;
    default:
        menu();
        break;
    }
}

void menu()
{
    limparTela();
    char in;

    while (true)
    {
        cout << endl;
        cout << "\t\t\tMenu Principal" << endl;
        cout << "[01] Etapa 1" << endl;
        cout << "[02] Etapa 2" << endl;
        cout << "[03] Testes" << endl;
        cout << "[0] Sair. " << endl;
        cout << endl;

        do
        {
            cout << "Selecione uma opcao valida: ";
            cin >> in;
        } while (
            (in < '0' || in > '5') && (in < 'a' || in > 'z'));

        menuAuxiliar(in);
    }
}

int main()
{
    menu();
    return 0;
}
