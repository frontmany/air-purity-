#include "centralwidget.h"
#include "menu.h"
#include <QStyleOption>
#include <Qlabel>
#include <QVboxLayout>
#include <QHboxLayout>
#include <QPushbutton>
#include <QMenu>

CentralWidget::CentralWidget() {
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumSize(300, 200);
	setMaximumSize(600, 400);
	// создание layouts
	QVBoxLayout* Vlayout = new QVBoxLayout;


	// создание обьектов
	QLabel* main_label = new QLabel(" Selection tool");
	main_label->setFixedSize(100,50);

	Menu* classTime_menu = new Menu;
	classTime_menu->addAction("1");
	classTime_menu->addAction("2");
	classTime_menu->addAction("3");
	QPushButton* classTime_btn = new QPushButton("choose class time");
	classTime_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	classTime_btn->setMinimumSize(200, 50);
	classTime_btn->setMaximumSize(500, 50);
	classTime_btn->setMenu(classTime_menu);


	QMenu* area_menu = new QMenu;
	area_menu->addAction("1");
	area_menu->addAction("2");
	area_menu->addAction("3");
	QPushButton* area_btn = new QPushButton("choose your area of the city");
	area_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	area_btn->setMinimumSize(200, 50);
	area_btn->setMaximumSize(500, 50);
	area_btn->setMenu(classTime_menu);

	QPushButton* search_btn = new QPushButton("search");
	search_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	search_btn->setMinimumSize(200, 50);
	search_btn->setMaximumSize(500, 50);

	// добавление в layout
	Vlayout->addWidget(main_label);
	Vlayout->addSpacing(25);
	Vlayout->addWidget(classTime_btn);
	Vlayout->addWidget(area_btn);
	Vlayout->addSpacing(35);
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
