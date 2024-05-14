#include "shiyan5.h"

void get_cut()
{
        printf("Thread ID: %ld 准备理发\n", pthread_self());
}


void* customer()
{
        sem_wait(&mutex);           /*顾客进入临界区*/
        if(waiting < CHAIRS)        /*有空椅子*/
        {
                waiting++;
                printf("顾客进店，现在店里有 %d 个顾客等待\n", waiting);
                sem_post(&customers);    /*顾客资源加1*/
                sem_post(&mutex);       /*释放临界区*/

                sem_wait(&barbers);      /*等待理发师理发*/
                /*理发*/
                get_cut();
        }
        else
        {
                printf("没有椅子顾客离开\n");
                sem_post(&mutex);       /*释放临界区*/
        }

        pthread_exit(NULL);
        /*释放进程*/
}