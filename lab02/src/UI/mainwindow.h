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

    void showEvent(QShowEvent *ev);
    void resizeEvent(QResizeEvent* event);

private:
    Ui::MainWindow *ui;


    void _stretchTabs();
    void _setRelativeTabsHeight(float percent);
};
#endif // MAINWINDOW_H