#include <TrackingProcessor.h>
#include <EVENT/LCCollection.h>
#include <IMPL/LCCollectionVec.h>
#include <EVENT/LCFloatVec.h>
#include <EVENT/MCParticle.h>
#include <EVENT/ReconstructedParticle.h>
#include <IMPL/MCParticleImpl.h>
#include <EVENT/LCFloatVec.h>
#include <EVENT/LCParameters.h>

#include <TFile.h>
#include <TTree.h>

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
    registerProcessorParameter( "OutputFile", "Name of the Output ROOT file", _outputFileName, _outputFileName );
}

void TrackingProcessor::init()
{
    StraightLine::setReferencePoint(0.0, 0.0, 0.0);

    if (_outputFileName != "")
    {
        _output = new TFile(_outputFileName.c_str(), "recreate");
    }
    else
    {
        _output = new TFile("tuple.root", "recreate");
    }

    initTree();

	streamlog_out(MESSAGE) << "\033[31m Tracking Processor Start \033[0m" << endl;
	// printParameters();
}

void TrackingProcessor::initTree()
{
    _tree = new TTree("tracksTree", "Tracks Parameters");
    _tree->Branch("marlinTrack_d0"        , &marlinTrack_d0        , "marlinTrack_d0/D");
    _tree->Branch("marlinTrack_phi"       , &marlinTrack_phi       , "marlinTrack_phi/D");
    _tree->Branch("marlinTrack_omega"     , &marlinTrack_omega     , "marlinTrack_omega/D");
    _tree->Branch("marlinTrack_z0"        , &marlinTrack_z0        , "marlinTrack_z0/D");
    _tree->Branch("marlinTrack_tanLambda" , &marlinTrack_tanLambda , "marlinTrack_tanLambda/D");
    _tree->Branch("siTrack_d0"        , &siTrack_d0        , "siTrack_d0/D");
    _tree->Branch("siTrack_phi"       , &siTrack_phi       , "siTrack_phi/D");
    _tree->Branch("siTrack_omega"     , &siTrack_omega     , "siTrack_omega/D");
    _tree->Branch("siTrack_z0"        , &siTrack_z0        , "siTrack_z0/D");
    _tree->Branch("siTrack_tanLambda" , &siTrack_tanLambda , "siTrack_tanLambda/D");
    _tree->Branch("cluptraTrack_d0"        , &cluptraTrack_d0        , "cluptraTrack_d0/D");
    _tree->Branch("cluptraTrack_phi"       , &cluptraTrack_phi       , "cluptraTrack_phi/D");
    _tree->Branch("cluptraTrack_omega"     , &cluptraTrack_omega     , "cluptraTrack_omega/D");
    _tree->Branch("cluptraTrack_z0"        , &cluptraTrack_z0        , "cluptraTrack_z0/D");
    _tree->Branch("cluptraTrack_tanLambda" , &cluptraTrack_tanLambda , "cluptraTrack_tanLambda/D");
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
    _tree->Fill();
	//processTrackingHits( evtP );

    streamlog_out(MESSAGE) << "\033[32m Successfully  \033[0m" << endl;
}

void TrackingProcessor::end()
{
    _tree->Write();
    delete _tree;
    _output->Close();
    delete _output;
    streamlog_out(MESSAGE) << "\033[31m Tracking Processor Stop \033[0m" << endl;
}

void TrackingProcessor::processClupatraTracks( LCEvent * evtP )
{
    streamlog_out(MESSAGE) << "\033[31m processing Clupatra Tracks \033[0m" << endl;
	// Get Collection of clupatraTracksCollection
	LCCollection* clupatraTracksCollection = evtP->getCollection("ClupatraTracks");
	int numberOfElements = clupatraTracksCollection->getNumberOfElements();

    if (numberOfElements == 0)
    {
        cluptraTrack_d0        = -10000;
        cluptraTrack_phi       = -10000;
        cluptraTrack_omega     = -10000;
        cluptraTrack_z0        = -10000;
        cluptraTrack_tanLambda = -10000;
    }

	for (int index = 0; index < numberOfElements; index++)
	{
		Track* clupatraTrack = dynamic_cast<Track*>( clupatraTracksCollection->getElementAt(index) );
		cluptraTrack_d0        = clupatraTrack->getD0();
		cluptraTrack_phi       = clupatraTrack->getPhi();
		cluptraTrack_omega     = clupatraTrack->getOmega();
		cluptraTrack_z0        = clupatraTrack->getZ0();
		cluptraTrack_tanLambda = clupatraTrack->getTanLambda();

	}
}

void TrackingProcessor::processSiTracks( LCEvent * evtP )
{
    streamlog_out(MESSAGE) << "\033[31m processing Silicon Tracks \033[0m" << endl;
	// Get Collection of siTracksCollection
	LCCollection* siTracksCollection = evtP->getCollection("SiTracks");
	int numberOfElements = siTracksCollection->getNumberOfElements();

    if (numberOfElements == 0)
    {
        siTrack_d0        = -10000;
        siTrack_phi       = -10000;
        siTrack_omega     = -10000;
        siTrack_z0        = -10000;
        siTrack_tanLambda = -10000;
    }

	for (int index = 0; index < numberOfElements; index++)
	{
		Track* siTrack = dynamic_cast<Track*>( siTracksCollection->getElementAt(index) );
		siTrack_d0        = siTrack->getD0();
		siTrack_phi       = siTrack->getPhi();
		siTrack_omega     = siTrack->getOmega();
		siTrack_z0        = siTrack->getZ0();
		siTrack_tanLambda = siTrack->getTanLambda();

	}
}

void TrackingProcessor::processMarlinTracks( LCEvent * evtP )
{
    streamlog_out(MESSAGE) << "\033[31m processing Marlin Tracks \033[0m" << endl;
    LCCollection* marlinTracksCollection = evtP->getCollection("MarlinTrkTracks");
    int numberOfElements = marlinTracksCollection->getNumberOfElements();

    if (numberOfElements == 0)
    {
        marlinTrack_d0        = -10000;
        marlinTrack_phi       = -10000;
        marlinTrack_omega     = -10000;
        marlinTrack_z0        = -10000;
        marlinTrack_tanLambda = -10000;
    }

    for (int index = 0; index < numberOfElements; index++)
    {
        Track* marlinTrack = dynamic_cast<Track*>( marlinTracksCollection->getElementAt(index) );
		marlinTrack_d0        = marlinTrack->getD0();
		marlinTrack_phi       = marlinTrack->getPhi();
		marlinTrack_omega     = marlinTrack->getOmega();
		marlinTrack_z0        = marlinTrack->getZ0();
		marlinTrack_tanLambda = marlinTrack->getTanLambda();

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
