// Simulates the flow of customers through a line in a store.
#include "pch.h"
#include "queuelinked.h"
#include <iostream>
#include <cstdlib> // for function rand()
#include <iomanip> // for setprecision manipulator


using namespace std;

int main()
{
	Queue<int> custQ; // Line (queue) of customers containing the
	// time that each customer arrived and joined the line
	int simLength, // Length of simulation (minutes)
		minute, // Current minute
		numCust, // Number of customers arrived
		timeArrived, // Time dequeued customer arrived
		waitTime, // How long dequeued customer waited
		totalServed = 0, // Total customers served
		totalWait = 0, // Total waiting time
		maxWait = 0, // Longest wait
		numArrivals = 0; // Number of new arrivals
	int rng = 0;

	cout << endl << "Enter the length of time to run the simulator : ";
	cin >> simLength;

	for (minute = 0; minute < simLength; minute++)
	{
		if (!custQ.isEmpty())
		{
			timeArrived = custQ.dequeue();
			totalServed++;

			waitTime = minute - timeArrived;
			totalWait += waitTime;
			if (waitTime > maxWait)
				maxWait = waitTime;
		}

		rng = rand() % 4;
		switch (rng)
		{
		case 0:
			break;
		case 1:
			custQ.enqueue(minute);
			numArrivals++;
			break;
		case 2:
			custQ.enqueue(minute);
			custQ.enqueue(minute);
			numArrivals += 2;
			break;
		case 3:
			break;
		default:
			break;
		}

	}

	cout << endl;
	cout << "Customers served : " << totalServed << endl;
	cout << "Average wait     : " << setprecision(2)
		<< double(totalWait) / totalServed << endl;
	cout << "Longest wait     : " << maxWait << endl;
}