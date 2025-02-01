/*

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

const char* getSensorPositionName(enum sensorPosition position);
void printDistance(struct distanceSensor *sensor);

enum sensorPosition {
	FRONT_LEFT,
	FRONT_CENTER,
	FRONT_RIGHT,
	REAR_LEFT,
	REAR_CENTER,
	REAR_RIGHT
};

struct distanceSensor {
	enum sensorPosition position;
	int lastMeasuredDistance;
};

int main() {
	struct distanceSensor sensor[6] = { {FRONT_LEFT, 256}, {FRONT_CENTER, 204}, {FRONT_RIGHT, 206}, {REAR_LEFT, 461}, {REAR_CENTER, 425}, {REAR_RIGHT, 422} };
	printDistance(sensor);
	return 0;
}

const char* getSensorPositionName(enum sensorPosition position) {
	switch (position) {
	case(FRONT_LEFT):
		return "Front Left";
	case(FRONT_CENTER):
		return "Front Center";
	case (FRONT_RIGHT):
		return "Front Right";
	case (REAR_LEFT):
		return "Rear Left";
	case (REAR_RIGHT):
		return "Rear Right";
	case (REAR_CENTER):
		return "Rear Center";
	}
		
		
}


void printDistance(struct distanceSensor *sensor) {
	for (int i = 0; i < 6; i++) {
		printf("%-15s : %d cm\n", getSensorPositionName((sensor + i)->position), (sensor +i)->lastMeasuredDistance);
	}
}
*/

