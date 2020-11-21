
#include "TekMonitor.h"

TekMonitor::TekMonitor(QWidget *parent) : QWidget(parent) {
    _mainLayout = new QVBoxLayout(this);

        _gUserHost = new QGroupBox("User Host:");
        _mainLayout->addWidget(_gUserHost);
            _lgUserHost = new QVBoxLayout(_gUserHost);
                _lUserHostName = new QHBoxLayout();
                _lgUserHost->addLayout(_lUserHostName);
                    _UserHostNameLt = new QLabel("User host: ");
                    _lUserHostName->addWidget(_UserHostNameLt);
                    _UserHostNameL = new QLabel("xxxxxxxxx");
                    _lUserHostName->addWidget(_UserHostNameL);
                _lUserName = new QHBoxLayout();
                _lgUserHost->addLayout(_lUserName);
                    _UserNameLt = new QLabel("User name: ");
                    _lUserName->addWidget(_UserNameLt);
                    _UserNameL = new QLabel("xxxxxxxxx");
                    _lUserName->addWidget(_UserNameL);

        _gKernel = new QGroupBox("Kernel");
        _mainLayout->addWidget(_gKernel);
            _lgKernel = new QVBoxLayout(_gKernel);
                _lKernelVersion = new QHBoxLayout();
                _lgKernel->addLayout(_lKernelVersion);
                    _kernelVersionLt = new QLabel("Version:");
                    _lKernelVersion->addWidget(_kernelVersionLt);
                    _kernelVersionL = new QLabel("xxxxxxxxx");
                    _lKernelVersion->addWidget(_kernelVersionL);
                _lKernelUptime = new QHBoxLayout();
                _lgKernel->addLayout(_lKernelUptime);
                    _kernelUptimeLt = new QLabel("Uptime:");
                    _lKernelUptime->addWidget(_kernelUptimeLt);
                    _kernelUptimeL = new QLabel("xxxxxxxxxxx");
                    _lKernelUptime->addWidget(_kernelUptimeL);
                _lKernelSystem = new QHBoxLayout();
                _lgKernel->addLayout(_lKernelSystem);
                    _kernelSystemLt = new QLabel("System name:");
                    _lKernelSystem->addWidget(_kernelSystemLt);
                    _kernelSystemL = new QLabel("xxxxxxxxxx");
                    _lKernelSystem->addWidget(_kernelSystemL);

        _gTime = new QGroupBox("Time:");
        _mainLayout->addWidget(_gTime);
            _lgTime = new QVBoxLayout(_gTime);
                _lDate = new QHBoxLayout();
                _lgTime->addLayout(_lDate);
                    _DateLt = new QLabel("Date:");
                    _lDate->addWidget(_DateLt);
                    _DateL = new QLabel("xxxxxxxx");
                    _lDate->addWidget(_DateL);
                _lTime = new QHBoxLayout();
                _lgTime->addLayout(_lTime);
                    _timeLt = new QLabel("Time");
                    _lTime->addWidget(_timeLt);
                    _timeL = new QLabel("xxxxxxxxx");
                    _lTime->addWidget(_timeL);

        _gCpu = new QGroupBox("CPU:");
        _mainLayout->addWidget(_gCpu);
            _lgCpu = new QVBoxLayout(_gCpu);
                _lModel = new QHBoxLayout();
                _lgCpu->addLayout(_lModel);
                    _modelLt = new QLabel("Model:");
                    _lModel->addWidget(_modelLt);
                    _modelL = new QLabel("xxxxxxxxx");
                    _lModel->addWidget(_modelL);
                _lCore = new QHBoxLayout();
                _lgCpu->addLayout(_lCore);
                    _coreLt = new QLabel("Core number:");
                    _lCore->addWidget(_coreLt);
                    _coreL = new QLabel("xxxxxxx");
                    _lCore->addWidget(_coreL);
                _lFrequency = new QHBoxLayout();
                _lgCpu->addLayout(_lFrequency);
                    _frequencyLt = new QLabel("Frequency:");
                    _lFrequency->addWidget(_frequencyLt);
                    _frequencyL = new QLabel("xxxxxxxxxx");
                    _lFrequency->addWidget(_frequencyL);
                _lActivity = new QHBoxLayout();
                _lgCpu->addLayout(_lActivity);
                    _activityLt = new QLabel("Activity:");
                    _lActivity->addWidget(_activityLt);
                    _activityP = new QProgressBar();
                    _lActivity->addWidget(_activityP);

        _gRam = new QGroupBox("RAM:");
        _mainLayout->addWidget(_gRam);
            _lgRam = new QVBoxLayout(_gRam);
                _lRam = new QHBoxLayout();
                _lgRam->addLayout(_lRam);
                    _ramLt = new QLabel("RAM: ");
                    _lRam->addWidget(_ramLt);
                    _ramP = new QProgressBar();
                    _lRam->addWidget(_ramP);
                _lSwap = new QHBoxLayout();
                _lgRam->addLayout(_lSwap);
                    _swapLt = new QLabel("SWAP:");
                    _lSwap->addWidget(_swapLt);
                    _swapP = new QProgressBar();
                    _lSwap->addWidget(_swapP);

        _gNetWork = new QGroupBox("Network:");
        _mainLayout->addWidget(_gNetWork);
            _lgNetwork = new QVBoxLayout(_gNetWork);
                _lin = new QHBoxLayout();
                _lgNetwork->addLayout(_lin);
                    _inLt = new QLabel("in:");
                    _lin->addWidget(_inLt);
                    _inL = new QLabel("xxxxxxx");
                    _lin->addWidget(_inL);
                _lout = new QHBoxLayout();
                _lgNetwork->addLayout(_lout);
                    _outLt = new QLabel("out:");
                    _lout->addWidget(_outLt);
                    _outL = new QLabel("xxxxxxx");
                    _lout->addWidget(_outL);

        _activityP->setRange(0, 100);

        Update();
        _timer = new QTimer(this);
        QObject::connect(_timer, SIGNAL(timeout()), this, SLOT(Update()));
        _timer->start(1000);
}

