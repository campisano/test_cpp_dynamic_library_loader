#ifndef DYNAMIC_LIBRARY_H_
#define DYNAMIC_LIBRARY_H_

class LibraryLoader;
class DynamicClass;

// The DynamicLibrary class.
// This class will be created by the dynamic loader,
// and can be used to create objects out of a loaded library
class DynamicLibrary
{

        // Declare the LibraryLoader as a friend, so it can
        // instantiate DynamicLibrary.
        friend class LibraryLoader;

    public:

        // Destructor, closes the open shared library
        ~DynamicLibrary ( );

        // Creates a new instance of the named class, or returns NULL is the
        // class isn't found. The array of void*'s takes the arguments for
        // the class's constructor, with argc giving the number of arguments.
        DynamicClass* newObject ( const char* name, int argc, void** argv );

    protected:

        // The handle to the shared library that was opened
        void* m_obj_library;
        // Since an instance of DynamicLibrary manages lifetime of an open
        // library, it is important to make sure that the object isn't
        // copied.
        DynamicLibrary ( const DynamicLibrary& );
        DynamicLibrary& operator= ( const DynamicLibrary& );

        // Creates a new library, with the object file handle that is passed
        // in. Protected so that only the LibraryLoader can create an
        // instance (since it is declared friend.
        DynamicLibrary ( void* _obj_library );

};

#endif
