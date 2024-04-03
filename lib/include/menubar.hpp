#pragma  once
#include "button.hpp"
#include "panel.hpp"
#include "ui_manager.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Window.hpp>
#include <functional>
#include <memory>
#include <vector>

namespace ui {

    class MenuBar : public UiElement{

        private: 
            Panel area;
            std::vector<std::shared_ptr<Button>> buttons;

        public:
            MenuBar();
            void draw() override;
            void addButton(std::string name,std::function<void()> callback);
            void setWindow(sf::RenderWindow * window) override;
            void setPosition(float x, float y) override;
            void setSize(float width, float height) override;
            void setBackground(sf::Color color) override;
            void setForeground(sf::Color color) override;
            void update() override;


    };
}
