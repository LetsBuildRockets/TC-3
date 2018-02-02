#include <libpq-fe.h>

static void exit_nicely(PGconn *conn);
std::string getSensorTransferFunction(int);
