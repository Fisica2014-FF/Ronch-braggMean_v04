... include header files ...

using namespace std;

EnergyDist::EnergyDist() {
}


EnergyDist::~EnergyDist() {
}


// function to be called at execution start
... {

  // create energy distributions for different total energy ranges
  ...
  return;

}


// function to be called at execution end
... {

  // number of points
  ...

  // loop over distributions
  ...
  for ( ... ) {
    // get Bragg curve informations
    ...
    // compute results
    ...
    // get mean and rms energies
    ...
    // loop over points
    for ( ... ) {
      // print results
      ...
    }
    // print number of events
    ...
  }

  return;

}


// function to be called for each event
... {
  // loop over energy distributions and pass event to each of them
  ...
  for ( ... ) {
      ...
  }
  return;
}

