#pragma once
#include "Shooter.h"

class Archer :virtual public Shooter
{
protected:
   Archer(const size_t& countAmunition);
   void addAmunition(const size_t& countAmunition);
   void shot();
};

