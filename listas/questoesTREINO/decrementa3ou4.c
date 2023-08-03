#include <stdio.h>


int calcular(int entrada, int aux) {
    if (aux / 10 == 0) {
        
        return (aux % 2 == 0) ? (entrada - 4) : (entrada - 3);
    } else {

        aux = aux / 10;
        return calcular(entrada, aux); // Corrigido para retornar o valor da chamada recursiva
    }
}


int main()
{

    int entrada;

    scanf("%d",&entrada);

    printf("%d",calcular(entrada,entrada));

    return 0;
}