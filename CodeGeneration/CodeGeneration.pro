QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    AbstractFactory.h \
    CSharpClassUnit.h \
    CSharpFactory.h \
    CSharpMethodUnit.h \
    CSharpPrintOperatorUnit.h \
    CppClassUnit.h \
    CppFactory.h \
    CppMethodUnit.h \
    CppPrintOperatorUnit.h \
    JavaClassUnit.h \
    JavaFactory.h \
    JavaMethodUnit.h \
    JavaPrintOperatorUnit.h \
    Unit.h \
    ‎Unit.h \
    ‎Unit.h \
    ‎Unit.h \
    ‎Unit.h
