#include <QToolBar>
#include <QWidget>
#include <qlayout.h>
#include "qmenu.h"
#include "qpainter.h"
#include <QpaintEvent>
#include <QStyleOption>
#include <Qlabel>
#include <QVboxLayout>
#include <QHboxLayout>
#include <QPushbutton>
#include <QMenu>
#include <QDockWidget>
#include <QTextEdit>


class MainWindow;
class ResultSearchWidget;
class FavouriteListWidget;

class Buttons : public QWidget {

public:
	Buttons(QWidget* parent, MainWindow* mainwindow, ResultSearchWidget* reswidget, FavouriteListWidget* favlistwid, int i);
	void onAddFavBtnClicked();
	void onAddFavBtnClicked2();
	~Buttons();

public:
	bool fl = false;

	QPushButton* backButton;
	QPushButton* saveButton;
	MainWindow* main_window;
	ResultSearchWidget* result_widget;
	FavouriteListWidget* fav_widget;

private:
	QString style1 = "QPushButton {color:rgb(66, 126, 66); background-color:rgb(46, 46, 46); border-radius: 5px; border:rgb(26, 26, 26); padding: 10px 20px; font-size: 14px;font-weight: 400;}"
		"QPushButton:hover {background-color: rgb(246, 93, 69);border: 1px solid rgb(246, 93, 69); outline: 0;}";

	QString style2 = "QPushButton {color:rgb(66, 126, 66); background-color:rgb(46, 46, 46); border-radius: 5px; border:rgb(26, 26, 26); padding: 10px 20px; font-size: 14px;font-weight: 400;}"
		"QPushButton:hover {background-color:rgb(117, 117, 117);border: 1px solid rgb(117, 117, 117); outline: 0;}";
};