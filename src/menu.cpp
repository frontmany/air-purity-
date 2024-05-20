#include <menu.h>

void Menu::mousePressEvent(QMouseEvent* event) {
	
	if (a_a == 1 ) {
		if (event->button() == Qt::LeftButton) {
			if (fl) {
				
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
	QString qString = "Количество человек в зале: " + tmp_state;

	Menu::setItemText(index, qString);
}



Menu::Menu(QWidget* parent, int a) : QComboBox(parent){
	a_a = a;

	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	setMinimumSize(350, 50);
	
	if (a_a == 1) {
		Menu::addItem("1");
		Menu::addItem("2");
		Menu::addItem("3");
		Menu::addItem("4");
		Menu::addItem("5");
		Menu::addItem("6");
		Menu::addItem("7");
		Menu::addItem("8");
		Menu::addItem("9");
		Menu::addItem("10");
		Menu::addItem("11");
		Menu::addItem("12");
		Menu::addItem("13");
		Menu::addItem("14");
		Menu::addItem("15");
		Menu::addItem("16");
		Menu::addItem("17");
		Menu::addItem("18");
		Menu::addItem("19");
		Menu::addItem("20");
		Menu::addItem("21");
		Menu::addItem("22");
		Menu::addItem("23");
		Menu::addItem("24");
		Menu::addItem("25");
		Menu::addItem("26");
		Menu::addItem("27");
		Menu::addItem("28");
		Menu::addItem("29");
		Menu::addItem("30");
		Menu::addItem("31");
		
		onCurrentIndexChanged(0);
	}


	if (a_a == 2) {
		std::vector<QString> lst;
		lst.push_back("Школа Компьютерных Наук");
		lst.push_back("Школа Образования");
		lst.push_back("Олимпия: Гимнастический Зал");
		lst.push_back("Олимпия: Тренажерный Зал");
		lst.push_back("Олимпия: Зал Групповых Программ");

		Menu::setMaxVisibleItems(7);
		Menu::addItem("Выберите зал:");
		for (int i = 0; i < 5; i++) {  
			Menu::addItem(lst[i]);
		}



	}

	if (a_a == 3) {
		std::vector<QString> lst;
		Menu::addItem("Выберите месяц:");
		lst.push_back("Сентябрь");
		lst.push_back("Октябрь");
		lst.push_back("Ноябрь");
		lst.push_back("Декабрь");
		lst.push_back("Январь");
		lst.push_back("Февраль");
		lst.push_back("Март");
		lst.push_back("Апрель");
		lst.push_back("Май");
		lst.push_back("Июнь");
		
		Menu::setMaxVisibleItems(7);
		for (int i = 0; i < 10; i++) {
			Menu::addItem(lst[i]);
		}
	}

	if (a_a == 4) {
		Menu::addItem("По Убыванию Co2");
		Menu::addItem("По Возрастанию Co2");
	}

	if (a_a == 5) {
		Menu::addItem("1");
		Menu::addItem("2");
		Menu::addItem("3");
		Menu::addItem("4");
		Menu::addItem("5");
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

