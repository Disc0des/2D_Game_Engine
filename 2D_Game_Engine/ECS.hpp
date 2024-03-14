//
//  ECS.hpp
//  2D_Game_Engine
//
//  Created by Dan Hembery on 10/02/2024.
//

#ifndef ECS_hpp
#define ECS_hpp

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID()
{
    static ComponentID lastID = 0;
    return lastID++;
};

// Get last componentID
template <typename T> inline ComponentID getComponentTypeID() noexcept
{
    static ComponentID typeID = getComponentTypeID();
    return typeID;
};

// Entity has a componenet attached ?
constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
public:
    Entity* entity;
    
    virtual void init() {};
    virtual void update() {};
    virtual void draw() {};
    
    virtual ~Component() {};
};

class Entity
{
private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;
    
    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
    
public:
    void update()
    {
        for(auto& c : components) c-> update();
        for(auto& c : components) c-> draw();
    };
    void draw() {}
    bool isActive() { return active; }
    void destroy() { active = false; }
    
    template <typename T> bool hasCompoent() const
    {
        return componentBitSet[getComponentTypeID<T>];
    }
    
    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... mArgs)
    {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr{ c };
        components.emplace_back(std::move(uPtr));
        
        componentArray[getComponentTypeID<T>()] = c;
        componentBitSet[getComponentTypeID<T>()] = true;
        
        c->init();
        return *c;
    }
    
    template<typename T> T& getComponent() const
    {
        auto ptr(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }
};

class Manager
{
private:
    std::vector<std::unique_ptr<Entity>> entities;
    
public:
    void update()
    {
        for(auto& e : entities) e->update();
    }
    
    void draw()
    {
        for(auto& e : entities) e->draw();
    }
        
    void refresh()
    {
        entities.erase(std::remove_if(std::begin(entities), std::end(entities), [](const std::unique_ptr<Entity> &mEntity)
        {
            return !mEntity->isActive();
        }),
        std::end(entities));
    }
    
    Entity& addEntity()
    {
        Entity* e = new Entity();
        std::unique_ptr<Entity> uPtr{ e };
        entities.emplace_back(std::move(uPtr));
        return *e;
    }
};



#endif /* ECS_hpp */
