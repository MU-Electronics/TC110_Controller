# Pfeiffer Vacuum TC110 Electronic Drive Unit

The project contains a C++ class (Windows support only) for controlling Pheiffer Vacuum's TC110 electronic drive unit over RS-485. The project also contains an example console applcation to demostrate using the class or for general debugging.

The project is built with and devloped in Visual Studio 2012.

### Example usage
**First create an instance of the class**
```c++
TC110Communicator* TC110 = new TC110Communicator("COM2", 123); //123
```
*Remember on windows for com ports larger than 9 using the following format ```\\\\.\\COM12"```*

**Check that you are successfully connect**
```c++
if(TC110->IsConnected()){
	// Method of choice
}
```

**Finally call the method for the information required**
```c++
	// Get the temperature of the bottom of the pump
	double temperature = TC110->GetTemperature(1);
	cout << temperature << endl << endl;
```

**All the above together**
```c++
TC110Communicator* TC110 = new TC110Communicator("COM2", 123); // COMPORT,  TC110 RS-485 ID
if(TC110->IsConnected()){
	// Get the temperature of the bottom of the pump
	double temperature = TC110->GetTemperature(1);
	cout << temperature << endl << endl;
}
```


### CopyRight
GNU license applies, for special permissions please contact.

In no way is this project connected in any way to Pfeiffer Vacuum themselfs.
