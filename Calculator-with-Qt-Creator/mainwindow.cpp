#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //signal and slot
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digit_pressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Slot Funktion
void MainWindow::digit_pressed()
{
    qDebug()<<"Funktion wird aktiviert";

    QPushButton * button = (QPushButton*) sender();

    double labelnumber = (ui->label->text() + button->text()).toDouble();
    QString newlabel = QString::number(labelnumber);

    ui->label->setText(newlabel);

    //Printing one by one
    //ui->label->setText(button->text());
}
