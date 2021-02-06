#include <iostream>
#include <QWidget>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    w.show();
    a.exec();

    cout << "Hello World"<< endl;
    return 0;
}
