#include <SoftwareSerial.h>
#include <Sabertooth.h>

#define JOY_V A1
#define JOY_H A0

SoftwareSerial ss(NOT_A_PIN, 18);
Sabertooth st(128, ss);

int get_controller_h_input();
int get_controller_v_input();

void setup() {
	SabertoothTXPinSerial.begin(9600);	// This is the baud rate you chose with the DIP switches
	ss.begin(9600);
	st.autobaud();
	st.drive(0);
	st.turn(0);
	pinMode(JOY_H, INPUT);
	pinMode(JOY_V, INPUT);
}

void loop() {
	int h = get_controller_h_input();
	int v = get_controller_v_input();
	st.turn(h);
	st.drive(v);

}

int get_controller_h_input() {
	int joy_h = (analogRead(JOY_H) / 4) - 127;
	if (joy_h > 127)
		joy_h = 127;
	if (abs(joy_h) < 11)
		joy_h = 0;
	return joy_h;
}

int get_controller_v_input() {
	int joy_v = (analogRead(JOY_V) / 4) - 127;
	if (joy_v > 127)
		joy_v = 127;
	if (abs(joy_v) < 11)
		joy_v = 0;
	return joy_v;
}