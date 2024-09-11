# C++ Testing for Automotive Embedded
Example repo combining C and C++ code for automotive embedded incl. testing (tests with BTC EmbeddedPlatform, linked to requirements from Polarion) and CD/CD (GitHub Actions / Docker).


## Main branch health
- ![CI](https://github.com/thabok/testing-automotive-cpp/actions/workflows/btc-tests.yml/badge.svg?branch=main)
- [Test Report](https://thabok.github.io/testing-automotive-cpp/report.html)


## Relevant files

### Implementation & Test
- Main Class: [InfotainmentSystem.cpp](src/InfotainmentSystem.cpp) (with related CPP classes and C-functions)
- Test project: [InfotainmentSystem.epp](tst/InfotainmentSystem.epp)


### CI/CD
- Automated test workflow: [run_tests.py](tst/run_tests.py)
- Docker: [Dockerfile](docker/Dockerfile)
- Pipeline: [GitHub Actions](.github/workflows/btc-tests.yml)


## Requirements
The requirements are stored in Polarion and directly imported into the test case (based on a baseline). This is just a reference:
| Title | Description |
|-------|-------------|
| 01 - Infotainment |  | 
| 01.1 - High volume shall stop navigation | A volume above the defined threshold shall disable the navigation. | 
| 01.2 - Saturate volume on bluetooth connect | When the bluetooth connector accepts an active connection request, the volume shall be saturated to the volume threshold value to prevent sudden driver distraction. | 
| 01.3 - System State | The system state bitfield shall reflected the status of the navigation system and bluetooth system | 
| 01.4 - Prevent override of active bluetooth connection | When the Bluetooth connector has an active connection and the Infotainment System tries to connect another device, the Bluetooth Connector will throw an Exception. This shall cause the Infotainment System's global error flag to become active. |
| 02 - VolumeControl |  | 
| 02.1 - Apply requested volume | Setting the volume shall apply the user request if it is in the expected range [0,100] | 
| 02.2 - Indicate volume above threshold | If the effective volume is higher than the defined volume threshold, the tooLoud flag shall be enabled (and disabled when it's <= the threshold). | 
| 03 - NavigationSystem |  | 
| 03.1 - Start Navigation | The navigation system's start function shall activate the navigation system and set the currentRouteLength to the requested length (if the requested length is greater than 0) | 
| 03.2 - Stop Navigation | The navigation system's stop function shall disable the navigation system and reset the currentRouteLength to 0 | 
| 04 - BluetoothConnector | Section for requirements related to the BluetoothConnector | 
| 04.1 - Detect active requests | The bluetooth connector shall indicate if a connection request is active (connection request id > 0) | 
| 04.2 - Connect device | The bluetooth connector's connect device function shall accept active connection requests, activate the bluetooth connected flag and set the connected device id | 
| 04.3 - Disconnect device | The bluetooth connector's disconnnect device function shall reset the bluetooth connected flag and reset the connected device to -1 | 
