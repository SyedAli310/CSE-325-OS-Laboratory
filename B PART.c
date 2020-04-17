#include<stdio.h>
#include<pthread.h>
int global[2];

void *sum_thread(void *arg)
{
    int *arg_array;
    arg_array = arg;

    int n1,n2,sum;
    n1=arg_array[0];
    n2=arg_array[1];
    sum = n1+n2;
printf("Welcome\n");
    printf("Addition= %d\n",sum);


    return NULL;
}

int main() 
{
    printf("First no: ");
    scanf("%d",&global[0]);

    printf("Second no: ");
    scanf("%d",&global[1]);

    pthread_t tid_sum, tid1;
    pthread_create(&tid_sum,NULL,sum_thread,global);
    pthread_join(tid_sum,NULL);
pthread_create(&tid1, NULL, sum_thread,NULL);

    return 0;
}
