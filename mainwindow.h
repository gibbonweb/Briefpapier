#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_generate_clicked();

    void on_toolLetter_clicked();

    void on_toolStationery_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
