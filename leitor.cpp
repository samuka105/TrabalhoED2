#include <iostream>
#include "leitor.h"



Leitor::Leitor(){}

Leitor::~Leitor(){}

string Leitor::getPath()
{
    return path;
}
void Leitor::setpath(string path)
{
    cout << "Digite o caminho do arquivo que quer ler" << endl;
    cin >> path;
}

