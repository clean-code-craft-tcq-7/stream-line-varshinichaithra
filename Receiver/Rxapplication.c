#include <stdio.h>
#include <stdlib.h>
#include "FileParser.h"
#include "SensorApplication.h"
#include "RxApplication.h"

float *min;
float *max;
float **movingAverage;

Sensorvalue RxApplication(FILE *fp)
{
    Sensorvalue value;
    value = fileparser(fp);
    RxApplication_MinMax(value.nrofSamples, value.count);
    RxApplication_MovingAvg(value.nrofSamples, value.count);
    return value;
}

int RxApplication_MinMax(int nrofsamples, int count){

    int sensorCnt;
    min = (float*)calloc(count, sizeof(float));
    max = (float*)calloc(count, sizeof(float));
    //Get min max
    for(sensorCnt = 0; sensorCnt < count; sensorCnt++)
    {
        min[sensorCnt] = GetMinMax(sampleList[sensorCnt], nrofsamples, GetMin);
        max[sensorCnt] = GetMinMax(sampleList[sensorCnt], nrofsamples, GetMax);
    }
    return sensorCnt;
}

int RxApplication_MovingAvg(int nrofsamples, int count){

    int sensorCnt;
    int sampleCnt;
    float* arrNumbers = (float*) calloc(5, sizeof(float));
    int pos = 0;
    float sum = 0;
    int size = 5;

    RxApplication_CreateMem(nrofsamples, count);

    for(sensorCnt = 0; sensorCnt < count; sensorCnt++)
    {
        for(sampleCnt = 0; sampleCnt < nrofsamples; sampleCnt++)
        {
            movingAverage[sensorCnt][sampleCnt] = GetmovingAverage(arrNumbers, &sum, pos,
                            size, sampleList[sensorCnt][sampleCnt]);
            pos++;
            if(pos >= size)
            {
                pos = 0;
            }
        }
    }
    return sensorCnt;
}

void RxApplication_CreateMem(int nrofsamples, int count){

    int sensorCnt;
    movingAverage = (float**)calloc(count, sizeof(float*));
    for(sensorCnt = 0; sensorCnt < count; sensorCnt++)
    {
        movingAverage[sensorCnt] = (float*) calloc(nrofsamples, sizeof(float));
    }
}

void RxApplication_FreeMem(int count){

    int sensorCnt;
    //Free memory allocated for application
    free(min);
    free(max);
    for(sensorCnt = 0; sensorCnt < count; sensorCnt++)
    {
        free(movingAverage[sensorCnt]);
    }
    free(movingAverage);

}


