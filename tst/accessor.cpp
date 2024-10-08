/*******************************************************************************
 *  BTC EP C++ Accessor Code
 *  (C) Copyright 2024 by
 *  BTC - Embedded Systems AG, Germany
 ******************************************************************************/

#include "..\incl\InfotainmentSystem.h"

#include "accessor_types.h"

namespace BTC {
	namespace EP_InfotainmentSystem {

		InfotainmentSystem sut;

		// public object attributes
		bool errorFlag;
		Volume userVolumeRequest;
		Volume effectiveVolume;
		Volume volumeThreshold;
		bool tooLoud;
		bool isNavigationActive;
		bool stopRequested;
		DistanceKM currentRouteLength;
		DistanceKM requestedRouteLength;
		bool isBluetoothConnected;
		Identifier connectedDeviceId;
		Identifier connectionRequestId;

		void stepFunction() {
			// Input interface
			sut.userVolumeRequest = userVolumeRequest;
			sut.volumeThreshold = volumeThreshold;
			sut.stopRequested = stopRequested;
			sut.requestedRouteLength = requestedRouteLength;
			sut.connectionRequestId = connectionRequestId;

			// Calling the method under test.
			sut.stepFunction();

			// Output interface
			errorFlag = sut.errorFlag;
			effectiveVolume = sut.effectiveVolume;
			tooLoud = sut.tooLoud;
			isNavigationActive = sut.isNavigationActive;
			currentRouteLength = sut.currentRouteLength;
			isBluetoothConnected = sut.isBluetoothConnected;
			connectedDeviceId = sut.connectedDeviceId;
		}
	}
}

