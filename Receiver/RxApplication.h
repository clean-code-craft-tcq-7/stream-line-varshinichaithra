#ifndef RX_APPLICATION_H_
#define RX_APPLICATION_H

extern float *min;
extern float *max;
extern float **movingAverage;

void RxApplication_CreateMem(int nrofsamples, int count);
void RxApplication_FreeMem(int count);
int RxApplication_MovingAvg(int nrofsamples, int count);
int RxApplication_MinMax(int nrofsamples, int count);
Sensorvalue RxApplication(FILE *fp);

#endif
