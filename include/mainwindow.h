#include <QWidget>
#include <Qmainwindow>
#include <QApplication>
#include <QLabel>
#include <QLineedit>
#include <QLayout>
#include <qtoolbar.h>
#include "qpushbutton.h"
#include <QStyleFactory>
#include "QPropertyAnimation"
#include "QList"
#include "QTimer"


class ToolBar;
class ResultSearchWidget;
class FavouriteListWidget;
class RatingWidget;
struct Gym;


class MainWindow : public QMainWindow 
{
	Q_OBJECT

public:	
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();
	
	
	void onSearchButtonClicked();
	void onAreaMenuChanged(int index);
	void onClassTimeMenuChanged(int index);
	void onMonthMenuChanged(int index);
	void searchWback();
	void onTimer();
	void replaceWidget(QWidget* oldWidget, QWidget* newWidget, QLayout* layout);

	void setSearchWidget();
	void setFavWidget();
	void setRateWidget();
	void onFavBtnClicked();



public slots:
	void handleButtonClicked(int index);


public:
	int body_count = 1;
	QString building = "Школа Компьютерных Наук";
	QString month = "Сентябрь";
	std::vector<QString> calculator_data;
	std::vector<QString> calculator_data2;
	std::vector<std::vector<QString>> storage_list;
	std::vector<std::vector<QString>> storage_list2;


public:
	
	QHBoxLayout* main_Hlayout;

	//gen
	bool genfl = true;
	ResultSearchWidget* ressWidget_toUpdate;


	std::vector<Gym> storage_list3_values;
	std::vector<Gym> storage_list3_forRecovery;


	int fav_wid_count = 0;
	FavouriteListWidget* fav_widget;
	ResultSearchWidget* ressWidget2;

private:
	QString trigBtnSheet = "QPushButton {background-color:rgb(105, 105, 105);color:rgb(202, 207, 210); border: 2px solid rgb(105, 105, 105); border-radius: 5px; padding: 10px 20px; font-size: 14px;font-weight: 800;}"
		"QPushButton:hover {background-color:rgb(105, 105, 105);border: 1px solid rgb(32, 32, 32); outline: 0; border-radius: 5px;}";

	QString toolbarBtnSheet = "QPushButton {background-color:rgb(34, 34, 34);color:rgb(202, 207, 210); border: 2px solid rgb(34, 34, 34); border-radius: 5px; padding: 10px 20px; font-size: 14px;font-weight: 800;}"
		"QPushButton:hover {background-color:rgb(105, 105, 105);border: 1px solid rgb(32, 32, 32); outline: 0; border-radius: 5px;}";

private:
	bool isFullscreeen = false;
	ToolBar* m_tbar;
	QWidget* searchW;
	ResultSearchWidget* ressWidget;
	RatingWidget* rate_widget;

	

private:

};


