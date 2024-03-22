#include "mainwindow.h"
#include "centralwidget.h"
#include "toolbar.h"
#include "toolbarButton.h"


MainWindow::MainWindow(QWidget* parent) 
	:	QMainWindow(parent),
		m_tbar(0)
{
	// создание шаблонов
	QHBoxLayout* main_layout = new QHBoxLayout;

	// создание объектов
	QWidget* cw1 = new QWidget;
	CentralWidget* searchWidget = new CentralWidget;

	m_tbar = new ToolBar(this, this);

	// добавление в layout
	main_layout->addWidget(searchWidget);
	cw1->setLayout(main_layout);

	setWindowFlags(Qt::CustomizeWindowHint);
	setCentralWidget(cw1);
	addToolBar(m_tbar);

	this->setStyleSheet("QMainWindow{background-color:rgb(32, 32, 32);}"
		"QMainWindow::title{background-color:rgb(59, 59, 59);}");

	
}


void MainWindow::onFullScreenButtonClicked() 
{

	

	if (!isFullscreeen) 
	{

		m_tbar->btn_fullscreen->setIcon(QIcon(":/fullscrBtn.png"));

		isFullscreeen = true;
		width = MainWindow::geometry().width();
		height = MainWindow::geometry().height();
		x = MainWindow::geometry().x();
		y = MainWindow::geometry().y();
		MainWindow::showMaximized();
	}

	else 
	{


		m_tbar->btn_fullscreen->setIcon(QIcon(":/fullscrBtn2.png"));

		isFullscreeen = false;
		this->setGeometry(x,y, width, height);
	}
	
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

