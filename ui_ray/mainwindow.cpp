#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QImage>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <QDebug>

using namespace std;
using namespace cv;

QImage hj_img;
VideoCapture cap(0);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my_timer = new QTimer();
    my_timer->start(5);  //5ms
}

MainWindow::~MainWindow()
{
    delete ui;
}

void robotWare::print_hello()
{
    cout<<"hello world!"<<endl;
}

void robotWare::readAndShowImg()
{
    Mat in_image;
    in_image=imread("cat.png");
    cout<<"height="<<in_image.rows<<endl;
    cout<<"width="<<in_image.cols<<endl;
    imshow("the image I have red:",in_image);
    waitKey(10000);

}

QImage cvMat2QImage(const cv::Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        qDebug() << "CV_8UC4";
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}


void robotWare::vedioCap()
{
    cap.set(CV_CAP_PROP_FRAME_WIDTH,480);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT,240);
    Mat frame;
    cap>>frame;
    hj_img=cvMat2QImage(frame);
}

void MainWindow::vedioShow()
{
    robotWare r;
    r.vedioCap();
    ui->label_8->setPixmap(QPixmap::fromImage(hj_img));
    ui->label_8->setGeometry(300,0,hj_img.width(),hj_img.height());
}

void MainWindow::on_pushButton_2_clicked()
{
    //vedioShow();
    connect(my_timer,SIGNAL(timeout()),this,SLOT(vedioShow()));
}
