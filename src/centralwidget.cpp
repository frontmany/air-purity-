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
#include <QStringLiteral>
#include <QPixmap>

CentralWidget::CentralWidget() {
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumSize(300, 200);
	setMaximumSize(600, 400);
	// создание layouts
	QVBoxLayout* Vlayout = new QVBoxLayout;


	// создание обьектов
	QLabel* main_label = new QLabel("Интструмент выбора");
	QPixmap image(":/dots.png");
	main_label->setPixmap(image);
	main_label->setFixedSize(250,50);

	Menu* classTime_menu = new Menu(1);

	classTime_menu->setStyleSheet("QComboBox { border-radius: 2px; padding: 2px;background: transparent;}"
		"QComboBox{border:none;background-color:rgb(87, 96, 134);color:rgb(255, 255, 255);font-weight:bold;padding:15px}"
		"QComboBox::drop-down{border:none;background-color:rgb(87, 96, 134);color:rgb(255, 255, 255);font-weight:bold;padding:0px;border-top-right-radius: 10px; border-bottom-right-radius: 10px;}"
		"QComboBox QAbstractItemView::item {color: rgb(255, 255, 255);font - weight: bold;padding: 5px;background-color:rgb(36, 36, 36);}"
		);


	Menu* area_menu = new Menu(2);
	area_menu->setStyleSheet("QComboBox { border-radius: 2px; padding: 2px;background: transparent;}"
		"QComboBox{border:none;background-color:rgb(87, 96, 134);color:rgb(255, 255, 255);font-weight:bold;padding:15px}"
		"QComboBox::drop-down{border:none;background-color:rgb(87, 96, 134);color:rgb(255, 255, 255);font-weight:bold;padding:0px;border-top-right-radius: 10px; border-bottom-right-radius: 10px;}"
		"QComboBox QAbstractItemView::item {color: rgb(255, 255, 255);font - weight: bold;padding: 5px;background-color:rgb(36, 36, 36);}"
	);

	
	QPushButton* search_btn = new QPushButton("найти");
	search_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	search_btn->setMinimumSize(200, 50);
	search_btn->setMaximumSize(500, 50);
	search_btn->setStyleSheet("QPushButton {background-color:rgb(199, 199, 199);color: black; border: 2px solid rgb(199, 199, 199); border-radius: 5px; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 400;}"
		"QPushButton:hover {background-color:rgb(148, 235, 188);border: 1px solid rgb(148, 235, 188); outline: 0;}");

	
	// добавление в layout
	Vlayout->addWidget(main_label);
	Vlayout->addSpacing(15);
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
	QColor color1(33, 33, 33);

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
