#ifndef shiyan5
#define shiyan5


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>


#define NUM_THREAD 20
#define CHAIRS 10

int waiting = 0;                /*等待区顾客数量*/

sem_t barbers;                  /*理发师信号量(是否理发)*/
sem_t customers;                /*顾客信号量(有无顾客)*/
sem_t mutex;                    /*临界区(限制椅子数目变化只能有一个线程)*/

void cut_hair();
void* barber();
void get_cut();
void* customer();

#endif // shiyan5
