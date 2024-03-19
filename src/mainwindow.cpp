#include "mainwindow.h"
#include "centralwidget.h"
#include "toolbar.h"


MainWindow::MainWindow(QWidget* parent) {
	// создание шаблонов
	QHBoxLayout* main_layout = new QHBoxLayout;

	// создание объектов
	QWidget* cw1 = new QWidget;
	CentralWidget* centralWidget = new CentralWidget;
	ToolBar* toolBar = new ToolBar(this);

	// добавление в layout
	main_layout->addWidget(centralWidget);
	cw1->setLayout(main_layout);

	setWindowFlags(Qt::CustomizeWindowHint);
	setCentralWidget(cw1);
	addToolBar(toolBar);
	this->setStyleSheet("QMainWindow{background-color:rgb(32, 32, 32);}"
		"QMainWindow::title{background-color:rgb(59, 59, 59);}");

	
}


void MainWindow::onFullScreenButtonClicked() {
	this->showFullScreen();
}

void MainWindow::mousePressEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		m_dragStartPosition = event->globalPos() - frameGeometry().topLeft();
	}
}

void MainWindow::mouseMoveEvent(QMouseEvent* event) {
	if (event->buttons() & Qt::LeftButton) {
		move(event->globalPos() - m_dragStartPosition);
		event->accept();
	}
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event) {
	m_dragStartPosition = QPoint();
	event->accept();
}

MainWindow::~MainWindow() {


}

