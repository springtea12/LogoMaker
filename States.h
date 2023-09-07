#ifndef FINAL_STATES_H
#define FINAL_STATES_H
#include <map>

enum statesEnum
{
    HIDDEN,
    ENABLED,
    LAST_STATE,
    SHOWCHILDREN,
    FRESHINDEX
};

class States
{
private:
    std::map<statesEnum, bool> bools;

public:
    States();
    void enableState(statesEnum state);
    void disableState(statesEnum state);
    bool checkState(statesEnum state) const;
    void toggleState(statesEnum state);
};


#endif //FINAL_STATES_H
