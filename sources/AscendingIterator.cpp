#include "MagicalContainer.hpp"
#include <algorithm>

namespace ariel
{

    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &container)
        : container(container), current(container.elements.begin()) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
        : container(other.container), current(other.current) {}

    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        if (this != &other)
        {
            if (&container != &other.container)
            {
                throw std::runtime_error("Cannot assign iterators from different containers");
            }
            current = other.current;
        }
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        return current == other.current;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        return current > other.current;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return current < other.current;
    }

    int MagicalContainer::AscendingIterator::operator*() const
    {
        return *current;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        if (this->end() == *this)
        {
            throw std::runtime_error("Can not increment beyond the end");
        }
        else
        {
            ++current;
            return *this;
        }
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        AscendingIterator iter(*this);
        iter.current = std::min_element(container.elements.begin(), container.elements.end());
        return iter;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        AscendingIterator iter(*this);
        iter.current = container.elements.end();
        return iter;
    }
}