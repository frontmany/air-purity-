#include <menu.h>
#include <QStyleOption>

Menu::Menu(int a) {
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
	setMinimumSize(500, 0);
	if (a == 1) {
		QAction* act1 = new QAction("1");
		QAction* act2 = new QAction("2");
		QAction* act3 = new QAction("3");
		QAction* act4 = new QAction("4");
		QAction* act5 = new QAction("5");
		QAction* act6 = new QAction("6");
		QAction* act7 = new QAction("7");
		Menu::addAction(act1);
		Menu::addAction(act2);
		Menu::addAction(act3);
		Menu::addAction(act4);
		Menu::addAction(act5);
		Menu::addAction(act6);
		Menu::addAction(act7);
	}
	if (a == 2) {

	}
	
}


Menu::~Menu() {

}

