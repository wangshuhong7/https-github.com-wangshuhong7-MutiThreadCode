//条件变量实例2：出租车问题
/*#include "pthread.h"
#include <stdio.h>
#include <windows.h>
#include<iostream>
#include<ctime>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<vector>
#pragma comment(lib,"pthreadVC2.lib")

using namespace std;
//提示出租车到达的条件变量
pthread_cond_t taxicond = PTHREAD_COND_INITIALIZER;
//同步锁
pthread_mutex_t taximutex = PTHREAD_MUTEX_INITIALIZER;
//增加的计数器，记录等待线程的个数
int traverlerCount = 0;

void* traverlerArrive(void* name) {
	cout << "Traverler: " << (char*)name << " needs a taxi now." << endl;
	pthread_mutex_lock(&taximutex);
	traverlerCount++;//旅客数量+1
	pthread_cond_wait(&taxicond, &taximutex);//等待条件满足
	pthread_mutex_unlock(&taximutex);
	cout << "Traverler :" << (char*)name << " now got a taxi." << endl;
	pthread_exit((void*)0);
	return 0;
}

void* taxiArrive(void* name) {
	cout << "Taxi: " << (char*)name << " arrives." << endl;
	while (1) {
		pthread_mutex_lock(&taximutex);
		if (traverlerCount > 0) {
			pthread_cond_signal(&taxicond);//激活一个线程
			pthread_mutex_unlock(&taximutex);//需要解锁
			break;
		}
		pthread_mutex_unlock(&taximutex);//需要解锁，因为有可能没进入if循环
	}
	pthread_exit((void*)0);
	return 0;
}

int  main() {
	pthread_t tid[3];
	int iret = pthread_create(&tid[0], NULL, taxiArrive, (void*)("jack"));//出租车
	if (iret) {
		cout << "pthread 1 create error " << endl;
		return iret;
	}
	cout << "time passing by.\n" << endl;
	Sleep(1);

	iret = pthread_create(&tid[1], NULL, traverlerArrive, (void*)("susan"));//乘客
	if (iret) {
		cout << "pthread 2 create error " << endl;
		return iret;
	}
	cout << "time passing by.\n" << endl;
	Sleep(1);

	iret = pthread_create(&tid[2], NULL, taxiArrive, (void*)("mike"));//出租车
	if (iret) {
		cout << "pthread 3 create error " << endl;
		return iret;
	}
	cout << "time passing by.\n" << endl;
	Sleep(1);

	void* retval;
	for (int i = 0; i < 3; i++) {
		iret = pthread_join(tid[i], &retval);
		if (iret) {
			printf("pthread_join error: iret: %d\n", iret);
			return iret;
		}
		printf("retval = %ld\n", (long)retval);
	}
	return 0;
}*/
