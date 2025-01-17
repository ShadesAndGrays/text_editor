#pragma  once
#include "ui_manager.hpp"

namespace ui {

    class Panel : public UiElement{

        private: 
            sf::RectangleShape rect;
        public:
            Panel();
            void draw() override;
            bool actionPerformed() override;

    };
}
