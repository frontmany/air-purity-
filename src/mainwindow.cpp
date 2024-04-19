#include "mainwindow.h"
#include "centralwidget.h"
#include "toolbar.h"
#include "settingsWidget.h"
#include "calculator.h"
#include "resultSearchWidget.h"
#include "favourite.h"
#include "buttonswidget.h"

void MainWindow::handleButtonClicked(int index)
{
	ressWidget2 = new ResultSearchWidget(storage_list[index], this);

}

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
	:	QMainWindow(parent)
{
	m_tbar = new ToolBar(this, this);
	for (int i = 0; i < 17; i++) {
		calculator_data.push_back("");
	}

	addToolBar(m_tbar);
	setSearchWidget();
	this->setStyleSheet("QMainWindow{background-color:rgb(34, 34, 34);}"
		"QMainWindow::title{background-color:rgb(59, 59, 59);}");

	
}



void MainWindow::setSearchWidget() {
	m_tbar->btn_search->setStyleSheet(trigBtnSheet);
	m_tbar->favourites_btn->setStyleSheet(toolbarBtnSheet);

	QHBoxLayout* Hlayout = new QHBoxLayout;
	QVBoxLayout* main_layout = new QVBoxLayout;
	main_layout->setAlignment(Qt::AlignCenter);

	QWidget* cw1 = new QWidget;

	CentralWidget* searchWidget = new CentralWidget(this, this);
	
	

	main_layout->addSpacing(10);
	main_layout->addWidget(searchWidget);
	cw1->setLayout(main_layout);
	setCentralWidget(cw1);
}


//fav
void MainWindow::setFavWidget() {
	m_tbar->favourites_btn->setStyleSheet(trigBtnSheet);
	m_tbar->btn_search->setStyleSheet(toolbarBtnSheet);
	m_tbar->setHidden(false);
	searchW = this->takeCentralWidget();
	
	fav_widget = new FavouriteListWidget(this, this);

	fav_widget->showFavWidgets();

	

	QWidget* mainWidget = new QWidget;
	QVBoxLayout* mainVlayout = new QVBoxLayout;
	mainVlayout->addWidget(fav_widget);
	mainVlayout->setAlignment(Qt::AlignCenter);
	mainWidget->setLayout(mainVlayout);
	setCentralWidget(mainWidget);

}


void MainWindow::onFavBtnClicked() {

	
	searchW = this->takeCentralWidget();
	m_tbar->setHidden(true);

	for (int i = 0; i < fav_wid_count; i++) {
		if ((storage_list[i])[0] == ressWidget2->month && (storage_list[i])[1] == ressWidget2->building && ((storage_list[i])[5]).toInt() == ressWidget2->body_count) {
			ressWidget2->ButtonWidget->fl = true;
			QIcon img(":/save_active.png");
			ressWidget2->ButtonWidget->saveButton->setIcon(img);
		}
	}

	QWidget* mainWidget = new QWidget;

	QVBoxLayout* mainVlayout = new QVBoxLayout;
	mainVlayout->setAlignment(Qt::AlignCenter);
	fav_widget->showFavWidgets();
	mainVlayout->addWidget(ressWidget2);
	mainWidget->setLayout(mainVlayout);
	setCentralWidget(mainWidget);
}


void MainWindow::searchWback() {
	setCentralWidget(searchW);
	m_tbar->setHidden(false);

}



void MainWindow::onSearchButtonClicked() {

	searchW = this->takeCentralWidget();
	m_tbar->setHidden(true);
	QWidget* mainWidget = new QWidget;

	QVBoxLayout* mainVlayout = new QVBoxLayout;
	mainVlayout->setAlignment(Qt::AlignCenter);

	ressWidget = new ResultSearchWidget(this, this);
	for (int i = 0; i < fav_wid_count; i++) {
		if ((storage_list[i])[0] == ressWidget->month && (storage_list[i])[1] == ressWidget->building && ((storage_list[i])[5]).toInt() == ressWidget->body_count) {
			ressWidget->ButtonWidget->fl = true;
			QIcon img(":/save_active.png");
			ressWidget->ButtonWidget->saveButton->setIcon(img);
		}
	}


	mainVlayout->addWidget(ressWidget);
	mainWidget->setLayout(mainVlayout);

	
	setCentralWidget(mainWidget);
}





MainWindow::~MainWindow() {


}

