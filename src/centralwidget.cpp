#include "centralwidget.h"
#include "menu.h"
#include "mainwindow.h"

void CentralWidget::comboBoxChanged(const QString&) {
	
}



CentralWidget::CentralWidget(QWidget* parent, MainWindow* mainwindow) : QWidget(parent){
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumSize(300, 200);
	setMaximumSize(600, 400);
	// создание layoutsb
	QVBoxLayout* Vlayout = new QVBoxLayout;



	// создание обьектов
	QString menuSheet = "QComboBox { border-radius: 2px; padding: 2px;background: transparent;}"
		"QComboBox{border:none;background-color:rgb(112, 128, 144);color:rgb(255, 255, 255);font-weight:bold;padding:15px}"
		"QComboBox::drop-down{border:none;background-color:rgb(112, 128, 144);color:rgb(255, 255, 255);font-weight:bold;padding:0px;border-top-right-radius: 10px; border-bottom-right-radius: 10px;}"
		"QComboBox QAbstractItemView::item {color: rgb(255, 255, 255);font - weight: bold;padding: 5px;background-color:rgb(36, 36, 36);}";


	Menu* classTime_menu = new Menu(this, 1);
	connect(classTime_menu, &QComboBox::currentIndexChanged, mainwindow, &MainWindow::onClassTimeMenuChanged);
	classTime_menu->setStyleSheet(menuSheet);

	Menu* area_menu = new Menu(this, 2);
	connect(area_menu, &QComboBox::currentIndexChanged, mainwindow, &MainWindow::onAreaMenuChanged);
	area_menu->setStyleSheet(menuSheet);



	

	QPushButton* search_btn = new QPushButton("Расчитать чистоту воздуха");
	search_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	search_btn->setMinimumSize(200, 50);
	search_btn->setMaximumSize(290, 50);
	search_btn->setStyleSheet("QPushButton {background-color:rgb(199, 199, 199);color: rgb(105, 105, 105); border: 2px solid rgb(199, 199, 199); border-radius: 5px; border-radius: 5px;padding: 10px 20px; font-size: 14px;font-weight: 400;}"
		"QPushButton:hover {background-color: #b3e1d4;border: 1px solid #b3e1d4; outline: 0;}");
	connect(search_btn, &QPushButton::clicked, mainwindow, &MainWindow::onSearchButtonClicked);

	
	// добавление в layout
	Vlayout->addSpacing(45);
	Vlayout->addWidget(classTime_menu);
	Vlayout->addSpacing(35);
	Vlayout->addWidget(area_menu);
	Vlayout->addSpacing(45);
	Vlayout->addWidget(search_btn);
	Vlayout->addSpacing(45);
	Vlayout->setAlignment(Qt::AlignHCenter);

	



	setLayout(Vlayout);
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

CentralWidget::~CentralWidget() {


}