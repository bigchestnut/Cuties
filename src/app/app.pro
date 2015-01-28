QT += core\
      gui\
      widgets

CONFIG += c++11

INCLUDEPATH += sdk

SOURCES += \
    main.cpp \
    kcloader.cpp \
    sdk/kcmainwindow.cpp \
    sdk/kctabmanager.cpp \
    sdk/kccodeeditor.cpp \
    sdk/kctexteditor.cpp \
    sdk/sao/knsaostyle.cpp \
    sdk/sao/knsaosubmenu.cpp \
    sdk/sao/knsaomainmenu.cpp \
    plugins/kcmainmenu/kcmainmenu.cpp \
    kcglobal.cpp \
    plugins/kcunititlebar/kcunititlebar.cpp \
    sdk/kctextblockdata.cpp \
    sdk/kctexteditorpanelbar.cpp \
    sdk/kctexteditorpanel.cpp \
    sdk/kctexteditorlinenumberpanel.cpp

HEADERS += \
    kcloader.h \
    sdk/kcmainwindow.h \
    knversion.h \
    sdk/kctabmanager.h \
    sdk/kccodeeditor.h \
    sdk/kctexteditor.h \
    sdk/sao/knsaostyle.h \
    sdk/sao/knsaosubmenu.h \
    sdk/sao/knsaomainmenu.h \
    plugins/kcmainmenu/kcmainmenu.h \
    kcglobal.h \
    plugins/kcunititlebar/kcunititlebar.h \
    sdk/kctextblockdata.h \
    sdk/kctexteditorpanelbar.h \
    sdk/kctexteditorpanel.h \
    sdk/kctexteditorlinenumberpanel.h

RESOURCES += \
    resources/resources.qrc

