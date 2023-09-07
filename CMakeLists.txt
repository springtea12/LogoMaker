cmake_minimum_required(VERSION 3.24)
project(final)

set(CMAKE_CXX_STANDARD 17)

add_executable(final main.cpp Application.h Application.cpp GUIComponent.cpp Helper.h Helper.cpp InputBox.h InputBox.cpp Item.h Item.cpp ItemList.h ItemList.cpp MenuBar.h MenuBar.cpp States.cpp Font.cpp Slider.h Slider.cpp MenuList.cpp MenuList.h SliderList.cpp SliderList.h Kologo.cpp Kologo.h SaveText.cpp SaveText.h ScreenShot.cpp ScreenShot.h Typing.cpp MultiText.h MultiText.cpp Letter.cpp Label.cpp Box.cpp Cursor.cpp DisplayBox.cpp DisplayBox.h Color.cpp Color.h dispImage.cpp dispImage.h)
target_link_libraries(final sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
