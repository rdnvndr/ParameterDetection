#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QAction>
#include <QPlainTextEdit>
#include <QLineEdit>

#include "element.h"
#include "thread.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->exitAction, &QAction::triggered, this, &MainWindow::close);
    connect(ui->runAction,  &QAction::triggered, this, &MainWindow::onExec);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onExec()
{
    ui->logPlainText->clear();

    QString designation =  ui->designLineEdit->text();
    if (designation.isEmpty()) {
        ui->logPlainText->appendPlainText("Необходимо ввести обозначение размера.");
        return;
    }

    Thread thread;
    QString result = thread.anyThread(designation);
    if (!result.isEmpty()) {
        ui->logPlainText->appendPlainText(result);
        return;
    }

    Element element;
    result = element.anyDimension(designation);
    if (!result.isEmpty()) {
        ui->logPlainText->appendPlainText(result);
        return;
    }

    ui->logPlainText->appendPlainText("Не удалось распознать размер.");
    return;
}

