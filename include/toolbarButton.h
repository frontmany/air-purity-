#include <qpushbutton.h>
#include <QWidget>
class ToolbarButton : public QPushButton {

public:
	ToolbarButton(QWidget* parent = nullptr);
	~ToolbarButton();

signals:
	void buttonClicked();

private:



};