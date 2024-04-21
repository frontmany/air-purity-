#include <QWidget>
#include <Qmainwindow>
#include <QApplication>
#include <QLabel>
#include <QLineedit>
#include <qtoolbar.h>
#include "qpushbutton.h"
#include <QStyleFactory>
#include "QSizeGrip"
#include "QList"

class ToolBar;
class ResultSearchWidget;
class FavouriteListWidget;


class MainWindow : public QMainWindow 
{
	Q_OBJECT

public:	
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();
	
	
	void onSearchButtonClicked();
	void onAreaMenuChanged(int index);
	void onClassTimeMenuChanged(int index);
	void onSliderChanged(int index);
	void isSpring(bool fl);
	void isAutumn(bool fl);
	void searchWback();
	


	void setSearchWidget();
	void setFavWidget();
	void onFavBtnClicked();



public slots:
	void handleButtonClicked(int index);


public:
	int body_count = 1;
	QString building = "Школа Компьютерных Наук";
	int slider_data = 1;
	QString season = "autumn";
	std::vector<QString> calculator_data;
	std::vector<QString> calculator_data2;
	std::vector<std::vector<QString>> storage_list;
	std::vector<std::vector<QString>> storage_list2;
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

	

private:

};


