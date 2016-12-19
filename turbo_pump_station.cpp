// turbo_pump_station.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "TC110Communicator.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// Set up communication link	
	TC110Communicator* TC110 = new TC110Communicator("\\\\.\\COM12", 123); //123

	// Welcome message
	cout << "======================================================" << endl 
		 << "== Electronics section TC110 control unit interface ==" << endl 
		 << "======================================================" << endl << endl;	
	
	Sleep(2000);

	// While connected allow commands
	while(TC110->IsConnected())	
	{
		cout << endl << "Select between: " << endl << "Pump Station, Turbo Pump, Backing Pump Mode, Gas Mode," << endl << "Get Pressure, Temperature, Turbo Speed, Read Error" << endl << "Command: ";

		// What should we do?
		string command = "";
		getline(cin, command);

		// Process command
		string value = "";
		string value_2 = "";
		if(command == "Pump Station")
		{
			// id = 10
			// This includes turbo pump and backing pump
			int pumpingState = TC110->GetPumpingState();
			cout << endl << "Do you want to turn: On (1) or Off (0)" << endl << "Currently set at:" << pumpingState << endl << "Command: ";
			getline(cin, value);
		
			if(value == "On"){
					
			}else if(value == "Off"){
					
			}else{
				cout << "I dont understand you :| returning to beginning"  << endl  << endl;
			}
		}
		else if(command == "Turbo Pump")
		{
			// id = 23
			// This decides whether the turbo pump turns on
			int turboPumpState = TC110->GetTurboPumpState();
			cout << endl << "Do you want to turn: On or Off" << endl << "Currently set at:" << turboPumpState << endl << "Command: ";
			getline(cin, value);

			if(value == "On"){
					
			}else if(value == "Off"){
					
			}else{
				cout << "I dont understand you :| returning to beginning"  << endl  << endl;
			}
		
		}
		else if(command == "Backing Pump Mode")
		{
			// id = 25
			// This decides how the backing pump is used
			int backingPumpMode = TC110->GetBackingPumpMode();
			cout << endl << "Select between: Continuous, Intermittent, Delayed, Delayed + Intermittent?"  << endl << "Currently set at:" << backingPumpMode << endl <<"Command: ";
			getline(cin, value);

			if(value == "Continuous"){ // option = 0
					
			}else if(value == "Intermittent"){ // option = 1
					
			}else if(value == "Delayed"){ // option = 2
					
			}else if(value == "Delayed + Intermittent"){ // option = 3
					
			}else{
				cout << "I dont understand you :| returning to beginning"  << endl  << endl;
			}
		
		}
		else if(command == "Gas Mode")
		{
			// id = 027
			int gasMode = TC110->GetGasMode();
			cout << endl << "Select between: Heavy (>39, 0), Light(=<39, 1), or Helium(2)?"  << endl << "Currently set at:" << gasMode << endl << "Command: ";
			getline(cin, value);

			if(value == "Heavy"){ // option = 0
				
			}else if(value == "Light"){ //option = 1

			}else if(value == "Helium"){ //option = 2

			}else{
				cout << "I dont understand you :| returning to beginning"  << endl  << endl;
			}
		}
		else if(command == "Get Pressure")
		{
			// id = 340

		}
		else if(command == "Temperature")
		{
			cout << endl << "Select between: Electronics, Pump Bottom, Bearing or Motor"  << endl << "Command: ";
			getline(cin, value);

			if(value == "Pump Bottom"){ // id = 330
				double temperature = TC110->GetTemperature(1);
				cout << temperature << endl << endl;
			}else if(value == "Electronics"){ // id = 326
				double temperature = TC110->GetTemperature(2);
				cout << temperature << endl << endl;	
			}else if(value == "Bearing"){ // id = 342
				double temperature = TC110->GetTemperature(3);
				cout << temperature << endl << endl;	
			}else if(value == "Motor"){ // id = 346
				double temperature = TC110->GetTemperature(4);
				cout << temperature << endl << endl;	
			}else{
				cout << "I dont understand you :| returning to beginning"  << endl  << endl;
			}
		}
		else if(command == "Turbo Speed")
		{
			cout << endl << "Select between: Accel-Decel, Set Rotation Speed, Actual Rotation Speed or Nominal Speed"  << endl << "Command: ";
			getline(cin, value);
		
			if(value == "Actual Rotation Speed"){ // id = 398
				double speed = TC110->GetTurboSpeed(1);
				cout << speed << endl << endl;
			}else if(value == "Accel-Decel"){ //id = 336
				double speed = TC110->GetTurboSpeed(2);
				cout << speed << endl << endl;
			}else if(value == "Get Set Rotation Speed"){ //id = 397
				double speed = TC110->GetTurboSpeed(4);
				cout << speed << endl << endl;
			}else if(value == "Set Rotation Speed"){ //id = 397
				cout << endl << "What speed: "  << endl << "Value: ";
				getline(cin, value_2);
				// @todo
			}else if(value == "Nominal Speed"){ //id = 399
				double speed = TC110->GetTurboSpeed(3);
				cout << speed << endl << endl;
			}else{
				cout << "I dont understand you :| returning to beginning"  << endl  << endl;
			}
		}
		else if(command == "Read Error")	
		{
			cout << endl << "Select History: 1, 2, 3, 4, 5, 6, 7, 8, 9 or 10 "  << endl << "Command: ";
			getline(cin, value);

			if(value >= "1" && value <= "10"){ // 1 (360), 2 (361), 3 (362), 4 (363), 5 (364), 6 (365), 7 (366), 8 (367), 9 (368) or 10 (369)
					
			}else{
				cout << "I dont understand you :| returning to beginning"  << endl  << endl;
			}
		
		}else{
			cout << "I dont understand you :| returning to beginning"  << endl  << endl;
		}
	}



	return 0;
}



