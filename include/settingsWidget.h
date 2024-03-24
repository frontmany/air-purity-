#include "QWidget"
#include "QPainter"
#include "QStyleOption"

class SettingsWidget : public QWidget {
public:
	SettingsWidget(QWidget* parent);
	~SettingsWidget();

private:
	void paintEvent(QPaintEvent* event);
};