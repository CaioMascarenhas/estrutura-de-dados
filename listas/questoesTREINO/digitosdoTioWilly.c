#include <stdio.h>

void calcular(int entrada,int resultado,int aux){

    if (entrada == 0)
    {   
        printf("%d\n",resultado);
        return;
    }
    
    else
    {   
        if (entrada%2==0)
        {
            resultado += (entrada%10)*aux*2;
            
        }
        else{
            resultado += (entrada%10)*aux*3;
        }
        aux++;
        entrada = entrada/10;
        calcular(entrada,resultado,aux);
    }
    

}


int main() {

    int entrada;

    while (1)
    {
        scanf("%d",&entrada);

        if (entrada==0)
        {
            break;
        }
        else
        {
            calcular(entrada,0,1);
        }
    
    }
    

    return 0;
}