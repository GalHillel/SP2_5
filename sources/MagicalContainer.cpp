#include "MagicalContainer.hpp"
#include <algorithm>

namespace ariel
{
    MagicalContainer::MagicalContainer() {}

    MagicalContainer::~MagicalContainer() {}

    void MagicalContainer::addElement(int element)
    {
        elements.push_back(element);
        std::sort(elements.begin(), elements.end());
    }

    void MagicalContainer::removeElement(int element)
    {
        bool in = false;
        for (auto it = elements.begin(); it != elements.end(); ++it)
        {
            if (*it == element)
            {
                elements.erase(it);
                in =  true;
                break;
            }
        }

        if (!in)
        {
            throw std::runtime_error("This element dont exist in this container");
        }
        
    }

    /*MagicalContainer &MagicalContainer::operator=(const MagicalContainer &other)
    {
        if (this != &other)
        {
            elements = other.elements;
        }
        return *this;
    }*/

    int MagicalContainer::size()
    {
        return elements.size();
    }
}