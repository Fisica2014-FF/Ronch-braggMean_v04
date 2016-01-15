#ifndef EnergyDist_h
#define EnergyDist_h

//... include header files ...

#include <vector>

#include "AnalysisSteering.h"
#include "BraggStatistic.h"
#include "Event.h"

class EnergyDist: public AnalysisSteering {

public:

	EnergyDist();
	virtual ~EnergyDist();

	// function to be called at execution start
	virtual void beginJob();
	// function to be called at execution end
	virtual void endJob();
	// function to be called for each event
	virtual void process(const Event& ev);

	EnergyDist(const EnergyDist& x) = delete;
	EnergyDist& operator=(const EnergyDist& x) = delete;

private:

	// set of Bragg curves for different total energies
	std::vector<BraggStatistic*> braggStat;

};

#endif

