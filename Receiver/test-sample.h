#ifndef TEST_SAMPLE_H_
#define TEST_SAMPLE_H_

#include <stdio.h>
#include "SensorApplication.h"

Sensorvalue TestSensorValue(FILE *fp);
void TestMinMax(void);
void TestMovingAverage(int nrofsensors, int nrofsamples);

#endif
