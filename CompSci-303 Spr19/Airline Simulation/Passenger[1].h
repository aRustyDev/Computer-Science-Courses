#include "Random.h"

class Passenger{

public:

	Passenger(int arrival_time);

	int get_arrival_time(){
		return arrival_time;
	}

	int get_processing_time(){
		return processing_time;
	}

	int get_id(){
		return passenger_id;
	}

	static void set_max_processing_time(int max_process_time){
		max_processing_time = max_process_time;
	}

private:
	int passenger_id;

	int processing_time;

	int arrival_time;

	static int max_processing_time;

	static int id_num;

	Random my_random;

};