#ifndef DB_HANDLER_H_
#define DB_HANDLER_H_

#include <string>

#include "../../LibraryLoader/inc/DynamicClass.h"

class DbHandler : public DynamicClass
{

    public:

        DbHandler ( void ( *delObj ) ( void* ) );
        virtual ~DbHandler ( void );
        virtual void print ( std::string _str_message ) = 0;

    private:

};

#endif
