#include <iostream>
#include "leitor.h"




LeitorBase::Leitor(){}

LeitorBase::~Leitor(){}

string LeitorBase::getPath()
{
    return path;
}
void LeitorBase::setpath(string path)
{
    cout << "Digite o caminho do arquivo que quer ler" << endl;
    cin >> path;
}

