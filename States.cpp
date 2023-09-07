#include "States.h"

void States::enableState(statesEnum state)
{
    bools[state] = true;
}

void States::disableState(statesEnum state)
{
    bools[state] = false;
}

bool States::checkState(statesEnum state) const
{
    return bools.at(state);
}

void States::toggleState(statesEnum state)
{
    bools[state] = !bools[state];
}

States::States()
{
    for(int i = 0; i < LAST_STATE; i++)
        bools[static_cast<statesEnum>(i)] = false;
}
