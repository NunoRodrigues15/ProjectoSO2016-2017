//*****************************************************************
//			Sistemas Operativos		- Projecto 2016/2017
// (●̮̮̃•̃)		João Borges				-
// /█\		Nuno Rodrigues			-
// .Π.		Vitor Paixão			-
//*****************************************************************

#include "unix.h"

typedef struct{
	int minute;
	int max_population;
	int start_time;
	int end_time;
	int capacity;
	int queue;
	int vip;
} s_simulator;
typedef struct{
	int id;
	int vip;
	int state;
	int arrival_time;
	int exit_time;
	int max_waiting_time;
} s_cliente;

/********************************* Global Variables **************************************/
int aquapark_open;
int attraction_open;
s_simulator simulator;

/************************** Threads, Mutex & Semaphores **********************************/
pthread_t t_swimming_pool;
pthread_t t_toboggan;
pthread_t t_race;
pthread_t t_sunbath;

void * sunbath(){
	printf("[%s] The Solario is now open!\n", make_hours(simulator.minute));
	while(aquapark_open){
		// recives clients
	}
	printf("[%s] The Solario is now closed!\n", make_hours(simulator.minute));
}
void * swimming_pool(){
	printf("[%s] The Swimming Pool is now open!\n", make_hours(simulator.minute));
	while(aquapark_open){
		// recives clients
	}
	printf("[%s] The he Swimming Pool is now closed!\n", make_hours(simulator.minute));
}
void * toboggan(){ // leaves when 2 or 4 clients are ready waiting at least 3 minute for each departure
	printf("[%s] The tobogan is now open!\n", make_hours(simulator.minute));
	while(attraction_open){
		printf("[%s] The tobogan is ready to get more costumers!\n", make_hours(simulator.minute));
		//whaits for 2 costumres then departures
		printf("[%s] The tobogan is departing!\n", make_hours(simulator.minute));
		sleep(3);
		// waits a minute so the constumers get to the end
	}
	printf("[%s] The tobogan is now closed!\n", make_hours(simulator.minute));
}
void * race(){ // leves evary minute
	printf("[%s] The Race tobogan is now open!\n", make_hours(simulator.minute));
	while(attraction_open){
		printf("[%s] The Race tobogan is ready to get more costumers!\n", make_hours(simulator.minute));
		sleep(1);
		// waits a minute
		printf("[%s] The Race tobogan is departing!\n", make_hours(simulator.minute));
	}
	printf("[%s] The Race tobogan is now closed!\n", make_hours(simulator.minute));
}

int main(int argc, char **argv){

	int *configuration_values = read_method(argc, argv[1]);

	DEBUG = configuration_values[0];

	simulator.max_population = configuration_values[1];
	simulator.start_time = configuration_values[2]*60;
	simulator.minute = simulator.start_time;
	simulator.end_time = configuration_values[3]*60;
	simulator.capacity = configuration_values[4];
	simulator.queue = configuration_values[5];
	simulator.vip = configuration_values[6];

	// Open the aquapark
	aquapark_open=1;
	attraction_open=1;
	printf("[%s] The Aquapark is now open!\n", make_hours(simulator.minute));


	if(pthread_create(&(t_sunbath), NULL ,(void *)&sunbath,NULL) != 0){ //thread sunbath
		printf("Erro na criacao da tarefa\n");
		exit(1);
	}
	if(pthread_create(&(t_swimming_pool), NULL ,(void *)&swimming_pool,NULL) != 0){ //thread swimming pool
		printf("Error creating thread\n");
		exit(1);
	}
	if(pthread_create(&(t_toboggan), NULL ,(void *)&toboggan,NULL) != 0){ //thread toboggan
		printf("Error creating thread\n");
		exit(1);
	}
	if(pthread_create(&(t_race), NULL ,(void *)&race,NULL) != 0){ //thread race
		printf("Erro na criacao da tarefa\n");
		exit(1);
	}



	while(simulator.minute < (simulator.end_time)){
		if(((simulator.end_time)-30) == simulator.minute){
			printf("[%s] The Aquapark is closing in 30 minuts!\n", make_hours(simulator.minute));
			attraction_open=0;
			//closes in the next departure
			pthread_join(t_race , NULL);
			pthread_join(t_toboggan , NULL);
		}
		sleep(1);
		simulator.minute++;
	}

	// closes aquapark
	aquapark_open = 0;
	pthread_join(t_sunbath , NULL);
	pthread_join(t_swimming_pool , NULL);
	printf("[%s] The Aquapark is now closed!\n", make_hours(simulator.minute));
}
