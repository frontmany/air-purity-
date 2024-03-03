#include "mainwindow.h"
#include "centralwidget.h"

MainWindow::MainWindow() {
	
	CentralWidget* cw = new CentralWidget;
	// созданий шаблонов
	QHBoxLayout* main_layout = new QHBoxLayout;
	QVBoxLayout* second_layout = new QVBoxLayout;

	QHBoxLayout* tmp1_layout = new QHBoxLayout;

	//создание объектов
	QMenu* menu_less = new QMenu;
	menu_less->addAction("1");
	menu_less->addAction("2");
	menu_less->addAction("3");
	QPushButton* lesson = new QPushButton("select");
	lesson->setMenu(menu_less);

	QLabel* label_less = new QLabel("choose a class time");

	QMenu* menu_building = new QMenu;
	menu_building->addAction("1");
	menu_building->addAction("2");
	menu_building->addAction("3");
	QPushButton* building = new QPushButton("select");
	building->setMenu(menu_building);

	QLabel* label_building = new QLabel("choose a building");

	QPushButton* find_button = new QPushButton("go");

	//добавление объектов в шаблоны
	second_layout->addWidget(label_less);
	second_layout->addWidget(lesson);

	second_layout->addWidget(label_building);
	second_layout->addWidget(building);
	main_layout->addLayout(second_layout);
	main_layout->addWidget(find_button);
	cw->setLayout(main_layout);


	setCentralWidget(cw);



}

MainWindow::~MainWindow() {


}