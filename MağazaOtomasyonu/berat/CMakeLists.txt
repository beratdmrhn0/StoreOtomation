cmake_minimum_required(VERSION 3.5)

project(proje_mgz VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        MagazaMain.cpp
        MagazaMain.h
        MagazaMain.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(proje_mgz
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        veri/ortak.h
        veri/veri_nesneleri/magazabilgileri.h veri/veri_nesneleri/magazabilgileri.cpp
        veri/veri_nesneleri/musteri.h veri/veri_nesneleri/musteri.cpp
        veri/veri_nesneleri/ortak_veri_sinifi.h veri/veri_nesneleri/ortak_veri_sinifi.cpp
        veri/veri_nesneleri/siparis.h veri/veri_nesneleri/siparis.cpp
        veri/veri_nesneleri/siparisurunu.h veri/veri_nesneleri/siparisurunu.cpp
        veri/veri_nesneleri/urunkategorisi.h veri/veri_nesneleri/urunkategorisi.cpp
        veri/veri_nesneleri/urunler.h veri/veri_nesneleri/urunler.cpp
        veri/veri_nesneleri/urunozellikleri.h veri/veri_nesneleri/urunozellikleri.cpp
        veri/veri_nesneleri/urunyorumu.h veri/veri_nesneleri/urunyorumu.cpp
        veri/konteynir.h
        veri/konteynirler/magazabilgilerikonteynir.h veri/konteynirler/magazabilgilerikonteynir.cpp
        veri/konteynirler.h
        veri/konteynirler/musterikonteynir.h veri/konteynirler/musterikonteynir.cpp
        veri/konteynirler/sipariskonteynir.h veri/konteynirler/sipariskonteynir.cpp
        veri/konteynirler/siparisurunukonteynir.h veri/konteynirler/siparisurunukonteynir.cpp
        veri/konteynirler/urunkategorisikonteynir.h veri/konteynirler/urunkategorisikonteynir.cpp
        veri/konteynirler/urunlerkonteynir.h veri/konteynirler/urunlerkonteynir.cpp
        veri/konteynirler/urunozelliklerikonteynir.h veri/konteynirler/urunozelliklerikonteynir.cpp
        veri/veritabani.h veri/veritabani.cpp
        ayarlar/uygulamaayarlari.h ayarlar/uygulamaayarlari.cpp
        ekranlar/bilesenler/saribbon.h ekranlar/bilesenler/saribbon.cpp


        kaynaklar/kaynaklar.qrc
        SARibbonBar/resource.qrc
        ekranlar/diger/ayarekrani.h ekranlar/diger/ayarekrani.cpp ekranlar/diger/ayarekrani.ui
        ekranlar/diger/yeniverigirisekrani.h ekranlar/diger/yeniverigirisekrani.cpp ekranlar/diger/yeniverigirisekrani.ui
        ekranlar/giris/verinesnesiatamaarayuzu.h
        ekranlar/giris/veriekraneslesmesi.h ekranlar/giris/veriekraneslesmesi.cpp
        ekranlar/eylemler/eylemyoneticisi.h ekranlar/eylemler/eylemyoneticisi.cpp
        ekranlar/eylemler/Sablonlar.h
        ekranlar/giris/mgzekran.h ekranlar/giris/mgzekran.cpp ekranlar/giris/mgzekran.ui


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET proje_mgz APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(proje_mgz SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(proje_mgz
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(proje_mgz PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.proje_mgz)
endif()
set_target_properties(proje_mgz PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS proje_mgz
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(proje_mgz)
endif()
