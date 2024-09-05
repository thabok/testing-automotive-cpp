/*******************************************************************************
 *  BTC EP C++ Accessor Code
 *  (C) Copyright 2024 by
 *  BTC - Embedded Systems AG, Germany
 ******************************************************************************/

#include "Infotainment.h"

#include "accessor_types.h"

namespace BTC {
	namespace EP_Infotainment {

		Infotainment sut;

		// public object attributes
		float usrVolReq;
		float sysVolReq;
		bool tooLoud;
		uint8_t directionInput;
		bool buttonOn;
		bool Bluetooth_Connected;

		void step() {
			// Input interface
			sut.usrVolReq = usrVolReq;
			sut.directionInput = directionInput;
			sut.buttonOn = buttonOn;

			// Calling the method under test.
			sut.step();

			// Output interface
			sysVolReq = sut.sysVolReq;
			tooLoud = sut.tooLoud;
			Bluetooth_Connected = sut.Bluetooth_Connected;
		}
	}
}

