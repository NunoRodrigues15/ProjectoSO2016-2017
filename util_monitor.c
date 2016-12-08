//*****************************************************************
//			Sistemas Operativos		- Projecto 2016/2017
// (●̮̮̃•̃)		João Borges				-
// /█\		Nuno Rodrigues			-
// .Π.		Vitor Paixão			-
//*****************************************************************

#include "unix.h"

int write_log(int hour, int state, int client_id){
	FILE *file_log = fopen("simulation.log", "a");
	if(file_log == NULL){
		printf("Error: opening simulation.log\n");
		return 0;
	}

	switch(state) {
		case 1: fprintf(file_log,"[%s] ❤ Client %d arrived to AquaPark.\n", make_hours(hour), client_id);break;
		case 2: fprintf(file_log,"[%s] ➤ Client %d arrived to swimming pool.\n", make_hours(hour), client_id); break;
		case 3: fprintf(file_log,"[%s] ➤ Client %d arrived to Toboggan.\n", make_hours(hour), client_id); break;
		case 4: fprintf(file_log,"[%s] ➤ Client %d arrived to Race.\n", make_hours(hour), client_id); break;
		case 5: fprintf(file_log,"[%s] ➤ Client %d arrived to Sunbath\n", make_hours(hour), client_id); break;
		case 11: fprintf(file_log,"[%s] ☀ Client %d entered to AquaPark.\n", make_hours(hour), client_id); break;
		case 12: fprintf(file_log,"[%s] ☀ Client %d entered to swimming pool.\n", make_hours(hour), client_id); break;
		case 13: fprintf(file_log,"[%s] ☀ Client %d entered to Toboggan.\n", make_hours(hour), client_id); break;
		case 14: fprintf(file_log,"[%s] ☀ Client %d entered to Race.\n", make_hours(hour), client_id); break;
		case 15: fprintf(file_log,"[%s] ☀ Client %d entered to Sunbath\n", make_hours(hour), client_id); break;
		case 21: fprintf(file_log,"[%s] ★ Client %d went out of AquaPark.\n", make_hours(hour), client_id); break;
		case 22: fprintf(file_log,"[%s] ⚫ Client %d went out of swimming pool.\n", make_hours(hour), client_id); break;
		case 23: fprintf(file_log,"[%s] ⚫ Client %d went out of Toboggan.\n", make_hours(hour), client_id); break;
		case 24: fprintf(file_log,"[%s] ⚫ Client %d went out of Race.\n", make_hours(hour), client_id); break;
		case 25: fprintf(file_log,"[%s] ⚫ Client %d went out of Sunbath\n", make_hours(hour), client_id); break;
		case 31: fprintf(file_log,"[%s] ❌ Client %d gave up on AquaPark, was waiting for too long\n", make_hours(hour), client_id); break;
		case 32: fprintf(file_log,"[%s] ❌ Client %d gave up on swimming pool, was waiting for too long\n", make_hours(hour), client_id); break;
		case 33: fprintf(file_log,"[%s] ❌ Client %d gave up on Toboggan, was waiting for too long\n", make_hours(hour), client_id); break;
		case 34: fprintf(file_log,"[%s] ❌ Client %d gave up on Race, was waiting for too long\n", make_hours(hour), client_id); break;
		case 35: fprintf(file_log,"[%s] ❌ Client %d gave up on Sunbath, was waiting for too long\n", make_hours(hour), client_id); break;
		case 100: fprintf(file_log,"[%s] ⛬ Simulation started.\n", make_hours(hour)); break;
		case 101: fprintf(file_log,"[%s] ⛬ Simulation is over.\n", make_hours(hour)); break;
		default: fprintf(file_log,"[%s] Error: didnt get what you mean", make_hours(hour)); break;
	}
	fclose(file_log);
	return 1;
}

