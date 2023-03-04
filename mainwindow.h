#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::string currentFilePath;

private slots:
    void executeCode();
    void displayErrors();
    void generateSymbolsReport();
    void generateAST();
    void on_actionAbrir_triggered();
    void on_actionGuardar_triggered();
    void on_actionGuardar_como_triggered();
};
#endif // MAINWINDOW_H
