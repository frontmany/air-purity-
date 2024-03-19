#include <toolbar.h>
#include <toolbarButton.h>
#include <mainwindow.h>


ToolBar::ToolBar(MainWindow* parent)
{
	this->setMovable(false);
	QPushButton* build1_btn = new QPushButton("ИПИП");
	build1_btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	build1_btn->setMinimumSize(100, 25);
	build1_btn->setStyleSheet("QPushButton {background-color:rgb(32, 32, 32);color:rgb(199, 199, 199); border: 2px solid rgb(32, 32, 32); border-radius: 5px; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 800;}"
		"QPushButton:hover {background-color:rgb(148, 235, 188);border: 1px solid rgb(32, 32, 32); outline: 0;}");

	QPushButton* build2_btn = new QPushButton("ИНБИО");
	build2_btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	build2_btn->setMinimumSize(100, 25);
	build2_btn->setStyleSheet("QPushButton {background-color:rgb(32, 32, 32);color:rgb(199, 199, 199); border: 2px solid rgb(32, 32, 32); border-radius: 5px; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 800;}"
		"QPushButton:hover {background-color:rgb(148, 235, 188);border: 1px solid rgb(32, 32, 32); outline: 0;}");

	QPushButton* build3_btn = new QPushButton("ИМИКН");
	build3_btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	build3_btn->setMinimumSize(100, 25);
	build3_btn->setStyleSheet("QPushButton {background-color:rgb(32, 32, 32);color:rgb(199, 199, 199); border: 2px solid rgb(32, 32, 32); border-radius: 5px; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 800;}"
		"QPushButton:hover {background-color:rgb(148, 235, 188);border: 1px solid rgb(32, 32, 32); outline: 0;}");

	QPushButton* build4_btn = new QPushButton("ОЛИМПИЯ");
	build4_btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	build4_btn->setMinimumSize(100, 25);
	build4_btn->setStyleSheet("QPushButton {background-color:rgb(32, 32, 32);color:rgb(199, 199, 199); border: 2px solid rgb(32, 32, 32); border-radius: 5px; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 800;}"
		"QPushButton:hover {background-color:rgb(148, 235, 188);border: 1px solid rgb(32, 32, 32); outline: 0;}");

	//new
	QPushButton* fullscreen_btn = new QPushButton("fullscreen");
	fullscreen_btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	fullscreen_btn->setMinimumSize(100, 25);
	fullscreen_btn->setStyleSheet("QPushButton {background-color:rgb(32, 32, 32);color:rgb(199, 199, 199); border: 2px solid rgb(32, 32, 32); border-radius: 5px; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 800;}"
		"QPushButton:hover {background-color:rgb(148, 235, 188);border: 1px solid rgb(32, 32, 32); outline: 0;}");



	QPushButton* exit_btn = new QPushButton("exit");
	exit_btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	exit_btn->setMinimumSize(100, 25);
	exit_btn->setStyleSheet("QPushButton {background-color:rgb(32, 32, 32);color:rgb(199, 199, 199); border: 2px solid rgb(32, 32, 32); border-radius: 5px; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 800;}"
		"QPushButton:hover {background-color:rgb(148, 235, 188);border: 1px solid rgb(32, 32, 32); outline: 0;}");
	connect(exit_btn, &QPushButton::clicked, parent, &MainWindow::close);

	QWidget* spacer = new QWidget();
	spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

	setStyleSheet("QToolBar{background-color:rgb(32, 32, 32); border: none;}");

	ToolBar::addWidget(build1_btn);
	ToolBar::addWidget(build2_btn);
	ToolBar::addWidget(build3_btn);
	ToolBar::addWidget(build4_btn);
	ToolBar::addWidget(spacer);
	ToolBar::addWidget(fullscreen_btn);
	ToolBar::addWidget(exit_btn);
}

ToolBar::~ToolBar() {

}
