//... include header files ...

#include "../EnergyDist.h"

#include <cstdio>
#include <iostream>

using namespace std;

EnergyDist::EnergyDist() {
}

EnergyDist::~EnergyDist() {
	for (auto& bs : braggStat) {
		delete bs;
	}
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

	for (unsigned i = 0; i < braggStat.size(); ++i) {
		auto stat = braggStat[i];
		braggStat[i]->compute();

		cout << "Energy range #" << i << endl;
		for (unsigned j = 0; j < stat->eMean().size(); ++j) {
			// It would have been preferable to
			// have getters for min and max energises.
			printf("%4f +/- %4f ", stat->eMean()[j], stat->eRMS()[j]);
			cout << endl;
		}
	}

	return;
}

// function to be called for each event
void EnergyDist::process(const Event& ev) {
	// loop over energy distributions and pass event to each of them
	for (auto bStat : braggStat) {
		// The energy ranges are mutually exclusive, so
		// we can simply call them for every event.
		bStat->add(ev);
	}
	return;
}

