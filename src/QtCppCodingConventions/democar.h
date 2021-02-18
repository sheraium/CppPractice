#ifndef DEMOCAR_H
#define DEMOCAR_H

#include <QObject>

#include <interfaces/icar.h>

class DemoCar : public QObject, public ICar
{
    Q_OBJECT
public:
    explicit DemoCar(QObject* parent = nullptr);

    // ICar interface
    void run();
    void stop();
    // 屬性getter與setter可放在 Header file
    int value() {
        return m_value;
    }
    void setValue(int value) {
        m_value = value;
    }

signals:

protected:
    // 保護層級欄位
    int m_height = 0;
private:
    // 私有欄位
    int m_value = 0; // m_ + 欄位名
    int m_forkSpeed = 0; // 小駝峰式命名法
};

#endif // DEMOCAR_H
