#include "rate2.h"
#include "rate1.h"
#include "mainwindow.h"
#include "menu.h"
#include "gym.h"

void RatingWidget2::paintEvent(QPaintEvent* event) {
	QColor color1(40, 40, 40);
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

	painter.drawRoundedRect(opt.rect, 10, 10);





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
	painter.drawText(textRect, Qt::AlignVCenter, "   Сравнить зал");

}

void RatingWidget2::errclear() {
	errGymCheck();
	if (check2) {
		edit2->setStyleSheet(lineEdStyle);
	}
	if (check3) {
		edit3->setStyleSheet(lineEdStyle);
	}
	if (edit2->text() == "") {
		edit2->setStyleSheet(lineEdStyle);
	}
	if (edit3->text() == "") {
		edit3->setStyleSheet(lineEdStyle);
	}
}

void RatingWidget2::addGym() {
	if (rate_widget->rate_Vlayout->count() > 7) {
		QDialog dialog;
		dialog.setFixedSize(260, 100);
		dialog.setStyleSheet("background-color: rgb(34,34,34); border: 1px solid rgb(34,34,34); border-radius: 5px;");
		dialog.setWindowFlags(Qt::CustomizeWindowHint);
		QVBoxLayout* layout = new QVBoxLayout;


		QLabel* datalabel = new QLabel("Максимальное число залов");
		datalabel->setAlignment(Qt::AlignCenter);
		datalabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
		datalabel->setMaximumSize(240, 40);
		datalabel->setStyleSheet("QLabel {"
			"color:rgb(248, 249, 249);"
			"background-color: rgb(34, 34, 34);"
			"font-family: Arial;"
			"font-size: 13px;"
			"font-weight: bold;"
			"padding: 5px;"
			"border-radius: 2px;"
			"}");


		QPushButton* button = new QPushButton("OK");
		button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
		button->setMaximumSize(600, 300);
		button->setStyleSheet(style1);
		QObject::connect(button, &QPushButton::clicked, &dialog, &QDialog::accept);


		dialog.setLayout(layout);
		layout->addWidget(datalabel);
		layout->addWidget(button);

		dialog.exec();
		return;
	}


	if (check1 && check2 && check3) {
		QString name = edit1->text();
		QString sq = edit2->text();
		QString he = edit3->text();
		double square = sq.toDouble();
		double height = he.toDouble();

		double A = 1 + ((square * 3) / ((square * height) * 1.82));
		double Co2 = 350 + (31 * 350 * 90 / (square * height * A));

		Gym ngym;
		ngym.name = name;
		ngym.V = square * height;
		ngym.Co2 = Co2;


		mainWindow->storage_list3_values.push_back(ngym);
		

		if (rate_widget->area_menu->currentText() == "По Убыванию Co2") {
			rate_widget->onSortMenuChanged(0);
		}
		if (rate_widget->area_menu->currentText() == "По Возрастанию Co2") {
			rate_widget->onSortMenuChanged(1);
		}

		rate_widget->show(mainWindow->storage_list3_values, 1);
	}
}

void RatingWidget2::errGymCheck() {
	QString name = edit1->text();
	QString sq = edit2->text();
	QString he = edit3->text();
	bool first = true;
	check1 = true;
	check2 = true;
	check3 = true;
	
	bool ok = true;

	double square = sq.toDouble(&ok);
	if (!ok) {
		edit2->setStyleSheet(errlineEdStyle);
		check2 = false;
	}

	ok = true;
	double height = he.toDouble(&ok);
	if (!ok) {
		edit3->setStyleSheet(errlineEdStyle);
		check3 = false;
	}

	for (Gym i : mainWindow->storage_list3_values) {
		if (i.name == name) {
			edit1->setStyleSheet(errlineEdStyle2);
			check1 = false;
		}
	}
}

RatingWidget2::RatingWidget2(QWidget* parent, MainWindow* mainw, RatingWidget* wid) : QWidget(parent) {
	mainWindow = mainw, rate_widget = wid, check2 = true, check3 = true;

	//новый зал
	QPushButton* ngymBtn = new QPushButton("Добавить Свой Зал");
	QIcon ic(":/plus.png");
	ngymBtn->setIcon(ic);
	QSize size(20, 20);
	ngymBtn->setIconSize(size);
	ngymBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	ngymBtn->setMinimumSize(350, 60);
	ngymBtn->setMaximumSize(400, 60);
	ngymBtn->setStyleSheet(style2);
	connect(ngymBtn, &QPushButton::clicked, this, &RatingWidget2::errGymCheck);
	connect(ngymBtn, &QPushButton::clicked, this, &RatingWidget2::addGym);
	


	QVBoxLayout* Vla1 = new QVBoxLayout;

	//ввод1
	edit1 = new QLineEdit();
	edit1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	edit1->setMinimumSize(60, 50);
	edit1->setMaximumSize(400, 50);
	edit1->setStyleSheet(lineEdStyle2);

	//ввод2
	edit2 = new QLineEdit();
	edit2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	edit2->setMinimumSize(60, 45);
	edit2->setMaximumSize(400, 45);
	edit2->setStyleSheet(lineEdStyle);
	connect(edit2, &QLineEdit::textEdited, this, &RatingWidget2::errclear);

	//ввод3
	edit3 = new QLineEdit();
	edit3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	edit3->setMinimumSize(60, 45);
	edit3->setMaximumSize(400, 45);
	edit3->setStyleSheet(lineEdStyle);
	connect(edit3, &QLineEdit::textEdited, this, &RatingWidget2::errclear);


	//namelabel
	QLabel* nameLabel = new QLabel("Название");
	nameLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	nameLabel->setMinimumSize(60, 50);
	nameLabel->setMaximumSize(100, 50);
	nameLabel->setStyleSheet(labelStyle);

	//площадь
	QLabel* squareLabel = new QLabel("Площадь");
	squareLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	squareLabel->setMinimumSize(60, 30);
	squareLabel->setMaximumSize(100, 30);
	squareLabel->setStyleSheet(labelStyle2);

	//высота потолков
	QLabel* heightLabel = new QLabel("Высота потолков");
	heightLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	heightLabel->setMinimumSize(60, 30);
	heightLabel->setMaximumSize(200, 30);
	heightLabel->setStyleSheet(labelStyle2);

	//запыленность
	QLabel* dustLabel = new QLabel("Предварительно оцените запыленность");
	dustLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	dustLabel->setMinimumSize(60, 40);
	dustLabel->setMaximumSize(300, 40);
	dustLabel->setStyleSheet(labelStyle2);



	
	Vla1->addWidget(nameLabel);
	Vla1->addWidget(edit1);
	Vla1->addWidget(squareLabel);
	Vla1->addWidget(edit2);
	Vla1->addWidget(heightLabel);
	Vla1->addWidget(edit3);
	Vla1->addSpacing(20);
	Vla1->addWidget(ngymBtn);

	




	rate_layout2 = new QVBoxLayout;
	rate_layout2->setAlignment(Qt::AlignCenter);
	rate_layout2->addSpacing(0);
	rate_layout2->addLayout(Vla1);
	rate_layout2->addSpacing(0);
	setLayout(rate_layout2);
}


RatingWidget2::~RatingWidget2() {

}