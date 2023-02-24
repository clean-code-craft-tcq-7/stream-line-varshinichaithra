#include <stdio.h>
#include <string.h>
#include "test-sample.h"

int main(int argc, char* argv[]) {  
  if(argc < 2){
    printf("\n./* [option]");
    return 0;
  }
  if(strncmp(argv[1], "test", strlen("test")) == 0){
      FILE* fp;
      fp = fopen("sample1.txt", "w+");
      if(fp == NULL){
         printf("\n file open failure");
      }
     else{
        printf("\n file open success");
      }
    
      fp = fopen("sample.txt", "r");
      if(fp == NULL){
         printf("\n file open failure");
      }
     else{
        printf("\n file open success");
      }
      TestSensorValue();
      TestMinMax();
      TestMovingAverage();
      printf("\n Test receiver workflow");
  } 
  return 0;
}
