#include "../inc/DynamicClass.h"

DynamicClass::DynamicClass(void (*delObj)(void *))
    : _deleteObject(delObj)
{
}

DynamicClass::~DynamicClass(void)
{
}

void DynamicClass::deleteSelf(void)
{
    (*_deleteObject)(reinterpret_cast<void *>(this));
}
