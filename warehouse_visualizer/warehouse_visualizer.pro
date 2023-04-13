QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += \
    -L ./../bachelor_work_code/src/ -lwarehouse_pick_opt \
    -lpython3.11

SOURCES += \
    src/load_json_data.cpp \
    src/itemgui.cpp \
    src/warehouse_original_controller.cpp \
    src/warehouse_final_controller.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/warehouseview.cpp

HEADERS += \
    ./../bachelor_work_code/src/WarehousePickingOpt.h \
    src/overtaken/waddress_functions.hpp \
    src/overtaken/objects.h \
    src/itemgui.h \
    src/warehouse_final_controller.h \
    src/warehouse_original_controller.h \
    src/debug.h \
    src/load_json_data.h \
    src/mainwindow.h \
    src/warehouseview.h

FORMS += \
    src/mainwindow.ui \
    src/warehouseview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
