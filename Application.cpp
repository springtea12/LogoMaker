#include "Application.h"

Application::Application() : Application({2560, 1440, 32}, "Kologo")
{

}

Application::Application(sf::VideoMode videoMode, std::string title)
: window(videoMode, title)
{
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(60);
}

void Application::runLoop()
{
    while(window.isOpen())
    {
        eventListener();

        window.clear();

        // Updating each object
        for(GUIComponent* o : objects)
            o->update();

        // Range based loop
        for(GUIComponent* o : objects)
            window.draw(*o);

        window.display();
    }
}

void Application::eventListener()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(sf::Event::Closed == event.type)
            window.close();

        // To check an event for an object
        for(GUIComponent* o: objects)
            o->eventHandler(window, event);
    }
}

void Application::run()
{
    //Button b;
    runLoop();
}

void Application::addDrawable(GUIComponent &object)
{
    // pushing the object into the vector of objects to be drawn.
    objects.push_back(&object);
}

void Application::test()
{
    Kologo ko;
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                window.close();
            ko.eventHandler(window, event);
        }
        ko.update();
        window.clear();
        window.draw(ko);
        window.display();
    }
}
