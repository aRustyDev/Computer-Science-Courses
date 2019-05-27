#include "Passenger_Queue.h"

class Airline_Checkin_Sim {

public:

	Airline_Checkin_Sim() : frequent_flyer_queue("Frequent Flyer Queue"), regular_passenger_queue("Regular Passenger Queue"), clock(0), time_done(0){}
	
	Airline_Checkin_Sim(double frequent_arrival_rate, double regular_arrival_rate, int frequent_flyer_max, int max_processing_time, int total_time, bool show_all) :
		frequent_flyer_queue("Frequent Flyer Queue"), regular_passenger_queue("Regular Passenger Queue"), frequent_flyer_max(frequent_flyer_max), max_processing_time(max_processing_time), total_time(total_time), show_all(show_all){
		
		frequent_flyer_queue.set_arrival_rate(frequent_arrival_rate);
		regular_passenger_queue.set_arrival_rate(regular_arrival_rate);

		Passenger::set_max_processing_time(max_processing_time);
	}


	void run_simulation();

	void show_stats();

	//void enter_data();

	
private:

	void start_serve();

	Passenger_Queue frequent_flyer_queue;

	Passenger_Queue regular_passenger_queue;

	int frequent_flyer_max;

	int max_processing_time;

	int total_time;

	bool show_all;

	int clock;

	int time_done;

	int frequent_flyers_since_RP;


};

void Airline_Checkin_Sim::run_simulation() {
	for (clock = 0; clock < total_time; clock++) {
		frequent_flyer_queue.check_new_arrival(clock, show_all);
		regular_passenger_queue.check_new_arrival(clock, show_all);
		if (clock >= time_done) {
			start_serve();
		}
	}
}

void Airline_Checkin_Sim::start_serve() {
	if (!frequent_flyer_queue.empty()
		&& ((frequent_flyers_since_RP <= frequent_flyer_max)
		|| regular_passenger_queue.empty())) {
		// Serve the next frequent flyer.
		frequent_flyers_since_RP++;
		time_done = frequent_flyer_queue.update(clock, show_all);
	}
	else if (!regular_passenger_queue.empty()) {
		// Serve the next regular passenger.
		frequent_flyers_since_RP = 0;
		time_done = regular_passenger_queue.update(clock, show_all);
	}
	else if (show_all) {
		cout << "Time is " << clock
			<< ": Server is idle\n";
	}
}


void Airline_Checkin_Sim::show_stats(){
	cout << "\n The number of regular passengers served was "
		<< regular_passenger_queue.get_num_served() << endl;
	double average_waiting_time = double(regular_passenger_queue.get_total_wait()) 
		/ double(regular_passenger_queue.get_num_served());
	
	cout << " with an average waiting time of "
		<< average_waiting_time << endl;

	cout << "The number of frequent flyers served was "
		<< frequent_flyer_queue.get_num_served() << endl;

	average_waiting_time =
		double(frequent_flyer_queue.get_total_wait())
		/ double(frequent_flyer_queue.get_num_served());

	cout << " with an average waiting time of "
		<< average_waiting_time << endl;
	
	cout << "Passengers in frequent flyer queue:"
		<< frequent_flyer_queue.size() << endl;

	cout << "Passengers in regular passenger queue:"
		<< regular_passenger_queue.size() << endl;
}
