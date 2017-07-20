﻿/////////////////////////////////////////////////////////////////////////﻿
///AMMSAppWindow.h
///20170622 jason wong 创建该文件
/////////////////////////////////////////////////////////////////////////

#pragma once

#include <vector>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <QObject>
#include <QString>
#include <QCloseEvent>
#include <QMouseEvent>
#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include "EventProcesser.h"
#include "EventObject.h"
#include "ActorsListWidget.h"
#include "ActorInfoWidget.h"
#include "MovieWallWidget.h"
#include "MovieInfoWindow.h"

namespace amms {
    using namespace std;

    class CAMMSAppWindow : public QMainWindow, public CEventProcesser {
        Q_OBJECT
    public:
        //构造函数
        explicit CAMMSAppWindow(CEventRouter* v_pcEventRouter)
            : QMainWindow(NULL), CEventProcesser(true, v_pcEventRouter)
        {
        }
        //析构函数
        virtual ~CAMMSAppWindow() {}

        void Init();

    public slots:
        void slotActorSelected(QString);
        void slotMovieSelected(QString);

    signals:
        void signalEventToSelf(CEventObject);

    ///子类重载方法
    protected:
        //
        virtual void _ProcessEvent(CEventPtr& pcEvent) override;

    private slots:
        void slotEventFromSelf(CEventObject);

    private:
        map<string, QListWidgetItem*> m_mapFile2Item;

        CActorsListWidget*  m_pcActorsList;
        CActorInfoWidget*   m_pcActorInfoWidget;
        CMovieWallWidget*   m_pcMovieWall;
        CMovieInfoWindow*   m_pcMovieInfoWindow;
    };
}

