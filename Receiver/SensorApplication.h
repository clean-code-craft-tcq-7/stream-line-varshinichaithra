#ifndef SENSOR_APPLICATION_H_
#define SENSOR_APPLICATION_H_

int GetMin(float a, float b);
int GetMax(float a, float b);
float GetMinMax(float list[], int size, int (*input)(float, float));
float GetmovingAverage(float *list, float *sum, int pos, int len, float nextNum);

#endif
