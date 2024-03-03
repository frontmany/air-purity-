#include "mainwindow.h"
#include "centralwidget.h"

MainWindow::MainWindow() {
	QWidget* cw = new QWidget;

	// созданий шаблонов
	QHBoxLayout* main_layout = new QHBoxLayout;
	QVBoxLayout* second_layout = new QVBoxLayout;

	QHBoxLayout* tmp1_layout = new QHBoxLayout;

	//создание объектов
	QMenu* menu_less = new QMenu;
	menu_less->addAction("1");
	menu_less->addAction("2");
	menu_less->addAction("3");
	QPushButton* lesson_btn = new QPushButton("select");
	lesson_btn->setMaximumSize(600, 150);
	lesson_btn->setMenu(menu_less);

	QLabel* label_less = new QLabel("choose a class time");

	QMenu* menu_building = new QMenu;
	menu_building->addAction("1");
	menu_building->addAction("2");
	menu_building->addAction("3");
	QPushButton* building_btn = new QPushButton("select");
	building_btn->setMaximumSize(600, 150);

	building_btn->setMenu(menu_building);


	QLabel* label_building = new QLabel("choose a building");

	QPushButton* find_button = new QPushButton("go");
	find_button->setMaximumSize(600, 150);

	MainWindow* w = new MainWindow;

	//добавление объектов в шаблоны
	second_layout->addWidget(label_less);
	second_layout->addWidget(lesson_btn);
	second_layout->addWidget(label_building);
	second_layout->addWidget(building_btn);
	second_layout->addWidget(find_button);
	main_layout->addLayout(second_layout);

	cw->setLayout(main_layout);


	setCentralWidget(cw);



}

MainWindow::~MainWindow() {


}