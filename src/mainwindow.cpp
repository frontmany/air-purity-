#include "mainwindow.h"
#include "centralwidget.h"
#include "toolbar.h"
#include "calculator.h"
#include "resultSearchWidget.h"
#include "favourite.h"
#include "buttonswidget.h"
#include "rate1.h"
#include "gym.h"


void MainWindow::handleButtonClicked(int index){
	ressWidget2 = new ResultSearchWidget(storage_list[index], storage_list2[index], this);

}



void MainWindow::onAreaMenuChanged(int index) {
	switch (index) {
	case 1:
		building = "Школа Компьютерных Наук";
		break;
	case 2:
		building = "Школа Образования";
		break;
	case 3:
		building = "Олимпия: Гимнастический Зал";
		break;
	case 4:
		building = "Олимпия: Тренажерный Зал";
		break;
	case 5:
		building = "Олимпия: Зал Групповых Программ";
		break;
	}
	ressWidget_toUpdate = new ResultSearchWidget(this, this);
	replaceWidget(ressWidget, ressWidget_toUpdate, main_Hlayout);
	ressWidget = ressWidget_toUpdate;
}



void MainWindow::replaceWidget(QWidget* oldWidget, QWidget* newWidget, QLayout* layout) {
	layout->removeWidget(oldWidget);
	layout->addWidget(newWidget);
	
	oldWidget->hide();
	newWidget->show();
	
	delete oldWidget;

}

void MainWindow::onClassTimeMenuChanged(int index) {
	body_count = index + 1;
	ressWidget_toUpdate = new ResultSearchWidget(this, this);
	replaceWidget(ressWidget,ressWidget_toUpdate, main_Hlayout);


	ressWidget = ressWidget_toUpdate;
}


void MainWindow::onMonthMenuChanged(int index) {
	switch (index) {
	case 1:
		month = "Сентябрь";
		break;
	case 2:
		month = "Октябрь";
		break;
	case 3:
		month = "Ноябрь";
		break;
	case 4:
		month = "Декабрь";
		break;
	case 5:
		month = "Январь";
		break;
	case 6:
		month = "Февраль";
		break;
	case 7:
		month = "Март";
		break;
	case 8:
		month = "Апрель";
		break;
	case 9:
		month = "Май";
		break;
	case 10:
		month = "Июнь";
		break;
	}

	ressWidget_toUpdate = new ResultSearchWidget(this, this);
	replaceWidget(ressWidget, ressWidget_toUpdate, main_Hlayout);
	ressWidget = ressWidget_toUpdate;
}


MainWindow::MainWindow(QWidget* parent) 
	:	QMainWindow(parent)
{
	m_tbar = new ToolBar(this, this);

	for (int i = 0; i < 17; i++) {
		calculator_data.push_back("");
	}

	for (int i = 0; i < 10; i++) {
		calculator_data2.push_back("");
	}

	Gym gym1;
	gym1.name = "Школа Компьютерных наук";
	gym1.V = 3000;
	double A1 = 1 + ((500 * 3) / (500 * 6 * 1.82));
	gym1.Co2 = 350 + (31 * 350 * 90 / (gym1.V * A1));
	
	
	Gym gym2;
	gym2.name = "Школа Образования";
	gym2.V = 2500;

	double A2 = 1 + (416 * 3) / ((416 * 6) * 1.82);
	gym2.Co2 = 350 + (31 * 350 * 90 / (gym2.V * A2));


	Gym gym3;
	gym3.name = "Олимпия: Гимнастический Зал";
	gym3.V = 3200;

	double A3 = 1 + (400 * 3) / ((400 * 8) * 1.82);
	gym3.Co2 = 350 + (31 * 350 * 90 / (gym3.V * A3));

	Gym gym4;
	gym4.name = "Олимпия: Тренажерный Зал";
	gym4.Co2 = 833;
	gym4.V = 1500;

	double A4 = 1 + (375 * 3) / ((375 * 4) * 1.82);
	gym4.Co2 = 350 + (31 * 350 * 90 / (gym4.V * A4));


	Gym gym5;
	gym5.name = "Олимпия: Зал Групповых Программ";
	gym5.Co2 = 871;
	gym5.V = 1200;

	double A5 = 1 + (333 * 3) / ((333 * 3) * 1.82);
	gym5.Co2 = 350 + (31 * 350 * 90 / (gym5.V * A5));


	storage_list3_values.push_back(gym5);
	storage_list3_values.push_back(gym4);
	storage_list3_values.push_back(gym3);
	storage_list3_values.push_back(gym2);
	storage_list3_values.push_back(gym1);

	storage_list3_forRecovery = storage_list3_values;

	addToolBar(m_tbar);
	setSearchWidget();
	this->setStyleSheet("QMainWindow{background-color:rgb(34, 34, 34);}"
		"QMainWindow::title{background-color:rgb(59, 59, 59);}");

	
}


void MainWindow::setRateWidget() {
	m_tbar->rate_btn->setStyleSheet(trigBtnSheet);
	m_tbar->btn_search->setStyleSheet(toolbarBtnSheet);
	m_tbar->favourites_btn->setStyleSheet(toolbarBtnSheet);

	rate_widget = new RatingWidget(this, this);




	QWidget* mainWidget = new QWidget;
	QVBoxLayout* mainVlayout = new QVBoxLayout;
	mainVlayout->addWidget(rate_widget);
	mainVlayout->setAlignment(Qt::AlignCenter);
	mainWidget->setLayout(mainVlayout);
	setCentralWidget(mainWidget);

}


void MainWindow::setSearchWidget() {
	m_tbar->btn_search->setStyleSheet(trigBtnSheet);
	m_tbar->favourites_btn->setStyleSheet(toolbarBtnSheet);
	m_tbar->rate_btn->setStyleSheet(toolbarBtnSheet);

	main_Hlayout = new QHBoxLayout;
	main_Hlayout->setAlignment(Qt::AlignLeft);

	QVBoxLayout* main_Vlayout = new QVBoxLayout;
	main_Vlayout->setAlignment(Qt::AlignCenter);



	QWidget* cw1 = new QWidget;
	CentralWidget* searchWidget = new CentralWidget(this, this);
	
	ressWidget = new ResultSearchWidget(this, this);


	main_Vlayout->addWidget(searchWidget);
	main_Hlayout->addLayout(main_Vlayout);
	main_Hlayout->addWidget(ressWidget);
	cw1->setLayout(main_Hlayout);
	setCentralWidget(cw1);
}


//fav
void MainWindow::setFavWidget() {
	m_tbar->favourites_btn->setStyleSheet(trigBtnSheet);
	m_tbar->btn_search->setStyleSheet(toolbarBtnSheet);
	m_tbar->rate_btn->setStyleSheet(toolbarBtnSheet);
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
			break;
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

