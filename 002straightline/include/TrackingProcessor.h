#ifndef INITIAL_HH
#define INITIAL_HH

#include <string>
using std::string;

// marlin
#include <marlin/Processor.h>

#include <TTree.h>
#include <TFile.h>

class TrackingProcessor  : public marlin::Processor
{
    public:

        Processor*  newProcessor() { return new TrackingProcessor ; }
        TrackingProcessor();
        ~TrackingProcessor() {};

        void init();
        void processEvent( LCEvent * evtP );
        void end();

    private:
        void initTree();

        void processClupatraTracks( LCEvent * evtP );
        void processSiTracks( LCEvent * evtP );
        void processMarlinTracks( LCEvent * evtP );
        void processTrackingHits( LCEvent * evtP );

        double marlinTrack_d0;
        double marlinTrack_phi;
        double marlinTrack_omega;
        double marlinTrack_z0;
        double marlinTrack_tanLambda;
        double siTrack_d0;
        double siTrack_phi;
        double siTrack_omega;
        double siTrack_z0;
        double siTrack_tanLambda;
        double cluptraTrack_d0;
        double cluptraTrack_phi;
        double cluptraTrack_omega;
        double cluptraTrack_z0;
        double cluptraTrack_tanLambda;

        TTree* _tree;
        TFile* _output;
        string _outputFileName;
//error();
//message();
};

#endif


