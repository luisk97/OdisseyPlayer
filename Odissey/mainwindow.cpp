#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "videohandler.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    videoW = new QVideoWidget(this);

    player->setVideoOutput(videoW);
    ui->gridLayout_2->addWidget(videoW);

    slider = new QSlider(this);
    pBar = new QProgressBar(this);

    slider->setOrientation(Qt::Horizontal);

    ui->statusBar->addPermanentWidget(slider);
    ui->statusBar->addPermanentWidget(pBar);

    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

    connect(player,&QMediaPlayer::durationChanged,pBar,&QProgressBar::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,pBar,&QProgressBar::setValue);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionPlay_triggered()
{
    player->play();
    ui->statusBar->showMessage("Reproduciendo");
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open a File","","Video File (*.*)");
    on_actionStop_triggered();
    std::string stringfile = fileName.toStdString();
    std::string videoName = VideoHandler::sendVideo(stringfile);
    if (videoName != "fail")
    {
        QMessageBox::information(this,tr("Envio de video"),tr("Se envio el video al servidor con exito"));
        QString vName = QString::fromStdString(videoName);
        ui->listWidget->addItem(vName);
    }else{
        QMessageBox::information(this,tr("Envio de video"),tr("No se pudo enviar el video al servidor"));
    }

    player->setMedia(QUrl::fromLocalFile(fileName));

    on_actionPlay_triggered();
}

void MainWindow::on_actionStop_triggered()
{
    player->stop();
    ui->statusBar->showMessage("Detenido");
}

void MainWindow::on_actionPause_triggered()
{
    player->pause();
    ui->statusBar->showMessage("Pausado");
}

void MainWindow::on_pushButton_clicked()
{
    QString nameVideo;
    nameVideo = (ui->listWidget->currentItem()->text());
    std::string videoName = nameVideo.toStdString();
    std::string extension = VideoHandler::getVideo(videoName);
    QString ext = QString::fromStdString(extension);
    player->setMedia(QUrl::fromLocalFile("/home/luisk/build-Odissey-Desktop_Qt_5_9_5_GCC_64bit-Debug/receive."+ext));

    on_actionPlay_triggered();
}
