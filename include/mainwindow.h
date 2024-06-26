#include <QWidget>
#include <Qmainwindow>
#include <QApplication>
#include <QLabel>
#include <QLineedit>
#include <qtoolbar.h>
#include "qpushbutton.h"
#include <QStyleFactory>
#include "QSizeGrip"

class ToolBar;


class MainWindow : public QMainWindow 
{
	Q_OBJECT

public:	
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();
	
	void onFullScreenButtonClicked();
	void onSearchButtonClicked();
	void onAreaMenuChanged(int index);
	void onClassTimeMenuChanged(int index);
	void onSliderChanged(int index);
	void isSpring(bool fl);
	void isAutumn(bool fl);
	void searchWback();



	void setSearchWidget();
	void setSettingsWidget();

public:
	int body_count = 1;
	QString building = "Школа Компьютерных Наук";
	int slider_data = 1;
	QString season = "autumn";

protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);



private:
	QString trigBtnSheet = "QPushButton {background-color:rgb(105, 105, 105);color:rgb(199, 199, 199); border: 2px solid rgb(105, 105, 105); border-radius: 5px; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 800;}"
		"QPushButton:hover {background-color:rgb(105, 105, 105);border: 1px solid rgb(32, 32, 32); outline: 0;}";

	QString toolbarBtnSheet = "QPushButton {background-color:rgb(32, 32, 32);color:rgb(199, 199, 199); border: 2px solid rgb(32, 32, 32); border-radius: 5px; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 800;}"
		"QPushButton:hover {background-color:rgb(105, 105, 105);border: 1px solid rgb(32, 32, 32); outline: 0;}";

private:
	bool isFullscreeen = false;
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
	QPoint m_dragStartPosition;
	ToolBar* m_tbar;
	QWidget* searchW;
	
private:

};


