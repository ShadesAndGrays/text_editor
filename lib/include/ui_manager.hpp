#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

namespace ui {

    class UiElement{

        protected:
            UiElement();
            float x;
            float y;
            float sixeX;
            float sizeY;
            bool visible;
            sf::RenderWindow * window;
            sf::Color bgColor;
            sf::Color fgColor;

        public:
            void setWindow(sf::RenderWindow * window);
            virtual void draw();
            virtual bool mouseOn();
            virtual bool actionPerformed();
            void setSize(float width , float height);
            void setPosition(float x, float y);
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



    };
}
