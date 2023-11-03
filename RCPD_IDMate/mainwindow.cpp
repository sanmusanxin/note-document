#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // 初始化状态栏
        QLabel *labCellIndex = new QLabel("文件存储位置: ");
        labCellIndex->setMinimumWidth(125);

        QString fileaddress = QCoreApplication::applicationDirPath();
        QLabel *labCellType=new QLabel(fileaddress,this);
        labCellType->setMinimumWidth(1250);

        QString filename = "RCPD_SP2_IDMate" + QDateTime::currentDateTime().toString("yyMMdd") + ".csv";
        QLabel *labStudID=new QLabel(filename,this);
        labStudID->setMinimumWidth(225);

        // 将初始化的标签添加到底部状态栏上
        ui->statusbar->addWidget(labCellIndex);
        ui->statusbar->addWidget(labStudID);
        ui->statusbar->addWidget(labCellType);

    serial1 = new SerialPort;
    mydata = new my_data;
    testTimer = new QTimer;

    connect(testTimer, &QTimer::timeout, this, &MainWindow::testTimerhund);


    receTimer = new QTimer;
    connect(receTimer, &QTimer::timeout, this, &MainWindow::receiveHandle);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    //获取系统中存在的串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite)){
            ui->serial1Box->addItem(serial.portName());
            serial.close();
        }
    }
    //配置为上一次使用过的串口（如果这个串口在系统中存在的话）
    QString histroyComStr = my_ini().Get("serialport1","COM").toString();
    for(int idx=0; idx<ui->serial1Box->count(); idx++){
        QString itemName = ui->serial1Box->itemText(idx);
        if(itemName == histroyComStr){
            ui->serial1Box->setCurrentText(histroyComStr);
        }
    }

    //为界面加载图片
    QString filename = ":/new/prefix1/RCLog.png";
    QImage img;
    img.load(filename);
    img = img.scaled(ui->rclabel->width(),ui->rclabel->height(),Qt::KeepAspectRatio);
    ui->rclabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::addLog(QString str)
{
    QString timestr = QDateTime::currentDateTime().toString("hhmmss");
    QString _str = timestr + ": " + str;
    ui->textEdit->append(_str);
}

void MainWindow::clearShow()
{
    ui->IDlabel->clear();
    mydata->ID.clear();
    mydata->IDmcu.clear();
    mydata->receive.clear();
    ui->resShowButton->setText("--");

}

void MainWindow::updataShow(bool b)
{
    if(b){
        ui->resShowButton->setStyleSheet("background-color:rgb(60,179,113)");
        ui->resShowButton->setText("OK");
    }else{
        ui->resShowButton->setStyleSheet("background-color:rgb(220,20,60)");
        ui->resShowButton->setText("NG");
    }
}

bool MainWindow::openSerial1()
{
    bool states = false;
    if(ui->openButton->text() == tr("连接设备")){
        serial1->open(ui->serial1Box->currentText(),9600);
        my_ini().Set("serialport1","COM",ui->serial1Box->currentText());
        connect(serial1,&SerialPort::dataReceived, this, &MainWindow::ACWResData);
    }
    else{
        serial1->close();
    }
    if (serial1->isopen()){
        ui->openButton->setText("断开设备");
        addLog("连接到设备->"+ui->serial1Box->currentText());
        states = true;
        ui->testStartButton->setEnabled(false);
    }else{
        ui->openButton->setText("连接设备");
        addLog("设备已断开");
        states = false;
        ui->testStartButton->setEnabled(false);
    }
    return states;
}

void MainWindow::ACWResData(QByteArray data)
{
    if(data.size() == 9){
        // 这是一条完整的数据
        mydata->receive = data;
    }else{
        // 数据不完整
        for (int i = 0; i <data.size(); i++) {
           mydata->receive.append(data[i]);
        }
    }
    QString s;
    for (int i = 0; i < data.count(); ++i)
    {
        s.append( tr("%1 ").arg((quint8)data.at(i),2,16,QLatin1Char('0')).toUpper());
    }
    addLog("接收到数据： " + s);
}

