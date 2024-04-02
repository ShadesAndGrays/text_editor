#pragma  once
#include "panel.hpp"
#include "ui_manager.hpp"

namespace ui {

    class MenuBar : public UiElement{

        private: 
            Panel area;
        public:
            MenuBar();
            void draw() override;
            bool actionPerformed() override;
            

    };
}
