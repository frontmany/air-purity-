#include "mainwindow.h"
#include "centralwidget.h"
#include "QResource"

MainWindow::MainWindow() {
	// �������� ��������
	QHBoxLayout* main_layout = new QHBoxLayout;


	// �������� ��������
	QWidget* cw1 = new QWidget;
	CentralWidget* centralWidget = new CentralWidget;


	// ���������� � layout
	main_layout->addWidget(centralWidget);


	cw1->setLayout(main_layout);
	setCentralWidget(cw1);



}

MainWindow::~MainWindow() {


}