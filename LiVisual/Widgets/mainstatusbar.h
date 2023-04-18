#ifndef MAINSTATUSBAR_H
#define MAINSTATUSBAR_H

#include <QStatusBar>
#include <QLabel>
#include <memory>

class MainStatusBar : public QStatusBar
{
    Q_OBJECT

public:
    explicit MainStatusBar(QWidget *parent = nullptr);
    virtual ~MainStatusBar() = default;

private:
    std::unique_ptr<QLabel> FieldSize;

public slots:
    void UpdateFieldSize(int width, int height);
    void ResetFieldSize();

};

#endif // MAINSTATUSBAR_H
