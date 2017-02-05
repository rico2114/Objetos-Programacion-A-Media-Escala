#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "NeuralNetwork.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setNetwork(NeuralNetwork * network);

private slots:
    void on_pushButton_clicked();

    void on_textEdit_textChanged();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    NeuralNetwork * network;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
