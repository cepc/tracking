#ifndef INITIAL_HH
#define INITIAL_HH

// marlin
#include <marlin/Processor.h>

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
		void processClupatraTracks( LCEvent * evtP );
		void processSiTracks( LCEvent * evtP );
        void processMarlinTracks( LCEvent * evtP );
		void processTrackingHits( LCEvent * evtP );
		//error();
		//message();
};

#endif


