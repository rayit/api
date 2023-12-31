#include "crow.h"
#include <stdio.h>
#include <sqlite3.h> 


static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main()
{
    /* Create SQL statement */
    // sql = "CREATE TABLE IF NOT EXISTS COMPANY("  \
    //   "ID INT PRIMARY KEY     NOT NULL," \
    //   "NAME           TEXT    NOT NULL," \
    //   "AGE            INT     NOT NULL," \
    //   "ADDRESS        CHAR(50)," \
    //   "SALARY         REAL );";

	// Creating crow app
    crow::SimpleApp app;

    // Endpoint /
    CROW_ROUTE(app, "/")([](){

        // SQLite
        sqlite3 *db;
        char *zErrMsg = 0;
        int rc;
        char *sql;
        rc = sqlite3_open("test.db", &db);
        if( rc ) {
            fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        } else {
            fprintf(stderr, "Opened database successfully\n");
        }
        /* Create SQL statement */
        sql = "SELECT * from COMPANY;";

        /* Execute SQL statement */
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } else {
            fprintf(stdout, "Table created successfully\n");
        }
        sqlite3_close(db);
        return "Hello world";
    });

    // Add loglevel
    app.loglevel(crow::LogLevel::Warning);
    // app port and run
    app.port(18080).run();
}

