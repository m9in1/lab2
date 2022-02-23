#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <les.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void searchLes();

private:
    Ui::MainWindow *ui;

    std::vector<les> lessons;
};
#endif // MAINWINDOW_H
