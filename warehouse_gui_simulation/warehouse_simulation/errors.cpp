#include "errors.h"
#include <QMessageBox>

errors::errors()
{

}

void errors::Alert(QString alertText){
    QMessageBox msgBox;
    msgBox.setBackgroundRole(QPalette::Window);
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText(alertText);
    msgBox.exec();
}
