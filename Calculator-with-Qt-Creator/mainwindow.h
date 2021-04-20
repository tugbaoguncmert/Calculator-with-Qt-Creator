#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


private slots:
    void digit_pressed();
    void on_pushButton_dezimal_clicked();
    void on_pushButton_PlusMinus_clicked();
    void on_pushButton_prozent_clicked();
    void on_pushButton_klar_clicked();
    void on_pushButton_gleich_clicked();
    void on_pushButton_addieren_clicked();
    void on_pushButton_subtrahieren_clicked();
    void on_pushButton_multiplizieren_clicked();
    void on_pushButton_teilen_clicked();
};
#endif // MAINWINDOW_H
