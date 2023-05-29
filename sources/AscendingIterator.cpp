#include "MagicalContainer.hpp"

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
        ++current;
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        AscendingIterator iter(*this);
        iter.current = container.elements.begin();
        return iter;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        AscendingIterator iter(*this);
        iter.current = container.elements.end();
        return iter;
    }
}