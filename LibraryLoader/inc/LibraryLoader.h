#ifndef LIBRARY_LOADER_H_
#define LIBRARY_LOADER_H_

#include <string>

class DynamicLibrary;

class LibraryLoader
{

    public:

        static DynamicLibrary* loadObjectFile ( std::string _str_file );
        static void unloadLibrary ( void*& _obj_library );
        static void* loadSym ( void* _obj_library, std::string _str_name );

    private:

        static void printErrors ( void* _result, void* _handler );
        static void printErrors ( void* _result );

};

#endif
