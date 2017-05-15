/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matrícula: 2015042150
 * Codigo do Problema: JDENTIST     Problema: Dentista
 *
 * O algoritmo ordena os horarios lidos pelo horario de término e, então, imprime a partir do primeiro
 * todos para os quais não tenha conflito entra o horário de início com o horário de término do anterior.
 *
 * */

#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool ordena(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}//ordena()

void print_vetor(vector<pair<int, int>> v, int tam)
{
    std::vector<pair<int, int>>::iterator it;

    for(it=v.begin(); it!=v.begin()+tam; it++)
    {
        cout << it->first << ", " << it->second << endl;
    }
}

int main() {
    vector<pair <int, int> >::iterator it;
    int n;
    int inicio, fim;
    int ult_horario;
    int cont;

    cont = 0;

    scanf("%d", &n);

    vector<pair <int, int> > horarios(n);

    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &inicio, &fim);
        horarios[i] = (make_pair(inicio, fim));
    }

    //print_vetor(horarios, n);
    sort(horarios.begin(), horarios.begin()+n, ordena);
    //print_vetor(horarios, n);

    ult_horario = horarios.begin()->second;
    cont++;
    for(it=horarios.begin()+1; it!=horarios.begin()+n; it++)
    {
        if(it->first>=ult_horario)
        {
            cont++;
            ult_horario = it->second;
        }//if
    }//for

    printf("%d\n", cont);

    return 0;
}