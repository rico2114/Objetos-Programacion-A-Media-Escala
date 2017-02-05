#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <iostream>
#include "EigenVectorCalculator.h"
#include "CorpusLoader.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setNetwork(NeuralNetwork * network) {
    this->network = network;
}

void MainWindow::on_pushButton_clicked()
{
    string imgName = ui -> textEdit -> toPlainText().toStdString();
    string defaultLoc = "C:/Users/Usuario/Documents/Javeriana/3 Semestre/Objetos/AIDefinitiva/ppm/";
    defaultLoc.append(imgName);
    const vector<int> cuts = {0, 1, 2, 4, 6, 8, 9};
    vector<float> * testInput = EigenVectorCalculator::calculateEigenVector(defaultLoc, cuts);
    if (testInput == nullptr) {
        ui -> label_2 -> setText(QString("La imagen no se pudo encontrar."));
        return;
    }
    network -> setInputs(testInput->data());
    float *data = network -> calculateOutput();
    int topIndex = 0;
    for (int x = 1; x < 10; x++) {
        if (data[x] > data[topIndex]) {
            topIndex = x;
        }
    }
    QString number = QString::number(topIndex);
    ui -> label_2 -> setText(QString("El numero identificado fue: ").append(number));
}

void MainWindow::on_textEdit_textChanged()
{

}

void MainWindow::on_pushButton_2_clicked()
{
    int iterations = ui -> textEdit_2 -> toPlainText().toInt();
    int inclusiveInitial = ui -> textEdit_3 -> toPlainText().toInt();
    int inclusiveFinal = ui -> textEdit_4 -> toPlainText().toInt();
    int samplesSize = ui -> textEdit_5 -> toPlainText().toInt();
    string directory = "C:/Users/Usuario/Desktop/AI_QT_Integration/AIIntegration/Nets/";
    string output = directory.append(ui -> textEdit_6 -> toPlainText().toStdString());

    NeuralNetwork localNetwork;
    localNetwork.create(14, 10);

    vector<vector<float>> * data = CorpusLoader::loadCorpus("C:/Users/Usuario/Documents/Javeriana/3 Semestre/Objetos/AIDefinitiva/ppm/", "image", inclusiveInitial, inclusiveFinal, samplesSize);

    vector<vector<float>> correct;
    // Salen 10
    // 0 = 1, 0, 0, 0, 0, 0, 0, 0, 0, 0
    // 1 = 0, 1, 0, 0, 0, 0, 0, 0, 0, 0
    // 2 = 0, 0, 1, 0, 0, 0, 0, 0, 0, 0
    // 3 = 0, 0, 0, 1, 0, 0, 0, 0, 0, 0
    // 4 = 0, 0, 0, 0, 1, 0, 0, 0, 0, 0
    // 5 = 0, 0, 0, 0, 0, 1, 0, 0, 0, 0
    // 6 = 0, 0, 0, 0, 0, 0, 1, 0, 0, 0
    // 7 = 0, 0, 0, 0, 0, 0, 0, 1, 0, 0
    // 8 = 0, 0, 0, 0, 0, 0, 0, 0, 1, 0
    // 9 = 0, 0, 0, 0, 0, 0, 0, 0, 0, 1
    vector<float> cero = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<float> one = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<float> two = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
    vector<float> three = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
    vector<float> fourth = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
    vector<float> fifth = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
    vector<float> six = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
    vector<float> seven = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
    vector<float> eight = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0};
    vector<float> nine = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

    correct.push_back(cero);
    correct.push_back(one);
    correct.push_back(two);
    correct.push_back(three);
    correct.push_back(fourth);
    correct.push_back(fifth);
    correct.push_back(six);
    correct.push_back(seven);
    correct.push_back(eight);
    correct.push_back(nine);

    for (int i = 0; i <= iterations; i++) {
        int offset = 0;
        for (vector<float> subData : *(data)) {
            localNetwork.setInputs(subData.data());
            localNetwork.calculateOutput();
            localNetwork.adjustWages(correct[offset % 10].data());
            offset ++;
        }
    }
    localNetwork.save(output);
}

void MainWindow::on_pushButton_3_clicked()
{
    string directory = ui -> textEdit_7-> toPlainText().toStdString();
    delete(this -> network);
    this -> network = NeuralNetwork::load(directory);
}
