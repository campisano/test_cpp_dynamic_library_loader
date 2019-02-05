#include "../inc/DynamicLibrary.h"

#include "../inc/DynamicClass.h"
#include "../inc/LibraryLoader.h"

DynamicLibrary::DynamicLibrary(void * _obj_library)
    : m_obj_library(_obj_library)
{
}

DynamicLibrary::~DynamicLibrary()
{
    LibraryLoader::unloadLibrary(m_obj_library);
}

DynamicClass * DynamicLibrary::newObject(const char * name, int argc,
        void ** argv)
{
    void * load_sym = LibraryLoader::loadSym(m_obj_library, "loadObject");

    if(load_sym == NULL)
    {
        return NULL;
    }

    // Load a new instance of the requested class, and return it
    void * obj = ((void * (*)(const char *, int, void **))(load_sym))(name, argc,
                 argv);

    return reinterpret_cast<DynamicClass *>(obj);
}
