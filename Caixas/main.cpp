/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: CAIXAS   Problema: Desempilhando Caixas
 *
 * O algoritmo, primeiramente, salva a altura de cada pilha pelo número de caixas de cada uma.
 * Depois, conta o número de caixas acima da caixa 1 nas pilhas entre a última pilha com altura
 * menor que a altura da caixa 1 e a pilha anterior à pilha que contém a caixa 1, a soma dessas
 * caixas com o número de caixas acima da caixa 1 é a dificuldade de desempilhá-la pelo lado
 * esquerdo. O processe é repetido para o lado direito, e a resposta é a menor entre a dificuldade
 * do lado esquerdo e do lado direito.
 * */

#include <iostream>

int main() {
    int n, p, caixas_na_pilha, caixa, soma_alturas_dir,
            soma_alturas_esq;
    int altura_c1, pilha_c1, altura;
    bool flag;

    scanf("%d %d", &n, &p);
    while(n!=0)
    {
        soma_alturas_dir = 0;
        soma_alturas_esq = 0;
        flag = false;
        int alturas[p+1];

        for(int i=0; i<p; i++)
        {
            scanf("%d", &caixas_na_pilha);
            for(int j=0; j<caixas_na_pilha; j++)
            {
                scanf("%d", &caixa);
                if(caixa == 1)
                {
                    pilha_c1 = i;
                    altura_c1 = j+1;
                }//if
            }//for
            alturas[i] = caixas_na_pilha;
        }//for

        for(int i=0; i<pilha_c1; i++)
        {
            if(alturas[i]>=altura_c1)
            {
                soma_alturas_dir+=alturas[i]+1-altura_c1;
            }else
            {
                soma_alturas_dir = 0;
            }
        }//for

        for(int i=pilha_c1+1; i<p; i++)
        {
            if(alturas[i]>=altura_c1)
            {
                soma_alturas_esq+=alturas[i]+1-altura_c1;
            }else
            {
                break;
            }
        }//for
        soma_alturas_dir += alturas[pilha_c1] - altura_c1;
        soma_alturas_esq += alturas[pilha_c1] - altura_c1;

        printf("%d\n", soma_alturas_dir<soma_alturas_esq ?
                       soma_alturas_dir : soma_alturas_esq);

        scanf("%d %d", &n, &p);
    }//while

    return 0;
}