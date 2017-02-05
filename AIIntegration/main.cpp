#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <NeuralNetwork.h>
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setNetwork(NeuralNetwork::load("C:/Users/Usuario/Documents/Javeriana/3 Semestre/Objetos/AIDefinitiva/saves/neuralSaveWorking.txt"));
    w.show();
    return a.exec();
}
