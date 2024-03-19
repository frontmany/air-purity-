#include <QWidget>
#include <Qmainwindow>
#include <QApplication>
#include <QLabel>
#include <QLineedit>
#include <qtoolbar.h>
#include "qpushbutton.h"
#include <QStyleFactory>
#include "QSizeGrip"

class MainWindow : public QMainWindow {
	Q_OBJECT

public:	
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

	void onFullScreenButtonClicked();

	

private:
	QPoint m_dragStartPosition = QPoint();

	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
};


