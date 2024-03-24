#include "centralwidget.h"
#include "menu.h"


CentralWidget::CentralWidget() {
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumSize(300, 200);
	setMaximumSize(600, 400);
	// создание layoutsb
	QVBoxLayout* Vlayout = new QVBoxLayout;



	// создание обьектов
	QLabel* main_label = new QLabel("Интструмент выбора");
	QPixmap image(":/dots.png");
	main_label->setPixmap(image);
	main_label->setFixedSize(250,50);

	QString menuSheet = "QComboBox { border-radius: 2px; padding: 2px;background: transparent;}"
		"QComboBox{border:none;background-color:rgb(112, 128, 144);color:rgb(255, 255, 255);font-weight:bold;padding:15px}"
		"QComboBox::drop-down{border:none;background-color:rgb(112, 128, 144);color:rgb(255, 255, 255);font-weight:bold;padding:0px;border-top-right-radius: 10px; border-bottom-right-radius: 10px;}"
		"QComboBox QAbstractItemView::item {color: rgb(255, 255, 255);font - weight: bold;padding: 5px;background-color:rgb(36, 36, 36);}";


	Menu* classTime_menu = new Menu(1);
	classTime_menu->setStyleSheet(menuSheet);


	Menu* area_menu = new Menu(2);
	area_menu->setStyleSheet(menuSheet);

	Menu* day_menu = new Menu(3);

	day_menu->setStyleSheet(menuSheet);

	//new
	QHBoxLayout* layoutSLid = new QHBoxLayout;
	QLabel* explanation = new QLabel("близость конца семестра");
	QSlider* sl = new QSlider(Qt::Horizontal);
	sl->setFixedSize(100, 30);
	layoutSLid->addSpacing(20);
	layoutSLid->addWidget(sl);
	layoutSLid->addSpacing(20); 
	layoutSLid->addWidget(explanation);
	

	QPushButton* search_btn = new QPushButton("найти");
	search_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	search_btn->setMinimumSize(200, 50);
	search_btn->setMaximumSize(500, 50);
	search_btn->setStyleSheet("QPushButton {background-color:rgb(199, 199, 199);color: black; border: 2px solid rgb(199, 199, 199); border-radius: 5px; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 400;}"
		"QPushButton:hover {background-color:rgb(144, 238, 144);border: 1px solid rgb(144, 238, 144); outline: 0;}");

	
	// добавление в layout
	Vlayout->addSpacing(45);
	Vlayout->addWidget(classTime_menu);
	Vlayout->addSpacing(35);
	Vlayout->addWidget(area_menu);
	Vlayout->addSpacing(35);
	Vlayout->addWidget(day_menu);
	Vlayout->addSpacing(45);
	Vlayout->addWidget(search_btn);
	Vlayout->addSpacing(45);
	Vlayout->setAlignment(Qt::AlignHCenter);

	



	setLayout(Vlayout);
}	


CentralWidget::~CentralWidget() {


}

void CentralWidget::paintEvent(QPaintEvent* event) {
	QColor color1(26, 26, 26);

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
