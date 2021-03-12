//信号量实例
#include "pthread.h"
#include <stdio.h>
#include <windows.h>
#include<iostream>
#include<ctime>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<vector>
#include<semaphore.h>

#define CUSTOMER_NUM 10
#pragma comment(lib,"pthreadVC2.lib")
using namespace std;

//某营业厅只能同时服务2个顾客，有多个顾客来时，若窗口已满，只能等待
sem_t sem;//将信号量定义为全局变量，这样方便多个线程共享
void *get_service(void *thread_id) {
	//立即保存thread_id的值，因为该值是对主线程循环变量i的引用，可能马上被修改
	int customer_id = *((int*)thread_id);
	if (sem_wait(&sem) == 0) {//表示当前信号量大于0，可以为顾客服务。同时将信号-1
		Sleep(0.1);//服务时间
		printf("customer %d receive service...\n", customer_id);
		sem_post(&sem);//服务完成后，把信号量+1
	}
	return 0;
}

int main() {
	//初始化信号量，初始值为2，表示同时可以有2个顾客可以接受服务
	sem_init(&sem, 0, 2);
	//为每个顾客定义一个线程id
	pthread_t customer[CUSTOMER_NUM];
	int i, iret;
	//为每个顾客生成一个线程
	for (int i = 0; i < CUSTOMER_NUM; i++) {
		int customer_id = i;
		iret = pthread_create(&customer[customer_id], NULL, get_service, &customer_id);
		if (iret) {
			perror("pthread_create.\n");
			return iret;
		}
		else {
			printf("customer %d arrived.\n", customer_id);
		}
		Sleep(1);
	}
	//等待所有顾客线程结束
	//这里不能再用i做变量，因为可能正在访问i的值
	for (int j = 0; j < CUSTOMER_NUM; j++) {
		pthread_join(customer[j], NULL);
	}
	//销毁信号量
	sem_destroy(&sem);
	return 0;
}