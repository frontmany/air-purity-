#include "mainwindow.h"
#include "centralwidget.h"
#include "toolbar.h"
#include "toolbarButton.h"
#include "settingsWidget.h"
#include "calculator.h"
#include "resultSearchWidget.h"

void MainWindow::isAutumn(bool fl) {
	season = "autumn";
}

void MainWindow::isSpring(bool fl) {
	season = "spring";
}

void MainWindow::onSliderChanged(int index) {
	slider_data = index;
}

void MainWindow::onAreaMenuChanged(int index) {
	switch (index) {
	case 0:
		building = "Школа Компьютерных Наук";
		break;
	case 1:
		building = "Школа Образования";
		break;
	case 2:
		building = "Олимпия: Гимнастический Зал";
		break;
	case 3:
		building = "Олимпия: Тренажерный Зал";
		break;
	case 4:
		building = "Олимпия: Зал Стрэтчинга";
		break;
	}

}

void MainWindow::onClassTimeMenuChanged(int index) {
	body_count = index + 1;
}

MainWindow::MainWindow(QWidget* parent) 
	:	QMainWindow(parent),
		m_tbar(0)
{
	m_tbar = new ToolBar(this, this);
	setWindowFlags(Qt::CustomizeWindowHint);

	addToolBar(m_tbar);
	setSearchWidget();
	this->setStyleSheet("QMainWindow{background-color:rgb(32, 32, 32);}"
		"QMainWindow::title{background-color:rgb(59, 59, 59);}");

	
}


void MainWindow::setSearchWidget() {
	m_tbar->btn_search->setStyleSheet(trigBtnSheet);
	QHBoxLayout* main_layout = new QHBoxLayout;
	QWidget* cw1 = new QWidget;

	CentralWidget* searchWidget = new CentralWidget(this, this);
	
	
	SettingsWidget* settingsWidget = new SettingsWidget(this, this);



	main_layout->addWidget(searchWidget);
	main_layout->addSpacing(10);
	main_layout->addWidget(settingsWidget);
	cw1->setLayout(main_layout);
	setCentralWidget(cw1);
}

void MainWindow::searchWback() {
	setCentralWidget(searchW);
}


void MainWindow::onSearchButtonClicked() {
	
	
	searchW = this->takeCentralWidget();
	ResultSearchWidget* ressWidget = new ResultSearchWidget(this, this);
	setCentralWidget(ressWidget);
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

