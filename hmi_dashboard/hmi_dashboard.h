#ifndef HMI_DASHBOARD_H
#define HMI_DASHBOARD_H

//Header file includes
#include <QObject>
#include <QQmlContext>
#include <QtQuick/QQuickView>
#include "qtquick2applicationviewer.h"
#include "hmi_shared_memory.h"

//Type
typedef enum{
    HMI_STATE_COMUNNICATION_ERROR,
    HMI_STATE_DEFAULT,
    HMI_STATE_ANIMATION,
    HMI_STATE_RUNTIME,
    HMI_STATE_SHUTDOWN
}HMI_STATES;


class Window : public QQuickView
{
    Q_OBJECT
    public:
        explicit Window(QWindow *parent = 0);
        QtQuick2ApplicationViewer *Dashboard;
    signals:
        public slots:
            void Update_Can_Data();
};

#endif
