#include "mainwindow.h"
#include "centralwidget.h"
#include "toolbar.h";


MainWindow::MainWindow(){
	// �������� ��������
	QHBoxLayout* main_layout = new QHBoxLayout;


	// �������� ��������
	QWidget* cw1 = new QWidget;
	CentralWidget* centralWidget = new CentralWidget;
	ToolBar* toolBar = new ToolBar;

	// ���������� � layout
	main_layout->addWidget(centralWidget);


	cw1->setLayout(main_layout);
	setCentralWidget(cw1);

	addToolBar(toolBar);
	
	this->setStyleSheet("QMainWindow{background-color:rgb(59, 59, 59);}");


}

void MainWindow::paintEvent(QPainter* event) {
}

MainWindow::~MainWindow() {


}
