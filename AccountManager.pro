QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    view/account_clone.cpp \
    moderator/moderator.cpp \
    model/account_model.cpp \
    view/account_set.cpp \
    main.cpp \
    view/mainwindow.cpp \

HEADERS += \
    view/account_clone.h \
    moderator/moderator.h \
    model/account_model.h \
    view/account_set.h \
    view/mainwindow.h \

FORMS += \
    view/account_clone.ui \
    view/account_set.ui \
    view/mainwindow.ui

INCLUDEPATH += \
    $$PWD/model \
    $$PWD/moderator \
    $$PWD/view

CONFIG += staticlib


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
