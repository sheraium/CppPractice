#include "democar.h"

DemoCar::DemoCar(QObject* parent) : QObject(parent)
{

}

void DemoCar::run()
{

}

void DemoCar::stop()
{

}

int DemoCar::height() const
{
    return m_height;
}

void DemoCar::setHeight(int height)
{
    m_height = height;
}

