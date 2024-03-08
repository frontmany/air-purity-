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
void Menu::paintEvent(QPaintEvent* event){
	QComboBox::paintEvent(event);

	
	QStyleOptionComboBox opt;
	initStyleOption(&opt);

	QPainter painter(this);
	painter.setPen(opt.palette.color(QPalette::ButtonText));

	int x = rect().width() - 30;
	int y = (rect().height() - 10) / 2;

	painter.drawLine(x, y, x + 10, y);
	painter.drawLine(x, y + 5, x + 10, y + 5);
	painter.drawLine(x, y + 10, x + 10, y + 10);


}

Menu::~Menu() {

}

