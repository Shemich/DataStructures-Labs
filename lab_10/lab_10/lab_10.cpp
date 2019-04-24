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
	int simLength[4], // Length of simulation (minutes)
		minute, // Current minute
		numCust = 0,// Number of customers arrived
		timeArrived, // Time dequeued customer arrived
		waitTime[4] = { 0,0,0,0 }, // How long dequeued customer waited
		totalServed[4] = {0,0,0,0}, // Total customers served
	
		maxWait[4] = { 0,0,0,0 }, // Longest wait
		numArrivals = 0; // Number of new arrivals
	int totalWait[4] = {0,0,0,0}; // Total waiting time


	for (int i = 0; i < 4; i++)
	{
		cout << endl << "Enter the length of time to run the simulator : ";
		cin >> simLength[i];

		for (minute = 0; minute < simLength[i]; minute++)
		{
			if (!custQ.isEmpty())
			{
				timeArrived = custQ.dequeue();
				totalServed[i]++;

				waitTime[i] = minute - timeArrived;
				totalWait[i] += waitTime[i];
				if (waitTime[i] > maxWait[i])
					maxWait[i] = waitTime[i];
			}

			numCust = rand() % 4;
			switch (numCust)
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
	}
	cout << "\nTime ";
	cout << "\tCustomers served ";
	cout << "\tAverage wait ";
	cout << "\tLongest wait ";
	for (int i = 0; i < 4; i++)
	{
		cout << "\n";
		cout << simLength[i];
		cout << "\t\t" << totalServed[i] << "\t\t   ";
		cout << setprecision(2);
		cout << double(totalWait[i]) / totalServed[i];
		cout << "\t\t\t" <<maxWait[i];
	}
	cout << "\n\n\n\n";
	system("pause");
}