#pragma  once
#include "panel.hpp"
#include "ui_manager.hpp"
#include <memory>

namespace ui {

    class Button : public UiElement{

        private: 
            sf::RectangleShape rect;
            std::unique_ptr<Panel> panel;
        public:
            Button();
            void draw() override;
            bool actionPerformed() override;
            void setWindow(sf::RenderWindow * window) override;
            void setPosition(float x, float y) override;
            void setSize(float width, float height) override;
            void update() override;

    };
}
