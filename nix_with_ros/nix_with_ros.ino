#include <ros.h>
#include <std_msgs/String.h>
#include <Sabertooth.h>

int x = 0;

void setup() {
	Serial.begin(9600);
	while (!Serial);
}

void loop() {
	Serial.print("test");
	Serial.println(x);
	x++;
	delay(100);
}
