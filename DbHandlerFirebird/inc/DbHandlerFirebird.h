#ifndef DB_HANDLER_FIREBIRD_H_
#define DB_HANDLER_FIREBIRD_H_

#include <string>

#include "../../DbHandler/inc/DbHandler.h"

class DbHandlerFirebird : public DbHandler
{

    public:

        DbHandlerFirebird ( void ( *delObj ) ( void* ) );
        virtual ~DbHandlerFirebird ( void );
        virtual void print ( std::string _str_message );

    private:

};

#endif
