#include "gui/gui_utils/special_log_content_manager.h"
#include "gui/main_window/main_window.h"
#include "gui/file_manager/file_manager.h"

#include <QTimer>
#include <QDateTime>
#include <QDir>
#include <QFileInfo>
#include <QPixmap>
#include <QDebug>
#include <QGuiApplication>
#include <QScreen>
#include <QTabWidget>
#include <QWindow>
#include <QWindowList>
#include <QPainter>

namespace hal
{
    SpecialLogContentManager::SpecialLogContentManager(QObject *parent) : QObject(parent),
       mTimer(new QTimer(this))
    {
        mScreenshotSubPath = "/screenshots";

        connect(mTimer, &QTimer::timeout, this, &SpecialLogContentManager::saveScreenshot);
    }

    SpecialLogContentManager::~SpecialLogContentManager()
    {

    }

    void SpecialLogContentManager::saveScreenshot()
    {
        QString halFileName = FileManager::get_instance()->fileName();

        if(halFileName.isEmpty() || qGuiApp->topLevelWindows().isEmpty())
            return;

        QDir halFileDir = QFileInfo(halFileName).absoluteDir();
        QString halFileNameSubPath = "/" + QFileInfo(halFileName).baseName();
        QString screenshotPath = halFileDir.path() + halFileNameSubPath + mScreenshotSubPath;
        if(!halFileDir.exists(screenshotPath))
        {
            if(!halFileDir.mkpath(screenshotPath))
            {
                qDebug() << "Failed to create screenshots directory.";
                return;
            }
        }

        QString fileName = "Screenshot_" +QString::number(QDateTime::currentDateTime().toTime_t());
        QString fileType = "png";

        QList<QPixmap> pixmapList;
        int totalWidth = 0;
        int maxHeight = 0;
        for(int i = 0; i < qGuiApp->topLevelWindows().size(); i++)
        {
            QWidget* found_wid = QWidget::find(qGuiApp->topLevelWindows().at(i)->winId());
            if(found_wid)
            {
                QPixmap p(found_wid->size());
                found_wid->render(&p);
                totalWidth += p.width();
                maxHeight = (maxHeight > p.height()) ? maxHeight : p.height();
                pixmapList.append(p);
            }
        }

        QImage image(totalWidth, maxHeight, QImage::Format_RGB32);
        QPainter painter(&image);
        int curr_x = 0;
        for(int i = 0; i < pixmapList.size(); i++)
        {
            QPixmap currPixmap = pixmapList.at(i);
            painter.drawPixmap(curr_x, 0, currPixmap);
            painter.fillRect(curr_x, currPixmap.height(), currPixmap.width(), maxHeight-currPixmap.height(),Qt::white);
            curr_x += currPixmap.width();
        }

        if(!image.save(screenshotPath + "/" + fileName + "." + fileType))
            qDebug() << "Could not save image!";
    }

    void SpecialLogContentManager::startLogging(int msec)
    {
        mTimer->start(msec);
    }

}
