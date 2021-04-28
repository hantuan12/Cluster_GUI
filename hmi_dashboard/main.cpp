#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "qtquick2applicationviewer.h"
#include <QTimer>
#include "hmi_dashboard.h"
#include "hmi_shared_memory.h"
#include "hmi_states_values.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    // Declare Window Object
    Window Dashboard;
    // Declare Timer Object
    QTimer Timer;
    // Set 100 ms timeout
    Timer.start(100);
    // Connect timeout signal to Update_Can_Data function - call function every 100 ms
    app.connect(&Timer, SIGNAL(timeout()),&Dashboard, SLOT(Update_Can_Data()));
    return app.exec();
}
