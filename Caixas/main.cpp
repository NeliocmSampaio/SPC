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
                    pilha_c1 = i+1;
                    altura_c1 = j;
                }//if
            }//for
            alturas[i] = caixas_na_pilha;
        }//for

        for(int i=0; i<=pilha_c1; i++)
        {
            if(alturas[i]>altura_c1)
            {
                soma_alturas_dir+=alturas[i]-altura_c1;
            }else
            {
                soma_alturas_dir = 0;
            }
        }//for

        for(int i=pilha_c1; i<p; i++)
        {
            if(alturas[i]>altura_c1)
            {
                soma_alturas_esq+=alturas[i]-altura_c1;
            }else
            {
                break;
            }
        }//for

        printf("%d\n", soma_alturas_dir<soma_alturas_esq ?
                       soma_alturas_dir : soma_alturas_esq);

        scanf("%d %d", &n, &p);
    }//while

    return 0;
}