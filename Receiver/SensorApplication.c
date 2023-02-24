
#include "SensorApplication.h"

int GetMin(float a, float b){
    return (a < b);
}

int GetMax(float a, float b){
    return (a > b);
}

//Get Min and max value
float GetMinMax(float list[], int size, int (*input)(float, float)){
    int i;
    float num = list[0];
    for(i = 1; i < size; i++){
        if(input(num, list[i]) == 0){
            num = list[i];
        }
    }
    return num;
}

float GetmovingAverage(float *list, float *sum, int pos, int len, float nextNum)
{
   *sum = *sum - list[pos] + nextNum;
   list[pos] = nextNum;
   return *sum / len;
}
