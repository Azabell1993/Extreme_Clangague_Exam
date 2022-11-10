cmake_minimum_required(VERSION 3.23)
project(MySqlTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "-fexec-charset=CP949")

include_directories("C:\\Program Files\\MySQL\\MySQL Server 8.0\\include")
link_directories("C:\\Program Files\\MySQL\\MySQL Server 8.0\\lib")

link_libraries(libmysql)

add_executable(MySqlTest main.cpp)
target_link_libraries(MySqlTest mysqlclient
        -Wall -Werror -Wformat
        )


