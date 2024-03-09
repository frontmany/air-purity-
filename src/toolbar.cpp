#include <toolbar.h>
#include <QPushButton>

ToolBar::ToolBar(){
	QPushButton* build1_btn = new QPushButton;
	build1_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	build1_btn->setMinimumSize(100, 100);
	QPushButton* build2_btn = new QPushButton;
	build2_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	build2_btn->setMinimumSize(100, 100);
	QPushButton* build3_btn = new QPushButton;
	build3_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	build3_btn->setMinimumSize(100, 100);
	QPushButton* build4_btn = new QPushButton;
	build4_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	build4_btn->setMinimumSize(100, 100);
	ToolBar::addWidget(build1_btn);
	ToolBar::addWidget(build2_btn);
	ToolBar::addWidget(build3_btn);
	ToolBar::addWidget(build4_btn);
}

ToolBar::~ToolBar() {

}