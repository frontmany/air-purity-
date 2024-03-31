#include <toolbar.h>
#include <toolbarButton.h>
#include <mainwindow.h>


ToolBar::ToolBar(QWidget* parent, MainWindow* mainwindow)
	: QToolBar(parent),
	btn_fullscreen(0),
	btn_search(0),
	settings_btn(0)
{
	QString toolbarBtnSheet = "QPushButton {background-color:rgb(32, 32, 32);color:rgb(199, 199, 199); border: 2px solid rgb(32, 32, 32); border-radius: 5px; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 800;}"
		"QPushButton:hover {background-color:rgb(105, 105, 105);border: 1px solid rgb(32, 32, 32); outline: 0;}";


	this->setMovable(false);

	
	btn_search = new QPushButton("Поиск");
	btn_search->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	btn_search->setMinimumSize(100, 25);
	btn_search->setStyleSheet(toolbarBtnSheet);
	connect(btn_search, &QPushButton::clicked, mainwindow, &MainWindow::setSearchWidget);
	

	QPushButton* build1_btn = new QPushButton("ШО");
	build1_btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	build1_btn->setMinimumSize(100, 25);
	build1_btn->setStyleSheet(toolbarBtnSheet);

	QPushButton* build2_btn = new QPushButton("ШКН");
	build2_btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	build2_btn->setMinimumSize(100, 25);
	build2_btn->setStyleSheet(toolbarBtnSheet);

	QPushButton* build3_btn = new QPushButton("Олимпия");
	build3_btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	build3_btn->setMinimumSize(100, 25);
	build3_btn->setStyleSheet(toolbarBtnSheet);




	QPushButton* btn_rollUp = new QPushButton();
	btn_rollUp->setIcon(QIcon(":/rollUp.png"));
	btn_rollUp->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	btn_rollUp->setFixedSize(50, 40);
	btn_rollUp->setStyleSheet(toolbarBtnSheet);
	connect(btn_rollUp, &QPushButton::clicked, mainwindow, &MainWindow::showMinimized);


	btn_fullscreen = new ToolbarButton(this, mainwindow);
	btn_fullscreen->setIcon(QIcon(":/fullscrBtn2.png"));
	btn_fullscreen->setIconSize(QSize(14, 14));
	btn_fullscreen->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	btn_fullscreen->setFixedSize(50, 40);
	btn_fullscreen->setStyleSheet(toolbarBtnSheet);
	connect(btn_fullscreen, &QPushButton::clicked, mainwindow, &MainWindow::onFullScreenButtonClicked);
	

	QPushButton* exit_btn = new QPushButton();
	exit_btn->setIcon(QIcon(":/cross.png"));
	exit_btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	exit_btn->setFixedSize(50, 40);
	exit_btn->setStyleSheet(toolbarBtnSheet);
	connect(exit_btn, &QPushButton::clicked, mainwindow, &MainWindow::close);

	QWidget* spacer = new QWidget();
	spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

	QWidget* spacer1 = new QWidget();
	spacer1->setFixedSize(10, 0);
	setStyleSheet("QToolBar{background-color:rgb(32, 32, 32); border: none;}");

	ToolBar::addWidget(spacer1);
	ToolBar::addWidget(btn_search);
	ToolBar::addSeparator();
	ToolBar::addWidget(build1_btn);
	ToolBar::addWidget(build2_btn);
	ToolBar::addWidget(build3_btn);
	ToolBar::addWidget(settings_btn);
	ToolBar::addWidget(spacer);
	ToolBar::addWidget(btn_rollUp);
	ToolBar::addWidget(btn_fullscreen);
	ToolBar::addWidget(exit_btn);
}

ToolBar::~ToolBar() {

}
