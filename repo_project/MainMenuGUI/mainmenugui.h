#ifndef MAINMENUGUI_H
#define MAINMENUGUI_H

#include <QMainWindow>

namespace Ui {
class MainMenuGUI;
}

class MainMenuGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenuGUI(QWidget *parent = 0);
    ~MainMenuGUI();

private:
    Ui::MainMenuGUI *ui;
};

#endif // MAINMENUGUI_H
