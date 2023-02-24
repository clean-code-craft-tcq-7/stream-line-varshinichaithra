#include <stdio.h>
#include <string.h>
#include "test-sample.h"

int main(int argc, char* argv[]) {  
  if(argc < 2){
    printf("\n./* [option]");
    return 0;
  }
  if(strncmp(argv[1], "test", strlen("test")) == 0){
      FILE *fp;
      fp = fopen("sample.txt", "r");
      if(fp == NULL){
         printf("\n File opening failed");
         return 0;
      }
      TestSensorValue(fp);
      TestMinMax();
      TestMovingAverage();
      printf("\n Test receiver workflow");
  } 
  return 0;
}
