#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FileParser.h"

int *paramArray;
float **sampleList;

Sensorvalue fileparser(FILE *fp){
  size_t len;
  int read;
  int count = 0;
  int nrofSamples = 0;
  int idx;
  char *lineptr = NULL;
    
  if((read = getline(&lineptr, &len, fp)) != -1){
    //Read summary
  }  
  if((read = getline(&lineptr, &len, fp)) != -1){
     //Read date and time  
  }
  if((read = getdelim(&lineptr, &len, ':', fp)) != -1){
       //Read nr of samples
  } 
  if((read = getdelim(&lineptr, &len, '\n', fp)) != -1){
      nrofSamples = atoi(lineptr);
  } 
  //Read paramters
  if((read = getline(&lineptr, &len, fp)) != -1){
      count = GetCount(lineptr); 
  }
  paramArray = (int*) calloc(count, sizeof(int));
  sampleList = (float**)calloc(count, sizeof(float*));
  for(idx = 0; idx < count; idx++){
     sampleList[idx] = (float*)calloc(nrofSamples , sizeof(float)); 
  }
  //get value 
  for(idx = 0; idx < nrofSamples; idx++){
     if((read = getline(&lineptr, &len, fp)) != -1){ 
        GetValue(lineptr, paramArray, sampleList);  
     }
  }
  free(lineptr);
  return packSensorValue(count, nrofSamples);   
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

