#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::putin(QTableView *view_in,QTableView *patientView_in,QTableView *devicePatientView_in )
{
    view=view_in;
    patientView=patientView_in;
    devicePatientView=devicePatientView_in;
}

void Widget::on_pushButton_2_clicked()
{
    patientView->show();
    btnc2=1;
    qDebug()<<btnc2;
}

void Widget::on_pushButton_3_clicked()
{
    devicePatientView->show();
    btnc3=1;
}

void Widget::on_pushButton_clicked()
{
    view->show();
    btnc1=1;
}
