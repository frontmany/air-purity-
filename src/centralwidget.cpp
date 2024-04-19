#include "centralwidget.h"
#include "menu.h"
#include "mainwindow.h"
#include "settingswidget.h"

void CentralWidget::comboBoxChanged(const QString&) {
	
}



CentralWidget::CentralWidget(QWidget* parent, MainWindow* mainwindow) : QWidget(parent){
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumSize(350, 300);
	setMaximumSize(1920, 1080);
	// создание layoutsb
	QVBoxLayout* Vlayout = new QVBoxLayout;
	QHBoxLayout* Hlayout = new QHBoxLayout;


	// создание обьектов

	SettingsWidget* settingsWidget = new SettingsWidget(this, mainwindow);


	QString menuSheet = "QComboBox { border-radius: 5px; padding: 2px;background: transparent;font-family: Arial; font-weight: bold;  font-size: 13px; padding: 5px;}"
		"QComboBox{border:none;background-color:rgb(66, 66, 66);color:rgb(255, 255, 255);font-weight:bold;padding:15px}"
		"QComboBox::drop-down{border:none;background-color:rgb(66, 66, 66);color:rgb(255, 255, 255);font-weight:bold;padding:0px;border-top-right-radius: 10px; border-bottom-right-radius: 10px;}"
		"QComboBox QAbstractItemView::item {color: rgb(255, 255, 255);font - weight: bold;padding: 5px;background-color:rgb(36, 36, 36);}";


	Menu* classTime_menu = new Menu(this, 1);
	classTime_menu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	classTime_menu->setMinimumSize(350, 60);
	classTime_menu->setMaximumSize(1200, 90);
	connect(classTime_menu, &QComboBox::currentIndexChanged, mainwindow, &MainWindow::onClassTimeMenuChanged);
	classTime_menu->setStyleSheet(menuSheet);

	Menu* area_menu = new Menu(this, 2);
	area_menu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	area_menu->setMinimumSize(350, 60);
	area_menu->setMaximumSize(1200, 90);
	connect(area_menu, &QComboBox::currentIndexChanged, mainwindow, &MainWindow::onAreaMenuChanged);
	area_menu->setStyleSheet(menuSheet);





	QPushButton* search_btn = new QPushButton("Расчитать запыленность воздуха");
	search_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	search_btn->setMinimumSize(350, 80);
	search_btn->setMaximumSize(1200, 110);
	search_btn->setStyleSheet("QPushButton {background-color:rgb(63, 90, 111); font-family: Arial; font-weight: bold;  font-size: 13px; padding: 5px; color: rgb(248, 249, 249); border-radius: 5px;}"
		"QPushButton:hover {background-color: rgb(94, 127, 152);border: 4px solid rgb(94, 127, 152); outline: 0;}");
	connect(search_btn, &QPushButton::clicked, mainwindow, &MainWindow::onSearchButtonClicked);

	QVBoxLayout* Hla1 = new QVBoxLayout;
	Hla1->addWidget(classTime_menu);
	Hla1->addSpacing(25);
	Hla1->addWidget(area_menu);
	Hla1->addSpacing(65);
	Hla1->addWidget(search_btn);
	Hla1->addSpacing(55);
	Hla1->setAlignment(Qt::AlignCenter);
	// добавление в layout
	Vlayout->addWidget(settingsWidget);
	Vlayout->addSpacing(35);
	Vlayout->addLayout(Hla1);
	Hlayout->addLayout(Vlayout);
	Hlayout->setAlignment(Qt::AlignCenter);
	



	setLayout(Hlayout);
}	




void CentralWidget::paintEvent(QPaintEvent* event) {
	QColor color1(34, 34, 34);

	QStyleOption opt;
	opt.initFrom(this);

	QPainter painter(this);
	QPen pen(color1);
	pen.setWidth(2); 
	painter.setPen(pen);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setBrush(color1);

	painter.drawRoundedRect(opt.rect, 15, 15);


	

}

CentralWidget::~CentralWidget() {


}