#ifndef FILE_PARSER_H_
#define FILE_PARSER_H_

typedef struct
{
   int nrofSamples;
   int count;
}Sensorvalue;

int GetCount(char * string);
int GetValue(char * string, int *paramArray, float **list);
Sensorvalue packSensorValue(int count, int samples);
Sensorvalue fileparser(FILE *fp);

#endif
