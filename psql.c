/*
 * testlibpq.c
 *
 *      Test the C version of libpq, the PostgreSQL frontend library.
 */
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

  char transfunc[100];
  sprintf(transfunc,"%-15s", PQgetvalue(res, 0, 0));

  PQclear(res);

  PQfinish(conn);
  return std::string(transfunc);
}
main(int argc, char **argv) {
    /*PGconn     *conn;
    PGresult   *res;
    int         nFields;
    int         i, j;
    conninfo = "dbname = DAQDATA";

    // Make a connection to the database
    conn = PQconnectdb(conninfo);

    // Check to see that the backend connection was successfully made
    if (PQstatus(conn) != CONNECTION_OK)
    {
        fprintf(stderr, "Connection to database failed: %s",
                PQerrorMessage(conn));
        exit_nicely(conn);
    }

    res = PQexec(conn, "select * from sensors");
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        fprintf(stderr, "FETCH ALL failed: %s", PQerrorMessage(conn));
        PQclear(res);
        exit_nicely(conn);
    }

    // first, print out the attribute names
    nFields = PQnfields(res);
    for (i = 0; i < nFields; i++)
        printf("%-15s", PQfname(res, i));
    printf("\n\n");

    // next, print out the rows
    for (i = 0; i < PQntuples(res); i++)
    {
        for (j = 0; j < nFields; j++)
            printf("%-15s", PQgetvalue(res, i, j));
        printf("\n");
    }

    PQclear(res);

    PQfinish(conn);
    */
    printf("transferfunc %s\n",getSensorTransferFunction(0).c_str());

    return 0;
}
