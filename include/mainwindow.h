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


protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);

private:
	bool isFullscreeen = false;
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
	QPoint m_dragStartPosition;
	ToolBar* m_tbar;
};


