#include <iostream>
#include "head.h"

int main()
{
    // -----Demo 2.-----
    DBConn dbc(DBConnection::create()); // 建立DBConnection对象并交给DBConn的接口

    // -----Demo 3.-----
    DBConn2 dbc2(DBConnection::create());
    try {
	  dbc2.close();
	}
    catch(...) {

    }

    return 0;
}
