#include "mainwindow.h"
#include "tipo.h"
#include "ui_mainwindow.h"
#include "parser.hpp"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QByteArray>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QString execButtonName = "execButton";
    connect(MainWindow::findChild<QPushButton *>(execButtonName), SIGNAL(released()), this, SLOT(executeCode()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::executeCode() {
    ui->textConsole->setPlainText("ejecutando...");
    MiniOlc::ParserCtx analizador;
    analizador.Analizar(ui->textInput->toPlainText().toStdString());
    ui->textConsole->setPlainText(QString::fromStdString(analizador.Salida));
}

void  MainWindow::displayErrors() {

}
void MainWindow::generateSymbolsReport() {

}
void MainWindow::generateAST() {

}

void MainWindow::on_actionAbrir_triggered(){
    QString fileName = QFileDialog::getOpenFileName(this, "open a file", "/home");
    if (fileName.isEmpty()) {
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    this->currentFilePath = fileName.toStdString();
    QTextStream in(&file);
    QString fileContent = in.readAll();
    file.close();
    ui->textInput->clear();
    ui->textInput->setPlainText(fileContent);
}


void MainWindow::on_actionGuardar_triggered() {
    if (this->currentFilePath.empty()) {
        return this->on_actionGuardar_como_triggered();
    }
    QString filePath = QString::fromStdString(this->currentFilePath);
    QFile file(filePath);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    if (!file.isOpen()) {
        QMessageBox::information(this, "Error", "No se pudo guardad el archivo.");
        return;
    }
    QTextStream out(&file);
    out << ui->textInput->toPlainText();
    file.flush();
    file.close();
}


void MainWindow::on_actionGuardar_como_triggered() {
    QString file = QFileDialog::getSaveFileName(this, "Guardar Archivo");
    if (!file.isEmpty()) {
        this->currentFilePath = file.toStdString();
        return this->on_actionGuardar_triggered();
    }
}

