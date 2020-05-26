#include <geapiwrapper.h>

GEEventHandler *GEApiWrapper::eventHandler;

void GEApiWrapper::setEventHandler(GEEventHandler *eventHandler)
{
	this->eventHandler = eventHandler;
}

// GEEventHandler * GEApiWrapper::getEventHandler()
// {
// 	return eventHandler;
// }
