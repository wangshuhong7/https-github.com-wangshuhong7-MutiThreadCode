//��������ʵ��2�����⳵����
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
//��ʾ���⳵�������������
pthread_cond_t taxicond = PTHREAD_COND_INITIALIZER;
//ͬ����
pthread_mutex_t taximutex = PTHREAD_MUTEX_INITIALIZER;
//���ӵļ���������¼�ȴ��̵߳ĸ���
int traverlerCount = 0;

void* traverlerArrive(void* name) {
	cout << "Traverler: " << (char*)name << " needs a taxi now." << endl;
	pthread_mutex_lock(&taximutex);
	traverlerCount++;//�ÿ�����+1
	pthread_cond_wait(&taxicond, &taximutex);//�ȴ���������
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
			pthread_cond_signal(&taxicond);//����һ���߳�
			pthread_mutex_unlock(&taximutex);//��Ҫ����
			break;
		}
		pthread_mutex_unlock(&taximutex);//��Ҫ��������Ϊ�п���û����ifѭ��
	}
	pthread_exit((void*)0);
	return 0;
}

int  main() {
	pthread_t tid[3];
	int iret = pthread_create(&tid[0], NULL, taxiArrive, (void*)("jack"));//���⳵
	if (iret) {
		cout << "pthread 1 create error " << endl;
		return iret;
	}
	cout << "time passing by.\n" << endl;
	Sleep(1);

	iret = pthread_create(&tid[1], NULL, traverlerArrive, (void*)("susan"));//�˿�
	if (iret) {
		cout << "pthread 2 create error " << endl;
		return iret;
	}
	cout << "time passing by.\n" << endl;
	Sleep(1);

	iret = pthread_create(&tid[2], NULL, taxiArrive, (void*)("mike"));//���⳵
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
