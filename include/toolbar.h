#include <QToolbar>
#include <QPushButton>
#include <QLayout>


class MainWindow;

class ToolBar : public QToolBar 
{

public:
	ToolBar(QWidget* parent, MainWindow* mainwindow);
	~ToolBar();

public:
	QPushButton* btn_fullscreen;
	QPushButton* btn_search;
	QPushButton* favourites_btn;
	QPushButton* rate_btn;

};
