#ifndef FILEIO_H_
#define FILEIO_H_
#define MAXSIZE 100
#define MAXNAME 20
#define NUM_RECORDS 3

int demoOpenClose(const char *, const char *);
int demoRead(const char *, const char *);
int demoWrite(const char *, const char *, const char *);
int demoWriteBinary(const char *, const char *, const int *);

//In class exercise
int exerciseBinaryWrite(const char* fileName, const char * fileMode);
int exerciseBinaryRead(const char* fileName, const char * fileMode, int id);

#endif
