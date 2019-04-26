#include<stdio.h>
#include<pthread.h>

int sumAdd, sumSub, sumMul;
float sumDiv;

int addIt(int m[2]) {
	sumAdd = m[0] + m[1];
	pthread_exit(&sumAdd);
}

int subIt(int m[2]) {
	sumSub = m[0] - m[1];
	pthread_exit(&sumSub);
}

int mulIt(int m[2]) {
	sumMul = m[0] * m[1];
	pthread_exit(&sumMul);
}

float divIt(int m[2]) {
	sumDiv = m[0] / m[1];
	pthread_exit(&sumDiv);
}

int main() {
	int p[2];
	void *s1,*s2,*s3,*s4;
	int a,s,m;
	float d;
	pthread_t thread1,thread2,thread3, thread4;
	
	printf("\n Enter two numbers");
	scanf("%d %d",&p[0],&p[1]);
	
	
	pthread_create(&thread1,NULL,(void *)addIt,p);
	pthread_create(&thread2,NULL,(void *)subIt,p);
	pthread_create(&thread3,NULL,(void *)mulIt,p);
	pthread_create(&thread4,NULL,(void *)divIt,p);
	
	
	pthread_join(thread1, &s1);
	pthread_join(thread2, &s2);
	pthread_join(thread3, &s3);
	pthread_join(thread4, &s4);
	
	a = *(int *)s1;
	s = *(int *)s2;
	m = *(int *)s3;
	d = *(float *)s4;

	printf("\n Addition is- %d",a);
	printf("\n Subtraction is- %d",s);
	printf("\n Multiplication is- %d",m);
	printf("\n Divsion is- %2.2f",d);
	return 0;
}
