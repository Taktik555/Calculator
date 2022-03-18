#include "mainwindow.h"
#include "ui_mainwindow.h"

double numFirst;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->But0,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->But1,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->But2,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->But3,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->But4,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->But5,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->But6,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->But7,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->But8,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->But9,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->ButPlus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->ButMinus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->ButDiv,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->ButX,SIGNAL(clicked()),this,SLOT(operations()));

    ui->ButPlus->setCheckable(true);
    ui->ButMinus->setCheckable(true);
    ui->ButDiv->setCheckable(true);
    ui->ButX->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_numbers(){
    QPushButton *button = (QPushButton *) sender();

    QString new_label;
    double allNumbers;
    allNumbers = (ui->Result->text() + button->text()).toDouble();
    new_label = QString::number(allNumbers, 'g', 15);

    ui->Result->setText(new_label);
}

void MainWindow::operations(){
    QPushButton *button = (QPushButton *) sender();
    numFirst = ui->Result->text().toDouble();
    ui->Result->setText("");
    button->setChecked(true);
}

void MainWindow::on_ButRes_clicked()
{
    double label_number;
    double num_second;
    QString new_label;

    num_second = ui->Result->text().toDouble();

    if(ui->ButPlus->isChecked()){
        label_number = numFirst + num_second;
        new_label = QString::number(label_number, 'g', 15);

        ui->Result->setText(new_label);
        ui->ButPlus->setChecked(false);
    }
    else if(ui->ButMinus->isChecked()){
        label_number = numFirst - num_second;
        new_label = QString::number(label_number, 'g', 15);

        ui->Result->setText(new_label);
        ui->ButMinus->setChecked(false);
    }
    else if(ui->ButDiv->isChecked()){
        if(num_second == 0){
            ui->Result->setText("Делить на 0 нельзя!");
        }else{
            label_number = numFirst / num_second;
            new_label = QString::number(label_number, 'g', 15);

            ui->Result->setText(new_label);
        }
        ui->ButDiv->setChecked(false);
    }
    else if(ui->ButX->isChecked()){
        label_number = numFirst * num_second;
        new_label = QString::number(label_number, 'g', 15);

        ui->Result->setText(new_label);
        ui->ButX->setChecked(false);
    }
}


void MainWindow::on_ButDel_clicked()
{
    ui->ButPlus->setChecked(false);
    ui->ButMinus->setChecked(false);
    ui->ButDiv->setChecked(false);
    ui->ButX->setChecked(false);
    ui->Result->setText("0");
}

