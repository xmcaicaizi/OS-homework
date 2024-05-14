#include "shiyan5.h"

void cut_hair()
{
        printf("理发师:开始理发\n");
        sleep(1);
}

/*理发师函数*/

void* barber()
{
        while(1)
        {
                sem_wait(&customers);                                   /*如无顾客,理发师睡觉(等待)*/
                sem_wait(&mutex);                                               /*顾客进入临界区*/

                waiting = waiting - 1;                                  /*等候顾客数少一个*/
                printf("理发师: 还剩 %d 个顾客\n", waiting);

                sem_post(&barbers);                                             /*唤醒理发师*/
                sem_post(&mutex);                                               /*释放临界区*/
                cut_hair();
                /*开始理发*/

                sem_wait(&mutex);
                if(waiting == 0)
                {
                        sem_post(&mutex);
                        break;
                }
                sem_post(&mutex);
        }
        printf("没有顾客，理发师去睡觉了\n");
        pthread_exit(NULL);
}