#include "rate1.h"
#include "rate2.h"
#include "menu.h"
#include "mainwindow.h"
#include "gym.h"





void RatingWidget::paintEvent(QPaintEvent* event) {
	QColor color1(30, 30, 30);
	QColor color2(34, 34, 34);
	QColor color3(209, 222, 240);

	QStyleOption opt;
	opt.initFrom(this);

	QPainter painter(this);
	QPen pen(color1);
	pen.setWidth(2);
	painter.setPen(pen);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setBrush(color1);

	painter.drawRoundedRect(opt.rect, 5, 5);



	painter.setBrush(color1);
	painter.setPen(Qt::NoPen);



	int rectWidth = width() - 20;
	int rectHeight = 60;
	int rectX = 10;
	int rectY = 20;

	QRect Rect1(rectX, rectY, rectWidth, rectHeight);
	painter.drawRoundedRect(Rect1, 5, 5);
	painter.setPen(color3);




	QFont font = QFont("Arial", 18);
	font.setBold(true);
	painter.setFont(font);
	QRect textRect(rectX, rectY, rectWidth, rectHeight);
	painter.drawText(textRect, Qt::AlignVCenter, "  Рейтинг Залов по Co2");

}

void RatingWidget::onButtonClicked()
{

	QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());

	for (int i = 1; i < rate_Vlayout->count(); i++) {
		if (qobject_cast<QPushButton*>((((rate_Vlayout->itemAt(i))->layout())->itemAt(2))->widget()) == clickedButton) {
			QPushButton* button = qobject_cast<QPushButton*>((((rate_Vlayout->itemAt(i))->layout())->itemAt(0))->widget());
			QString s = button->text();
			for (int j = 0; j < mainWindow->storage_list3_values.size(); j++) {
				Gym g = mainWindow->storage_list3_values[j];
				int indVla = i - 1;

				if (indVla < 0) {
					mainWindow->storage_list3_values.erase(mainWindow->storage_list3_values.begin());
					show(mainWindow->storage_list3_values, 1);
					break;
				}

				if (s == g.name) {
					mainWindow->storage_list3_values.erase(mainWindow->storage_list3_values.begin() + indVla);
					show(mainWindow->storage_list3_values, 1);
					
					break;
				}
			}
			break;
			
		}
		
	}


}

void RatingWidget::show(std::vector<Gym> storage3, int sw) {
	rate_Vlayout->setAlignment(Qt::AlignLeft);

	if (sw == 0) {
		for (Gym i : storage3) {
			QHBoxLayout* Hla = new QHBoxLayout;

			QPushButton* btn = new QPushButton(i.name);
			btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
			btn->setMinimumSize(350, 100);
			btn->setMaximumSize(1000, 100);
			btn->setStyleSheet(style1);
			Hla->addWidget(btn);

			QPushButton* btn_co2 = new QPushButton(QString::number(i.Co2));
			btn_co2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
			btn_co2->setMinimumSize(50, 100);
			btn_co2->setMaximumSize(350, 100);
			btn_co2->setStyleSheet(style1);
			Hla->addWidget(btn_co2);
			

			QPushButton* deleteBtn = new QPushButton;
			QIcon ic(":/cross.png");
			QSize size(30, 30);
			ic.actualSize(size);
			deleteBtn->setIcon(ic);
			deleteBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
			deleteBtn->setMinimumSize(30, 100);
			deleteBtn->setMaximumSize(30, 100);
			deleteBtn->setStyleSheet(delstyle);
			Hla->addWidget(deleteBtn);
			rate_Vlayout->addLayout(Hla);
			connect(deleteBtn, &QPushButton::clicked, this, &RatingWidget::onButtonClicked);
			
		}
		return;
	}

	if (sw == 1) {
		QLayoutItem* item;
		
		while (rate_Vlayout->count() > 1) {
			QLayoutItem* item = rate_Vlayout->itemAt(1); // Получаем вложенный элемент
			QLayout* innerLayout = item->layout(); // Получаем вложенный layout

			while (QLayoutItem* childItem = innerLayout->takeAt(0)) { // Удаляем все элементы из вложенного layout
				delete childItem->widget(); // Удаляем объекты (widget), если они есть
				delete childItem; // Освобождаем память
			}

			delete innerLayout; // Освобождаем память от вложенного layout
			rate_Vlayout->removeItem(item); // Удаляем элемент из внешнего layout
			
		}


		for (Gym i : storage3) {
			QHBoxLayout* Hla = new QHBoxLayout;
			QPushButton* btn = new QPushButton(i.name);
			btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
			btn->setMinimumSize(50, 100);
			btn->setMaximumSize(1000, 100);
			btn->setStyleSheet(style1);
			Hla->addWidget(btn);

			QPushButton* btn_co2 = new QPushButton(QString::number(i.Co2));
			btn_co2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
			btn_co2->setMinimumSize(50, 100);
			btn_co2->setMaximumSize(350, 100);
			btn_co2->setStyleSheet(style1);
			Hla->addWidget(btn_co2);
			


			QPushButton* deleteBtn = new QPushButton;
			QIcon ic(":/cross.png");
			deleteBtn->setIcon(ic);
			QSize size(30, 30);
			ic.actualSize(size);
			deleteBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
			deleteBtn->setMinimumSize(30, 100);
			deleteBtn->setMaximumSize(30, 100);
			deleteBtn->setStyleSheet(delstyle);
			Hla->addWidget(deleteBtn);
			rate_Vlayout->addLayout(Hla);
			connect(deleteBtn, &QPushButton::clicked, this, &RatingWidget::onButtonClicked);
		}
	}
	
	

}

