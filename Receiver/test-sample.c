#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "test-sample.h"
#include "FileParser.h"
#include "SensorApplication.h"

void TestSensorValue(FILE *fp){     
      int sampleCnt;
      Sensorvalue value = fileparser(fp);
      assert(value.nrofSamples == 10);
      assert(value.count == 3);
      //Test input
      float sensor1[10] = {11.0, 25.0, 19.0, 19.0, 9.0, 21.0, 12.0, 29.0, 12.0, 35.0};
      float sensor2[10] = {69.0, 66.0, 25.0, 42.0, 30.0, 69.0, 36.0, 32.0, 26.0, 31.0};
      float sensor3[10] = {0.8, 0.2, 0.7, 0.7, 0.4, 0.0, 0.0, 0.2, 0.0, 0.3};   
      for(sampleCnt = 0; sampleCnt < value.nrofSamples; sampleCnt ++){
           assert(sensor1[sampleCnt] == sampleList[0][sampleCnt]);
      }
      for(sampleCnt = 0; sampleCnt < value.nrofSamples; sampleCnt ++){
           assert(sensor2[sampleCnt] == sampleList[1][sampleCnt]);
      }
      for(sampleCnt = 0; sampleCnt < value.count; sampleCnt ++){
           assert(sensor3[sampleCnt] == sampleList[2][sampleCnt]);
      }   
}

void TestMinMax(void){
    assert(GetMinMax(sampleList[0], 10, GetMin) == 9.0);
    assert(GetMinMax(sampleList[0], 10, GetMax) == 35.0);
}

void TestMovingAverage(void)
{
  int idx;    
  int pos = 0;
  float sum = 0;
  int size = 5;
  int nrofsensors = 3;
  int nrofsamples = 10; 
  float* arrNumbers = (float*)calloc(5, sizeof(float));    

  float **movingAverage = (float**)calloc(nrofsensors, sizeof(float*));
  for(idx = 0; idx < nrofsensors; idx++){
     movingAverage[idx] = (float*)calloc(nrofsamples , sizeof(float)); 
  }   
  float sensor1movingAverage[10] = {5.5, 18.0, 22.0, 19.0, 14.0, 15.0, 16.5, 20.5, 20.5, 23.5};
  for(idx = 0; idx < nrofsamples; idx++) {
      movingAverage[0][idx] = GetmovingAverage(arrNumbers, &sum, pos, size, sampleList[0][idx]);
      assert(sensor1movingAverage[idx] == movingAverage[0][idx]);
      pos++;
      if (pos >= size){
        pos = 0;
      }
   } 
}
