#include "widget.h"
#include "./ui_widget.h"
#include <QSerialPortInfo>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 随动布局
    this->setLayout(ui->gridLayoutGlobal);

    // 自动获取串口号并添加到ComboBox里
    QList<QSerialPortInfo> serialList =  QSerialPortInfo::availablePorts();
    for(QSerialPortInfo serialPort : serialList)
    {
        // 打印端口名字
        qDebug() << serialPort.portName();
        // 添加端口到ComboBox
        ui->comboBoxSerial->addItem(serialPort.portName());
    }

}

Widget::~Widget()
{
    delete ui;
}
