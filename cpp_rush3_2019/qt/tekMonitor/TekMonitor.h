#ifndef TEKMONITOR_H
#define TEKMONITOR_H

#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QProgressBar>
#include <QLCDNumber>
#include <QString>
#include <string>
#include <iostream>
#include <QObject>
#include <QTimer>

#include <ModuleCPU.hpp>
#include <ModuleKernel.hpp>
#include <ModuleRAM.hpp>
#include <ModuleNetwork.hpp>
#include <ModuleTime.hpp>
#include <ModuleUserHost.hpp>

class TekMonitor : public QWidget {
    Q_OBJECT
public:
    TekMonitor(QWidget *parent = 0);
    ~TekMonitor();

public slots:
    void Update();

private:
    ModuleCPU _mCpu;
    ModuleKernel _mKernel;
    ModuleRAM _mRam;
    ModuleTime _mTime;
    ModuleNetwork _mNetwork;
    ModuleUserHost _mUserHost;

    QTimer *_timer;

    QVBoxLayout *_mainLayout;
        QGroupBox *_gUserHost;
            QVBoxLayout *_lgUserHost;
                QHBoxLayout *_lUserHostName;
                    QLabel *_UserHostNameLt;
                    QLabel *_UserHostNameL;
                QHBoxLayout *_lUserName;
                    QLabel *_UserNameLt;
                    QLabel *_UserNameL;
        QGroupBox *_gKernel;
            QVBoxLayout *_lgKernel;
                QHBoxLayout *_lKernelVersion;
                    QLabel *_kernelVersionLt;
                    QLabel *_kernelVersionL;
                QHBoxLayout *_lKernelUptime;
                    QLabel *_kernelUptimeLt;
                    QLabel *_kernelUptimeL;
                QHBoxLayout *_lKernelSystem;
                    QLabel *_kernelSystemLt;
                    QLabel *_kernelSystemL;
        QGroupBox *_gTime;
            QVBoxLayout *_lgTime;
                QHBoxLayout *_lDate;
                    QLabel *_DateLt;
                    QLabel *_DateL;
                QHBoxLayout *_lTime;
                    QLabel *_timeLt;
                    QLabel *_timeL;
        QGroupBox *_gCpu;
            QVBoxLayout *_lgCpu;
                QHBoxLayout *_lModel;
                    QLabel *_modelLt;
                    QLabel *_modelL;
                QHBoxLayout *_lCore;
                    QLabel *_coreLt;
                    QLabel *_coreL;
                QHBoxLayout *_lFrequency;
                    QLabel *_frequencyLt;
                    QLabel *_frequencyL;
                QHBoxLayout *_lActivity;
                    QLabel *_activityLt;
                    QProgressBar *_activityP;
        QGroupBox *_gRam;
            QVBoxLayout *_lgRam;
                QHBoxLayout *_lRam;
                    QLabel *_ramLt;
                    QProgressBar *_ramP;
                    QLabel *_ramTotalL;
                QHBoxLayout *_lSwap;
                    QLabel *_swapLt;
                    QProgressBar *_swapP;
                    QLabel *_swapTotalL;
        QGroupBox *_gNetWork;
            QVBoxLayout *_lgNetwork;
                QHBoxLayout *_lin;
                    QLabel *_inLt;
                    QLabel *_inL;
                QHBoxLayout *_lout;
                    QLabel *_outLt;
                    QLabel *_outL;
};

#endif // TEKMONITOR_H
