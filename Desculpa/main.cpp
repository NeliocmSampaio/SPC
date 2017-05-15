/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matrícula: 2015042150
 * Codigo do Problema: DESCULPA     Problema: Pedido de Desculpas
 *
 *  O algoritmo utiliza a solução com programação dinâmica para o problema da
 *  mochila, sendo, no caso, a capacidade da mochila igual à capacidade do cartão,
 *  o peso dos itens igual ao tamanho de cada frase e o valor dos itens igual ao número
 *  de veses que a palavra desculpa aparece na frase. Calcula-se o máximo que se pode
 *  carregar em uma mochila de capacidade i,para i de 0 até s (s a capacidade da mochila
 *  original), considerando todos os itens (máximo entre [o valor do item j (caso ele
 *  caiba na mochila i) + o valor máximo carregado em uma mochila de capacidade j-peso do
 *  item atual] e [o valor carregado pela mochila de capacidade i até o item j-1]). Todos
 *  os calculos são guardados em uma matriz para que não seja necessário recalculo.
 * */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int cap_maxima(vector<pair<int, int>> itens, int qnt, int cap_mochila)
{
    int bag_cItem;  //valor carregado pela mochila com cap x carregando o item z
    vector<pair<int, int>>::iterator it;

    int mat[qnt+2][cap_mochila+2];
    for(int i=0; i<qnt+2; i++)
        mat[i][0] = 0;
    for(int i=0; i<cap_mochila+2; i++)
        mat[0][i] = 0;

    for(int i=1; i<=qnt; i++)
    {
        //cout << "linha " << i << " coluna ";
        it = itens.begin()+(i);
        for(int j=1; j<=cap_mochila; j++)
        {
            //cout << j << " ";
            if(it->first<=j)
            {
                bag_cItem = it->second + (mat[i-1][j - it->first]);
                mat[i][j] = bag_cItem < mat[i-1][j] ? mat[i-1][j] : bag_cItem;
            } else
            {
                mat[i][j] = mat[i-1][j];
            }//else

            //cout << "valor: " << mat[i][j];
            //cout << endl;
        }//for
    }//for

    return mat[qnt][cap_mochila];
}

int main() {
    int s, n;
    int peso, valor;
    int cont;

    cont = 0;

    scanf("%d %d", &s, &n);

    while(n!=0)
    {
        vector<pair<int, int>> itens(n+1);

        for(int i=1; i<=n; i++)
        {
            scanf("%d %d", &peso, &valor);
            itens[i] = make_pair(peso, valor);
        }//for

        cont++;

        printf("Teste %d\n", cont);
        printf("%d\n\n", cap_maxima(itens, n, s));

        scanf("%d %d", &s, &n);
    }

    return 0;
}