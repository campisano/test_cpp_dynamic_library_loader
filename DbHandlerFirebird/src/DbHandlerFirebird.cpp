#include "../inc/DbHandlerFirebird.h"

#include <cstring>
#include <iostream>

DbHandlerFirebird::DbHandlerFirebird(void (*delObj)(void *))
    : DbHandler(delObj)
{
}

DbHandlerFirebird::~DbHandlerFirebird(void)
{
}

void DbHandlerFirebird::print(std::string _str_message)
{
    std::cout << "Hello, I'm DbHandlerFirebird and your message is " << _str_message
              << std::endl;
}


// The Dynamic library should also contain the following external C
// function definitions
extern "C"
{
    void deleteObject(void * obj)
    {
        delete reinterpret_cast<DynamicClass *>(obj);
    }

    void * loadObject(const char * name)
    {
        if(strncmp(name, "DbHandlerFirebird", strlen(name) < 17
                   ? strlen(name)
                   : 17) == 0)
        {
            return new DbHandlerFirebird(deleteObject);
        }

        return NULL;
    }
}
