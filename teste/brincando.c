#include <stdio.h>


int main(){
        int numturmas;
        scanf("%d",&numturmas);
        int turmas[numturmas];
        int x=0;

    for (int i = 0; i < 10; i++)
    {
        int *v;
        v = malloc(4 * sizeof(int));

        for (int i = 0; i < 4; i++)
        {
            v[i]=x;
            printf("%d ",v[i]);
            x++;
        }
    printf("\n");
    free(v);

    }
    
    return 0;
}