#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <opencv2/opencv.hpp>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer *my_timer;

private slots:
    void on_pushButton_2_clicked();
    void vedioShow();
private:
    Ui::MainWindow *ui;
};

class robotWare
{
public:
    void print_hello();
    void readAndShowImg();
    void vedioCap();
};

#endif // MAINWINDOW_H
