#include "../inc/LibraryLoader.h"

#include <apr-1/apr_general.h>
#include <apr-1/apr_dso.h>
#include <cstdio>
//#include <dlfcn.h>

#include "../inc/AprLibrary.h"
#include "../inc/DynamicLibrary.h"

DynamicLibrary * LibraryLoader::loadObjectFile(std::string _str_file)
{
    /*
    void* obj_library = dlopen ( _str_file.c_str(), RTLD_NOW );

    if ( obj_library == NULL )
    {
        return NULL;
    }

    return new DynamicLibrary ( obj_library );
    */
    apr_status_t res_status;
    apr_pool_t * mem_pool;
    apr_dso_handle_t * pnt_dso_handle;
    {
        apr_pool_create(&mem_pool, NULL);
        res_status = apr_dso_load(&pnt_dso_handle, _str_file.c_str(), mem_pool);
    }

    if(res_status != APR_SUCCESS)
    {
        LibraryLoader::printErrors(&res_status, pnt_dso_handle);
        return NULL;
    }

    AprLibrary * apr_library = new AprLibrary();
    apr_library->m_apr_handler = (void *) pnt_dso_handle;
    apr_library->m_apr_poolmem = (void *) mem_pool;

    return new DynamicLibrary(apr_library);
}

void LibraryLoader::unloadLibrary(void *& _obj_library)
{
    //dlclose ( _obj_library );

    if(! _obj_library)
    {
        return;
    }

    AprLibrary * apr_library = (AprLibrary *) _obj_library;

    apr_dso_handle_t * pnt_dso_handle = (apr_dso_handle_t *)
                                        apr_library->m_apr_handler;
    apr_dso_unload(pnt_dso_handle);

    apr_pool_t * mem_pool = (apr_pool_t *) apr_library->m_apr_poolmem;
    apr_pool_destroy(mem_pool);

    delete apr_library;
    _obj_library = 0;
}

void * LibraryLoader::loadSym(void * _obj_library, std::string _str_name)
{
    if(! _obj_library)
    {
        return NULL;
    }

    //return dlsym ( _obj_library, "loadObject" );
    AprLibrary * apr_library = (AprLibrary *) _obj_library;
    apr_dso_handle_t * pnt_dso_handle = (apr_dso_handle_t *)
                                        apr_library->m_apr_handler;

    apr_dso_handle_sym_t pnt_func = NULL;
    apr_status_t res_status = apr_dso_sym(&pnt_func, pnt_dso_handle,
                                          _str_name.c_str());

    if(res_status != APR_SUCCESS)
    {
        LibraryLoader::printErrors(&res_status, pnt_dso_handle);
        return NULL;
    }

    return (void *) pnt_func;
}

void LibraryLoader::printErrors(void * _result)
{
    LibraryLoader::printErrors(NULL, _result);
}

void LibraryLoader::printErrors(void * _result, void * _handler)
{
    char ary_c_buf[256];

    if(_result)
    {
        apr_status_t * pnt_status = (apr_status_t *) _result;
        apr_strerror((*pnt_status), ary_c_buf, sizeof(ary_c_buf));
        printf("error: %d, %s\n", (*pnt_status), ary_c_buf);
    }

    if(_handler)
    {
        apr_dso_handle_t * pnt_dso_handle = (apr_dso_handle_t *) _handler;
        apr_dso_error(pnt_dso_handle, ary_c_buf, sizeof(ary_c_buf));
        printf("dso-error: %s\n", ary_c_buf);
    }
}
