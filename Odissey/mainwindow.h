#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
#include <videos.h>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionPlay_triggered();

    void on_actionOpen_triggered();

    void on_actionStop_triggered();

    void on_actionPause_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QVideoWidget* videoW;
    QProgressBar* pBar;
    QSlider* slider;
    Videos* ventanaVideos;

};

#endif // MAINWINDOW_H
