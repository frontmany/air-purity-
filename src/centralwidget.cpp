#include "centralwidget.h"
#include "menu.h"
#include <QStyleOption>
#include <Qlabel>
#include <QVboxLayout>
#include <QHboxLayout>
#include <QPushbutton>
#include <QMenu>
#include <QScrollArea>
#include <QStyledItemDelegate>

CentralWidget::CentralWidget() {
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumSize(300, 200);
	setMaximumSize(600, 400);
	// создание layouts
	QVBoxLayout* Vlayout = new QVBoxLayout;


	// создание обьектов


	QLabel* main_label = new QLabel(" Selection tool");
	main_label->setFixedSize(100,50);


	Menu* classTime_menu = new Menu(1);

	classTime_menu->setStyleSheet("QComboBox { border-radius: 2px; padding: 2px;background: transparent;}"
		"QComboBox{border:none;background-color:rgb(87, 96, 134);color:rgb(255, 255, 255);font-weight:bold;padding:5px}"
		"QComboBox::drop-down{border:none;background-color:rgb(87, 96, 134);color:rgb(255, 255, 255);font-weight:bold;padding:0px;border-top-right-radius: 10px; border-bottom-right-radius: 10px;}"
		"QComboBox QAbstractItemView::item {color: rgb(87, 96, 134);font - weight: bold;padding: 5px;}"
		);


	Menu* area_menu = new Menu(2);
	area_menu->setStyleSheet("QComboBox { border-radius: 2px; padding: 2px;background: transparent;}"
		"QComboBox{border:none;background-color:rgb(87, 96, 134);color:rgb(255, 255, 255);font-weight:bold;padding:5px}"
		"QComboBox::drop-down{border:none;background-color:rgb(87, 96, 134);color:rgb(255, 255, 255);font-weight:bold;padding:0px;border-top-right-radius: 10px; border-bottom-right-radius: 10px;}"
		"QComboBox QAbstractItemView::item {color: rgb(87, 96, 134);font - weight: bold;padding: 5px;}"
	);


	QPushButton* search_btn = new QPushButton("search");
	search_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	search_btn->setMinimumSize(200, 50);
	search_btn->setMaximumSize(500, 50);
	search_btn->setStyleSheet("QPushButton {background-color: white;color: black;border: 1px solid white;border-radius: 2px;padding: 10px 20px;}"
		"QPushButton:hover {background-color:rgb(237, 64, 84);border: 1px solid rgb(237, 64, 84); outline: 0;}");

	
	// добавление в layout
	Vlayout->addWidget(main_label);
	Vlayout->addSpacing(25);
	Vlayout->addWidget(classTime_menu);
	Vlayout->addSpacing(25);
	Vlayout->addWidget(area_menu);
	Vlayout->addSpacing(45);
	Vlayout->addWidget(search_btn);
	Vlayout->addSpacing(45);
	Vlayout->setAlignment(Qt::AlignHCenter);

	



	setLayout(Vlayout);
}	


CentralWidget::~CentralWidget() {


}

void CentralWidget::paintEvent(QPaintEvent* event) {
	QStyleOption opt;
	opt.initFrom(this);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.drawRoundedRect(opt.rect, 25, 25);


	

}
