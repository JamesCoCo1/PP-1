#include "interfacedisplay.h"

InterfaceDisplay::InterfaceDisplay(QWidget *parent) : QWidget(parent)
{

}

InterfaceDisplay::InterfaceDisplay(int maxE, int maxS, int maxI, QWidget *parent):
    QWidget(parent), maxEcg(maxE), maxSPO2(maxS), maxIBP2(maxI)
{
    this->ecgDrawer = new QWidgetDrawForSerialRx(this->maxEcg);
    this->ibp2Drawer = new QWidgetDrawForSerialRx(this->maxIBP2);
    this->spo2Drawer = new QWidgetDrawForSerialRx(this->maxSPO2);

    this->initMainLayout();

    // 这个只是测试用的 还需要添加更多的控件
    this->resize(600, 400);
    this->setLayout(this->mainLayout);
}

void InterfaceDisplay::initMainLayout()
{
    this->initDrawerLayout();
    this->initRightSideWidgetLayout();

    // 初始化主 layout
    this->mainLayout = new QHBoxLayout();
    this->mainLayout->addLayout(this->drawerLayout);
    this->mainLayout->addLayout(this->rightSideWidgetLayout);
    // 配置拉伸因子
    this->mainLayout->setStretchFactor(this->drawerLayout, 2);
    this->mainLayout->setStretchFactor(this->rightSideWidgetLayout, 1);
}

// 初始化画图部分的 layout
void InterfaceDisplay::initDrawerLayout()
{
    this->ecgDrawer->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    this->ibp2Drawer->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    this->spo2Drawer->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);

    this->ecgDrawer->setLabelText("ECG");
    this->spo2Drawer->setLabelText("SPO2");
    this->ibp2Drawer->setLabelText("IBP2");

    // 创建垂直箱式 layout
    // 添加波形绘制到 layout 中
    this->drawerLayout = new QVBoxLayout();
    this->drawerLayout->addWidget(this->ecgDrawer);
    this->drawerLayout->addWidget(this->spo2Drawer);
    this->drawerLayout->addWidget(this->ibp2Drawer);
}

void InterfaceDisplay::initRightSideWidgetLayout()
{
    this->rightSideWidgetLayout = new QVBoxLayout();

    this->widgetHr = new QLabel();
    this->widgetNibp = new QLabel();
    widgetHr->setText("HR");
    widgetNibp->setText("NiBP");

    this->btnUp = new QPushButton("UP");
    this->btnDowm = new QPushButton("DOWN");

    this->btnUp->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    this->btnDowm->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);

    // 加入 layout
    this->rightSideWidgetLayout->addWidget(widgetHr);
    this->rightSideWidgetLayout->addWidget(widgetNibp);
    this->rightSideWidgetLayout->addWidget(btnUp);
    this->rightSideWidgetLayout->addWidget(btnDowm);

}
