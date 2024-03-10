#include <menu.h>




Menu::Menu(int a) {


	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	setMinimumSize(500, 50);
	
	if (a == 1) {
		
		std::vector<QString> lst;
		lst.push_back("8.30 - 10.00");
		lst.push_back("10.15 - 11.45");
		lst.push_back("12.00 - 13.30");
		lst.push_back("14.00 - 15.30");
		lst.push_back("15.45 - 17.15");
		lst.push_back("17.30 - 19.00");
		lst.push_back("19.10 - 20.40");

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

	if (a == 3) {
		std::vector<QString> lst;
		lst.push_back("Понедельник");
		lst.push_back("Вторник");
		lst.push_back("Среда");
		lst.push_back("Четверг");
		lst.push_back("Пятница");
		lst.push_back("Суббота");

		Menu::setMaxVisibleItems(7);
		for (int i = 0; i < 6; i++) {
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

