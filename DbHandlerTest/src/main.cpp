#include <apr-1/apr_general.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include "../../LibraryLoader/inc/DynamicLibrary.h"
#include "../../LibraryLoader/inc/LibraryLoader.h"
#include "../../LibraryLoader/inc/DynamicClass.h"
#include "../../DbHandler/inc/DbHandler.h"

int main(int _n_args, const char * const _ary_args[])
{
    apr_app_initialize(&_n_args, &_ary_args, NULL);
    atexit(apr_terminate);

    // Load the dynamic library with the DbHandlerFirebird class
    DynamicLibrary * dynLibrary =
        LibraryLoader::loadObjectFile("libDbHandlerFirebird.so");

    if(dynLibrary == NULL)
    {
        std::cerr << "Couldn't load the dynamic library." << std::endl;
        return -1;
    }

    // Load a DbHandlerFirebird object
    DbHandler * handler = dynamic_cast<DbHandler *>
                          (dynLibrary->newObject("DbHandlerFirebird", 0, NULL));

    if(handler == NULL)
    {
        std::cerr << "Couldn't create filter object." << std::endl;
        return -1;
    }

    handler->print("ciao!");
    handler->deleteSelf();
    handler = NULL;

    // Close the dynamic library
    delete dynLibrary;

    // Exit the program
    return 0;
}
