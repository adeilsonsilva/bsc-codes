#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define SHMSZ     10
#define TAM	10 //bytes

int
main()
{

	int shmid;
	key_t key;
	int *shm;
	long pid_filho;
	int i;

	key = 567194;

	shm = (int *) calloc(TAM, sizeof(int));

	if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
		perror("shmget");
		exit(1);
	}

	if ((shm = shmat(shmid, NULL, 0)) == (int *) -1) {
		perror("shmat");
		exit(1);
	}

	pid_filho = fork();		

	if (pid_filho == 0){

		srand(time(NULL));

		for(i = 0; i < TAM; i++){
			sleep(1);
			shm[i] = 1 + rand()%19;
		}
			
	}else{

		for(i = 0; i < TAM; i++){
			while(shm[i] == 0);	
			fprintf(stdout, "Filho produziu %d: %d\n", i, shm[i]);
		}

		if (shmctl(shmid, IPC_RMID, 0) == -1) {
			fprintf(stderr, "shmctl(IPC_RMID) failed\n");
			exit(EXIT_FAILURE);
		}

	}

	

	return EXIT_SUCCESS;
}
	

