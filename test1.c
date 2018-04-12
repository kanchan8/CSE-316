#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<semaphore.h>
sem_t s;

int hours;
void *student();
void *teacher();
void *staff();

int main()
{      sem_init(&s,0,1);
	printf("user plzz enter the time in 24 hours\n");
	scanf("%d",&hours);
	
	pthread_t t1,t2,t3;
	pthread_create(&t1,NULL,student,NULL);
	pthread_create(&t2,NULL,teacher,NULL);
	pthread_create(&t3,NULL,staff,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
}
void *student()
{  
	if(hours>=22 && hours<=24 || hours>=0 && hours <=6)
	{
		sem_wait(&s);
		printf("student is playing the game\n");
		sem_post(&s);	
	}
}

void *teacher()
{
		if(hours>=17 && hours<=24 || hours>=0 && hours<=8)
		{
			sem_wait(&s);
			printf("teacher is playing the game\n");
			sem_post(&s);
		}
	
}

void *staff()
{   
		sem_wait(&s);
		printf("staff is playing the game\n");
		sem_post(&s);
}

