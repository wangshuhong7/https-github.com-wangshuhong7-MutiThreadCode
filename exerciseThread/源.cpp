#include "pthread.h"
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
void* thread(void* val)
{
	int value = *((int*)val);
	printf("value: %d \n", value);
	printf("thread2 id in thread= %lu\n", pthread_self());
	/*while (value-- > 0)
	{
		printf(" %d \n", value);
	}*/
	time_t now = time(0);
	
	
	cout<<"time2 : "<<now<<endl;
	return NULL;
}

void* function(void *arg) {
	printf("thread1 id in thread= %lu\n", pthread_self());
	time_t now = time(0);

	cout << "time1 : " << now << endl;
	pthread_exit((void*)1);
	return nullptr;
}

void *tfn1(void* arg) {
	printf("thread tfn1 id in thread= %lu\n", pthread_self());
	printf("the sub thread sleeping for 5 seconds.\n");
	Sleep(1);
	printf("the thread done\n");
	return nullptr;
}

int totalTickets = 25;
pthread_mutex_t mutex_x = PTHREAD_MUTEX_INITIALIZER;
void * sell(void* arg) {
	for (int i = 0; i < 25; i++) {
		pthread_mutex_lock(&mutex_x);//上锁
		if (totalTickets > 0) {
			
			printf("thread1: sell the %dth ticket\n", 20 - totalTickets + 1);
			totalTickets--;
		}
		Sleep(1);
		pthread_mutex_unlock(&mutex_x);//解锁
		Sleep(1);
	}
	return 0;
}
void *sell2(void *arg) {
	int iRet = 0;
	for (int i = 0; i < 10; i++) {
		iRet = pthread_mutex_trylock(&mutex_x);//测试锁
		if (iRet == EBUSY) {
			printf("sell2: the variable is locked by sell1. \n");
		}
		else if (iRet == 0) {
			if (totalTickets > 0) {
				printf("thread2 : sell the %dth ticket\n", 20 - totalTickets + 1);
				totalTickets--;
			}
			pthread_mutex_unlock(&mutex_x);//解锁
		}
		Sleep(1);
	}
	return 0;
}
/*int main()
{
	pthread_t tids[2];
	int iRet = pthread_create(&tids[0], NULL, &sell, NULL);//thread 1
	if (iRet) {
		printf("can't creat thread %d,rt=%d\n", tids[0], iRet);
		return iRet;
	}
	iRet = pthread_create(&tids[1], NULL, &sell2, NULL); //thread 2
	if (iRet) {
		printf("can't creat thread %d,rt=%d\n", tids[1], iRet);
		return iRet;
	}
	Sleep(30);
	void* retval;
	iRet = pthread_join(tids[0], &retval);//thread 1
	if (iRet) {
		printf("tid=%d join error, iret=%d\n", tids[0], iRet);
		return iRet;
	}
	else {
		printf("retval = %ld\n", (long*)retval);
	}

	iRet = pthread_join(tids[1], &retval);//thread 2
	if (iRet) {
		printf("tid=%d join error, iret=%d\n", tids[1], iRet);
		return iRet;
	}
	else {
		printf("retval = %ld\n", (long*)retval);
	}

	return 0;
}*/
	/*pthread_t tpid[4];
	int rt;
	for (int i = 0; i < 4; i++) {
		//创建了4个线程
		rt = pthread_create(&tpid[i], NULL, sell, NULL);
		if (rt) {
			printf("can't creat thread %d,rt=%d\n", tpid[i],rt);
			return rt;
		}
	}
	Sleep(1);
	void *retval;
	for (int i = 0; i < 4; i++) {
		rt = pthread_join(tpid[i], &retval);
		if (rt) {
			printf("tid=%d join error, iret=%d\n", tpid[i], rt);
			return rt;
		}
		printf("retval =%ld\n", (long*)retval);
	}*/
	

	
	
	/*pthread_t pid;
	int ret;
	int val = 100;
	ret = pthread_create(&pid, nullptr, thread,&val);
	printf("thread2 id in process = %lu\n", pid);
	void* retval2;
	ret = pthread_join(pid,&retval2);
	printf("retval2  = %ld\n",  (long*)retval2);*/


	
