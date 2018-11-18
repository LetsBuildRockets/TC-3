#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include <string>
#include <iostream>
#include <sys/time.h>
#include <cstdlib>
#include <cstring>
#include "database.h"


const char *conninfo = "dbname = DAQDATA";
char *transaction;
int transactionCount = 0;

void exitDatabase(PGconn *conn) {
  PQfinish(conn);
  exit(1);
}

long getSensorUpdateThrottle(int id) {
  PGconn *conn;
  PGresult *res;

  conn = PQconnectdb(conninfo);
  if (PQstatus(conn) != CONNECTION_OK) {
    fprintf(stderr, "Connection to database failed: %s",
    PQerrorMessage(conn));
    exitDatabase(conn);
  }
  char tmptransaction[100];
  sprintf(tmptransaction, "select throttle_us from sensors where id=%d", id);
  res = PQexec(conn, tmptransaction);
  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    fprintf(stderr, "failed: %s", PQerrorMessage(conn));
    PQclear(res);
    exitDatabase(conn);
  }
  if(PQntuples(res) <1){
    return 0;
  }

  long throttle = atoll(PQgetvalue(res, 0, 0));

  PQclear(res);

  PQfinish(conn);
  return throttle;
}

std::string getSensorTransferFunction(int id) {
  PGconn *conn;
  PGresult *res;

  conn = PQconnectdb(conninfo);
  if (PQstatus(conn) != CONNECTION_OK) {
    fprintf(stderr, "Connection to database failed: %s",
    PQerrorMessage(conn));
    exitDatabase(conn);
  }
  char tmptransaction[100];
  sprintf(tmptransaction, "select transfer_function from sensors where id=%d", id);
  res = PQexec(conn, tmptransaction);
  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    fprintf(stderr, "failed: %s", PQerrorMessage(conn));
    PQclear(res);
    exitDatabase(conn);
  }
  if(PQntuples(res) < 1){
    return "";
  }

  char transfunc[100];
  sprintf(transfunc,"%-15s", PQgetvalue(res, 0, 0));

  PQclear(res);

  PQfinish(conn);
  return std::string(transfunc);
}

int getTestNumber() {
  PGconn *conn;
  PGresult *res;

  conn = PQconnectdb(conninfo);
  if (PQstatus(conn) != CONNECTION_OK) {
    fprintf(stderr, "Connection to database failed: %s",
    PQerrorMessage(conn));
    exitDatabase(conn);
  }
  char tmptransaction[100];
  sprintf(tmptransaction, "SELECT MAX(test_num) FROM testdata");
  res = PQexec(conn, tmptransaction);
  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    fprintf(stderr, "failed: %s", PQerrorMessage(conn));
    PQclear(res);
    exitDatabase(conn);
  }
  if(PQntuples(res) < 1){
    return 0;
  }

  int testNumber = atoi(PQgetvalue(res, 0, 0)) + 1;

  PQclear(res);

  PQfinish(conn);
  return testNumber;
}

void executeDatabaseWrite() { // TODO Paramtraize
  if(transaction[0] == '\0') return;
  //printf("transaction: %s\n", transaction);
  char *p = transaction;
  databaseBufferClear();

  PGconn *conn;
  PGresult *res;
  conn = PQconnectdb(conninfo);
  if (PQstatus(conn) != CONNECTION_OK) {
    fprintf(stderr, "Connection to database failed: %s",
    PQerrorMessage(conn));
    exitDatabase(conn);
  }
  res = PQexec(conn, p);
  if (PQresultStatus(res) != PGRES_COMMAND_OK) {
    fprintf(stderr, "failed: %s", PQerrorMessage(conn));
    PQclear(res);
    exitDatabase(conn);
  }
  PQfinish(conn);
  free(p);
  //exit(0);
}

/*getTransaction(char *transaction) {
  if (transactionCount == 0) {
    transaction[0] = '\0';
  } else {
    std::strcat(transaction, ";");
  }
}*/

void databaseBufferClear() {
  transaction = (char*)malloc(sizeof(char[262144]));
  transactionCount = 0;
  transaction[0] = '\0';
}

void bufferSensorData(int testNumber, timespec *time, int sensorId, int raw, double scaled) {
  if (transactionCount > 3200){
    printf("Warning! Your buffer is filling up. You have %d transactions pending!!!\n", transactionCount);
    executeDatabaseWrite();
  }
  if(transactionCount == 0) {
    std::strcat(transaction, "INSERT INTO testdata VALUES");
  } else {
      std::strcat(transaction, ",");
  }
  transactionCount++;
  double timestamp = (double) ((*time).tv_nsec) / 1000000000.0 +(double) ((*time).tv_sec);
  char tmptransaction[100];
  sprintf(tmptransaction, "(%d,to_timestamp(%f),%d,%d,%f)", testNumber, timestamp, sensorId, raw, scaled);
  std::strcat(transaction, tmptransaction);
}
