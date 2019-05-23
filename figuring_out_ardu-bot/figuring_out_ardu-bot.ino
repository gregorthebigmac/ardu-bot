/*
I wrote this to get a handle on how the Arduino talks to the Sabertooth motor controller
*/

#include <SoftwareSerial.h>
#include <Sabertooth.h>

SoftwareSerial sw_serial(NOT_A_PIN, 18);
Sabertooth st(128, sw_serial);

int throttle = 0;
int steering = 0;
bool forward_or_backward = true;	// false = backward | true = forward
bool left_or_right = true;			// false = left		| true = right

void setup() {
	SabertoothTXPinSerial.begin(9600);
	sw_serial.begin(9600);
	st.autobaud();
	st.drive(0);
	st.turn(0);
}

void loop() {
	//st.drive(throttle);
	st.turn(steering);

	/*
	if (forward_or_backward) {
		if (throttle > 127) {
			forward_or_backward = !forward_or_backward;
			throttle--;
		}
		else {
			throttle++; }
	}
	else {
		if (throttle < -127) {
			forward_or_backward = !forward_or_backward;
			throttle++;
		}
		else {
			throttle--; }
	}
	*/
	if (left_or_right) {
		if (steering > 127) {
			left_or_right = !left_or_right;
			steering--;
		}
		else {
			steering++;
		}
	}
	else {
		if (steering < -127) {
			left_or_right = !left_or_right;
			steering++;
		}
		else {
			steering--;
		}
	}
	/*
	if (throttle == 0 && steering == 0) {
		delay(5000); }
	else if (throttle == 0 && steering != 0) {
		delay(1000); }
	else if (throttle != 0 && steering == 0) {
		delay(2000); }
	else {}
	*/
	delay(100);
}
