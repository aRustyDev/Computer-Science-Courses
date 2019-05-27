#include "Passenger.h"
//#include "Random.h"
//extern Random my_random;

Passenger::Passenger(int arrive_time){
	arrival_time = arrive_time;
	processing_time = 1 + my_random.next_int(max_processing_time);
	passenger_id = id_num++;
}

int Passenger::max_processing_time;

int Passenger::id_num = 0;