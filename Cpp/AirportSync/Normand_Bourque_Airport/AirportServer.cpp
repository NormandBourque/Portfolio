#include <iostream>
#include <thread>
#include <condition_variable>

#include "AirportServer.h"

mutex AirportServer::runwayFourL;
mutex AirportServer::runwayFourR;
mutex AirportServer::runwayNine;
mutex AirportServer::runwayFourteen;
mutex AirportServer::runwayFifteenL;
mutex AirportServer::runwayFifteenR;

/**
*  Called by an Airplane when it wishes to land on a runway
*/
void AirportServer::reserveRunway(int airplaneNum, AirportRunways::RunwayNumber runway)
{
	// Acquire runway(s)
	{ // Begin critical region

		{
			lock_guard<mutex> lk(AirportRunways::checkMutex);

			cout << "Airplane #" << airplaneNum << " is acquiring any needed runway(s) for landing on Runway "
				 << AirportRunways::runwayName(runway) << endl;
		}

		switch (runway)
		{
		case AirportRunways::RunwayNumber::RUNWAY_4L:
			runwayFourL.lock();
			runwayFifteenL.lock();
			runwayFifteenR.lock();
			break;
		case AirportRunways::RunwayNumber::RUNWAY_4R:
			runwayFourR.lock();
			runwayNine.lock();
			runwayFifteenL.lock();
			runwayFifteenR.lock();
			break;
		case AirportRunways::RunwayNumber::RUNWAY_9:
			runwayFourR.lock();
			runwayNine.lock();
			runwayFifteenR.lock();
			break;
		case AirportRunways::RunwayNumber::RUNWAY_14:
			runwayFourteen.lock();
			break;
		case AirportRunways::RunwayNumber::RUNWAY_15L:
			runwayFourL.lock();
			runwayFourR.lock();
			runwayFifteenL.lock();
			break;
		case AirportRunways::RunwayNumber::RUNWAY_15R:
			runwayFourL.lock();
			runwayFourR.lock();
			runwayNine.lock();
			runwayFifteenR.lock();
			break;
		default:
			std::cout << "not found runway for lock =================================================================================================================";
		}
		// Check status of the airport for any rule violations

		AirportRunways::checkAirportStatus(runway);

		//runwaysLock.unlock();

	} // End critical region

	// obtain a seed from the system clock:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	// Taxi for a random number of milliseconds
	std::uniform_int_distribution<int> taxiTimeDistribution(1, MAX_TAXI_TIME);
	int taxiTime = taxiTimeDistribution(generator);

	{
		lock_guard<mutex> lk(AirportRunways::checkMutex);

		cout << "Airplane #" << airplaneNum << " is taxiing on Runway " << AirportRunways::runwayName(runway)
			 << " for " << taxiTime << " milliseconds\n";
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(taxiTime));

} // end AirportServer::reserveRunway()

/**
  *  Called by an Airplane when it is finished landing
  */
void AirportServer::releaseRunway(int airplaneNum, AirportRunways::RunwayNumber runway)
{
	// Release the landing runway and any other needed runways
	{ // Begin critical region

		//unique_lock<mutex> runwaysLock(runwaysMutex);
		{
			lock_guard<mutex> lk(AirportRunways::checkMutex);

			cout << "Airplane #" << airplaneNum << " is releasing any needed runway(s) after landing on Runway "
				 << AirportRunways::runwayName(runway) << endl;
		}

		/**
		*  ***** Add your synchronization here! *****
		*/
		AirportRunways::finishedWithRunway(runway);
		switch (runway)
		{
		case AirportRunways::RunwayNumber::RUNWAY_4L:
			runwayFourL.unlock();
			runwayFifteenL.unlock();
			runwayFifteenR.unlock();
			break;
		case AirportRunways::RunwayNumber::RUNWAY_4R:
			runwayFourR.unlock();
			runwayNine.unlock();
			runwayFifteenL.unlock();
			runwayFifteenR.unlock();
			break;
		case AirportRunways::RunwayNumber::RUNWAY_9:
			runwayFourR.unlock();
			runwayNine.unlock();
			runwayFifteenR.unlock();
			break;
		case AirportRunways::RunwayNumber::RUNWAY_14:
			runwayFourteen.unlock();
			break;
		case AirportRunways::RunwayNumber::RUNWAY_15L:
			runwayFourL.unlock();
			runwayFourR.unlock();
			runwayFifteenL.unlock();
			break;
		case AirportRunways::RunwayNumber::RUNWAY_15R:
			runwayFourL.unlock();
			runwayFourR.unlock();
			runwayNine.unlock();
			runwayFifteenR.unlock();
			break;
		}

		// Update the status of the airport to indicate that the landing is complete
	} // End critical region

	// obtain a seed from the system clock:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	// Wait for a random number of milliseconds before requesting the next landing for this Airplane
	std::uniform_int_distribution<int> waitTimeDistribution(1, MAX_WAIT_TIME);
	int waitTime = waitTimeDistribution(generator);

	{
		lock_guard<mutex> lk(AirportRunways::checkMutex);

		cout << "Airplane #" << airplaneNum << " is waiting for " << waitTime << " milliseconds before landing again\n";
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));

} // end AirportServer::releaseRunway()