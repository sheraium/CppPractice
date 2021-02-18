#ifndef ICAR_H
#define ICAR_H

// interface 名 I + Car 大駝峰式命名法
class ICar {
public:
    // 方法使用小駝峰式命名法
    virtual void run() = 0;
    virtual void stop() = 0;

    // 屬性getter，同方法
    virtual int value() = 0;
    // 屬性setter, set + 屬性名
    virtual void setValue(int value) = 0;
};

#endif // ICAR_H
