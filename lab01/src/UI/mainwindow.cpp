#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->_console = new Console(ui->graphConsole);
    this->_initGraphs();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::_initGraphs()
{
    this->_lgr = new LGraph<Network, int>();
    this->_mgr = new MGraph<Network, int>();

    this->_currGraph = dynamic_cast<Graph<Network, int>*>(this->_lgr);
    this->_curr_IA_T = IA_t::IPv4;
}


void MainWindow::on_createNewGraphButton_clicked()
{
    switch (this->_curr_IA_T) {
        case IA_t::IPv4:
            this->_lgr = new LGraph<Network, int>();
            break;

        case IA_t::IPv6:
            this->_mgr = new MGraph<Network, int>();
            break;
    }

    this->_console->newPar();
    this->_console->printTech(this->_currGraph->typeStr() + ": ");
    this->_console->newLine();
    this->_console->print("Created new graph!");
}
