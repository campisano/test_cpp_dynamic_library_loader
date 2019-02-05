#ifndef APR_LIBRARY_H_
#define APR_LIBRARY_H_

class LibraryLoader;

class AprLibrary
{

        friend class LibraryLoader;

    protected:

        void* m_apr_handler;
        void* m_apr_poolmem;

};

#endif
