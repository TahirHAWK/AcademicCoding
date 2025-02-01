/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void displayParkPilot(struct distanceSensor *sensor);

struct distanceSensor {
	enum sensorPosition position;
	int lastMeasuredDistance;
};

enum sensorPosition {
	FRONT_LEFT,
	FRONT_CENTER,
	FRONT_RIGHT,
	REAR_LEFT,
	REAR_CENTER,
	REAR_RIGHT
};

int main() {
	struct distanceSensor sensors[4] = { {FRONT_LEFT, 256}, {FRONT_CENTER, 204}, {FRONT_RIGHT, 52}, {REAR_CENTER, 425} };
	displayParkPilot(sensors);
	return 0;
}



void displayParkPilot(struct distanceSensor* sensor) {
	printf("Park pilot : \n"
			"%d %d %d\n"
			"v-------v\n"
			"|       |\n"
			"|  ---  |\n"
			"|       |\n"
			"|       |\n"
			"|       |\n"
			"x-------x\n"
			"    %d   \n", 
		(sensor + 0)->lastMeasuredDistance, 
		(sensor + 1)->lastMeasuredDistance,
		(sensor + 2)->lastMeasuredDistance,
		(sensor + 3)->lastMeasuredDistance
	);
}
*/

