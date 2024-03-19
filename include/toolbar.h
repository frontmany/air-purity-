#include <QToolbar>

class MainWindow;
class ToolBar : public QToolBar 
{
public:
	ToolBar(MainWindow* parent = nullptr);
	~ToolBar();


};
