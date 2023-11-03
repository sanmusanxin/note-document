#include "my_ini.h"


//创建ini文件
my_ini::my_ini(QString qstrfilename)
{
    if (qstrfilename.isEmpty())
    {
        m_qstrFileName = QCoreApplication::applicationDirPath() + "/Config.ini";
    }
    else
    {
        m_qstrFileName = qstrfilename;
    }

    m_psetting = new QSettings(m_qstrFileName, QSettings::IniFormat);
    //m_psetting->setCodec(QTextCodec::codecForName("utf-8"));
    //m_psetting->setinicodec("utf8");
    //以上两句与下面一句作用相同，用于在qt4，在qt5中已经弃用
    m_psetting->setIniCodec(QTextCodec::codecForName("UTF-8"));
    qDebug() << m_qstrFileName;
}

my_ini::~my_ini(void)
{
    delete m_psetting;
    m_psetting = NULL;
}

void my_ini::CreateFile(QString qstrFileName, QString qstrFilePath)
{
    m_qstrFileName = qstrFilePath + "/"+ qstrFileName+ ".ini";
}

void my_ini::Set(QString qstrnodename,QString qstrkeyname,QVariant qvarvalue)
{
    m_psetting->setValue(QString("/%1/%2").arg(qstrnodename).arg(qstrkeyname), qvarvalue);
}

QVariant my_ini::Get(QString qstrnodename,QString qstrkeyname)
{
    QVariant qvar = m_psetting->value(QString("/%1/%2").arg(qstrnodename).arg(qstrkeyname));
    return qvar;
}

QList<float> my_ini::LineFitLeastSquares(QList<float> data_x, QList<float> data_y, int data_n)
{
    QList<float> result = {1.01,1.01,1.01};
    float A = 0.0;
    float B = 0.0;
    float C = 0.0;
    float D = 0.0;
    float E = 0.0;

    uint8_t i;

    for (i=0; i<data_n; i++)
    {
        A += data_x[i] * data_x[i];
        B += data_x[i];
        C += data_x[i] * data_y[i];
        D += data_y[i];
    }
    float a, b, temp = 0;
    temp = (data_n*A - B*B);

    if( temp )
    {
        a = (data_n*C - B*D) / temp;
        b = (A*D - B*C) / temp;
    }
    else
    {
        a = 1;
        b = 0;
    }
    float Xmean, Ymean;
    Xmean = B / data_n;
    Ymean = D / data_n;

    float tempSumXX = 0.0, tempSumYY = 0.0;
    for (int i=0; i<data_n; i++)
    {
        tempSumXX += (data_x[i] - Xmean) * (data_x[i] - Xmean);
        tempSumYY += (data_y[i] - Ymean) * (data_y[i] - Ymean);
        E += (data_x[i] - Xmean) * (data_y[i] - Ymean);
    }

    float F;
    F = sqrt(tempSumXX) * sqrt(tempSumYY);

    float r;
    r = E / F;
    result[0] = r;
    result[1] = a;
    result[2] = b;
    return result;
}
