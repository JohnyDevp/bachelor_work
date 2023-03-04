#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "warehouse_final_controller.h"
#include "warehouse_original_controller.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void btnLoadOriginalJson_click();
    void btnLoadFinalJson_click();
    void btnShowOriginalJson_click();
    void btnShowFinalJson_click();
    void btnCompare_click();

private:
    Ui::MainWindow *ui;

    /// @brief currently loaded original data controller
    WarehouseOriginalController * woc;

    /// @brief currently loaded final data controller
    WarehouseFinalController * wfc;
};
#endif // MAINWINDOW_H