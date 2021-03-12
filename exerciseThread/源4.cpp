//�ź���ʵ��
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

//ĳӪҵ��ֻ��ͬʱ����2���˿ͣ��ж���˿���ʱ��������������ֻ�ܵȴ�
sem_t sem;//���ź�������Ϊȫ�ֱ����������������̹߳���
void *get_service(void *thread_id) {
	//��������thread_id��ֵ����Ϊ��ֵ�Ƕ����߳�ѭ������i�����ã��������ϱ��޸�
	int customer_id = *((int*)thread_id);
	if (sem_wait(&sem) == 0) {//��ʾ��ǰ�ź�������0������Ϊ�˿ͷ���ͬʱ���ź�-1
		Sleep(0.1);//����ʱ��
		printf("customer %d receive service...\n", customer_id);
		sem_post(&sem);//������ɺ󣬰��ź���+1
	}
	return 0;
}

int main() {
	//��ʼ���ź�������ʼֵΪ2����ʾͬʱ������2���˿Ϳ��Խ��ܷ���
	sem_init(&sem, 0, 2);
	//Ϊÿ���˿Ͷ���һ���߳�id
	pthread_t customer[CUSTOMER_NUM];
	int i, iret;
	//Ϊÿ���˿�����һ���߳�
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
	//�ȴ����й˿��߳̽���
	//���ﲻ������i����������Ϊ�������ڷ���i��ֵ
	for (int j = 0; j < CUSTOMER_NUM; j++) {
		pthread_join(customer[j], NULL);
	}
	//�����ź���
	sem_destroy(&sem);
	return 0;
}