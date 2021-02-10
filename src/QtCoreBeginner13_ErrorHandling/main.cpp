#include <QCoreApplication>
#include <QDebug>
#include <iostream>

using namespace std;

struct MyIssue : public exception {
    const char *description;

    const char *what() const throw() {
        return "Our Description Here!!!";
    }
};


bool doDivision(int max) {
    try {
        int value;
        qInfo() << "Enter a number";
        cin >> value;

        if (value == 0 || value == NULL)throw std::invalid_argument("Can no divide by zero");
        if (value > 5)throw std::out_of_range("Should be less than 5");

        if (value == 1) {
            MyIssue e;
            e.description = "Hello World";
            throw e;
        }

        int result = max / value;
        qInfo() << "Result = " << result;
        return true;
    }
    catch (MyIssue &e) {
        qInfo() << e.what() << " " << e.description;
    }
    catch (std::exception &e) {
        qWarning() << e.what();
        return false;
    }

    return true;
}


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
//    return a.exec();

    int max = 44;
    do {
// do something here
    } while (doDivision(max));
    return 0;
}



