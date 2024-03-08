#include "mainwindow.h"
#include "centralwidget.h"
#include "QResource"

MainWindow::MainWindow() {
	// создание шаблонов
	QHBoxLayout* main_layout = new QHBoxLayout;


	// создание объектов
	QWidget* cw1 = new QWidget;
	CentralWidget* centralWidget = new CentralWidget;


	// добавление в layout
	main_layout->addWidget(centralWidget);


	cw1->setLayout(main_layout);
	setCentralWidget(cw1);



}

MainWindow::~MainWindow() {


}