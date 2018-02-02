#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include <string>
#include <iostream>


const char *conninfo = "dbname = DAQDATA";
static void exit_nicely(PGconn *conn) {
    PQfinish(conn);
    exit(1);
}

std::string getSensorTransferFunction(int id) {
  PGconn     *conn;
  PGresult   *res;
  int         nFields;
  int         i, j;

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
