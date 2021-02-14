#ifndef IANIMAL_H
#define IANIMAL_H

class IAnimal {
public:
    virtual void eat() = 0;

    virtual void sleep() = 0;

    virtual void move() = 0;

    virtual  ~IAnimal() {};

};

#endif // IANIMAL_H
