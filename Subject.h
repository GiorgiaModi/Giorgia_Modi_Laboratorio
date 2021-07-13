//
// Created by Giorg on 13/07/2021.
//

#ifndef ESAME_LABORATORIO_SUBJECT_H
#define ESAME_LABORATORIO_SUBJECT_H
#include "Observer.h"

class Subject {
public:
    virtual ~Subject()=default;

    virtual void subscribe(Observer* o)=0;

    virtual void unsubscribe(Observer* o)=0;

    virtual void notify()=0;
};


#endif //ESAME_LABORATORIO_SUBJECT_H