void RatingWidget::onSortMenuChanged(int index) {
	if (index == 0) {
		for (int i = 0; i < mainWindow->storage_list3_values.size(); i++) {
			for (int j = 0; j < mainWindow->storage_list3_values.size() - 1; j++) {
				if (mainWindow->storage_list3_values[j].Co2 < mainWindow->storage_list3_values[j + 1].Co2) {
					Gym tmp = mainWindow->storage_list3_values[j];
					mainWindow->storage_list3_values[j] = mainWindow->storage_list3_values[j + 1];
					mainWindow->storage_list3_values[j + 1] = tmp;
				}
			}
		}
	}

	if (index == 1) {
		for (int i = 0; i < mainWindow->storage_list3_values.size(); i++) {
			for (int j = 0; j < mainWindow->storage_list3_values.size() - 1; j++) {
				if (mainWindow->storage_list3_values[j].Co2 > mainWindow->storage_list3_values[j + 1].Co2) {
					Gym tmp = mainWindow->storage_list3_values[j];
					mainWindow->storage_list3_values[j] = mainWindow->storage_list3_values[j + 1];
					mainWindow->storage_list3_values[j + 1] = tmp;
				}
			}
		}
	}
	
	show(mainWindow->storage_list3_values, 1);
}

void RatingWidget::recoverMenu() {
	mainWindow->storage_list3_values = mainWindow->storage_list3_forRecovery;
	while (rate_Vlayout->count() > 1) {
		QLayoutItem* item = rate_Vlayout->itemAt(1); 
		QLayout* innerLayout = item->layout(); 

		while (QLayoutItem* childItem = innerLayout->takeAt(0)) { 
			delete childItem->widget(); 
			delete childItem;
		}

		delete innerLayout; 
		rate_Vlayout->removeItem(item);

	}


	for (Gym i : mainWindow->storage_list3_forRecovery) {
		QHBoxLayout* Hla = new QHBoxLayout;

		QPushButton* btn = new QPushButton(i.name);
		btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
		btn->setMinimumSize(350, 100);
		btn->setMaximumSize(1000, 100);
		btn->setStyleSheet(style1);
		Hla->addWidget(btn);

		QPushButton* btn_co2 = new QPushButton(QString::number(i.Co2));
		btn_co2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
		btn_co2->setMinimumSize(50, 100);
		btn_co2->setMaximumSize(350, 100);
		btn_co2->setStyleSheet(style1);
		Hla->addWidget(btn_co2);


		QPushButton* deleteBtn = new QPushButton;
		QIcon ic(":/cross.png");
		QSize size(30, 30);
		ic.actualSize(size);
		deleteBtn->setIcon(ic);
		deleteBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
		deleteBtn->setMinimumSize(30, 100);
		deleteBtn->setMaximumSize(30, 100);
		deleteBtn->setStyleSheet(delstyle);
		Hla->addWidget(deleteBtn);
		rate_Vlayout->addLayout(Hla);
		connect(deleteBtn, &QPushButton::clicked, this, &RatingWidget::onButtonClicked);

	}
}


RatingWidget::RatingWidget(QWidget* parent, MainWindow* mainw) : QWidget(parent) {
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumSize(350, 300);
	setMaximumSize(1920, 1080);
	mainWindow = mainw;

	rate_Vlayout = new QVBoxLayout();
	adjustment_layout = new QHBoxLayout();
	Hla = new QHBoxLayout;


	QHBoxLayout* MenuHla = new QHBoxLayout;
	MenuHla->setAlignment(Qt::AlignLeft);

	area_menu = new Menu(this, 4);
	area_menu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	area_menu->setMinimumSize(260, 60);
	area_menu->setMaximumSize(892, 60);
	connect(area_menu, &QComboBox::currentIndexChanged, this, &RatingWidget::onSortMenuChanged);
	area_menu->setStyleSheet(menuSheet);

	QPushButton* recoverBtn = new QPushButton;
	recoverBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	recoverBtn->setMinimumSize(60, 60);
	recoverBtn->setMaximumSize(60, 60);
	recoverBtn->setStyleSheet(style2);
	QSize size(40, 40);
	QIcon ic(":/recovery_icon.png");
	recoverBtn->setIcon(ic);
	recoverBtn->setIconSize(size);
	connect(recoverBtn, &QPushButton::clicked, this, &RatingWidget::recoverMenu);

	MenuHla->addWidget(area_menu);
	MenuHla->addWidget(recoverBtn);

	rate_Vlayout->addLayout(MenuHla);

	show(mainw->storage_list3_values, 0);


	MainWindow* mw = mainw;

	//rate2
	RatingWidget2* wid = new RatingWidget2(this, mainw, this);
	wid->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	wid->setMinimumSize(350, 530);
	wid->setMaximumSize(800, 590);




	rate_Vlayout2 = new QVBoxLayout;
	rate_Vlayout2->addWidget(wid);




	adjustment_layout->setAlignment(Qt::AlignCenter);
	adjustment_layout->addLayout(rate_Vlayout);
	adjustment_layout->addSpacing(80);
	adjustment_layout->addLayout(rate_Vlayout2);
	setLayout(adjustment_layout);
	
}

void onButtonClicked(){
	int myValue = 5;

}
