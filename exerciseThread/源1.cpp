//条件变量实例1
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
pthread_cond_t qready = PTHREAD_COND_INITIALIZER;
pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;
int x = 10;
int y = 20;
void* fun1(void *arg) {
	cout << "func 1 start: " << endl;
	pthread_mutex_lock(&qlock);
	while (x < y) {
		cout << "fun1 block" << endl;
		pthread_cond_wait(&qready, &qlock);//x<y，阻塞，等待条件(x>=y)满足
		
	}
	pthread_mutex_unlock(&qlock);
	cout << "x= " << x << " y= " << y << endl;
	Sleep(3);
	cout << "func 1 end. " << endl;
	return 0;
}

void* fun2(void* arg) {
	cout << "func 2 start: " << endl;
	pthread_mutex_lock(&qlock);
	x = 20;
	y = 10;
	cout << "has changed x and y." << endl;
	pthread_mutex_unlock(&qlock);
	if (x > y) {
		pthread_cond_signal(&qready);//激活func 1 线程
	}
	cout << "func 2 end." << endl;
	return 0;
}

int main(int argc, char **argv) {
	pthread_t tid1, tid2;
	int iRet;
	iRet = pthread_create(&tid1, NULL, fun1, NULL);
	if (iRet) {
		cout << "pthread 1 create error " << endl;
		return iRet;
	}
	Sleep(2);//确保线程1先执行
	iRet = pthread_create(&tid2, NULL, fun2, NULL);
	if (iRet) {
		cout << "pthread 2 create error " << endl;
		return iRet;
	}
	Sleep(5);
	
	return 0;
}*/