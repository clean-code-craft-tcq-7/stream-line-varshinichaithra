#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FileParser.h"
#include "SensorApplication.h"
#include "RxApplication.h"
#include "test-sample.h"

int main(int argc, char* argv[]) {

    if(argc < 2)
    {
        printf("\n./* [option]");
        return 0;
    }
    if(strncmp(argv[1], "test", strlen("test")) == 0)
    {
        Sensorvalue value;
        int sensorCnt;
        FILE *fp;
        errno = 0;
        fp = fopen("sample.txt", "r");
        if(fp == NULL)
        {
            printf("\n File opening failed %d", errno);
            return 0;
        }

        value = TestSensorValue(fp);
        TestMinMax();
        TestMovingAverage(value.count, value.nrofSamples);
        free(lineptr);
        free(paramArray);
        for(sensorCnt = 0; sensorCnt < value.count; sensorCnt++)
        {
            free(sampleList[sensorCnt]);
        }
        free(sampleList);
        fclose(fp);
        printf("\n Test receiver workflow");
    }
    else if(strncmp(argv[1], "application", strlen("application")) == 0)
    {
        Sensorvalue value;
        int sensorCnt, sampleCnt;
        FILE *fp;
        errno = 0;
        fp = fopen("sample.txt", "r");
        if(fp == NULL)
        {
           printf("\n File opening failed %d", errno);
           return 0;
        }
        value = RxApplication(fp);

        if(strncmp(argv[2], "-p", strlen("-p")) == 0)
        {
            printf("\nnrofsample %d, count = %d", value.nrofSamples, value.count);
            //print sensor values
            for(sensorCnt = 0; sensorCnt < value.count; sensorCnt++)
            {
                printf("\nParameters %d =  %d\n", sensorCnt, paramArray[sensorCnt]);
                for(sampleCnt = 0; sampleCnt < value.nrofSamples; sampleCnt++)
                {
                    printf("\t%f", sampleList[sensorCnt][sampleCnt]);
                }
            }
            //print min max values
            for(sensorCnt = 0; sensorCnt < value.count; sensorCnt++)
            {
                printf("\nList = %d, min = %f, max = %f", sensorCnt, min[sensorCnt],
                                max[sensorCnt]);
            }
            //print moving average
            for(sensorCnt = 0; sensorCnt < value.count; sensorCnt++)
            {
                printf("\nlist %d moving average\n", sensorCnt);
                for(sampleCnt = 0; sampleCnt < value.nrofSamples; sampleCnt++)
                {
                    printf("\t%f", movingAverage[sensorCnt][sampleCnt]);
                }
            }
        }

        //Free memory allocated
        free(lineptr);
        free(paramArray);
        for(sensorCnt = 0; sensorCnt < value.count; sensorCnt++)
        {
            free(sampleList[sensorCnt]);
        }
        free(sampleList);

        RxApplication_FreeMem(value.count);
        fclose(fp);
  }
  else{
      //Do nothing
  }
  return 0;
}
