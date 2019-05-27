

#include "Airline_Checkin_Sim.h"

int main()
{
	Airline_Checkin_Sim simulation(0.5,0.75, 5, 2, 30, true);
	simulation.run_simulation();
	simulation.show_stats();


	return 0;
}

