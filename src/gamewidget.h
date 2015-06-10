#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QColor>
#include <QWidget>

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

signals:
    //когад одна из клеток была заменена, идёт сигнал для фиксации размеров вселенной
    void environmentChanged(bool ok);
    //когда игра закончена иили чистое поле
    void gameEnds(bool ok);

public slots:
    void startGame(const int &number = -1); // старт
    void stopGame(); // стоп
    void clear(); // очистить
    void rules(); // правила

    int cellNumber(); // количество клеток в одной строке
    void setCellNumber(const int &s); // установить количество клеток в одной строке

    int interval(); // интервал между поколениями
    void setInterval(int msec); // установить интервал между поколениями

    QColor masterColor(); // цвет ячеек
    void setMasterColor(const QColor &color); // установить цвет ячеек

    QString dump(); // сброс текущей вселенной
    void setDump(const QString &data); // set current universe from it's dump

private slots:
    void paintGrid(QPainter &p);
    void paintUniverse(QPainter &p);
    void newGeneration();

private:
    QColor m_masterColor;
    QTimer* timer;
    int generations;
    bool* universe; // карта1
    bool* next; // карта2
    int universeSize;
    bool isAlive(int k, int j); // вернуться к true, если вселенная k,j правильная
    void resetUniverse();// сбросить размер вселенной
};

#endif // GAMEWIDGET_H
