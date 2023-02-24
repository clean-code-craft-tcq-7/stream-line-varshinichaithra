#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  
  if(argc < 2){
    printf("\n./* [option]");
    return 0;
  }
  if(strncmp(argv[1], "test", strlen("test")) == 0){
      TestSensorValue();
      TestMinMax();
      TestMovingAverage();
  }
  
  return 0;
}
