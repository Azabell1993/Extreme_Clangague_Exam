#include <stdio.h>
#include <mysql/mysql.h>
#include <windows.h>

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "pw123"
#define DB_NAME "azabelldb"

int main() {
    MYSQL *conn_ptr;
    conn_ptr = mysql_init(NULL);
    if(!conn_ptr) {
        printf("mysql_init failed!!\n");
        return 0;
    }

    conn_ptr = mysql_real_connect(conn_ptr, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306,(char *)NULL, 0);

    if(conn_ptr) {
        printf("Success!! 성공\n");
    } else {
        printf("Faild!!! 실패\n");
    }
    mysql_close(conn_ptr);
    return 1;
}


