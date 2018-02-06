#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include <string>
#include <iostream>
#include <sys/time.h>
#include <cstdlib>
#include "database.h"


const char *conninfo = "dbname = DAQDATA";
static void exit_nicely(PGconn *conn) {
  PQfinish(conn);
  exit(1);
}

std::string getSensorTransferFunction(int id) {
  PGconn     *conn;
  PGresult   *res;

  conn = PQconnectdb(conninfo);
  if (PQstatus(conn) != CONNECTION_OK) {
    fprintf(stderr, "Connection to database failed: %s",
    PQerrorMessage(conn));
    exit_nicely(conn);
  }
  char transaction[100];
  sprintf(transaction, "select transfer_function from sensors where id=%d", id);
  res = PQexec(conn, transaction);
  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    fprintf(stderr, "failed: %s", PQerrorMessage(conn));
    PQclear(res);
    exit_nicely(conn);
  }
  if(PQntuples(res) <1){
    return "";
  }

  char transfunc[100];
  sprintf(transfunc,"%-15s", PQgetvalue(res, 0, 0));

  PQclear(res);

  PQfinish(conn);
  return std::string(transfunc);
}

int getTestNumber() {
  PGconn     *conn;
  PGresult   *res;

  conn = PQconnectdb(conninfo);
  if (PQstatus(conn) != CONNECTION_OK) {
    fprintf(stderr, "Connection to database failed: %s",
    PQerrorMessage(conn));
    exit_nicely(conn);
  }
  char transaction[100];
  sprintf(transaction, "SELECT MAX(test_num) FROM testdata");
  res = PQexec(conn, transaction);
  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    fprintf(stderr, "failed: %s", PQerrorMessage(conn));
    PQclear(res);
    exit_nicely(conn);
  }
  if(PQntuples(res) < 1){
    return 0;
  }

  int testNumber = atoi(PQgetvalue(res, 0, 0)) + 1;

  PQclear(res);

  PQfinish(conn);
  return testNumber;
}

void executeDatabaseWrite(std::string transaction) {
  //printf("transaction: %s\n", transaction.c_str());
  PGconn     *conn;
  PGresult   *res;
  conn = PQconnectdb(conninfo);
  if (PQstatus(conn) != CONNECTION_OK) {
    fprintf(stderr, "Connection to database failed: %s",
    PQerrorMessage(conn));
    exit_nicely(conn);
  }
  res = PQexec(conn, transaction.c_str());
  if (PQresultStatus(res) != PGRES_COMMAND_OK) {
    fprintf(stderr, "failed: %s", PQerrorMessage(conn));
    PQclear(res);
    exit_nicely(conn);
  }
  PQfinish(conn);
}

DatabaseBuffer::DatabaseBuffer() {
  transaction = "";
}

std::string DatabaseBuffer::getTransaction() {
  transaction += ";";
  return transaction;
}

void DatabaseBuffer::clear() {
  transaction = "";
}

void DatabaseBuffer::bufferSensorData(int testNumber, timeval* time, int sensorId, int raw, double scaled) {
  if(transaction.compare("")==0) {
    transaction = "INSERT INTO testdata VALUES";
  } else  {
    transaction += ",";
  }
  double timestamp = (double) ((*time).tv_usec) / 1000000 +(double) ((*time).tv_sec);
  char tmptransaction[100];
  sprintf(tmptransaction, "(%d,to_timestamp(%f),%d,%d,%f)", testNumber, timestamp, sensorId, raw, scaled);
  transaction += std::string(tmptransaction);
}
