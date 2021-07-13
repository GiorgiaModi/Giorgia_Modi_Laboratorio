//
// Created by Giorg on 13/07/2021.
//

#ifndef ESAME_LABORATORIO_OBSERVER_H
#define ESAME_LABORATORIO_OBSERVER_H

#include <string>

using namespace std;

class Observer {
public:
    virtual ~Observer(){}

    virtual void update(const string& listName)=0;
};


#endif //ESAME_LABORATORIO_OBSERVER_H
