#ifndef LABVIEWGUI_H
#define LABVIEWGUI_H

#include <QWidget>

namespace Ui {
class labViewGUI;
}

class labViewGUI : public QWidget
{
    Q_OBJECT

public:
    explicit labViewGUI(QWidget *parent = 0);
    ~labViewGUI();

private:
    Ui::labViewGUI *ui;
};

#endif // LABVIEWGUI_H
