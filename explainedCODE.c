/* header files included is */
include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<semaphore.h>     //it contains the locking semaphore
#include<stdio.h>

sem_t s;    //declaring semaphore variable
int hours;

void *student();   //function for student to let student play the game
void *teacher();   //function for teacher to let faculty member play the game
void *staff();      //for staff

int main()

{  	
		pthread_t t1,t2,t3;            //
        sem_init(&s,0,1);              //initialising semaphore variable by 1
		printf("user ,please enter time hh : min \n");
		scanf("%d",&hours);             /* time is taken as inputed by user*/
	
	/*thred creation*/
	pthread_create(&t1,NULL,student,NULL);        
	pthread_create(&t2,NULL,teacher,NULL);
	pthread_create(&t3,NULL,staff,NULL);
	/*thread joining*/
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
}
void *student()
{  
	if(hours>=22 && hours<=24 || hours>=0 && hours <=6)
	{
		
		sem_wait(&s);     //impose lock
		printf("game is played by student\n");
		sem_post(&s);	// release the lock
		
	}
}

void *teacher()
{
	if(hours>=17 && hours<=24 || hours>=0 && hours<=8)
		{
			
			sem_wait(&s);   will impose the lock
			printf("game is played by teacher\n");
			
			sem_post(&s);  will release the lock
		}
	
}

void *staff()
{   sem_wait(&s);   // imposing the lock
    printf("staff is playing the game\n");
    sem_post(&s);  //releasing the lock
}
