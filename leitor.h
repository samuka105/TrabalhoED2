#ifndef LEITOR_H
#define LEITOR_H
#include <string>

using namespace std;

class LeitorBase
{
    public:
        LeitorBase();//construtor
        ~LeitorBase();//destrutor
        string getpath();//pegar o caminho
        void setpath(string path);//colocar o caminho do arquivo
}



#endif // LEITOR_H