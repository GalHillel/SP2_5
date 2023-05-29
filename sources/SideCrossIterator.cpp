#include "MagicalContainer.hpp"

namespace ariel
{
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &container)
        : container(container), forward(container.elements.begin()), backward(container.elements.end() - 1), isForward(true) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
        : container(other.container), forward(other.forward), backward(other.backward), isForward(other.isForward) {}

    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        if (this != &other)
        {
            forward = other.forward;
            backward = other.backward;
            isForward = other.isForward;
        }
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        return forward == other.forward && backward == other.backward && isForward == other.isForward;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return forward > other.forward;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return forward < other.forward;
    }

    int MagicalContainer::SideCrossIterator::operator*() const
    {
        if (isForward)
        {
            return *forward;
        }
        else
        {
            return *backward;
        }
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        if (isForward)
        {
            ++forward;
        }
        else
        {
            --backward;
        }
        isForward = !isForward;
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        SideCrossIterator iter(*this);
        return iter;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        SideCrossIterator iter(*this);
        return iter;
    }
}