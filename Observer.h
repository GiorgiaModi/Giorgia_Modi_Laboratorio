//
// Created by Giorg on 13/07/2021.
//

#ifndef ESAME_LABORATORIO_OBSERVER_H
#define ESAME_LABORATORIO_OBSERVER_H


class Observer {
public:
    virtual ~Observer()=default;

    virtual void update(const string& listName)=0;
};


#endif //ESAME_LABORATORIO_OBSERVER_H
