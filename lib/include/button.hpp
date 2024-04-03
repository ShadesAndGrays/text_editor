#pragma  once
#include "panel.hpp"
#include "ui_manager.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <functional>
#include <memory>

namespace ui {

    class Button : public UiElement{

        private: 
            sf::Font font;
            sf::Text txt;
            std::string name;
            sf::RectangleShape rect;
            std::unique_ptr<Panel> panel;
            std::function<void()> callback;
        public:
            

            Button();
            Button(std::function<void()> callback);
            void setName(std::string name);
            void draw() override;
            bool actionPerformed() override;
            void setWindow(sf::RenderWindow * window) override;
            void setPosition(float x, float y) override;
            void setSize(float width, float height) override;
            void update() override;


    };
}
