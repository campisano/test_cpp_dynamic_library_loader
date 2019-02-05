#ifndef DYNAMIC_CLASS_H_
#define DYNAMIC_CLASS_H_

class DynamicClass
{

    public:

        // The constructor sets the callback function to use
        DynamicClass ( void ( *delObj ) ( void* ) );

        // The destructor
        virtual ~DynamicClass ( void );

        // Sends "this" to the callback destructor function.
        void deleteSelf ( void );

    private:

        // Callback function that should be called to delete dynamic object
        void ( *_deleteObject ) ( void* );

};

#endif
