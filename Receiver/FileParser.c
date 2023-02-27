#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FileParser.h"

int *paramArray;
float **sampleList;
char *lineptr = NULL;

Sensorvalue fileparser(FILE *fp){
  size_t len;
  int idx;
  int count = 0;
  int nrofSamples = 0;
  Sensorvalue value;
    
  //Read summary
  getline(&lineptr, &len, fp);
  //Read date and time
  getline(&lineptr, &len, fp);
  //Read nr of samples
  getdelim(&lineptr, &len, ':', fp);
  //Get header
  value = GetHeader(fp);
  //allocate memory
  paramArray = (int*) calloc(count, sizeof(int));
  sampleList = (float**)calloc(count, sizeof(float*));
  for(idx = 0; idx < count; idx++){
     sampleList[idx] = (float*)calloc(nrofSamples , sizeof(float)); 
  }
  GetSamples(fp, value.nrofSamples);
  return value;
}

Sensorvalue GetHeader(FILE *fp){
    int count = 0;
    int nrofSamples = 0;
    size_t len;
    int read;
    if((read = getdelim(&lineptr, &len, '\n', fp)) != -1){
      nrofSamples = atoi(lineptr);
    }
    //Read paramters
    if((read = getline(&lineptr, &len, fp)) != -1){
      count = GetCount(lineptr);
    }
    return packSensorValue(count, nrofSamples);
}

int GetSamples(FILE *fp, int nrofSamples){
    int idx;
    size_t len;
    int read;
    //get value
    for(idx = 0; idx < nrofSamples; idx++){
       if((read = getline(&lineptr, &len, fp)) != -1){
          GetValue(lineptr, paramArray, sampleList);
       }
       else{
           return 0;
       }
    }
    return 1;
}

Sensorvalue packSensorValue(int count, int samples){
    Sensorvalue retVal;
    retVal.nrofSamples = samples;
    retVal.count = count;
    return retVal;
}

int GetCount(char * string){
    int count = 0;
    char * token = strtok(string, ";");
    while (token != NULL) {            
        token = strtok(NULL, ";");           
        count++;       
    }  
    return count;
}

int GetValue(char * string, int *paramArray, float **list){
    int count = 0;
    char * token = strtok(string, ";");
    while (token != NULL) {           
        list[count][paramArray[count]] = atof(token);
        token = strtok(NULL, ";");     
        paramArray[count] ++;
        count++; 
    }  
    return count;
}

