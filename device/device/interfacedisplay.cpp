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
    // 初始化子 layout
    this->initUpsideLayout();
    this->initDownsideLayout();

    // 初始化主 layout
    this->mainLayout = new QVBoxLayout();
    this->mainLayout->addLayout(this->upsideLayout);
    this->mainLayout->addLayout(this->downsideLayout);
    // 配置拉伸因子
    this->mainLayout->setStretchFactor(this->upsideLayout, 1);
    this->mainLayout->setStretchFactor(this->downsideLayout, 10);
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

void InterfaceDisplay::initUpsideLayout()
{
    this->upsideLayout = new QHBoxLayout();

    this->testBtn = new QPushButton("test");
    this->testBtn->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);

    this->upsideLayout->addWidget(this->testBtn);

}

void InterfaceDisplay::initDownsideLayout()
{
    // 用之前进行初始化
    this->initDrawerLayout();
    this->initRightSideWidgetLayout();

    // downside layout
    this->downsideLayout = new QHBoxLayout();

    this->downsideLayout->addLayout(this->drawerLayout);
    this->downsideLayout->addLayout(this->rightSideWidgetLayout);
    // 配置拉伸因子
    this->downsideLayout->setStretchFactor(this->drawerLayout, 2);
    this->downsideLayout->setStretchFactor(this->rightSideWidgetLayout, 1);
}
