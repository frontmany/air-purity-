#include "mainwindow.h"
#include "centralwidget.h"

MainWindow::MainWindow() {
	QWidget* cw1 = new QWidget;

	// созданий шаблонов
	QHBoxLayout* main_layout = new QHBoxLayout;
	CentralWidget* centralWidget = new CentralWidget;
	main_layout->addWidget(centralWidget);
	cw1->setLayout(main_layout);
	setCentralWidget(cw1);



}

MainWindow::~MainWindow() {


}