TekMonitor::~TekMonitor() {
    delete _mainLayout;
        delete _gUserHost;
        delete _gKernel;
        delete _gTime;
        delete _gCpu;
        delete _gRam;
        delete _gNetWork;
}

void TekMonitor::Update() {
    _mUserHost.Update();
    _mKernel.Update();
    _mTime.Update();
    _mCpu.Update();
    _mRam.Update();
    _mNetwork.Update();

    _UserHostNameL->setText(QString::fromUtf8(_mUserHost.GetHostName().c_str()));
    _UserNameL->setText(QString::fromUtf8(_mUserHost.GetUserName().c_str()));

    _kernelVersionL->setText(QString::fromUtf8(_mKernel.getKernelVersion().c_str()));
    _kernelUptimeL->setText(QString::number(_mKernel.getUptime()));
    _kernelSystemL->setText(QString::fromUtf8(_mKernel.getSystemName().c_str()));

    _DateL->setText(QString::fromUtf8(_mTime.GetDate().c_str()));
    _timeL->setText(QString::fromUtf8(_mTime.GetTime().c_str()));

    _modelL->setText(QString::fromUtf8(_mCpu.getModel().c_str()));
    _coreL->setText(QString::number(_mCpu.getNbCores()));
    _frequencyL->setText(QString::number(_mCpu.getFrequency()) + "MHz");
    _activityP->setValue(_mCpu.getActivity());

    _ramP->setRange(0, _mRam.getMemTotal());
    _ramP->setValue(_mRam.getMemTotal() - _mRam.getMemFree());
    _swapP->setRange(0, _mRam.getSwapTotal());
    _swapP->setValue(_mRam.getSwapTotal() - _mRam.getSwapFree());


    _outL->setText(QString::number(_mNetwork.GetUpload()) + " Ko/s");
    _inL->setText(QString::number(_mNetwork.GetDownload()) + " Ko/s");
}
