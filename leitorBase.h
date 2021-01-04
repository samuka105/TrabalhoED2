#ifndef LEITORBASE_H
#define LEITORBASE_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
#include <chrono>

using namespace std;

class LeitorBase
{
public:
    LeitorBase(){};
    ~LeitorBase(){};

    /**
         * Quebra a string fornecida em strings menores dado o separador
         * @s String para quebrar
         * @c Caractere separador
         * @return vector<string>
    */
    const vector<string> explode(const string &s, const char &c)
    {
        if (s == "" || s.length() <= 0)
        {
            cout << "explode(): string vazia" << endl;
            return vector<string>();
        }

        string buff{""};
        vector<string> v;

        for (auto n : s)
        {
            if (n != c)
                buff += n;
            else if (n == c && buff != "")
            {
                v.push_back(buff);
                buff = "";
            }
        }
        if (buff != "")
            v.push_back(buff);

        return v;
    }

    /**
         * Inicia contagem de tempo
         */
    void timerStart()
    {
        start = std::chrono::system_clock::now();
    }

    /**
         * Obtem a diferenca de tempo em segundos
         * @return double
         */
    double timerEnd()
    {
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        double duracao = elapsed_seconds.count();
        return duracao;
    }

private:
    std::chrono::time_point<std::chrono::system_clock> start, end;
};

#endif // LEITORBASE_H