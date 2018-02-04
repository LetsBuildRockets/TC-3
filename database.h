#include <libpq-fe.h>

class DatabaseWriter {
public:
  DatabaseWriter();
  void writeSensorData(int testNumber, timeval* time, int sensorId, int raw, double scaled);
  void execute();
private:
  PGconn *conn;
  PGresult *res;
  std::string transaction;
};
static void exit_nicely(PGconn *conn);
std::string getSensorTransferFunction(int sensorId);
void writeSensorData(int testNumber, timeval* time, int sensorId, int raw, double scaled);
int getTestNumber();
