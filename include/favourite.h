#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QList>
#include <vector>

class ResultSearchWidget;
class MainWindow;

class FavouriteListWidget : public QWidget {
	Q_OBJECT
public:
	FavouriteListWidget(QWidget* parent, MainWindow* mainwindow);
	~FavouriteListWidget();
	void showFavWidgets();


	

public:
	MainWindow* main_window;
	QVBoxLayout* fav_layout;
	QVBoxLayout* storage_layout;
	QVBoxLayout* storage_layout2ex;
	QHBoxLayout* Hla1;

signals:
	void buttonClicked(int index);

	

private slots:
	void onButtonClicked();



protected:
	void paintEvent(QPaintEvent* event);
	

};