#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

namespace ui {

    class UiElement{

        protected:
            UiElement();
            float x = 0;
            float y= 0;
            float sizeX = 0;
            float sizeY = 0;
            bool visible = false;
            sf::RenderWindow * window;
            sf::Color bgColor;
            sf::Color fgColor;
            sf::Rect<float> region;

        public:
            virtual void setWindow(sf::RenderWindow * window);
            virtual void draw();
            virtual bool mouseOn();
            virtual bool actionPerformed();
            virtual void setSize(float width , float height);
            virtual void setPosition(float x, float y);
            virtual void update();
            void setVisible(bool visible);
            virtual void setBackground(sf::Color color);
            virtual void setForeground(sf::Color color);
            bool isVisible();
    };

    class UiManager{

        private:
            std::vector<std::shared_ptr<UiElement>> elements;
            sf::RenderWindow * window;
            sf::Color bgColor;
        public:
            UiManager(sf::RenderWindow *window);
            void addElement(std::shared_ptr<UiElement> element);
            void draw();
            void update();



    };
}
