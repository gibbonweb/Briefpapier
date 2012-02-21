#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QCoreApplication::setOrganizationName("gibbonweb");
    QCoreApplication::setOrganizationDomain("gibbonweb.net");
    QCoreApplication::setApplicationName("Briefpapier");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generate_clicked()
{
    QFile letter(ui->lineLetter->text());
    QString letterTmp(ui->lineLetter->text());
    letterTmp.append("_tmp.pdf");
    letter.copy(letterTmp);
    QFileInfo letterInfo(letter);
    QDir letterDir(letterInfo.absoluteDir());

    QString cmd = QString("/usr/local/bin/pdftk \"%1\" background \"%2\" output \"%3\"")
            .arg(letterTmp)
            .arg(ui->lineStationery->text())
            .arg(letterInfo.absoluteFilePath());
    qDebug() << cmd;
    if(!system(cmd.toStdString().c_str())) {
        qDebug() << "done!";
        QString openDir = QString("open \"%1\"").arg(letterDir.absolutePath());
        system(openDir.toStdString().c_str());
        QFile tmpFile(letterTmp);
        tmpFile.remove();
    } else {
        qDebug() << "an error occurred";
    }
}

void MainWindow::on_toolLetter_clicked()
{
    QSettings settings;
    QString letterPath = settings.value("letterPath",QDir::homePath()).toString();
    ui->lineLetter->setText(
                QFileDialog::getOpenFileName(this,tr("Brief öffnen"),
                                             letterPath,
                                             tr("PDF Dateien (*.pdf)")));
    if(!(ui->lineLetter->text().isEmpty()))
        settings.setValue("letterPath",ui->lineLetter->text());
}

void MainWindow::on_toolStationery_clicked()
{
    QSettings settings;
    QString stationeryPath = settings.value("stationeryPath",QDir::homePath()).toString();
    ui->lineStationery->setText(
                QFileDialog::getOpenFileName(this,tr("Briefpapier öffnen"),
                                             stationeryPath,
                                             tr("PDF Dateien (*.pdf)")));
    if(!(ui->lineStationery->text().isEmpty()))
        settings.setValue("stationeryPath",ui->lineStationery->text());
}
