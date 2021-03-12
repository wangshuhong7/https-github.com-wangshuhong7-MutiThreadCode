//读写锁实例1
/*#include "pthread.h"
#include <stdio.h>
#include <windows.h>
#include<iostream>
#include<ctime>
#include<string>
#include<sstream>
#include<stdlib.h>
#pragma comment(lib,"pthreadVC2.lib")
#define THREADNUM 10
using namespace std;
pthread_rwlock_t rwlock;
void *readers(void*arg) {
	pthread_rwlock_rdlock(&rwlock);//读锁
	printf("reader: %ld got the lock.\n", (long)arg);
	pthread_rwlock_unlock(&rwlock);//解锁
	pthread_exit((void*)0);
	return 0;
}

void* writers(void* arg) {
	pthread_rwlock_wrlock(&rwlock);//写锁
	printf("writers: %ld got the lock.\n", (long)arg);
	pthread_rwlock_unlock(&rwlock);//解锁
	pthread_exit((void*)0);
	return 0;
}

int main(int argc, char**argv) {
	int iret, i;
	pthread_t writerId, readerId;
	
	int nreadcount = 1, nwritecount = 1;
	iret = pthread_rwlock_init(&rwlock, NULL);//初始化，使用默认属性
	if (iret) {
		fprintf(stderr, "init lock failed.\n");
		return iret;
	}
	//设置线程为分离状态
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	for (int i = 0; i < THREADNUM; i++) {
		if (i % 3) {
			pthread_create(&readerId, &attr, readers, (void*)nreadcount);//创建读线程
			printf("create reader  %d\n", nreadcount++);
		}
		else {
			pthread_create(&writerId, &attr, writers, (void*)nwritecount);//创建写线程
			printf("create writer %d.\n", nwritecount++);
		}
	}
	Sleep(5);//sleep是为了等待另外的线程的执行
	return 0;
}*/