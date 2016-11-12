#include <TrackingProcessor.h>
#include <EVENT/LCCollection.h>
#include <IMPL/LCCollectionVec.h>
#include <EVENT/LCFloatVec.h>
#include <EVENT/MCParticle.h>
#include <EVENT/ReconstructedParticle.h>
#include <IMPL/MCParticleImpl.h>
#include <EVENT/LCFloatVec.h>
#include <EVENT/LCParameters.h>

#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

#include "StraightLine.h"
//extern class StraightLine;


// FIXIT
// Why do I need an instance here?
TrackingProcessor aTrackingProcessor;

TrackingProcessor::TrackingProcessor() : marlin::Processor("TrackingProcessor")
{
	_description = "";
}

void TrackingProcessor::init()
{
    StraightLine::setReferencePoint(0.0, 0.0, 0.0);
	streamlog_out(MESSAGE) << "\033[31m Tracking Processor Start \033[0m" << endl;
	// printParameters();
}


void TrackingProcessor::processEvent( LCEvent * evtP )
{
	// Check Event
	if (evtP == NULL)
	{
		streamlog_out(ERROR) << "\033[31m ERROR the event is empty \033[0m" << endl;
		return;
	}


	// Process clupatra
	processClupatraTracks( evtP );
    processSiTracks( evtP );
    processMarlinTracks( evtP );
	//processTrackingHits( evtP );
}

void TrackingProcessor::end()
{
    streamlog_out(MESSAGE) << "\033[31m Tracking Processor Stop \033[0m" << endl;
}

void TrackingProcessor::processClupatraTracks( LCEvent * evtP )
{
    streamlog_out(MESSAGE) << "\033[31m processing Clupatra Tracks \033[0m" << endl;
	// Get Collection of clupatraTracksCollection
	LCCollection* clupatraTracksCollection = evtP->getCollection("ClupatraTracks");
	int numberOfElements = clupatraTracksCollection->getNumberOfElements();

	for (int index = 0; index < numberOfElements; index++)
	{
		Track* clupatraTrack = dynamic_cast<Track*>( clupatraTracksCollection->getElementAt(index) );
		double d0        = clupatraTrack->getD0();
		double phi       = clupatraTrack->getPhi();
		double omega     = clupatraTrack->getOmega();
		double z0        = clupatraTrack->getZ0();
		double tanLambda = clupatraTrack->getTanLambda();
        streamlog_out(MESSAGE) << "d0 = " << d0 << " phi = " << phi << " omega = " << omega << " z0 = " << z0 << " tanLambda = " << tanLambda << endl;
	}
}

void TrackingProcessor::processSiTracks( LCEvent * evtP )
{
    streamlog_out(MESSAGE) << "\033[31m processing Silicon Tracks \033[0m" << endl;
	// Get Collection of siTracksCollection
	LCCollection* siTracksCollection = evtP->getCollection("SiTracks");
    if (siTracksCollection == 0) return;
	int numberOfElements = siTracksCollection->getNumberOfElements();

	for (int index = 0; index < numberOfElements; index++)
	{
		Track* siTrack = dynamic_cast<Track*>( siTracksCollection->getElementAt(index) );
		double d0        = siTrack->getD0();
		double phi       = siTrack->getPhi();
		double omega     = siTrack->getOmega();
		double z0        = siTrack->getZ0();
		double tanLambda = siTrack->getTanLambda();
        streamlog_out(MESSAGE) << "d0 = " << d0 << " phi = " << phi << " omega = " << omega << " z0 = " << z0 << " tanLambda = " << tanLambda << endl;
		//streamlog_out(MESSAGE) << "d0 = " << d0 << " phi = " << phi << " omega = " << omega << " z0 = " << z0 << " tanLambda = " << tanLambda << endl;
        //StraightLine line(phi, d0, omega, z0, tanLambda);
        //streamlog_out(MESSAGE) << line.omega << endl;
	}
}

void TrackingProcessor::processMarlinTracks( LCEvent * evtP )
{
    streamlog_out(MESSAGE) << "\033[31m processing Marlin Tracks \033[0m" << endl;
    LCCollection* marlinTracksCollection = evtP->getCollection("MarlinTrkTracks");
    int numberOfElements = marlinTracksCollection->getNumberOfElements();

    for (int index = 0; index < numberOfElements; index++)
    {
        Track* marlinTrack = dynamic_cast<Track*>( marlinTracksCollection->getElementAt(index) );
		double d0        = marlinTrack->getD0();
		double phi       = marlinTrack->getPhi();
		double omega     = marlinTrack->getOmega();
		double z0        = marlinTrack->getZ0();
		double tanLambda = marlinTrack->getTanLambda();
        streamlog_out(MESSAGE) << "d0 = " << d0 << " phi = " << phi << " omega = " << omega << " z0 = " << z0 << " tanLambda = " << tanLambda << endl;
    }
}

void TrackingProcessor::processTrackingHits( LCEvent *evtP )
{
	//streamlog_out(MESSAGE) << "\033[31m processing Tracking Hits \033[0m" << endl;
	// Get Collection of TPC Tracker Hits
	LCCollection* tpcTrackerHitsCollection = evtP->getCollection("TPCTrackerHits");
	int numberOfElements = tpcTrackerHitsCollection->getNumberOfElements();

	for (int index = 0; index < numberOfElements; index++)
	{
		TrackerHit* tpcTrackerHit = dynamic_cast<TrackerHit*>( tpcTrackerHitsCollection->getElementAt(index) );
		const double* pos = tpcTrackerHit->getPosition();
		//streamlog_out(MESSAGE) << pos[0] << " " << pos[1] << " " << pos[2] << endl;
	}

}
