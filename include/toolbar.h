#include <QToolbar>


class MainWindow;
class ToolbarButton;

class ToolBar : public QToolBar 
{

public:
	ToolBar(QWidget* parent, MainWindow* mainwindow);
	~ToolBar();

public:
	ToolbarButton* btn_fullscreen;

};
