#include <QWidget>
#include <Qmainwindow>
#include <QApplication>
#include <QLabel>
#include <QLineedit>
#include <qtoolbar.h>
#include "qpushbutton.h"


class MainWindow : public QMainWindow {
public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();
private:
	void paintEvent(QPainter* event);


};