#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

double erstenummer;
bool userIsTypingSecondNumber;

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

    ui->pushButton_addieren->setCheckable(true);
    ui->pushButton_subtrahieren->setCheckable(true);
    ui->pushButton_multiplizieren->setCheckable(true);
    ui->pushButton_teilen->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Slot Function of numbers
void MainWindow::digit_pressed()
{
    qDebug()<<"Funktion wird aktiviert";

    QPushButton * button = (QPushButton*) sender();
    double labelnumber;

    if((ui->pushButton_addieren->isChecked() || ui->pushButton_subtrahieren->isChecked() ||
       ui->pushButton_multiplizieren->isChecked() || ui->pushButton_teilen->isChecked()) && (! userIsTypingSecondNumber)){

        labelnumber = (button->text()).toDouble();
        userIsTypingSecondNumber = true;
    }else{
        labelnumber = (ui->label->text() + button->text()).toDouble();
    }

    QString newlabel = QString::number(labelnumber);

    ui->label->setText(newlabel);

    //Printing one by one
    //ui->label->setText(button->text());
}

//Slot Function of dezimalButton
void MainWindow::on_pushButton_dezimal_clicked()
{
    qDebug()<<"clicked on dezimal button";
    ui->label->setText(ui->label->text() + ".");
}

//Slot Function of +/-
void MainWindow::on_pushButton_PlusMinus_clicked()
{
    qDebug()<<"clicked on plusminus button";

    double labelnummer = ui->label->text().toDouble();
    labelnummer =labelnummer * -1;
    QString newlabel =QString::number(labelnummer);

    ui->label->setText(newlabel);
}

//Slot Function of %
void MainWindow::on_pushButton_prozent_clicked()
{
    qDebug()<<"clicked on prozent button";

    double labelnummer = ui->label->text().toDouble();
    labelnummer =labelnummer / 100;
    QString newlabel =QString::number(labelnummer);

    ui->label->setText(newlabel);
}

//Slot Function of klarButton
void MainWindow::on_pushButton_klar_clicked()
{
    ui->pushButton_addieren->setCheckable(false);
    ui->pushButton_subtrahieren->setCheckable(false);
    ui->pushButton_multiplizieren->setCheckable(false);
    ui->pushButton_teilen->setCheckable(false);

    userIsTypingSecondNumber = false;

    ui->label->setText("0");
}

//Slot Function of =
void MainWindow::on_pushButton_gleich_clicked()
{
    qDebug()<<"gle'ch";
    double labelnumber;
    double zweitenumber;
    QString newlabel;
    zweitenumber = ui->label->text().toDouble();

    if(ui->pushButton_addieren->isChecked()){
        qDebug()<<"gleadd";
        labelnumber = erstenummer + zweitenumber;
        newlabel = QString::number(labelnumber);
        ui->label->setText(newlabel);

        ui->pushButton_addieren->setChecked(false);
    }
    else if(ui->pushButton_subtrahieren->isChecked()){
        labelnumber = erstenummer - zweitenumber;
        newlabel = QString::number(labelnumber);
        ui->label->setText(newlabel);

        ui->pushButton_subtrahieren->setChecked(false);
    }
    else if(ui->pushButton_multiplizieren->isChecked()){
        labelnumber = erstenummer * zweitenumber;
        newlabel = QString::number(labelnumber);
        ui->label->setText(newlabel);

        ui->pushButton_multiplizieren->setChecked(false);
    }
    else if(ui->pushButton_teilen->isChecked()){
        labelnumber = erstenummer / zweitenumber;
        newlabel = QString::number(labelnumber);
        ui->label->setText(newlabel);

        ui->pushButton_teilen->setChecked(false);
    }

    userIsTypingSecondNumber = false;
}
//Slot Function of +-/*
void MainWindow::on_pushButton_addieren_clicked()
{
    QPushButton * button = (QPushButton*) sender();
    erstenummer = ui->label->text().toDouble();
    button->setChecked(true);
}

void MainWindow::on_pushButton_subtrahieren_clicked()
{
    QPushButton * button = (QPushButton*) sender();
    erstenummer = ui->label->text().toDouble();
    button->setChecked(true);
}

void MainWindow::on_pushButton_multiplizieren_clicked()
{
    QPushButton * button = (QPushButton*) sender();
    erstenummer = ui->label->text().toDouble();
    button->setChecked(true);
}

void MainWindow::on_pushButton_teilen_clicked()
{
    QPushButton * button = (QPushButton*) sender();
    erstenummer = ui->label->text().toDouble();
    button->setChecked(true);
}
