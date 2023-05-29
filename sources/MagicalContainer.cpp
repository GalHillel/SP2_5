    #include "MagicalContainer.hpp"

    namespace ariel
    {
        MagicalContainer::MagicalContainer() {}

        MagicalContainer::~MagicalContainer() {}

        void MagicalContainer::addElement(int element)
        {
            elements.push_back(element);
        }

        void MagicalContainer::removeElement(int element)
        {
            for (auto it = elements.begin(); it != elements.end(); ++it)
            {
                if (*it == element)
                {
                    elements.erase(it);
                    break;
                }
            }
        }

        int MagicalContainer::size()
        {
            return elements.size();
        }
    }