void MainWindow::strageFile()
{
    QString timestr = QDateTime::currentDateTime().toString("hh:mm:ss");
    QString _ID = mydata->ID;
    QString _IDmcu = mydata->IDmcu;

    QString writeStr = timestr + "," + _ID + "," + _IDmcu + "\r\n";
    QString filename = "./data/RCPD_SP2_IDMate" + QDateTime::currentDateTime().toString("yyMMdd") + ".csv";
    QFile file(filename);
    file.open(QFile::WriteOnly | QFile::Append);
    file.write(writeStr.toLatin1());
    file.close();
}

void MainWindow::on_openButton_clicked()
{
    openSerial1();
}

void MainWindow::sleepMsec(int msec)
{
    QEventLoop loop;		//定义一个新的事件循环
    QTimer::singleShot(msec, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
    loop.exec();			//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
}

void MainWindow::testTimerhund()
{
    timerCount++;
    ui->progressBar->setValue(timerCount);
    if(timerCount>=10){
        timerCount = 0;
        testTimer->stop();
    }
}

void MainWindow::SP2MateID()
{
    int flag = 0;
    QByteArray data;
    data.resize(8);
    data[0] = 0x01;
    data[1] = 0x03;
    data[2] = 0x00;
    data[3] = 0x0B;
    data[4] = 0x00;
    data[5] = 0x02;
    data[6] = 0xB5;
    data[7] = 0xC9;

    serial1->write(data);
    for (int i = 0; i < 5 ; i++)
    {
        sleepMsec(50);
        receTimer->start(10);
        if(mydata->receive.size() == 9)
        {
            mydata->address = mydata->receive[0];
            mydata->command = mydata->receive[1];
            mydata->len = mydata->receive[2];
            mydata->id1 = mydata->receive[3] *256 +  mydata->receive[4];
            mydata->id2 = mydata->receive[5] *256 +  mydata->receive[6];

            mydata->day = mydata-> id1 &0x1F;
            mydata->mouth = (mydata-> id1 >> 5) & 0xF;
            mydata->year = mydata-> id1 >> 9;
            mydata->number = mydata->id2;
            mydata->IDmcu = QString("%1%2%3%4")
                    .arg(mydata->year,2,10,QLatin1Char('0'))
                    .arg(mydata->mouth,2,10,QLatin1Char('0'))
                    .arg(mydata->day,2,10,QLatin1Char('0'))
                    .arg(mydata->number,4,10,QLatin1Char('0'));

            if(mydata->IDmcu.size() == 10 && mydata->ID.size() == 12){
                addLog("匹配ID和二维码：" + mydata->ID + "------>" +mydata->IDmcu);
                ui->idShowEdit->clear();
                ui->IDlabel->setText(mydata->IDmcu);
                strageFile();
            }

            flag = -1;
            updataShow(true);
            return;
        }
        flag = i;
    }
    if(flag != -1)
    {
        addLog("接收的数据不完整");
        updataShow(false);
        ui->idShowEdit->clear();
    }
}

void MainWindow::receiveHandle()
{

}


void MainWindow::on_idShowEdit_textChanged(const QString &arg1)
{
    QString _id = ui->idShowEdit->text();
    if(_id.size() == 12)
    {
        clearShow();
        mydata->ID = _id;
        SP2MateID();
    }

}

void MainWindow::on_testStopButton_clicked()
{
    QByteArray data;
    data.resize(8);
    data[0] = 0x02;
    data[1] = 0x03;
    data[2] = 0x00;
    data[3] = 0x00;
    data[4] = 0x00;
    data[5] = 0x03;
    data[6] = 0x05;
    data[7] = 0xF8;

    serial1->write(data);
    addLog("传感器上电-------->");
}
