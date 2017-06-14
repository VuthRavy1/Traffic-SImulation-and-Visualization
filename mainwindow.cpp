#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow),m_car(nullptr),simulate_state(false),m_road(nullptr)
{
        ui->setupUi(this);
        m_scene = new SimulationScene;
        m_scene->setSceneRect(0,0,800,600);
        ui->graphicsView->setScene(m_scene);
        //ui->graphicsView->Initializer();
        ui->stackedWidget->setCurrentIndex(0);
        m_timer = new QTimer;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    qDebug()<<event->size();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_play_clicked()
{
    if(!m_car){
        return;
    }
    m_timer->start(10);
    simulate_state = true;
}

void MainWindow::on_vehicles_clicked()
{
    if(!m_road){
        return;
    }
    m_car = new Vehicle();
    m_car->extract_coordinate(m_road);
    m_car->initialize();
    m_scene->addItem(m_car);
    m_car->setPos(m_car->initial_path());
    QObject::connect(m_timer,SIGNAL(timeout()),m_car,SLOT(advance()));
}

void MainWindow::on_road_clicked()
{
    m_road = new road(m_scene);
    m_scene->addItem(m_road);
    //m_road->setPos(m_road->mapToScene(m_scene->sceneRect().x(),m_scene->sceneRect().y()));
}

void MainWindow::on_trafficLight_clicked()
{

}

void MainWindow::on_matherials_clicked()
{

}

void MainWindow::on_terrains_clicked()
{

}

void MainWindow::on_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_open_simulation_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_exit_clicked()
{
    QApplication::quit();
}

void MainWindow::on_reset_clicked()
{
    m_scene->clear();
}

void MainWindow::on_pause_clicked()
{
    m_timer->stop();
    simulate_state = false;
}
