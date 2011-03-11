#ifndef STATIONWIDGET_H
#define STATIONWIDGET_H

#include <QWidget>

#include <lastfm/RadioStation>

namespace Ui {
    class StationWidget;
}

class StationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StationWidget(QWidget *parent = 0);
    ~StationWidget();

    void addStation( const RadioStation& station );
    void recentStation( const RadioStation& station );

private:
    void resizeEvent ( QResizeEvent * event );

    class QTreeWidgetItem* createItem( const RadioStation& station );

private slots:
    void onItemClicked( class QTreeWidgetItem* item, int column );
    void onTuningIn( const RadioStation& station );

private:
    Ui::StationWidget *ui;
};

#endif // STATIONWIDGET_H