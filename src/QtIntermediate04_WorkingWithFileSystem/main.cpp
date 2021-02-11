#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QBuffer>
#include <QIODevice>
#include <QDir>
#include <QFileInfo>

using namespace std;

bool createDir(QString path) {
    QDir dir(path);

    if (dir.exists()) {
        qInfo() << "Already exists!";
        return true;
    }

    if (dir.mkpath(path)) {
        qInfo() << "Created!";
        return true;
    } else {
        qInfo() << "Could not create!";
        return false;
    }
}

bool renameDir(QString path, QString name) {
    QDir dir(path);
    if (!dir.exists()) {
        qInfo() << "Path does not exist!";
        return false;
    }

    int pos = path.lastIndexOf(QDir::separator()); /* Linux is /, Windows is C:\ */
    QString parent = path.mid(0, pos);
    QString newpath = parent + QDir::separator() + name;
    qInfo() << "Absolute: " << dir.absolutePath();
    qInfo() << "Parent: " << parent;
    qInfo() << "New: " << newpath;

    return dir.rename(path, newpath);
}

bool removeDir(QString path) {
    qInfo() << "Removing: " << path;
    QDir dir(path);

    if (!dir.exists()) {
        qInfo() << "Path does not exists!";
        return false;
    }

    // DANGER!!!
    return dir.removeRecursively();
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // QBuffer
    QBuffer buffer;
    if (buffer.open(QIODevice::ReadWrite)) {
        qInfo() << "Buffer Opened!";
        QByteArray data("Hello World");
        for (int i = 0; i < 5; ++i) {
            buffer.write(data);
            buffer.write("\r\n");
        }
        // buffer.flush();
        buffer.seek(0);
        qInfo() << buffer.readAll();
        buffer.close();
    } else {
        qInfo() << "Could not open buffer!!!";
    }

    // QDir
    QString path = QDir::currentPath();
    QString testDir = path + QDir::separator() + "test";
    QString tmp = path + QDir::separator() + "tmp";
    QDir current(QDir::currentPath());
    if (current.exists()) {
                foreach(QFileInfo fi, current.entryInfoList()) {
                qInfo() << fi.fileName();
            }
    }

    if (createDir(testDir)) {
        qInfo() << "Created test!";
        if (renameDir(testDir, "tmp")) {
            qInfo() << "Renamed!";
            if (removeDir(tmp)) {
                qInfo() << "Removed";
            } else {
                qInfo() << "Could not remove";
            }
        }
    }

    // QFileInfo


    return 0;
}

