

#include<iostream>
#include <mysql/mysql.h>

int main(int argc,char *argv[])
{
    MYSQL * pdb;
    pdb = mysql_init(NULL);
    if(pdb != NULL)
    {
        std::cout << "init succ" << std::endl;
    }
    else
    {
        std::cout << "init failed" << std::endl;
    }
    if(pdb != NULL)
    {
        mysql_close(pdb);
        std::cout << "close succ" << std::endl;
    }
    return 0;
}