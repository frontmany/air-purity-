#include <QToolbar>
#include <QPushButton>


class MainWindow;
class ToolbarButton;

class ToolBar : public QToolBar 
{

public:
	ToolBar(QWidget* parent, MainWindow* mainwindow);
	~ToolBar();

public:
	ToolbarButton* btn_fullscreen;
	QPushButton* btn_search;
	QPushButton* settings_btn;

};
