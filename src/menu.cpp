#include <menu.h>

void Menu::mousePressEvent(QMouseEvent* event) {
	
	if (a_a == 1) {
		if (event->button() == Qt::LeftButton) {
			if (fl) {
				removeItem(0);
				fl = false;
			}


			if (true) {
				connect(this, &QComboBox::currentIndexChanged, this, &Menu::onCurrentIndexChanged);
				Menu::setItemText(tmp_state_ind, tmp_state);
			}

		}
		QComboBox::mousePressEvent(event);
	}


	if (a_a != 1) {
		if (event->button() == Qt::LeftButton) {

		}
		QComboBox::mousePressEvent(event);
	}
}
	
void Menu::onCurrentIndexChanged(int index){
	std::string str = std::to_string(index+1);
	tmp_state = QString::fromUtf8(str.c_str());
	tmp_state_ind = index;
	QString qString = "Количество человек: " + tmp_state;

	Menu::setItemText(index, qString);
}



Menu::Menu(QWidget* parent, int a) : QComboBox(parent){
	a_a = a;
	
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	setMinimumSize(290, 50);
	
	if (a_a == 1) {
		
		std::vector<QString> lst;
		lst.push_back("1");
		lst.push_back("2");
		lst.push_back("3");
		lst.push_back("4");
		lst.push_back("5");
		lst.push_back("6");
		lst.push_back("7");
		lst.push_back("8");
		lst.push_back("9");
		lst.push_back("10");
		lst.push_back("11");
		lst.push_back("12");
		lst.push_back("13");
		lst.push_back("14");
		lst.push_back("15");
		lst.push_back("16");
		lst.push_back("17");
		lst.push_back("18");
		lst.push_back("19");
		lst.push_back("20");
		lst.push_back("21");
		lst.push_back("22");
		lst.push_back("23");
		lst.push_back("24");
		lst.push_back("25");
		lst.push_back("26");
		lst.push_back("27");
		lst.push_back("28");
		lst.push_back("29");
		lst.push_back("30");
		lst.push_back("31");
		Menu::addItem("Количество человек");



		for (int i = 0; i < 31; i++) {
			QString s = QString(lst[i]);
			Menu::addItem(s);
		}

		
		

	}


	if (a_a == 2) {
		std::vector<QString> lst;
		lst.push_back("Школа Компьютерных Наук");
		lst.push_back("Школа Образования");
		lst.push_back("Олимпия: Гимнастический Зал");
		lst.push_back("Олимпия: Тренажерный Зал");
		lst.push_back("Олимпия: Зал Стрэтчинга");

		Menu::setMaxVisibleItems(7);
		for (int i = 0; i < 5; i++) {  
			Menu::addItem(lst[i]);
		}



	}

	if (a_a == 3) {
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

