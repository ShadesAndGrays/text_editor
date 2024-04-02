find_package(SFML COMPONENTS graphics window system)

set(SFML_STATIC_LIBRARIES TRUE)

add_library(
    ui 
    UI/ui_manager.cpp
    UI/panel.cpp
    UI/menubar.cpp
    UI/button.cpp
    )

target_include_directories(ui PUBLIC include/)
