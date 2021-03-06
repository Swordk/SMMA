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
#include <QAction>
#include "EventProcesser.h"
#include "EventObject.h"
#include "ActorsListWidget.h"
#include "CommonContentListWidget.h"
#include "ActorInfoWidget.h"
#include "MovieWallWidget.h"
#include "MovieWallSortCtlWidget.h"
#include "MovieInfoWindow.h"
#include "ScanDiskProcesser.h"

namespace amms {
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
        void slotSeriesSelected(QString);
        void slotGenresSelected(QString);
        void slotSnSelected(QString);
        void slotMovieSelected(QString);

    signals:
        void signalEventToSelf(CEventObject);
        void signalEventToChild(CEventObject);

    ///子类重载方法
    protected:
        //
        virtual void _ProcessEvent(CEventPtr& pcEvent) override;

    private slots:
        void slotEventFromSelf(CEventObject);
        void slotEventFromChild(CEventObject);

        void slotFreeMem();
        void slotScanDisk();

    private:
        void Movies2MovieWall(const std::set<std::string>& setMovies);


    private:
        // map<string, QListWidgetItem*> m_mapFile2Item;
        CScanDiskProcesser*         m_pcScanDiskProcesser;
        CActorsListWidget*          m_pcActorsList;         // 演员列表
        CCommonContentListWidget*   m_pcSeriesList;         // 系列列表
        CCommonContentListWidget*   m_pcGenresList;         // 类别列表
        CCommonContentListWidget*   m_pcSnList;             // 番号列表

        QAction*                    m_pcScanDisk;
        CActorInfoWidget*           m_pcActorInfoWidget;
        CMovieWallWidget*           m_pcMovieWall;
        CMovieWallSortCtlWidget*    m_pcMovieWallSortCtlWidget;
        CMovieInfoWindow*           m_pcMovieInfoWindow;
    };
}

