#include <toolbar.h>
#include <toolbarButton.h>



ToolBar::ToolBar(QWidget* parent){
	QPushButton* build1_btn = new QPushButton("ИПИП");
	build1_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	build1_btn->setMinimumSize(100, 25);
	build1_btn->setStyleSheet("QPushButton {background-color:rgb(33, 33, 33);color: black; border: 2px solid rgb(33, 33, 33); border-radius: 5px; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 400;}"
		"QPushButton:hover {background-color:rgb(148, 235, 188);border: 1px solid rgb(148, 235, 188); outline: 0;}");

	QPushButton* build2_btn = new QPushButton;
	build2_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	build2_btn->setMinimumSize(100, 25);
	build2_btn->setStyleSheet("QPushButton {background-color:rgb(33, 33, 33);color: black; border: 2px solid rgb(33, 33, 33); border-radius: 5px; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 400;}"
		"QPushButton:hover {background-color:rgb(148, 235, 188);border: 1px solid rgb(148, 235, 188); outline: 0;}");

	QPushButton* build3_btn = new QPushButton;
	build3_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	build3_btn->setMinimumSize(100, 25);
	build3_btn->setStyleSheet("QPushButton {background-color:rgb(33, 33, 33);color: black; border: 2px solid rgb(33, 33, 33); border-radius: 5px; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 400;}"
		"QPushButton:hover {background-color:rgb(148, 235, 188);border: 1px solid rgb(148, 235, 188); outline: 0;}");

	QPushButton* build4_btn = new QPushButton;
	build4_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	build4_btn->setMinimumSize(100, 25);
	build4_btn->setStyleSheet("QPushButton {background-color:rgb(33, 33, 33);color: black; border: 2px solid rgb(33, 33, 33); border-radius: 5px; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 400;}"
		"QPushButton:hover {background-color:rgb(148, 235, 188);border: 1px solid rgb(148, 235, 188); outline: 0;}");
	//new
	ToolbarButton* fullscreen_btn = new ToolbarButton(parent);
	build4_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	build4_btn->setMinimumSize(100, 25);
	build4_btn->setStyleSheet("QPushButton {background-color:rgb(33, 33, 33);color: black; border: 2px solid rgb(33, 33, 33); border-radius: 5px; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 400;}"
		"QPushButton:hover {background-color:rgb(148, 235, 188);border: 1px solid rgb(148, 235, 188); outline: 0;}");


	QPushButton* exit_btn = new QPushButton;
	build4_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	build4_btn->setMinimumSize(100, 25);
	build4_btn->setStyleSheet("QPushButton {background-color:rgb(33, 33, 33);color: black; border: 2px solid rgb(33, 33, 33); border-radius: 5px; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 400;}"
		"QPushButton:hover {background-color:rgb(148, 235, 188);border: 1px solid rgb(148, 235, 188); outline: 0;}");
	connect(exit_btn, &QPushButton::clicked, [parent]() {parent->close();});

	setStyleSheet("QToolBar{background-color:rgb(59, 59, 59); border: none;}");

	ToolBar::addWidget(build1_btn);
	ToolBar::addWidget(build2_btn);
	ToolBar::addWidget(build3_btn);
	ToolBar::addWidget(build4_btn);
	ToolBar::addWidget(fullscreen_btn);
	ToolBar::addWidget(exit_btn);
}

ToolBar::~ToolBar() {

}
