#include <libpq-fe.h>

class DatabaseBuffer {
public:
  DatabaseBuffer();
  void bufferSensorData(int testNumber, timeval* time, int sensorId, int raw, double scaled);
  std::string getTransaction();
  void clear();
private:
  std::string transaction;
};
void executeDatabaseWrite(std::string transaction);
static void exit_nicely(PGconn *conn);
std::string getSensorTransferFunction(int sensorId);
int getTestNumber();
