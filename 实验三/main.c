#include "shiyan5.h"
#include "barber.c"
#include "customer.c"


int main()
{
        int retval = 0;

        sem_init(&mutex, 0, 1);
        sem_init(&customers, 0, 0);      /*没有理发师*/
        sem_init(&barbers, 0, 0);        /*没有顾客*/

        /*1个理发师，20个顾客*/
        pthread_t bar, cus[NUM_THREAD];

        /*创建理发师*/
        retval = pthread_create(&bar, NULL, barber, NULL);
        if (0 != retval)
        {
                perror("pthread_create error.");
                return -1;
        }

        /*创建顾客*/
        for (int i=0; i<NUM_THREAD; i++){
                retval = pthread_create(&cus[i], NULL, customer, &i);
                if (0 != retval){
                        printf("%d \t return value: %d\n", i, retval);
                        perror("pthread_create error.");
                        return -1;
                }
        }


        /*将理发师和顾客加入阻塞*/
        pthread_join(bar, NULL);
        for (int i=0; i<NUM_THREAD; i++)
        {
                pthread_join(cus[i], NULL);
        }

        return 0;
}