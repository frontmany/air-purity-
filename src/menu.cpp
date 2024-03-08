#include <menu.h>
#include <QStyleOption>
#include <QScrollArea>

Menu::Menu(int a) {
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	setMinimumSize(500, 50);
	
	if (a == 1) {
		

		for (int i = 0; i < 7; i++) {
			Menu::addItem(QString("  Item%1").arg(i));
		}
	}

	if (a == 2) {
		Menu::setMaxVisibleItems(7);
		for (int i = 0; i < 18; i++) {
			Menu::addItem(QString("  Item%1").arg(i));
		}
	}
	
}


Menu::~Menu() {

}

