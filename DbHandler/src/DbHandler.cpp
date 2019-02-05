#include "../inc/DbHandler.h"

DbHandler::DbHandler(void (*delObj)(void *))
    : DynamicClass(delObj)
{
}

DbHandler::~DbHandler(void)
{
}
