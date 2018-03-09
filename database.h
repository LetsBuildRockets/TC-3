#ifndef DATABASE_H
#define DATABASE_H

void exitDatabase();
long getSensorUpdateThrottle(int id);
std::string getSensorTransferFunction(int id);
int getTestNumber();
void executeDatabaseWrite();
void databaseBufferClear();
void bufferSensorData(int testNumber, timespec* time, int sensorId, int raw, double scaled);

#endif
