#include <menu.h>
#include <QStyleOption>
#include <QScrollArea>
#include <vector>



Menu::Menu(int a) {


	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	setMinimumSize(500, 50);
	
	if (a == 1) {
		
		std::vector<QString> lst;
		lst.push_back("Первая  (8.30 - 10.00)");
		lst.push_back("Вторая  (10.15 - 11.45)");
		lst.push_back("Третья  (12.00 - 13.30)");
		lst.push_back("Четвертая  (14.00 - 15.30)");
		lst.push_back("Пятая  (15.45 - 17.15)");
		lst.push_back("Шестая  (17.30 - 19.00)");
		lst.push_back("Седьмая  (19.10 - 20.40)");

		for (int i = 0; i < 7; i++) {
			QString s = QString(lst[i]);
			Menu::addItem(s);
		}
	}

	if (a == 2) {
		std::vector<QString> lst;
		lst.push_back("Институт психологии и педагогики");
		lst.push_back("Институт биологии");
		lst.push_back("Институт математики и компьютерных наук");
		lst.push_back("Спортивный центр Олимпия");

		Menu::setMaxVisibleItems(7);
		for (int i = 0; i < 4; i++) {  
			Menu::addItem(lst[i]);
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

