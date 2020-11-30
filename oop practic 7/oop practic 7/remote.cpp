#include "remote.h"

remote& remote::power()
{
    this->tv->power();
    return *this;
}

remote& remote::operator++()
{
    this->tv->nextChannel();
    return *this;
}

remote& remote::operator--()
{
    tv->prevChannel();
    return *this;
}

remote& remote::setTv(TV* temp)
{
    tv = temp;
    return *this;
}

remote& remote::incVolume()
{
    this->tv->incVolume();
    return *this;
}

remote& remote::decVolume()
{
    this->tv->decVolume();
    return *this;
}


remote& remote::goToChannel(size_t channel)
{
    if (channel >= 0 && channel <= tv->maxChannel) {
         tv->currentChannel = channel;
        return *this;
    }
}


