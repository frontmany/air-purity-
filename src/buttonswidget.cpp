#include <buttonswidget.h>
#include <calculator.h>
#include <mainwindow.h>
#include <favourite.h>
#include <resultsearchwidget.h>

void Buttons::onAddFavBtnClicked2() {
	if (!fl) {
		QIcon img(":/save_active.png");
		saveButton->setIcon(img);
		fl = true;
		main_window->calculator_data[0] = (result_widget->month);
		main_window->calculator_data[1] = (result_widget->building);
		main_window->calculator_data[2] = (QString::number(result_widget->co_2_value));
		main_window->calculator_data[3] = (QString::number(result_widget->dust_value));
		main_window->calculator_data[4] = (QString::number(result_widget->mark));
		main_window->calculator_data[5] = (QString::number(result_widget->body_count));
		main_window->calculator_data[6] = (QString::number(result_widget->real_co2));

		int tempy = 7;
		for (int i = 0; i < 10; i++) {

			main_window->calculator_data[tempy] = (QString::number(result_widget->allco2vec[i]));
			tempy++;
		}

		for (int i = 0; i < 10; i++) {

			main_window->calculator_data2[i] = (QString::number(result_widget->alldustvec[i]));
		}
		main_window->storage_list.push_back(main_window->calculator_data);
		main_window->storage_list2.push_back(main_window->calculator_data2);


		main_window->fav_wid_count++;

	}
	else {
		QIcon img(":/save.png");
		saveButton->setIcon(img);
		fl = false;
		for (int i = 0; i < main_window->fav_wid_count; i++) {
			if (main_window->storage_list[i][0] == result_widget->month && main_window->storage_list[i][1] == result_widget->building && (main_window->storage_list[i][5]).toInt() == result_widget->body_count) {
				int j = i;
				main_window->storage_list.erase(main_window->storage_list.begin()+j);
				main_window->storage_list2.erase(main_window->storage_list2.begin()+j);
				main_window->fav_wid_count--;
				break;
			}


		}
		

	}
	
}


void Buttons::onAddFavBtnClicked() {


	if (!fl) {
		if (main_window->fav_wid_count == 4) {
			QDialog dialog;
			dialog.setFixedSize(260, 100);
			dialog.setStyleSheet("background-color: rgb(34,34,34); border: 1px solid rgb(34,34,34); border-radius: 5px;");
			dialog.setWindowFlags(Qt::CustomizeWindowHint);
			QVBoxLayout* layout = new QVBoxLayout;


			QLabel* datalabel = new QLabel("Максимальное число избранных");
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



		QIcon img(":/save_active.png");
		saveButton->setIcon(img);
		fl = true;
		main_window->calculator_data[0] = (result_widget->month);
		main_window->calculator_data[1] = (result_widget->building);
		main_window->calculator_data[2] = (QString::number(result_widget->co_2_value));
		main_window->calculator_data[3] = (QString::number(result_widget->dust_value));
		main_window->calculator_data[4] = (QString::number(result_widget->mark));
		main_window->calculator_data[5] = (QString::number(result_widget->body_count));
		main_window->calculator_data[6] = (QString::number(result_widget->real_co2));


		int tempy = 7;
		for (int i = 0; i < 10; i++) {

			main_window->calculator_data[tempy] = (QString::number(result_widget->allco2vec[i]));
			tempy++;
		}
		
		for (int i = 0; i < 10; i++) {

			main_window->calculator_data2[i] = (QString::number(result_widget->alldustvec[i]));
		}

		main_window->storage_list.push_back(main_window->calculator_data);
		main_window->storage_list2.push_back(main_window->calculator_data2);

		main_window->fav_wid_count++;

	}


	else {
		QIcon img(":/save.png");
		saveButton->setIcon(img);
		fl = false;
		main_window->storage_list.pop_back();
		main_window->storage_list2.pop_back();
		main_window->fav_wid_count--;
		
	}
	

}


Buttons::Buttons(QWidget* parent, MainWindow* mainwindow, ResultSearchWidget* reswidget, FavouriteListWidget* favlistwid, int i) : QWidget(parent) {
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMaximumSize(80, 80);

	main_window = mainwindow;
	result_widget = reswidget;
	

	if (i == 1) {
		QHBoxLayout* Hlayout = new QHBoxLayout;
		Hlayout->setAlignment(Qt::AlignCenter);


		saveButton = new QPushButton();
		saveButton->setMinimumSize(55, 55);
		saveButton->setMaximumSize(55, 55);
		saveButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
		connect(saveButton, &QPushButton::clicked, this, &Buttons::onAddFavBtnClicked);

		saveButton->setStyleSheet(style2);
		QIcon img2(":/save.png");
		saveButton->setIcon(img2);
		Hlayout->addWidget(saveButton);
		
		setLayout(Hlayout);
	}

	if (i == 2) {
		fav_widget = favlistwid;
		QHBoxLayout* layout = new QHBoxLayout;
		layout->setAlignment(Qt::AlignCenter);
		backButton = new QPushButton();
		backButton->setMinimumSize(1, 55);
		backButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
		connect(backButton, &QPushButton::clicked, mainwindow, &MainWindow::setFavWidget);
		layout->addWidget(backButton);
		backButton->setStyleSheet(style1);
		QIcon img1(":/arrow.png");
		backButton->setIcon(img1);
		layout->addSpacing(5);
		saveButton = new QPushButton();
		saveButton->setMinimumSize(1, 55);
		saveButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
		connect(saveButton, &QPushButton::clicked, this, &Buttons::onAddFavBtnClicked2);

		saveButton->setStyleSheet(style2);
		QIcon img2(":/save.png");
		saveButton->setIcon(img2);
		layout->addWidget(saveButton);
		setLayout(layout);
		
	}
	
}

Buttons::~Buttons() {

}