int write_report(){
	FILE *file_report = fopen("statistics.txt", "w");
	if(file_report == NULL){
		printf("Erro ao abrir o ficheiro Relatorio.txt\n");
		return 0;
	}

	fprintf(file_report,"%s","---------------------------Simulation statistics--------------------------\n");
	fprintf(file_report,"%s","Clientes:\n");
	fprintf(file_report,"	%s : %d\n","Total clients on AquaPark", 2);
	fprintf(file_report,"	%s : %d\n","Total clients on swimming pool", 1);
	fprintf(file_report,"	%s : %d\n","Total clients on Toboggan", 0);
	fprintf(file_report,"	%s : %d\n","Total clients on Race", 0);
	fprintf(file_report,"	%s : %d\n","Total clients on Sunbath", 0);
	fprintf(file_report,"	%s : %d\n","Average of VIP clients on AquaPark", 0);
	fprintf(file_report,"	%s : %d\n","Average of VIP clients on swimming pool", 0);
	fprintf(file_report,"	%s : %d\n","Average of VIP clients on Toboggan", 0);
	fprintf(file_report,"	%s : %d\n","Average of VIP clients on Race", 0);
	fprintf(file_report,"	%s : %d\n","Average of VIP clients on Sunbath", 0);
	fprintf(file_report,"%s","Drops:\n");
	fprintf(file_report,"	%s : %d\n","Total drops on queue",0);
	fprintf(file_report,"	%s : %d\n","Drops on AquaPark",0);
	fprintf(file_report,"	%s : %d\n","Drops on swimming pool",1);
	fprintf(file_report,"	%s : %d\n","Drops on Toboggan",0);
	fprintf(file_report,"	%s : %d\n","Drops on  Race",0);
	fprintf(file_report,"	%s : %d\n","Drops on  Sunbath",0);
	fprintf(file_report,"%s","Average time:\n");
	fprintf(file_report,"	%s : %f\n","Average time on AquaPark",0.0);
	fprintf(file_report,"	%s : %f\n","Average time on swimming pool",0.0);
	fprintf(file_report,"	%s : %f\n","Average time on Toboggan",0.0);
	fprintf(file_report,"	%s : %f\n","Average time on Race",0.0);
	fprintf(file_report,"	%s : %f\n","Average time on Sunbath",0.0);
	fprintf(file_report,"%s","Max time:\n");
	fprintf(file_report,"	%s : %f\n","Max time on AquaPark",0.0);
	fprintf(file_report,"	%s : %f\n","Max time on swimming pool",0.0);
	fprintf(file_report,"	%s : %f\n","Max time on Toboggan",0.0);
	fprintf(file_report,"	%s : %f\n","Max time on Race",0.0);
	fprintf(file_report,"	%s : %f\n","Max time on Sunbath",0.0);
	fprintf(file_report,"%s","\n--------------------------------------------------------------------------\n");
	fclose(file_report);

	return 1;
}

int * decode (char str[28]){

	char s_hours[4];
	char s_state[3];
	char s_client_id[4];
	int static final[3];

	stpcpy(s_hours, strtok(str,","));
	stpcpy(s_state, strtok(NULL,","));
	strcpy(s_client_id, strtok(NULL,","));

	final[0] = atoi(s_hours);
	final[1] = atoi(s_state);
	final[2] = atoi(s_client_id);

	return final;
}

void write_decoder(int final[3]) {

	int state = final[1];

	switch(state) {
		case 1: printf("[%s] ❤ Client %d arrived to AquaPark.\n", make_hours(final[0]), final[2]);break;
		case 2: printf("[%s] ➤ Client %d arrived to swimming pool.\n", make_hours(final[0]), final[2]); break;
		case 3: printf("[%s] ➤ Client %d arrived to Toboggan.\n", make_hours(final[0]), final[2]); break;
		case 4: printf("[%s] ➤ Client %d arrived to Race.\n", make_hours(final[0]), final[2]); break;
		case 5: printf("[%s] ➤ Client %d arrived to Sunbath\n", make_hours(final[0]), final[2]); break;
		case 11: printf("[%s] ☀ Client %d entered to AquaPark.\n", make_hours(final[0]), final[2]); break;
		case 12: printf("[%s] ☀ Client %d entered to swimming pool.\n", make_hours(final[0]), final[2]); break;
		case 13: printf("[%s] ☀ Client %d entered to Toboggan.\n", make_hours(final[0]), final[2]); break;
		case 14: printf("[%s] ☀ Client %d entered to Race.\n", make_hours(final[0]), final[2]); break;
		case 15: printf("[%s] ☀ Client %d entered to Sunbath\n", make_hours(final[0]), final[2]); break;
		case 21: printf("[%s] ★ Client %d went out of AquaPark.\n", make_hours(final[0]), final[2]); break;
		case 22: printf("[%s] ⚫ Client %d went out of swimming pool.\n", make_hours(final[0]), final[2]); break;
		case 23: printf("[%s] ⚫ Client %d went out of Toboggan.\n", make_hours(final[0]), final[2]); break;
		case 24: printf("[%s] ⚫ Client %d went out of Race.\n", make_hours(final[0]), final[2]); break;
		case 25: printf("[%s] ⚫ Client %d went out of Sunbath\n", make_hours(final[0]), final[2]); break;
		case 31: printf("[%s] ❌ Client %d gave up on AquaPark, was waiting for too long\n", make_hours(final[0]), final[2]); break;
		case 32: printf("[%s] ❌ Client %d gave up on swimming pool, was waiting for too long\n", make_hours(final[0]), final[2]); break;
		case 33: printf("[%s] ❌ Client %d gave up on Toboggan, was waiting for too long\n", make_hours(final[0]), final[2]); break;
		case 34: printf("[%s] ❌ Client %d gave up on Race, was waiting for too long\n", make_hours(final[0]), final[2]); break;
		case 35: printf("[%s] ❌ Client %d gave up on Sunbath, was waiting for too long\n", make_hours(final[0]), final[2]); break;
		case 100: printf("[%s] ⛬ Simulation started.\n", make_hours(final[0])); break;
		case 101: printf("[%s] ⛬ Simulation is over.\n", make_hours(final[0])); break;
		default: printf("[%s] Error: didnt get what you mean", make_hours(final[0])); break;
	}

}
