//... include header files ...

#include "../EnergyDist.h"

using namespace std;

EnergyDist::EnergyDist() {
}

EnergyDist::~EnergyDist() {
}

// function to be called at execution start
void EnergyDist::beginJob() {

	// create energy distributions for different total energy ranges
	//Background
	braggStat.push_back(new BraggStatistic(3000, 5000));

	//Africium
	braggStat.push_back(new BraggStatistic(6000, 6499));

	//Asium
	braggStat.push_back(new BraggStatistic(6500, 6799));

	//Australium
	braggStat.push_back(new BraggStatistic(6800, 7200));

	return;

}

// function to be called at execution end
void EnergyDist::endJob() {


	  for ( auto stat : braggStat ) {
	    stat->compute();
	    stat->
	  }
	  return;

}

// function to be called for each event
void EnergyDist::process(const Event& ev) {
	// loop over energy distributions and pass event to each of them
	for ( auto bStat : braggStat) {
		// The energy ranges are mutually exclusive, so
		// we can simply call them for every event.
		bStat->add(ev);
	}
	return;
}

