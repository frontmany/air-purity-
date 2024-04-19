#include <toolbar.h>
#include <mainwindow.h>


ToolBar::ToolBar(QWidget* parent, MainWindow* mainwindow)
	: QToolBar(parent),
	btn_fullscreen(0)
{
	QString toolbarBtnSheet = "QPushButton {background-color:rgb(48, 48, 48);color:rgb(199, 199, 199); border: 1px solid rgb(48, 48, 48); border-radius: 8px;  font-size: 14px;font-weight: 800;}"
		"QPushButton:hover {background-color:rgb(105, 105, 105);border: 2px solid rgb(32, 32, 32); outline: 0;}";


	this->setMovable(false);

	QWidget* widget1 = new QWidget;
	QVBoxLayout* Vla1 = new QVBoxLayout;
	btn_search = new QPushButton("Калькулятор");
	btn_search->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	btn_search->setMinimumSize(100, 25);
	btn_search->setStyleSheet(toolbarBtnSheet);
	Vla1->addWidget(btn_search);
	Vla1->addSpacing(0);
	widget1->setLayout(Vla1);
	connect(btn_search, &QPushButton::clicked, mainwindow, &MainWindow::setSearchWidget);
	

	QWidget* widget2 = new QWidget;
	QVBoxLayout* Vla2 = new QVBoxLayout;
	favourites_btn = new QPushButton("Избранное");
	favourites_btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	favourites_btn->setMinimumSize(100, 25);
	favourites_btn->setStyleSheet(toolbarBtnSheet);
	Vla2->addWidget(favourites_btn);
	widget2->setLayout(Vla2);
	connect(favourites_btn, &QPushButton::clicked, mainwindow, &MainWindow::setFavWidget);


	setStyleSheet("QToolBar{background-color:rgb(34, 34, 34); border: none;}");


	ToolBar::addWidget(widget1);
	ToolBar::addWidget(widget2);


}

ToolBar::~ToolBar() {

}
