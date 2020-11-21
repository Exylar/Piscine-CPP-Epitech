#include <QApplication>
#include "TekMonitor.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    TekMonitor w;

    w.show();
    return (app.exec());
}
